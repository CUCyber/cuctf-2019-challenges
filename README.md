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
| Not Flag            | 350    | none |
| Without a Trace     | 500    | none |

### Binary Exploitation

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| Bof1                |  10    | 9000 |
| Bof2                |  50    | 9100 |
| Spectre             | 300    | 9200 |
| Aegis               | 400    | 9300 |
| TCash               | 700    | 9400 |
| VM                  | 750    | 9500 |

### Web Exploitation

| Challenge           | Points | Port |
| ------------------- | ------ | ---- |
| Web1                |  10    | 7000 |
| Web2                |  25    | 7010 |
| Web3                |  50    | 7020 |
| ReadMe              | 100    | 7100 |
| Election            | 200    | 7200 |
| Paths               | 300    | 7300 |
| Heist               | 400    | 7400 |
| Responsive          | 600    | 7500 |

### Cryptography

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| Crypto1             |  10    | None |
| Crypto2             |  20    | None |
| Crypto3             |  30    | None |
| Crypto4             |  40    | None |
| Crypto5             |  50    | None |
| RSAdmin             | 200    | 8000 |

### Forensics

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| RingRing            | 50     | None |

### Trivia

| Challenge           | Points | Port |
| --------------------| ------ | ---- |
| Question 1          | 10     | None |
| Question 2          | 10     | None |
| Question 3          | 10     | None |
| Question 4          | 10     | None |
| Question 5          | 10     | None |
| Question 6          | 10     | None |
| Question 7          | 10     | None |
| Question 8          | 10     | None |
| Question 9          | 10     | None |
| Question 10         | 10     | None |
