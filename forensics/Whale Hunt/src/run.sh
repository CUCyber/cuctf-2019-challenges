#!/bin/bash
nohup /comms 2>/dev/null &
apache2ctl -DFOREGROUND
