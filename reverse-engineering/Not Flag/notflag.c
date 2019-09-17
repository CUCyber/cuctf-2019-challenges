
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define FLAG "CUCTF{17_c0uld_h4v3_b33n_4_h07d06}"
#define FLAGLEN sizeof(FLAG)
char flag[FLAGLEN+1];

int check(){
	int checks = 0;
	if (flag[15]+flag[30]+flag[6]+flag[14]+flag[10]+flag[6]+flag[32]+flag[4]+flag[18]+flag[31]+flag[20]+flag[8]+flag[15]+flag[25]+flag[12]+flag[0]+flag[16]+flag[32]+flag[28]+flag[8] == 1441) checks++;
	if (flag[27]+flag[20] == 202) checks++;
	if (flag[12]+flag[10] == 156) checks++;
	if (flag[4]+flag[6]+flag[25]+flag[24]+flag[13]+flag[16]+flag[27]+flag[12] == 630) checks++;
	if (flag[8]+flag[17]+flag[18]+flag[15]+flag[0] == 435) checks++;
	if (flag[11]+flag[1]+flag[30]+flag[26]+flag[19]+flag[16]+flag[10]+flag[16]+flag[12]+flag[18]+flag[7]+flag[10]+flag[13]+flag[23]+flag[30]+flag[3]+flag[14] == 1395) checks++;
	if (flag[4]+flag[23]+flag[18]+flag[10]+flag[9]+flag[19]+flag[15]+flag[22]+flag[17]+flag[9]+flag[1]+flag[5]+flag[22]+flag[28]+flag[33]+flag[17] == 1395) checks++;
	if (flag[7]+flag[27]+flag[27]+flag[15]+flag[26] == 462) checks++;
	if (flag[30]+flag[6]+flag[9]+flag[0]+flag[25] == 367) checks++;
	if (flag[12]+flag[6]+flag[22]+flag[22]+flag[18] == 310) checks++;
	if (flag[16]+flag[29]+flag[14]+flag[25]+flag[6]+flag[3]+flag[16]+flag[18]+flag[10]+flag[33]+flag[24]+flag[24]+flag[4]+flag[28]+flag[22]+flag[18]+flag[32]+flag[7]+flag[13] == 1282) checks++;
	if (flag[29]+flag[7]+flag[1]+flag[33]+flag[31]+flag[24]+flag[4]+flag[1]+flag[7]+flag[25]+flag[28]+flag[7]+flag[4]+flag[2]+flag[26]+flag[32]+flag[23]+flag[29]+flag[15] == 1383) checks++;
	if (flag[29]+flag[1]+flag[28]+flag[14]+flag[18]+flag[12]+flag[18]+flag[14]+flag[4]+flag[31]+flag[11]+flag[28]+flag[21]+flag[28]+flag[10]+flag[14] == 1113) checks++;
	if (flag[11]+flag[14]+flag[0]+flag[21]+flag[28]+flag[22]+flag[23]+flag[11]+flag[30]+flag[17]+flag[5]+flag[9]+flag[28]+flag[17]+flag[13]+flag[18]+flag[30]+flag[28]+flag[6] == 1610) checks++;
	if (flag[1]+flag[25]+flag[21]+flag[23]+flag[15]+flag[0]+flag[8]+flag[20]+flag[19]+flag[12]+flag[25] == 917) checks++;
	if (flag[29]+flag[11]+flag[30]+flag[21]+flag[31]+flag[28] == 419) checks++;
	if (flag[0]+flag[22]+flag[19]+flag[17]+flag[9]+flag[22]+flag[31]+flag[13]+flag[24]+flag[24]+flag[22]+flag[18]+flag[6]+flag[10] == 1018) checks++;
	if (flag[33]+flag[22]+flag[11]+flag[13]+flag[16]+flag[5]+flag[20]+flag[10]+flag[4]+flag[31]+flag[25]+flag[30]+flag[27]+flag[28]+flag[26]+flag[5]+flag[8]+flag[26]+flag[0] == 1611) checks++;
	if (flag[11]+flag[19]+flag[1]+flag[16]+flag[26]+flag[19]+flag[4]+flag[15]+flag[2]+flag[5]+flag[19]+flag[33]+flag[21]+flag[10]+flag[16]+flag[11]+flag[29]+flag[20]+flag[10] == 1592) checks++;
	if (flag[3]+flag[4]+flag[18]+flag[18]+flag[25]+flag[8]+flag[25]+flag[28]+flag[1]+flag[20]+flag[10]+flag[30]+flag[11]+flag[27]+flag[17]+flag[23]+flag[23] == 1393) checks++;
	if (flag[6]+flag[16]+flag[12]+flag[20]+flag[23]+flag[31]+flag[2] == 532) checks++;
	if (flag[26]+flag[2]+flag[3]+flag[11]+flag[12]+flag[13]+flag[17]+flag[10]+flag[0]+flag[23] == 914) checks++;
	if (flag[10]+flag[28]+flag[33]+flag[11]+flag[29]+flag[26]+flag[5]+flag[14]+flag[14]+flag[1]+flag[24]+flag[26]+flag[8]+flag[13]+flag[19]+flag[8]+flag[10]+flag[10]+flag[0]+flag[25] == 1676) checks++;
	if (flag[7]+flag[2]+flag[27]+flag[18]+flag[0]+flag[32]+flag[18]+flag[32]+flag[14]+flag[1]+flag[3]+flag[19]+flag[22] == 913) checks++;
	if (flag[13]+flag[16]+flag[4]+flag[12]+flag[18]+flag[4]+flag[13]+flag[32]+flag[18]+flag[15]+flag[32]+flag[0]+flag[2] == 948) checks++;
	if (flag[9]+flag[11]+flag[18]+flag[17]+flag[4]+flag[1] == 540) checks++;
	if (flag[23]+flag[20]+flag[26]+flag[23]+flag[9]+flag[7] == 567) checks++;
	if (flag[14]+flag[0]+flag[6]+flag[0]+flag[5]+flag[14]+flag[15]+flag[24]+flag[20]+flag[7]+flag[27]+flag[18]+flag[16]+flag[16]+flag[23]+flag[0] == 1284) checks++;
	if (flag[1]+flag[8]+flag[10]+flag[20]+flag[5]+flag[31]+flag[31]+flag[32]+flag[21]+flag[17]+flag[7]+flag[26]+flag[29] == 973) checks++;
	if (flag[9]+flag[29]+flag[13]+flag[32]+flag[29]+flag[11]+flag[0]+flag[24]+flag[21]+flag[21]+flag[32]+flag[25]+flag[9]+flag[21]+flag[27]+flag[24]+flag[30]+flag[2] == 1366) checks++;
	if (flag[28]+flag[26]+flag[13]+flag[11]+flag[16]+flag[8]+flag[10]+flag[28]+flag[14] == 698) checks++;
	if (flag[26]+flag[15]+flag[16]+flag[15]+flag[3]+flag[16]+flag[16]+flag[29]+flag[25] == 650) checks++;
	if (flag[15]+flag[1]+flag[29]+flag[28]+flag[3]+flag[9]+flag[6]+flag[29]+flag[5]+flag[28]+flag[16]+flag[23]+flag[20]+flag[25] == 1062) checks++;
	if (flag[23]+flag[18]+flag[20]+flag[10]+flag[11]+flag[2]+flag[17]+flag[11]+flag[31]+flag[20]+flag[12]+flag[18]+flag[20]+flag[2]+flag[7]+flag[7]+flag[32] == 1360) checks++;

	return checks == 34;
}

int main(void){
    read(0, flag, FLAGLEN);
    if (check()) puts("Flag");
    else puts("Not flag");
    return 0;
}

