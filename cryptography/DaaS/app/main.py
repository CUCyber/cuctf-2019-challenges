from random import randint
from Crypto.PublicKey import RSA
from flask import Flask, request, jsonify, render_template, render_template_string

app = Flask(__name__)

FLAG = b"CUCTF{4lw4y5_p4d_y0ur_m3ss4g3s}"

rsa = None
rsa_server = None

def initialize():
    global rsa, rsa_server
    rsa = CustomRSA(1024)
    rsa_server = RSAServer(
        rsa, rsa.encrypt(FLAG)
    )

def int_to_bytes(n):
    ''' https://stackoverflow.com/a/30375198/3610102 '''
    return n.to_bytes((n.bit_length() + 7) // 8, 'big')

class CustomRSA:
    def __init__(self, key_length):
        self.key = RSA.generate(key_length)
        self.n = self.key.n
        self.e = self.key.e
        
        self._d = self.key.d

    def encrypt(self, plaintext):
        int_data = self.key.encrypt(plaintext, 1337)[0]
        return int.from_bytes(int_data, byteorder='big')

    def decrypt(self, ciphertext):
        int_data = pow(ciphertext, self._d, self.n)
        return int_to_bytes(int_data)

class RSAServer:
    def __init__(self, rsa, flag):
        self._rsa = rsa
        self._decrypted = set({flag})

    def export_public_key(self):
        return self._rsa.key.publickey().exportKey('PEM')

    def decrypt(self, data):
        if data in self._decrypted:
            return "This ciphertext has already been decrypted"
        self._decrypted.add(data)
        return self._rsa.decrypt(data)

@app.route('/key', methods=['GET'])
def key():
    if not rsa or not rsa_server:
        initialize()
    pubkey = rsa_server.export_public_key().decode("utf-8")
    pubkey_html = pubkey.replace("\n","<br />")
    return render_template_string(pubkey_html)

@app.route('/sample', methods=["GET"])
def sample():
    if not rsa or not rsa_server:
        initialize()
    sample_texts = [
        b"Hello, world!",
        b"Testing, testing, 1... 2... 3...",
        b"Once upon a time",
        FLAG,
        b"Lorem ipsum dolor sit amet"
    ]
    ciphertexts = {'samples': []}
    for text in sample_texts:
        ciphertext = rsa.encrypt(text)
        ciphertexts['samples'].append(ciphertext)
    return jsonify(ciphertexts)

@app.route('/', methods=["GET", "POST"])
def index():
    if not rsa or not rsa_server:
        initialize()
    if request.method == 'GET':
        return render_template("index.html")
    elif request.method == 'POST':
        ciphertext = request.form.get('ciphertext', None)
        if not ciphertext:
            return "Missing ciphertext in post request."
        if not ciphertext.isdigit():
            return "Ciphertext is not an integer."
        return rsa_server.decrypt(int(ciphertext))
    else:
        return "Request method not understood."

if __name__ == '__main__':
    app.config.from_object(__name__)
    app.config['SECRET_KEY'] = '9b7ef59d2a37d56d9a9bd1c8013925f055e4ab0b'
    app.run(debug=False, host='0.0.0.0', port=8100)
