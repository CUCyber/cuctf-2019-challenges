# StrangerHeaders

When trying to run the binary whether that be normally, in GDB, or radare2 it becomes clear that this binary just won't execute.

```
$ ./StrangerHeaders
Failed to execute process './StrangerHeaders'. Reason:
exec: Exec format error
The file './StrangerHeaders' is marked as an executable but could not be run by the operating system.
```

If we take a look at the file's ELF headers, nothing immediately obvious stands out.

```
root@dev ~/c/r/StrangerHeaders# readelf -h StrangerHeaders
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              NONE (None)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x1070
  Start of program headers:          64 (bytes into file)
  Start of section headers:          14936 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         11
  Size of section headers:           64 (bytes)
  Number of section headers:         29
  Section header string table index: 28
```

However, if we compare it to RE3's binary:

```
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x1060
  Start of program headers:          64 (bytes into file)
  Start of section headers:          16544 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         11
  Size of section headers:           64 (bytes)
  Number of section headers:         35
  Section header string table index: 34
```

It becomes increasingly obvious that the `Type` field is wrong. We can figure out which byte(s) is/are the `Type` field by looking at the [ELF header spec here](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format).

The spec shows us that Type is a 2 byte field at offset 0x10 or 16. If we open up the file in a hex editor, edit the 16th byte to a 2, save the patched file, and mark the binary as executable, when we run it again it should print the flag.

```
$ ghex StrangerHeaders 
$ chmod +x StrangerHeaders-patched 
$ ./StrangerHeaders-patched 
CUCTF{b4d_ex3cut4bl3_b4d_b0y}
```
