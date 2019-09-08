
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 32

int main(){
	char buffer[BUFFERSIZE];

	printf("What is the password?\n");
	fgets(buffer, BUFFERSIZE, stdin);
	buffer[strcspn(buffer, "\r\n")] = 0;

	if (!strcmp(buffer, "the password")){
		printf("CUCTF{S7r1ng5_m4k3_R3_345y}\n");
	} else {
		printf("Password incorrect!\n");
	}

	return 0;
}
