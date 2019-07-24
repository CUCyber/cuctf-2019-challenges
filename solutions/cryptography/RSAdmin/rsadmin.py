import json
from base64 import b64decode, b64encode
from Crypto.Hash import SHA256
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5
from ecdsa.numbertheory import inverse_mod

message = "I am an administrator."

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

def solve_p(nlist):
	for key1 in nlist:
		for key2 in nlist:
			if key1 != key2:
				p = gcd(key1, key2)
				if p != 1:
					return key1, p, key1//p

def solve(keylist):
	publickeys = [RSA.importKey(k) for k in keylist]
	nlist = [k.n for k in publickeys]
	n, p, q = solve_p(nlist)
	e = 65537
	d = modinv(e, (p-1) * (q-1))
	key_params = (n, e, d, p, q)
	privatekey = RSA.construct(key_params)

	h = SHA256.new(message.encode('utf-8'))
	signer = PKCS1_v1_5.new(privatekey)
	signature = signer.sign(h)
	return signature

def main():
	keylistJson = json.load(open("keylist.json"))
	pubkeylist = [k["publickey"] for k in keylistJson]
	hexsig = solve(pubkeylist)
	print(b64encode(hexsig))

if __name__ == "__main__":
	main()
