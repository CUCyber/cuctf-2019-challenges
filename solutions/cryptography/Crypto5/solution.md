# Crypto5

The description refers to a single byte making all the difference. A common beginner crypto challenge is called a single-byte xor. In fact, it's Challenge 3 of Set 1 of the Cryptopals crypto challenges: https://cryptopals.com/sets/1/challenges/3

If we base64 decode the flag and then run a single-byte XOR brute force on the resulting ciphertext, our flag should be in the mix.

https://gchq.github.io/CyberChef/#recipe=From_Base64('A-Za-z0-9%2B/%3D',true)XOR_Brute_Force(1,100,0,'Standard',false,true,false,'')&input=Q1I4Skhnd3hmaVltRlh0OUZSNStJWGwvRlh0L0ZYNFZDRE45ZVRjPQ

Searching for "CUCTF" we can see a single-byte xor of 4a obfuscated the flag.
