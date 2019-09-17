import base64

FLAG = "CUCTF{4ll_17_T4k35_15_4_By73}"

XORED_FLAG = ""
for char in FLAG:
    XORED_FLAG += chr(ord(char) ^ 0x4a)

BASE64_FLAG = base64.b64encode(XORED_FLAG.encode())
print(BASE64_FLAG.decode())
