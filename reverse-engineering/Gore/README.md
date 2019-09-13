# Gore

## Description

What the heck is this? This isn't a C binary?!

## Internal Notes

Golang binaries always put user-defined functions at the very end. Analyzing the call instructions you will get a small list of functions. One of the functions has data and an xor. Go to the data, write the data out into a string, and xor it with 0x8 to get the flag.
