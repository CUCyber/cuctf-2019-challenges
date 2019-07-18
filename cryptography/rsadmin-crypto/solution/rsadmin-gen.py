import json
from os import urandom
from Crypto.Hash import SHA
from Crypto.Util import number
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5

def gcd(x, y):
	while y != 0:
		(x, y) = (y, x % y)
	return x

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

def genKey(p):
	q = number.getPrime(2048)
	n = p * q
	e = 65537L
	d = modinv(e, ((p-1) * (q-1)))
	key_params = (n, e, d, p, q)
	key = RSA.construct(key_params)
	return key

def main():
	message = "I am an administrator."
	keylist = []
	names = ["Mollie", "Randolph", "Calvin", "Bob", "Joe", "Mason", "Corrina", "Carolyn", "Maurice", "Myra"]

	p = number.getPrime(2048)
	keylist.append({"name":names[0], "publickey":genKey(p)})
	keylist.append({"name":names[1], "publickey":genKey(p)})
	for i in range(8):
		p = number.getPrime(2048)
		keylist.append({"name":names[i+2], "publickey":genKey(p)})

	jsonlist = keylist
	privatekeys = [k["publickey"] for k in keylist]
	pubkeystrs = [k.publickey().exportKey("PEM") for k in privatekeys]

	for i, key in enumerate(pubkeystrs):
		jsonlist[i]['publickey'] = key

	print(json.dumps(jsonlist, indent=4, sort_keys=True))
	
if __name__ == "__main__":
	main()
