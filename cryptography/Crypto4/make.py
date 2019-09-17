from string import ascii_letters
from itertools import starmap, cycle

text = 'This is a vigenere cipher. The flag is LE_CHIFFRE_INDECHIFFRABLE'
key = 'CUCTF'

message = filter(str.isalpha, text.upper())

def vigenere_enc(c, k):
    return chr(((ord(k) + ord(c) - 2 * ord('A')) % 26) + ord('A'))

encrypted = ''.join(starmap(vigenere_enc, zip(message, cycle(key))))

for idx, val in enumerate(text):
    if val not in ascii_letters:
        encrypted = ''.join([
            encrypted[:idx], val, encrypted[idx:]
        ])

print(encrypted)
