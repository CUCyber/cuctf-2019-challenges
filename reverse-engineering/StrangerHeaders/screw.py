#!/usr/bin/python

with open("StrangerHeaders", "rb") as f:
    data = bytearray(f.read())

data[0x10] = 0x00

with open("StrangerHeaders", "wb+") as f:
    f.write(data)
