# Whale Hunt

1. Set up Docker CRIU in Ubuntu 18.03

```Bash
#!/bin/bash

# Enables HTTPS APT
sudo apt update -y && sudo apt install -y \
  apt-transport-https \
  ca-certificates \
  curl \
  software-properties-common

# Add the Docker GPG Key
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

# Add the Docker repo
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable"

# Install Docker and CRIU
sudo apt update -y && sudo apt install docker-ce criu -y

# Enable experimental Docker features and restart the daemon
echo "{\"experimental\": true}" | sudo tee /etc/docker/daemon.json
sudo systemctl restart docker

# Add user to the docker group
sudo usermod -aG docker "${USER}"
```

2. Load the image

```Bash
testuser@computer2:~/Downloads$ docker load -i whalehunt-image.tar
```

3. Create the container. The VOL mount is **necessary** for the checkpoint to restore properly. This is probably the biggest "gotcha". You can get the vol by checking the mountpoints or looking at the binary's strings in comparison to the docker image (there was no COPY to /vol in the image).

```Bash
testuser@computer2:~/Downloads$ docker create -v $(pwd):/vol --name whalehunt whalehunt
9606471ba247789d0d585c08b0524f1c431ba876dd128806b722d8abbc58c344
```

4. Copy the checkpoint into the newly created container

```Bash
testuser@computer2:~/Downloads$ sudo cp -r whalehunt/ /var/lib/docker/containers/$(docker ps -aq --no-trunc)/checkpoints
```

5. Start the container

```Bash
testuser@computer2:~/Downloads$ docker start --checkpoint whalehunt whalehunt
```

6. Examine currently running image to find something listening on port 1337

```Bash
testuser@computer2:~/Downloads$ docker ps -a
CONTAINER ID        IMAGE               COMMAND               CREATED             STATUS              PORTS                                        NAMES
57c5242de46e        whalehunt           "/bin/bash /run.sh"   29 minutes ago      Up 29 minutes       0.0.0.0:80->80/tcp, 0.0.0.0:1337->1337/tcp   whalehunt
```

7. Netcat to the port to receive the flag

```Bash
testuser@computer2:~/Downloads$ nc 172.17.0.2 1337
CUCTF{WHALE_WHALE_WHALE_WHAT_HAVE_WE_GOT_HERE?}
```
