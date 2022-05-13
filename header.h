#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

int tavla[2][12] = {2,0,0,0,0,5,0,3,0,0,0,5,2,0,0,0,0,5,0,3,0,0,0,5};
int ZAR[2];

int oyuncu1satir = 4;
int oyuncu2satir = 4;


int oyuncu_1_yerleri[50][2] = { 0,0,
							   1,5,
							   1,7,
							   0,11};
							   
int oyuncu_2_yerleri[50][2] = {0,5,
							   1,0,
							   1,11};

void ekranaYazdir() {
	
	FILE *dosya; 
	dosya = fopen("tavla.txt", "a");
	
	
	
	fprintf(dosya ,"  0   1   2   3   4   5   6   7   8   9   10  11  --> Sutun Numaralari \n");
	fprintf(dosya,"--------------------------------------------------\n");
	
	int i,j;

printf("  0   1   2   3   4   5   6   7   8   9   10  11  --> Sutun Numaralari \n");
printf("--------------------------------------------------\n");
for(i=0; i<2; i++) {
	printf("|");
	fprintf(dosya,"|");
	for(j=0; j<12; j++) {
		
		
		printf(" %d |",tavla[i][j]);
		fprintf(dosya," %d |",tavla[i][j]);
	}
	
	if(i == 0) {
	
	
	printf("\n");	
	printf("|   |   |   |   |   |   |   |   |   |   |   |   |\n");
	printf("|   |   |   |   |   |   |   |   |   |   |   |   |\n");
	printf("|   |   |   |   |   |   |   |   |   |   |   |   |\n");
	printf("|   |   |   |   |   |   |   |   |   |   |   |   |\n");
	
	
	fprintf(dosya,"\n");	
	fprintf(dosya,"|   |   |   |   |   |   |   |   |   |   |   |   |\n");
	fprintf(dosya,"|   |   |   |   |   |   |   |   |   |   |   |   |\n");
	fprintf(dosya,"|   |   |   |   |   |   |   |   |   |   |   |   |\n");
	fprintf(dosya,"|   |   |   |   |   |   |   |   |   |   |   |   |\n");

	
	}
}







fprintf(dosya," \n--------------------------------------------------\n\n\n");
printf(" \n--------------------------------------------------\n\n\n");

fprintf(dosya,"1. OYUNCUNUN ALANLARI\n\n");
printf("1. OYUNCUNUN ALANLARI\n\n");

printf("  0  1 --> Sutun Numarasi\n");
printf(" ------\n");

fprintf(dosya,"  0  1 --> Sutun Numarasi\n");
fprintf(dosya," ------\n");

for(i=0; i<oyuncu1satir; i++) {
	
	fprintf(dosya,"  %d  %d\n", oyuncu_1_yerleri[i][0], oyuncu_1_yerleri[i][1]);
	printf("  %d  %d\n", oyuncu_1_yerleri[i][0], oyuncu_1_yerleri[i][1]);
	
}

fprintf(dosya,"\n");
printf("\n");

printf("2. OYUNCUNUN ALANLARI\n\n");
fprintf(dosya,"2. OYUNCUNUN ALANLARI\n\n");

printf("  0  1 --> Sutun Numarasi\n");
printf(" ------\n");

fprintf(dosya,"  0  1 --> Sutun Numarasi\n");
fprintf(dosya," ------\n");

for(i=0; i<oyuncu2satir; i++) {
	
	printf("  %d  %d\n", oyuncu_2_yerleri[i][0], oyuncu_2_yerleri[i][1]);
	fprintf(dosya,"  %d  %d\n", oyuncu_2_yerleri[i][0], oyuncu_2_yerleri[i][1]);
}

printf("\n\n");
fprintf(dosya,"\n\n");


fclose(dosya);

}


void Zar() {
	
	srand(time(0));
	
	ZAR[0] = rand() % 7;
	ZAR[1] = rand() % 7;
	
	if(ZAR[0] == 0)
		ZAR[0]++;
		
	
	
	if(ZAR[1] == 0)
		ZAR[1]++;
		
		
		
	
	
}
