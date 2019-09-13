# SMS

* `docker build -t sms .`
* `docker run --rm -d -p 8100:8100 sms`

This challenge is very fickle in that the exploit could take 1 minute, 30 minutes, or 30 hours. Test the exploit script on the server beforehand to figure out how long each one takes. If it looks like it won't finish in a reasonable time, restart the docker container.

## Description

I built a new SMS API to message my friends. A couple of them (Alice, Bob, and Charlie) have already tried it out. Do you want to give it a go? It uses state-of-the-art public-key encryption to ensure that all messages sent can't be decrypted. I'm sure you'll like it!