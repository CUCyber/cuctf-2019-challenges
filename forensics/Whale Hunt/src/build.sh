#!/bin/bash
docker build -t whalehunt .
docker run --rm -v $(pwd)/vol:/vol -p80:80 -p 1337:1337 -d --name whalehunt whalehunt
docker checkpoint create whalehunt whalehunt --leave-running
sudo cp -r "/var/lib/docker/containers/$(docker ps -aq --no-trunc)/checkpoints/whalehunt" ./whalehunt
sudo chown user: whalehunt
docker save whalehunt -o whalehunt-image.tar
tar -cvf whalehunt-container.tar ./whalehunt
