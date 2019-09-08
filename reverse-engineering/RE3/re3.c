#include <stdio.h>

unsigned long long flag[] = {1397213917, 852704260, 1863304945, 1583112018, 1864231666, 1860264365, 31926};

void printFlag(unsigned long long flag[], int nelems){
	for (int i = 0; i < nelems; i++){
		while(flag[i] != 0){
			printf("%c", flag[i] % 255), fflush(stdout);
			flag[i] = (flag[i] - (flag[i] % 255)) / 255;
		}
	} printf("\n");
}

int main() {
    int a = 1;

    if (a == 1){
        printFlag(flag, sizeof(flag)/sizeof(flag[0]));
    }

	return 0;
}
