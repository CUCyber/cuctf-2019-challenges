import pprint
import argparse

'''
Decode a list of integers into a string
'''
def decode(integer_list):
	string = []
	for integer in integer_list:
		while integer:
			string.append(chr(integer % 255))
			integer = int((integer - (integer % 255)) / 255)
	return ''.join(string)

'''
Encode a string into n-byte integers
'''
def encode(string, n):

	def divide_chunks(l, n):
		for i in range(0, len(l), n):
			yield l[i:i + n] 

	total = []
	for chunk in divide_chunks(string, n):
		integer = 0
		for idx, val in enumerate(chunk):
			integer += (ord(val) * 255**idx)
		total.append(integer)
	return total

def parse_arguments():
	parser = argparse.ArgumentParser(description='String/integer encoding/decoding.')
	group = parser.add_mutually_exclusive_group()
	group.add_argument('--string', type=str, default="ABCD",
						help='string to be encoded')
	group.add_argument('--list', type=list, default=[1131907070],
						help='list to bedecoded')
	parser.add_argument('--bytes', type=int, default=4,
						help='width in bytes of your integer')
	return parser.parse_args()

if __name__== '__main__':
	args = parse_arguments()

	enc_list = encode(args.string, args.bytes)
	dec_str = decode(args.list)

	print(f"Input: {args.string}\nEncoded:", end=' ')
	pprint.pprint(enc_list)
	print(f"Input: {args.list}\nDecoded:", end=' ')
	pprint.pprint(dec_str)
