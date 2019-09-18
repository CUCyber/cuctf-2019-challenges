# RE3

```
root@dev ~/c/r/RE3# gdb -q ./re3
pwndbg: loaded 171 commands. Type pwndbg [filter] for a list.
pwndbg: created $rebase, $ida gdb functions (can be used with print/break)
Reading symbols from ./re3...
```

Disassemble main

```
pwndbg> disassemble main
Dump of assembler code for function main:
   0x0000000000001295 <+0>:	push   rbp
   0x0000000000001296 <+1>:	mov    rbp,rsp
   0x0000000000001299 <+4>:	sub    rsp,0x10
   0x000000000000129d <+8>:	mov    DWORD PTR [rbp-0x4],0x0
   0x00000000000012a4 <+15>:	cmp    DWORD PTR [rbp-0x4],0x1
   0x00000000000012a8 <+19>:	jne    0x12bb <main+38>
   0x00000000000012aa <+21>:	mov    esi,0x7
   0x00000000000012af <+26>:	lea    rdi,[rip+0x2daa]        # 0x4060 <flag>
   0x00000000000012b6 <+33>:	call   0x1159 <printFlag>
   0x00000000000012bb <+38>:	mov    eax,0x0
   0x00000000000012c0 <+43>:	leave  
   0x00000000000012c1 <+44>:	ret    
End of assembler dump.
```

At main+8 the value 0 is moved into rbp-4, but then the line below it checks to see if it's equal to 1. We can solve this challenge 2 different ways:

1. Editing the value in memory with GDB

2. Patching the binary

### Method 1 - Editing memory in GDB

Our strategy for editing the memory will be to

1. Break on the comparison
2. Edit the memory to set the value to 1
3. Continue the execution of the program


`main+15` is where the comparison is, so we'll set a breakpoint there:

```
pwndbg> break *main+15
Breakpoint 1 at 0x12a4
```

When we run the program, we hit the breakpoint:

```
pwndbg> r
Starting program: /root/cuctf-challenges/reverse-engineering/RE3/re3 

Breakpoint 1, 0x00005555555552a4 in main ()
```

Now we need to edit the memory of the integer:

```
pwndbg> x $rbp-4
0x7fffffffe27c:	0x555552d000000000
pwndbg> set {int}0x7fffffffe27c = 1
pwndbg> x $rbp-4
0x7fffffffe27c:	0x555552d000000001
```

If we continue the program's execution, we'll receive the flag:

```
pwndbg> c
Continuing.
CUCTF{l375_pl4y_jump_r0p3}
[Inferior 1 (process 84079) exited normally]
```

### Method 2 - Binary Patching

Our methodology for this is simple, alter the jump condition to always jump regardless of the value check.

```
root@dev /tmp# radare2 -AAA -w re3
[0x00001060]> pdf@sym.main
/ (fcn) main 45
|   int main (int argc, char **argv, char **envp);
|           ; var uint32_t var_4h @ rbp-0x4
|           ; DATA XREF from entry0 @ 0x1081
|           0x00001295      55             push rbp
|           0x00001296      4889e5         mov rbp, rsp
|           0x00001299      4883ec10       sub rsp, 0x10
|           0x0000129d      c745fc000000.  mov dword [var_4h], 0
|           0x000012a4      837dfc01       cmp dword [var_4h], 1
|       ,=< 0x000012a8      7511           jne 0x12bb
|       |   0x000012aa      be07000000     mov esi, 7
|       |   0x000012af      488d3daa2d00.  lea rdi, obj.flag           ; 0x4060
|       |   0x000012b6      e89efeffff     call sym.printFlag
|       |   ; CODE XREF from main @ 0x12a8
|       `-> 0x000012bb      b800000000     mov eax, 0
|           0x000012c0      c9             leave
\           0x000012c1      c3             ret
```

In radare2 we see that the jne call will jump to `mov eax, 0; leave; ret` (`return 0;`) if the check fails. If we simply replace that with `je` it will jump if they values are equal instead of not equal - effectively it will never branch.

```
[0x00001060]> s 0x000012a8
[0x000012a8]> wa je 0x12bb
Written 2 byte(s) (je 0x12bb) = wx 7411
[0x000012a8]> pdf@sym.main
/ (fcn) main 45
|   int main (int argc, char **argv, char **envp);
|           ; var uint32_t var_4h @ rbp-0x4
|           ; DATA XREF from entry0 @ 0x1081
|           0x00001295      55             push rbp
|           0x00001296      4889e5         mov rbp, rsp
|           0x00001299      4883ec10       sub rsp, 0x10
|           0x0000129d      c745fc000000.  mov dword [var_4h], 0
|           0x000012a4      837dfc01       cmp dword [var_4h], 1
|       ,=< 0x000012a8      7411           je 0x12bb
|       |   0x000012aa      be07000000     mov esi, 7
|       |   0x000012af      488d3daa2d00.  lea rdi, obj.flag           ; 0x4060
|       |   0x000012b6      e89efeffff     call sym.printFlag
|       |   ; CODE XREF from main @ 0x12a8
|       `-> 0x000012bb      b800000000     mov eax, 0
|           0x000012c0      c9             leave
\           0x000012c1      c3             ret
[0x000012a8]> q
```

If we rerun the binary after patching it, we should see the flag:

```
$ ./re3
CUCTF{l375_pl4y_jump_r0p3}
```
