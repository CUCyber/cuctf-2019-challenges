
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define FLAG "CUCTF{17_c0uld_h4v3_b33n_4_h07d06}"
#define FLAGLEN sizeof(FLAG)
char flag[FLAGLEN+1];

int check(){
	int checks = 0;
	if (flag[25]+flag[25]+flag[11]+flag[6]+flag[4]+flag[28]+flag[9]+flag[12]+flag[21]+flag[1]+flag[11] == 848) checks++;
	if (flag[14]+flag[31]+flag[0]+flag[25]+flag[30]+flag[3]+flag[21] == 497) checks++;
	if (flag[31]+flag[31]+flag[24]+flag[16]+flag[15]+flag[18]+flag[15]+flag[21]+flag[16]+flag[17]+flag[23]+flag[2]+flag[0]+flag[28]+flag[4]+flag[28]+flag[2]+flag[30]+flag[18]+flag[33] == 1476) checks++;
	if (flag[15]+flag[16]+flag[15]+flag[19]+flag[10]+flag[15]+flag[18]+flag[17]+flag[16]+flag[28]+flag[22]+flag[2] == 894) checks++;
	if (flag[14]+flag[10]+flag[23]+flag[13]+flag[8]+flag[1]+flag[4]+flag[17]+flag[15]+flag[15]+flag[13]+flag[30]+flag[11]+flag[19]+flag[2]+flag[27]+flag[0]+flag[22]+flag[9]+flag[2] == 1796) checks++;
	if (flag[25]+flag[13]+flag[25]+flag[19]+flag[6]+flag[9]+flag[20]+flag[22]+flag[7]+flag[33]+flag[29]+flag[11]+flag[7]+flag[30]+flag[33]+flag[26]+flag[0]+flag[27]+flag[30]+flag[9] == 1693) checks++;
	if (flag[20]+flag[22]+flag[26]+flag[15]+flag[9]+flag[29]+flag[16]+flag[12]+flag[30]+flag[29]+flag[12]+flag[17] == 1043) checks++;
	if (flag[15]+flag[28]+flag[6]+flag[13]+flag[8]+flag[1]+flag[17]+flag[27]+flag[18]+flag[27]+flag[11]+flag[1]+flag[22]+flag[20]+flag[23]+flag[17]+flag[11] == 1554) checks++;
	if (flag[7]+flag[24]+flag[13]+flag[4]+flag[9]+flag[1] == 504) checks++;
	if (flag[8]+flag[0]+flag[20]+flag[30]+flag[31]+flag[16]+flag[31]+flag[23]+flag[29]+flag[22]+flag[13]+flag[12]+flag[0]+flag[16]+flag[27]+flag[30]+flag[0]+flag[23] == 1432) checks++;
	if (flag[7]+flag[20]+flag[2]+flag[12]+flag[25]+flag[21]+flag[12]+flag[28]+flag[6]+flag[12] == 744) checks++;
	if (flag[25]+flag[27]+flag[6] == 205) checks++;
	if (flag[33]+flag[15]+flag[32]+flag[0]+flag[2]+flag[0]+flag[16]+flag[1]+flag[19]+flag[13]+flag[2]+flag[7]+flag[11] == 1055) checks++;
	if (flag[17]+flag[20]+flag[27]+flag[12]+flag[13]+flag[0]+flag[1]+flag[5]+flag[31]+flag[30]+flag[3]+flag[28]+flag[2]+flag[9]+flag[22]+flag[16] == 1352) checks++;
	if (flag[18]+flag[10]+flag[33]+flag[32]+flag[9]+flag[2]+flag[16]+flag[24]+flag[16]+flag[31]+flag[17]+flag[31]+flag[23]+flag[2]+flag[8]+flag[22]+flag[4] == 1250) checks++;
	if (flag[9]+flag[16]+flag[31]+flag[8]+flag[20]+flag[23]+flag[32]+flag[15]+flag[8]+flag[24]+flag[18] == 901) checks++;
	if (flag[17]+flag[0]+flag[11]+flag[17] == 420) checks++;
	if (flag[15]+flag[9]+flag[25]+flag[0]+flag[29]+flag[21]+flag[29]+flag[24]+flag[23]+flag[21]+flag[20]+flag[26]+flag[20] == 1030) checks++;
	if (flag[29]+flag[13]+flag[4]+flag[25]+flag[27]+flag[0]+flag[27]+flag[27]+flag[32]+flag[23]+flag[8] == 915) checks++;
	if (flag[16]+flag[6]+flag[25]+flag[27]+flag[33]+flag[13]+flag[20]+flag[7]+flag[24]+flag[3]+flag[3]+flag[11]+flag[0]+flag[20]+flag[9]+flag[30]+flag[24]+flag[13] == 1574) checks++;
	if (flag[0]+flag[7]+flag[7]+flag[30]+flag[0]+flag[15]+flag[16]+flag[0]+flag[29] == 622) checks++;
	if (flag[18]+flag[12]+flag[17]+flag[13]+flag[9]+flag[16] == 528) checks++;
	if (flag[24]+flag[23]+flag[14] == 300) checks++;
	if (flag[27]+flag[8]+flag[1]+flag[19]+flag[7]+flag[9]+flag[2]+flag[17]+flag[0]+flag[1] == 870) checks++;
	if (flag[6]+flag[29]+flag[8]+flag[28]+flag[15]+flag[8]+flag[32]+flag[22] == 551) checks++;
	if (flag[26]+flag[25] == 147) checks++;
	if (flag[23]+flag[11]+flag[23]+flag[12]+flag[6]+flag[16]+flag[12]+flag[33]+flag[17] == 897) checks++;
	if (flag[0]+flag[31]+flag[21]+flag[6]+flag[14]+flag[8]+flag[29]+flag[18]+flag[29]+flag[24] == 661) checks++;
	if (flag[33]+flag[31]+flag[22]+flag[16]+flag[12]+flag[0]+flag[9]+flag[24]+flag[25] == 697) checks++;
	if (flag[11]+flag[5]+flag[31]+flag[13]+flag[15]+flag[0]+flag[23]+flag[10]+flag[5]+flag[27]+flag[25]+flag[32]+flag[1]+flag[12]+flag[20]+flag[26]+flag[27]+flag[0]+flag[7] == 1662) checks++;
	if (flag[22]+flag[7]+flag[6]+flag[1]+flag[19]+flag[23]+flag[19]+flag[14]+flag[20]+flag[6]+flag[19]+flag[4]+flag[28]+flag[25]+flag[28]+flag[25] == 1147) checks++;
	if (flag[27]+flag[2]+flag[28]+flag[16]+flag[29]+flag[13]+flag[2]+flag[29]+flag[1]+flag[9]+flag[11]+flag[30] == 949) checks++;
	if (flag[14]+flag[7]+flag[14]+flag[29]+flag[4]+flag[1] == 455) checks++;
	if (flag[12]+flag[10]+flag[0]+flag[14]+flag[27]+flag[26]+flag[10]+flag[13]+flag[27]+flag[20]+flag[27]+flag[26]+flag[15]+flag[18]+flag[3]+flag[16] == 1357) checks++;

	return checks == 34;
}

int main(void){
    read(0, flag, FLAGLEN);
    if (check()) puts("Flag");
    else puts("Not flag");
    return 0;
}

