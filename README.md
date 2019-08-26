# CUCTF

A CTF that challenges you from trivia questions to reverse engineering ELF binaries.

## Recommended Tools

* netcat
	* gnu-netcat
	* nc6
	* openbsd-netcat (discouraged)
* python
	* pwntools
* http request mitm
	* burpsuite
	* tamper chrome
* debugger
	* gdb
		* pwndbg
		* peda
	* radare2
* reverse engineering platform
	* radare2
	* binaryninja
	* ida/ida pro
	* ghidra

## Rules

1. No sharing of flags or solutions. The entire point of a CTF is to learn, so simply handing someone a solution won't benefit them.
2. No attacking the scoreboard.
3. No brute forcing. All challenges can be done without DDoSing or bruteforcing flags. If there is any need to run a binary a million times, it will work on your own system. 
4. No DoSing. If you intentionally hold the challenges of the platform down, you will be banned.

## Challenges

### Reverse Engineering

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| StrangerHeaders     | 100    | none |
| Without a Trace     | 500    | none |

### Binary Exploitation

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| Spectre             | 300    | 9000 |
| VM                  | 750    | 9100 |
| Aegis               | 400    | 9200 |
| TCash               | 700    | 9300 |

### Web Exploitation

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| Heist               | 400    | 8545 |

### Cryptography

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| RSAdmin             | 200    | 8000 |

### Forensics

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| RingRing            | 50     | None |

### Trivia

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| Challenge Name Here | 0      | 0000 |
