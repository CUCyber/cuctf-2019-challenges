# Hunted

This challenge gives us two files, a memory dump of the box and a compressed file of the box. It's pretty clear now that we need to use Volatility. We can determine what type of memory dump by looking at the first few bytes of the dump.

```
$ head -c 8 dump | hexdump  -C
00000000  45 4d 69 4c 01 00 00 00                           |EMiL....|
00000008
```

This dump file is a [LiME (Linux Memory Extractor) memory dump](https://github.com/504ensicsLabs/LiME). Fortunately for us, we can analyze these with volatility!

Extracting the items from info, we can see the contents that make up a Volatility profile. If we compress this back into a zip file, we can use it with Volatility.

This next step will involve some guess work. Given that the threat actor is an APT, they're going to opt for more stealthy approaches. This could involve process injection, memfd_create + fexecve, or... hidden linux kernel modules.

```
$ volatility --plugins=/usr/local/vol-profiles/ --profile=LinuxUbuntu1604x64 --file=./dump linux_hidden_modules
Volatility Foundation Volatility Framework 2.6.1
Offset (V)         Name
------------------ ----
0xffffffffc04da3e0 resetafter
0xffffffffc0619300 qni
0xffffffffc0685000 phalanx2
```

If we Google Phalanx2 we will get a few results detailing and dissecting the malware's activities.

["P2 is often considered an infamous Linux kernel rootkit due to the number of high-profile investigations in which it was encountered."](https://learning.oreilly.com/library/view/the-art-of/9781118824993/c27.xhtml)

The flag is: `CUCTF{phalanx2}`.
