# Stego2

Steghide is one of the most common steganography tools for beginner CTFs. It embeds data into JPG or WAV files. If you get one of these file types in a steganography challenge, it's worth trying steghide if strings doesn't work.

```Bash
$ steghide extract -sf Stego2.jpg
$ cat flag.txt
CUCTF{v3ry_5tr0ng_st3gh1d3}
```
