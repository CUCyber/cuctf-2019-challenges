from Crypto.PublicKey import RSA
from Crypto.Util.number import getPrime

flag = b'CUCTF{Qu4sI_Pr1m3_T0t4L_SC4M}'

def mod_inv(a, n):
    t, r = 0, n
    new_t, new_r = 1, a

    while new_r != 0:
        quotient = r // new_r
        t, new_t = new_t, t - quotient * new_t
        r, new_r = new_r, r - quotient * new_r

    if r > 1:
        raise Exception("a is not invertible")
    if t < 0:
        t = t + n

    return t

p = getPrime(128)
q = getPrime(128)
n = p * q
e = 65537

phi = (p-1) * (q-1)

d = mod_inv(e, phi)

key_params = (n, e, d, p, q)
key = RSA.construct(key_params)

pubkey = key.publickey()
ciphertext = pubkey.encrypt(flag, 32)[0]

with open("flag.enc", "wb+") as f:
    f.write(ciphertext)

with open("pub.key", "w+") as f:
    f.write(key.publickey().exportKey('PEM').decode('utf-8'))

with open("priv.key", "w+") as f:
    f.write(key.exportKey('PEM').decode('utf-8'))
