# Gore

```
$ file gore
gore: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), statically linked, Go BuildID=0MhO66iTlY-OthSfvXnG/diRwE7flw7na8AV8LMKe/nVWdXru5Pk26ndPZQswG/k4EF4WHTWF0zMMRx7CJU, stripped
```

This isn't a normal binary, it's a Golang binary! What's worse is that it's also statically linked and stripped. This means we're in for a difficult time reverse engineering this.

Or does it?

```
$ objdump -d gore

...

  48cdc0:	64 48 8b 0c 25 f8 ff 	mov    %fs:0xfffffffffffffff8,%rcx
  48cdc7:	ff ff 
  48cdc9:	48 3b 61 10          	cmp    0x10(%rcx),%rsp
  48cdcd:	76 2a                	jbe    0x48cdf9
  48cdcf:	48 83 ec 10          	sub    $0x10,%rsp
  48cdd3:	48 89 6c 24 08       	mov    %rbp,0x8(%rsp)
  48cdd8:	48 8d 6c 24 08       	lea    0x8(%rsp),%rbp
  48cddd:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  48cde4:	00 
  48cde5:	e8 c6 62 ff ff       	callq  0x4830b0
  48cdea:	e8 b1 fe ff ff       	callq  0x48cca0
  48cdef:	48 8b 6c 24 08       	mov    0x8(%rsp),%rbp
  48cdf4:	48 83 c4 10          	add    $0x10,%rsp
  48cdf8:	c3                   	retq   
  48cdf9:	e8 82 47 fc ff       	callq  0x451580
  48cdfe:	eb c0                	jmp    0x48cdc0
```

Functions in Golang start with `mov %fs:0xfffffffffffffff8,%rcx` so we can use that to determine the start/stop points between each function.

The key to this challenge is that functions are placed into the compiled output depending on their placement in the original golang source code. For example, in the following code, `main` would be the last function in the binary and `foo` would be the second to last.

```Golang
package main

import "fmt"

func foo(){
  fmt.Println("Hello, world!");
}

func main(){
    foo();
}
```

There are two call instructions in this last function, so let's try to figure out what they both do.

`0x4830b0` is very high up in the binary to be a separate function unless there are multiple files or a lot of source code. Therefore we can assume it is a library function.

`0x48cca0` is the function right above the last function which gives us a good indication that it was user-defined. If we examine what that function is doing. It appears to be a single-byte xor with the xor key being `0x8`, `xor $0x8,%rcx`.

Ultimately, decrypting the array of data that is being XORed with `0x8` we get the flag `CUCTF{57r1pp3d_G0_b1n4r135_huRt}`.
