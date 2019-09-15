# Whale Hunt

* `docker build -t whalehunt .`
* `docker run --rm -v $(pwd)/vol:/vol -p80:80 -p 1337:1337 -d --name whalehunt whalehunt`
* `docker checkpoint create whalehunt whalehunt --leave-running`
* `sudo cp -r "/var/lib/docker/containers/$(docker ps -aq --no-trunc)/checkpoints/whalehunt" ./whalehunt`
* `sudo chown user: whalehunt`
* `docker save whalehunt -o whalehunt-image.tar`
* `tar -cvf whalehunt-container.tar ./whalehunt`

## Description

Welcome to the National Cyber Investigative Joint Task Force, the cyber branch of the FBI, probie! We're tracking down a criminal organization known as The Syndicate. We were able to seize their sysadmin's Ubuntu 18.04.3 VPS which was masquerading as a backdoored website to communicate with the rest of their network. Each week they broadcast a new message to their org and we need to figure out what this week's message was. Time is of the essence.

We took the base image and a snapshot of the running container and are giving it to you to analyze as your first task. Don't let us down.
