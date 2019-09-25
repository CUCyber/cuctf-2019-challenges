# Crown Sterling

Crown Sterling's presentation was an attempt to deceive executives about the security of RSA. This challenge, based off of that complete scam demonstration, uses a laughably weak RSA key.

```Python
>>> from Crypto.PublicKey import RSA
>>> with open("pub.key", "r") as f:
...     pubkey = f.read()
... 
>>> pubkey = RSA.importKey(pubkey)
>>> pubkey
<_RSAobj @0x7efbfe899bd0 n(255),e>
>>> pubkey.n
55487512261113946775940605368043897621006165961211690446196359791752113379141
```

We can see in the RSA object output that the N is a 255-bit integer. This is well within our bounds to factor.

We're going to fire up YAFU (Yet Another Factoring Utility). This will allow us to efficiently factor N into P and Q.

```
$ yafu

09/25/19 00:36:46 v1.34.3 @ dev, System/Build Info: 
Using GMP-ECM 7.0.4, Powered by GMP 6.1.2
detected AMD Ryzen 7 3800X 8-Core Processor             
detected L1 = 32768 bytes, L2 = 33554432 bytes, CL = 64 bytes
measured cpu frequency ~= 3892.628220
using 20 random witnesses for Rabin-Miller PRP checks

===============================================================
======= Welcome to YAFU (Yet Another Factoring Utility) =======
=======             bbuhrow@gmail.com                   =======
=======     Type help at any time, or quit to quit      =======
===============================================================
cached 78498 primes. pmax = 999983


>> factor(55487512261113946775940605368043897621006165961211690446196359791752113379141)

fac: factoring 55487512261113946775940605368043897621006165961211690446196359791752113379141
fac: using pretesting plan: normal
fac: no tune info: using qs/gnfs crossover of 95 digits
div: primes less than 10000
rho: x^2 + 3, starting 1000 iterations on C77 
rho: x^2 + 2, starting 1000 iterations on C77 
rho: x^2 + 1, starting 1000 iterations on C77 
pm1: starting B1 = 150K, B2 = gmp-ecm default on C77
ecm: 30/30 curves on C77, B1=2K, B2=gmp-ecm default
ecm: 74/74 curves on C77, B1=11K, B2=gmp-ecm default
ecm: 149/149 curves on C77, B1=50K, B2=gmp-ecm default, ETA: 0 sec 

starting SIQS on c77: 55487512261113946775940605368043897621006165961211690446196359791752113379141

==== sieving in progress (1 thread):   35008 relations needed ====
====           Press ctrl-c to abort and save state           ====
34557 rels found: 18139 full + 16418 from 178629 partial, (3830.93 rels/sec)

SIQS elapsed time = 52.6425 seconds.
Total factoring time = 63.3081 seconds


***factors found***

P39 = 186076660469935544364191142499091336399
P39 = 298197055562909131871702501023109228459

ans = 1
```

We've successfully factored the public key in ~1 minute. We can use this to generate a private key.


```Python
from Crypto.PublicKey import RSA

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

p = 186076660469935544364191142499091336399
q = 298197055562909131871702501023109228459

n = p * q
e = 65537

phi = (p-1) * (q-1)

d = mod_inv(e, phi)

key_params = (n, e, d, p, q)
key = RSA.construct(key_params)

with open("flag.enc", "rb") as f:
    flag = f.read()

print(key.decrypt(flag))
```

This yields the flag:

```Python
>>> print(key.decrypt(flag))
b'CUCTF{Qu4sI_Pr1m3_T0t4L_SC4M}'
```
