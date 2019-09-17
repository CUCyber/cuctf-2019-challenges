
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define FLAG "CUCTF{17_c0uld_h4v3_b33n_4_h07d06}"
#define FLAGLEN sizeof(FLAG)
char flag[FLAGLEN+1];

int check(){
	int checks = 0;
	if (flag[11]+flag[4]+flag[23]+flag[0]+flag[24]+flag[21]+flag[9]+flag[2]+flag[12]+flag[22]+flag[24]+flag[0]+flag[29]+flag[2]+flag[18]+flag[17]+flag[5]+flag[5]+flag[1] == 1619) checks++;
	if (flag[18]+flag[33]+flag[9]+flag[28]+flag[9]+flag[14]+flag[27]+flag[22]+flag[10]+flag[9]+flag[13] == 919) checks++;
	if (flag[3]+flag[29]+flag[24]+flag[22]+flag[28]+flag[32] == 387) checks++;
	if (flag[14]+flag[32]+flag[7]+flag[2]+flag[16]+flag[33]+flag[9]+flag[0]+flag[29] == 669) checks++;
	if (flag[21]+flag[11]+flag[21]+flag[24]+flag[21] == 365) checks++;
	if (flag[33]+flag[4]+flag[2]+flag[10]+flag[0]+flag[13]+flag[32]+flag[33]+flag[7] == 711) checks++;
	if (flag[27]+flag[29]+flag[13]+flag[25]+flag[5]+flag[14]+flag[1]+flag[29]+flag[18]+flag[17]+flag[12] == 946) checks++;
	if (flag[16]+flag[19]+flag[14]+flag[11]+flag[23]+flag[25]+flag[9]+flag[3]+flag[22]+flag[27] == 859) checks++;
	if (flag[5]+flag[7]+flag[20]+flag[26]+flag[10]+flag[2] == 486) checks++;
	if (flag[13]+flag[6]+flag[3]+flag[30]+flag[30]+flag[11]+flag[9]+flag[13]+flag[27]+flag[13]+flag[32]+flag[9]+flag[4]+flag[7]+flag[31]+flag[24]+flag[9]+flag[18]+flag[33]+flag[24] == 1744) checks++;
	if (flag[28]+flag[11]+flag[1]+flag[7]+flag[9]+flag[30]+flag[6]+flag[32]+flag[7]+flag[5]+flag[27]+flag[22]+flag[21]+flag[25]+flag[18]+flag[10] == 1142) checks++;
	if (flag[7]+flag[26]+flag[32]+flag[11]+flag[0]+flag[0]+flag[1]+flag[4]+flag[18]+flag[11]+flag[12]+flag[3]+flag[9]+flag[31] == 1117) checks++;
	if (flag[27]+flag[31] == 152) checks++;
	if (flag[7]+flag[26]+flag[28]+flag[28]+flag[33] == 371) checks++;
	if (flag[3]+flag[3]+flag[32]+flag[28]+flag[23]+flag[8]+flag[12] == 583) checks++;
	if (flag[14]+flag[15]+flag[14]+flag[1]+flag[0]+flag[14]+flag[27]+flag[2]+flag[26]+flag[25]+flag[28]+flag[10]+flag[11]+flag[7]+flag[26]+flag[3]+flag[32] == 1360) checks++;
	if (flag[32]+flag[5]+flag[24]+flag[24]+flag[31]+flag[21]+flag[13]+flag[30]+flag[29] == 721) checks++;
	if (flag[16]+flag[17]+flag[18]+flag[2]+flag[4] == 358) checks++;
	if (flag[2]+flag[22]+flag[15]+flag[32]+flag[18]+flag[10]+flag[4]+flag[1] == 530) checks++;
	if (flag[21]+flag[1]+flag[1]+flag[24]+flag[28]+flag[27]+flag[28]+flag[6]+flag[21]+flag[3]+flag[28]+flag[0] == 815) checks++;
	if (flag[32]+flag[11]+flag[10] == 219) checks++;
	if (flag[20]+flag[26]+flag[23]+flag[8]+flag[14]+flag[14]+flag[26]+flag[30]+flag[24]+flag[4]+flag[32] == 1002) checks++;
	if (flag[26]+flag[5]+flag[18]+flag[18]+flag[28]+flag[26]+flag[30]+flag[15]+flag[14] == 762) checks++;
	if (flag[8]+flag[26]+flag[5]+flag[20]+flag[11]+flag[11]+flag[8]+flag[21]+flag[26]+flag[10]+flag[8]+flag[2]+flag[14]+flag[25]+flag[21]+flag[33] == 1419) checks++;
	if (flag[26]+flag[6]+flag[31]+flag[24]+flag[13]+flag[2]+flag[12]+flag[3]+flag[22]+flag[23]+flag[13]+flag[32] == 961) checks++;
	if (flag[33]+flag[31]+flag[8]+flag[4]+flag[32]+flag[24]+flag[33]+flag[19] == 707) checks++;
	if (flag[7]+flag[0]+flag[20]+flag[14]+flag[12]+flag[17]+flag[5]+flag[3]+flag[29]+flag[19]+flag[11]+flag[6]+flag[17]+flag[1]+flag[0] == 1334) checks++;
	if (flag[29]+flag[4]+flag[2]+flag[22]+flag[21] == 294) checks++;
	if (flag[11]+flag[0]+flag[16]+flag[7]+flag[23]+flag[23]+flag[32]+flag[27]+flag[19] == 764) checks++;
	if (flag[0]+flag[32]+flag[24]+flag[16]+flag[2]+flag[19]+flag[17]+flag[30]+flag[4] == 718) checks++;
	if (flag[17]+flag[28]+flag[20]+flag[7]+flag[25]+flag[31] == 419) checks++;
	if (flag[26]+flag[7]+flag[33]+flag[4]+flag[16]+flag[17]+flag[21]+flag[28]+flag[20]+flag[29]+flag[21] == 818) checks++;
	if (flag[16]+flag[32]+flag[8] == 201) checks++;
	if (flag[33]+flag[20]+flag[15]+flag[24]+flag[14]+flag[5]+flag[2]+flag[4]+flag[29]+flag[12]+flag[1]+flag[8]+flag[9]+flag[25]+flag[27] == 1375) checks++;

	return checks == 34;
}

int main(void){
    read(0, flag, FLAGLEN);
    if (check()) puts("Flag");
    else puts("Not flag");
    return 0;
}

