#include <stdio.h>

void printFlag(unsigned long long flag[], int nelems){
	for (int i = 0; i < nelems; i++){
		while(flag[i] != 0){
			printf("%c", flag[i] % 255), fflush(stdout);
			flag[i] = (flag[i] - (flag[i] % 255)) / 255;
		}
	} printf("\n");
}

/*
 1397213917,
 868635385,
 1996344100,
 1931072721,
 852697867,
 1661543835,
 2009492610,
 125
 
 
 
 */


int main() {
	unsigned long long flag[] = {	
	1397213917,
	868635385,
	1996344100,
	1931072721,
	852697867,
	1661543835,
	2009492610,
	125
	};
	printFlag(flag, sizeof(flag)/sizeof(flag[0]));
	return 0;
}
