from binascii import hexlify, unhexlify
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_v1_5

class Crypto:
    def __init__(self, user_list, flag):
        self.user_list = []
        for user_id, user in enumerate(user_list):
            pub, priv = self.generateKeys(user)
            self.user_list.append(
                {
                    "id": user_id,
                    "name": user,
                    "keypair": (pub, priv)
                }
            )
        self.flag = self.generateFlag(
            self.user_list[1]['name'], flag
        )

    def generateKeys(self, name):
        key = RSA.generate(1024, e=3)
        with open(f"{name}-pubkey.pem", "wb") as f:
            f.write(key.publickey().exportKey("PEM"))
        with open(f"{name}-privkey.pem", "wb") as f:
            f.write(key.exportKey("PEM"))
        return key.publickey(), key

    def generateFlag(self, name, flag):
        print(f"{name}-pubkey.pem")
        with open(f"{name}-pubkey.pem", "r") as f:
            key = RSA.importKey(f.read())
        with open(f"{name}-privkey.pem", "r") as f:
            self.key = RSA.importKey(f.read())
        cipher = PKCS1_v1_5.new(key)
        ciphertext = cipher.encrypt(flag.encode())
        return hexlify(ciphertext)

    def check_padding(self, ciphertext):
        ciphertext = unhexlify(ciphertext)
        plaintext = self.key.decrypt(ciphertext)
        return hexlify(plaintext)[:2] == b'02'
