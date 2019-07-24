import json
from base64 import b64decode
from Crypto.Hash import SHA256
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5

def verify_signature(signature):
	message = "I am an administrator."

	keylistJson = json.load(open("keylist.json"))
	pubkeylist = [k["publickey"] for k in keylistJson]
	publickeys = [RSA.importKey(k) for k in pubkeylist]

	for key in publickeys:
		h = SHA256.new()
		h.update(message.encode('utf-8'))
		verifier = PKCS1_v1_5.new(key)
		if verifier.verify(h, b64decode(signature)):
			print("The sig is valid")

def main():
	signature = "Lfw3KfTNBjvgeV0oCROAYB/tlMPXwyjdx2nvNo49aZbBTm+7idZzlV+UcjXTIKzJKg/w66IUVBcCtmm/CEOpEGkHoeDqDxKlVfAz8ZaXqOEtoYBfvJ00Hi+VChVr1CmwySZvQq+CrfRbh2pHJBy84wtBr3xGljnpYj7IA7CKFbocAVBnJKWFC71XIFpmTYKECYUNVPOcNDrYvpUBgNYklg8pTa3ZjDndT5OQIrdBqMKcnCbGnCG3BtYQTMeaspJ4+AYiP0XKeNkEz3K1atkdAEZjw+m8jvrZfzZKR1lK70b57JbTwBYBf87HzJYVChXye3AkADoDdnQoKn2f9M8bVhXCs7kl8ruHI5alw2pjR8MbALCty2IYOptMSWu39ITUSXRheqiPuiutoV7GRrqzuM/Grr2nqlbloLNTtf/hPuXAe8Zaw5UFilNqySrOrvUo2VRfRLs/G92HbnWsB0MvYmrjs/ZoveNjF/Rx2FkOi2L2Zi3sU1ZATG4VWsrPnYZ6LbQwMC04GdPhSewHuz6y9dSek2fVLMBEbcSZQkp/r0d2JG/eiC4OWKdDoNSeeEOLpawbygk2p/8llHPHV0LpdoDVmA1g7gborQS9f8JeA4qPJbuUMp7/uMHk30bG7HaQ9S9tx+RuNjJW0lPeCmqw2acOxz3vf4gjgN87i492oGI="
	verify_signature(signature)

if __name__ == "__main__":
	main()
