#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#include "encrypt.h"

PRIVATE_HELPER_FUNC void
private_helper(int cfd, unsigned long long flag[], int nelems){
    char byte = 0;
    for (int i = 0; i < nelems; i++){
        while(flag[i] != 0){
            byte = flag[i] % 255;
            write(cfd, &byte, 1), fflush(stdout);
            flag[i] = (flag[i] - (flag[i] % 255)) / 255;
        }
    }
    write(cfd, "\n", 1);
}
PRIVATE_HELPER_FUNC void private_helper_guard(){};

PRIVATE_FUNC void
private_function(void){
	int s, sfd, cfd, status;
	struct addrinfo hints, *res;
	struct sockaddr_storage client;
	socklen_t sin_size = sizeof client;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	status = getaddrinfo(NULL, "1337", &hints, &res);
	if (status != 0){
		return;
	}

	sfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (sfd == -1){
		return;
	}

	status = bind(sfd, res->ai_addr, res->ai_addrlen);
	if (status == -1){
		return;
	}

	freeaddrinfo(res);

	s = listen(sfd, SOMAXCONN);
	if (s == -1){
		return;
	}

	cfd = accept(sfd, (struct sockaddr *) &client, &sin_size);
	if (cfd == -1) {
		perror("accept");
	}

    decrypt_mem(
        (unsigned char*)&private_helper,
        (unsigned char*)&private_helper_guard
    );

    for (int i = 0; ; i++){
        unsigned long long flag[] = {
            1397213917,
            1199547610,
            1579736795,
            1264429572,
            1199540469,
            1579736795,
            1397080572,
            1430243330,
            1149796344,
            1397990675,
            1364177930,
            8144259
        };
        private_helper(cfd, flag, sizeof(flag)/sizeof(flag[0]));
        sleep(1);
    }
}
PRIVATE_FUNC void private_function_guard(){};

PUBLIC_HELPER_FUNC void
public_helper(unsigned long long flag[], int nelems){
    for (int i = 0; i < nelems; i++){
        while(flag[i] != 0){
            printf("%c", flag[i] % 255), fflush(stdout);
            flag[i] = (flag[i] - (flag[i] % 255)) / 255;
        }
    } printf("\n");
}
PUBLIC_HELPER_FUNC void public_helper_guard(){};

int main(void){
    char buffer[128];
    FILE *fp = NULL;

    fp = fopen("/vol/key", "r");
    if (fp == NULL){
        goto spin;
    }
    fgets(buffer, 128, fp);
    fclose(fp);

    buffer[strcspn(buffer, "\r\n")] = 0;

    set_key(buffer);

    decrypt_mem(
        (unsigned char*)&private_function,
        (unsigned char*)&private_function_guard
    );

    private_function();

spin:

    set_key("CUCTF");

    decrypt_mem(
        (unsigned char*)&public_helper,
        (unsigned char*)&public_helper_guard
    );

    for (int i = 0; ; i++){
        unsigned long long flag[] = {
            654309944,
            1826059698,
            1896874466,
            1929772202,
            1809477294,
            8516
        };

        printf("%d: ", i);
        public_helper(flag, sizeof(flag)/sizeof(flag[0]));
        sleep(1);
    }

    return 0;
}
