# SMS

This challenge is an [adaptive chosen-ciphertext attack](https://en.wikipedia.org/wiki/Adaptive_chosen-ciphertext_attack) (CCA2) against PKCS1#1 v1.5. 

Navigating to the server we see a two classes, User and Message, and a few different API calls that we can make:

```
User:
    user_id: int
    username: str

Message:
    to_user: User
    from_user: User
    ciphertext: str

GET "/"
GET "/list/users"
GET "/list/messages"
GET "/keys/{user_id}"
GET "/read/{message_id}"
POST "/send"
  - Data: Message
```

1. If we make a get request to "/", we just get redirected to "/docs".
2. If we make a get request to "/list/users", we get a list of users:

3. If we make a get request to "/list/messages", we get a list of archived messages:

4. If we make a get request to "/keys/{user_id}" with a user_id of 0 we get Alice's public key, 1 we get Bob's public key, and 2 we get Charlie's public key.

5. If we read the only archived message (message id 0) we can see an encrypted message was sent from Bob to Alice.

```JSON
{
  "to_user": {
    "user_id": 0,
    "username": "Alice"
  },
  "from_user": {
    "user_id": 1,
    "username": "Bob"
  },
  "ciphertext": "58b3432a..."
}
```

We don't have Alice's private key so we can't easily decrypt it. We can try factoring N from her public key, but you would quickly realize that it's a 1024 bit key. It's far too strong to factor in a reasonable time frame.

If we try the send API endpoint, we can try sending data from one user to another. Let's try to replay the message from Bob to Alice.

If we send the exact message back, we receive the following response:

```JSON
{
  "Success": "Message sent successfully!"
}
```

What were to happen if we sent the ciphertext to a user who doesn't exist? We will receive one of the following messages:

```JSON
{
  "Error": "To user not in user list!"
}
```

or

```JSON
{
  "Error": "From user not in user list!"
}
```

If we try to modify the ciphertext with the same `to_user` and `from_user`, we get the following error message:

```JSON
{
  "Failure": "Incorrect message padding."
}
```

There's our bug! The server revealed that our message had an incorrect padding. The ability to send a ciphertext and receive a response indicating valid or invalid padding is called a [padding oracle](https://en.wikipedia.org/wiki/Padding_oracle_attack) and the act of exploiting a padding oracle is aptly named a padding oracle attack.

We can use Bleichenbacher's '98 adaptive chosen-ciphertext attack to reveal the entire ciphertext.

We first need to define an oracle such that it returns `True` on valid padding and `False` on invalid padding of any given ciphertext.

```Python
def oracle(ciphertext):
    json_data = {
      "to_user": {
        "user_id": 0,
        "username": "Alice"
      },
      "from_user": {
        "user_id": 1,
        "username": "Bob"
      },
      "ciphertext": hexlify(ciphertext)
    }
    r = requests.post(
        URL+"/send",
        headers={'Content-type': 'application/json'},
        json=json_data
    )
    return "Failure" not in r.json()
```

We can then use a powerful cryptographic exploitation library called [Featherduster](https://github.com/nccgroup/featherduster) to do the remainder of the heavy lifting. We use the function bb98_padding_oracle with the ciphertext that contains our original encrypted message, the oracle function, and the E and N values in Bob's public key.

```Python
decrypted = cryptanalib.bb98_padding_oracle(
    ciphertext,
    oracle,
    key.e,
    key.n,
    verbose=True,
    debug=True
)
```

After some time, we eventually get the completely deciphered message containing the flag:

`CUCTF{7h3_p4dd1n6_0r4cl3_kn0w5_4ll}`
