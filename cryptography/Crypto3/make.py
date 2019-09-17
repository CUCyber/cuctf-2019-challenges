from random import shuffle
from string import (
    ascii_lowercase,
    ascii_uppercase
)

key_lower = "hpfickntedjvzqywrsbalmguox"
key_upper = "HPFICKNTEDJVZQYWRSBALMGUOX"

description = '''\
Welcome to cuctf. The flag for this challenge is the words substitution and cipher in all upper case letters separated by an underscore.\
'''

def transform(letter):
    if letter in key_lower:
        return key_lower[
            ascii_lowercase.index(letter)
        ]
    elif letter in key_upper:
        return key_upper[
            ascii_uppercase.index(letter)
        ]
    else:
        return letter

print(''.join(map(transform, description)))
