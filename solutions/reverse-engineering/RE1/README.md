# RE1

On very simple RE challenges, running strings might be enough to solve them. 

```
$ strings re1
...
_ITM_registerTMCloneTable
u3UH
[]A\A]A^A_
What is the password?
the password
CUCTF{S7r1ng5_m4k3_R3_345y}
Password incorrect!
;*3$"
GCC: (GNU) 9.1.0
init.c
crtstuff.c
...
```

An alternative solution that is also very effective on introductory problems is to use the command `ltrace`. `ltrace` traces library calls like `strcmp` which can easily reveal simple string checks for the right key.

```
root@dev ~/c/r/RE1# ltrace ./re1
puts("What is the password?"What is the password?
)                         = 22
fgets(idk
"idk\n", 32, 0x7f0907437860)                    = 0x7fff7d5962a0
strcspn("idk\n", "\r\n")                              = 3
strcmp("idk", "the password")                         = -11
puts("Password incorrect!"Password incorrect!
)                           = 20
+++ exited (status 0) +++
root@dev ~/c/r/RE1# ./re1 
What is the password?
the password
CUCTF{S7r1ng5_m4k3_R3_345y}
```
