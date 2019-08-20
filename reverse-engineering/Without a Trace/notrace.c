#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>

#include "encrypt.h"

#define ASSERT(x) \
    if (!(x)) exit(-1)

FORBIDDEN_FUNC void
flag_function(void){
    printf("CUCTF{TRACE_THE_FLAG_TO_VICTORY}\n");
}
FORBIDDEN_FUNC void flag_guard(){};

SECRET_HELPER_FUNC char *
secret_encryption(char *key){
    for(int i = 0; i < strlen(key); i++)
        key[i] ^= 0x42;
    return key;
}
SECRET_HELPER_FUNC void secret_encryption_guard(){};

SECRET_FUNC void
secret_function(char *key){
    printf("Level 3\n");

    decrypt_mem(
        (unsigned char*)&secret_encryption,
        (unsigned char*)&secret_encryption_guard
    );

    set_key(secret_encryption(key));

    decrypt_mem(
        (unsigned char*)&flag_function,
        (unsigned char*)&flag_guard
    );

    flag_function();
}
SECRET_FUNC void secret_guard(){};

PRIVATE_HELPER_FUNC const char *
private_encryption(char *s){
    if (s == NULL)
        return NULL;

    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'm') { s[i] += 13; continue; }
        if (s[i] >= 'A' && s[i] <= 'M') { s[i] += 13; continue; }
        if (s[i] >= 'n' && s[i] <= 'z') { s[i] -= 13; continue; }
        if (s[i] >= 'N' && s[i] <= 'Z') { s[i] -= 13; continue; }
    }

    return (const char *)s;
}
PRIVATE_HELPER_FUNC void private_encryption_guard(){};

PRIVATE_FUNC void
private_function(char *key1, char *key2){
    int offset = 0;
    const char *s;

    printf("Level 2\n");

    decrypt_mem(
        (unsigned char*)&private_encryption,
        (unsigned char*)&private_encryption_guard
    );

    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == 0)
        offset = 2;

    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
        offset = offset * 3;

    ASSERT(offset == 2 * 3);

    ASSERT(strlen(key1) == 6);

    s = private_encryption(key1);
    if (s == NULL)
        exit(-1);

    for (int i = 2, j = 0; i > 0; i--, j++)
        ASSERT(s[i] == 0x6d-j);

    ASSERT(s[0] == 'a');

    for (int i = 0; i < 2; i++)
        ASSERT(s[i+4] == 0x73+i);

    ASSERT(s[3] == 'o');

    set_key((char *)s);
    decrypt_mem(
        (unsigned char*)&secret_function,
        (unsigned char*)&secret_guard
    );

    secret_function(key2);
}

PRIVATE_FUNC void private_guard(){};

int main (int argc, char *argv[]){
    if (argc != 4)
        exit(-1);

    printf("Level 1\n");

    set_key(argv[1]);

    decrypt_mem(
        (unsigned char*)&private_function,
        (unsigned char*)&private_guard
    );

    private_function(argv[2], argv[3]);

    return 0;
}
