from flask import Flask

app = Flask(__name__)

import json
import random
from base64 import b64decode
from Crypto.Hash import SHA256
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5
from flask import Flask, render_template, flash, request
from wtforms import Form, TextField, TextAreaField, validators, StringField, SubmitField

class ReusableForm(Form):
	name = TextField('Signature:', validators=[validators.required()], id="signature")
 
def verify_signature(signature):
	message = "I am an administrator."

	keylistJson = json.load(open("static/uploads/keylist.json"))
	pubkeylist = [k["publickey"] for k in keylistJson]
	publickeys = [RSA.importKey(k) for k in pubkeylist]

	for key in publickeys:
		h = SHA256.new()
		h.update(message.encode('utf-8'))
		verifier = PKCS1_v1_5.new(key)
		try:
			if verifier.verify(h, b64decode(signature)):
				return True
		except:
			return False

	return False

@app.route('/authenticate', methods=['GET', 'POST'])
def authenticate():
	if request.method == 'POST':
		signature = request.form['signature']
		if verify_signature(signature):
			return render_template('flag-8b8a7d3931eec3f0567e97ac1879601e72baf5ffaec192318b72f5c73a12e105f787c9542ace022e30f19b96e565e1289487e88e93962152e801cb7d6448a07d.html')
		else:
			return render_template('auth.html', incorrect=True)
	elif request.method == 'GET':
		return render_template('auth.html', incorrect=False)

@app.route('/')
@app.route('/index.html')
def index():
	return render_template('index.html')

if __name__ == '__main__':
	app.config.from_object(__name__)
	app.config['SECRET_KEY'] = '7d441f27d441f27567d441f2b6176a'
	app.run(debug=False, host='0.0.0.0', port=8000)
