#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main() {
	
	
	
	
	int i,j,k,deger = 0;
	int e,f,l;
	int sonuc = 0,secim;
	int zar;
	
	int satir;
	int sutun;
	int zarSecim;
	
	
	FILE *yazdir; 
	yazdir = fopen("bilgi.txt", "a");
	
	
	
	

	
	///// OYUNCU 1 ÝÇÝN KODLAR /////7
	
	
	
	while (1) {
	
	system("CLS");

	ekranaYazdir();
	
	
	printf("\n\n1.OYUNCU\n\n");
	
	for(i=0; i<oyuncu1satir; i++) {
		
		if(oyuncu_1_yerleri[i][0] == 0 || oyuncu_1_yerleri[i][1] > 6) {
			
			sonuc = 1;
			break;
			
		}
		
	}
	
	if ( sonuc != 1) {
		
	
		printf("1-Pul Topla\n2-Pul Oyna: ");
		scanf("%d",&secim);
	
		if (secim == 2) {
			
			goto B;
		}
		
		if (secim == 1) {
			
			printf("Sutun: (0-5): ");
			scanf("%d",&sutun);
		
			tavla[1][sutun]--;
			
			
			printf("Sutun: (0-5): ");
			scanf("%d",&sutun);
		
			tavla[1][sutun]--;
			
		}
			
			
	
	}
	
	
else {
	
	Zar();
	
	fprintf(yazdir , "1.OYUNCU\n") ;
	fprintf(yazdir , "%d %d\n", ZAR[0],ZAR[1]) ;
	fclose(yazdir);
			
for(l=0; l<2; l++) {	


	
		
			
		A:	
			
			printf("\nZar\n1-)%d\n2-)%d \n\n",ZAR[0],ZAR[1]);
			printf("Hangi zar degeri oynansin: ");
			
			scanf("%d",&zarSecim);
			
			if(zarSecim == 1) {
				
				zar = ZAR[0];
			}
			
			if(zarSecim == 2) {
				
				zar = ZAR[1];
			}



	
B:	printf("Hangi Tas Oynansin\n");
	
	printf("Satir: (0-1): ");
	scanf("%d",&satir);
	
	printf("Sutun: (0-11): ");
	scanf("%d",&sutun);
	
	// ilk önce o taþ 1. oyuncunun mu ona bakalým
	
	for(i=0; i<oyuncu1satir; i++) {
			
			if(oyuncu_1_yerleri[i][0] == satir && oyuncu_1_yerleri[i][1] == sutun ) {
				
				deger = 1; 
				break;
			}
				
	}
	
	
		
		if (deger == 1) {	// Eðer o taþ oyuncunun ise
		
			
	
			
			
	
		
			
			
			if(satir == 1) {
				
				
				for(i=0; i<oyuncu2satir; i++) {
					
						if(sutun-zar == oyuncu_2_yerleri[i][1] && oyuncu_2_yerleri[i][0] == 1) {
							
							goto A;
						}
					
				}
					
						if( sutun - zar >= 0 ) {
							
							
							tavla[1][sutun]--;
							
							tavla[1][sutun-zar]++;
							
							for(e=0; e<oyuncu1satir; e++) {
								
								if(oyuncu_1_yerleri[e][0] == 1 && oyuncu_1_yerleri[e][1] == sutun-zar) {
									
									f = 0;
									break;
								}
								
								else {
									
									f = 1;
								}
								
							}
							
							if (f == 1) {
								
								oyuncu_1_yerleri[oyuncu1satir][0] = 1;
								oyuncu_1_yerleri[oyuncu1satir][1] = sutun-zar;
								oyuncu1satir++;
							}
								
						}
						
					
				
			}
			
			
		if (satir == 0) {
			
			
			
			
				
				if(sutun + zar < 12) { // 0.satýr ve 0-11 sutun aralýðýnda pul oynatma
				
					for(i=0; i<oyuncu2satir; i++) {
					
						if(sutun+zar == oyuncu_2_yerleri[i][1] && oyuncu_2_yerleri[i][0] == 0 ) {
							
							goto A;
						}
					
				}
					
					tavla[0][sutun]--;
					
					tavla[0][zar+sutun]++;
					
					for(e=0; e<oyuncu1satir; e++) {
								
								if(oyuncu_1_yerleri[e][0] == 0 && oyuncu_1_yerleri[e][1] == sutun+zar) {
									
									f = 0;
									break;
								}
								
								else {
									
									f = 1;
								}
								
							}
							
							if (f == 1) {
								
								oyuncu_1_yerleri[oyuncu1satir][0] = 0;
								oyuncu_1_yerleri[oyuncu1satir][1] = sutun+zar;
								oyuncu1satir++;
							}
					
					
					
					
				}
				
			else if (sutun == 11) { // 11.sutundan pul oynatma
			
				for(i=0; i<oyuncu2satir; i++) {
					
						if(sutun - zar + 1 == oyuncu_2_yerleri[i][1] &&  oyuncu_2_yerleri[i][0] == 1) {
							
							goto A;
						}
					
				}
					
					tavla[0][sutun]--;
					
					int x = sutun - zar + 1;
					
					tavla[1][x]++;
					
					
					for(e=0; e<oyuncu1satir; e++) {
								
								if(oyuncu_1_yerleri[e][0] == 1 && oyuncu_1_yerleri[e][1] == x) {
									
									f = 0;
									break;
								}
								
								else {
									
									f = 1;
								}
								
							}
							
							if (f == 1) {
								
								oyuncu_1_yerleri[oyuncu1satir][0] = 1;
								oyuncu_1_yerleri[oyuncu1satir][1] = x;
								oyuncu1satir++;
							}
					
					
					
					
					
				}
				
				else { // 0.satýr'dan 1.satýra pul oynatma
					
					
			
					
					int tutucu = sutun;
						
					
					for(k=0; k<100; k++) {
						
						if(tutucu == 11) {
							break;
						}
						
						tutucu++;
					}
					
					for(i=0; i<oyuncu2satir; i++) {
					
						if(11 - (zar - k) + 1 == oyuncu_2_yerleri[i][1] && oyuncu_2_yerleri[i][0] == 1) {
							
							goto A;
						}
					
				}
					
					int s = 11 - (zar - k) + 1;
					tavla[0][sutun]--;
					tavla[1][s]++;
					
					
					
					for(e=0; e<oyuncu1satir; e++) {
								
								if(oyuncu_1_yerleri[e][0] == 1 && oyuncu_1_yerleri[e][1] == s) {
									
									f = 0;
									break;
								}
								
								else {
									
									f = 1;
								}
								
							}
							
							if (f == 1) {
								
								oyuncu_1_yerleri[oyuncu1satir][0] = 1;
								oyuncu_1_yerleri[oyuncu1satir][1] = s;
								oyuncu1satir++;
							}
					
					
					
				}
				
			
			}	
			
		}
	

	
	ekranaYazdir();
	}
	
	}
	
	
	
	
	
	
	////// OYUNCU 2 ÝÇÝN KODLAR ////
	
	
	FILE *yazdir; 
	yazdir = fopen("bilgi.txt", "a");
	
		
	printf("\n\n2.OYUNCU\n\n");
	
	for(i=0; i<oyuncu2satir; i++) {
		
		if(oyuncu_2_yerleri[i][0] == 1 || oyuncu_1_yerleri[i][1] > 6) {
			
			sonuc = 1;
			break;
			
		}
		
	}
	
	if ( sonuc != 1) {
		
	
		printf("1-Pul Topla\n2-Pul Oyna: ");
		scanf("%d",&secim);
	
		if (secim == 2) {
			
			goto C;
		}
		
		if (secim == 1) {
			
			printf("Sutun: (0-5): ");
			scanf("%d",&sutun);
			
			
			
			
			tavla[0][sutun]--;
			
		}
			
			
	
	}
	
	
else {
	
	
		Zar();
		
	fprintf(yazdir , "2.OYUNCU\n") ;
	fprintf(yazdir , "%d %d\n", ZAR[0],ZAR[1]) ;
	fclose(yazdir);
		

			
for(l=0; l<2; l++) { 

		D:	

			printf("\nZar\n1-)%d\n2-)%d \n\n",ZAR[0],ZAR[1]);
			printf("Hangi zar degeri oynansin: ");
			
			scanf("%d",&zarSecim);
			
			if(zarSecim == 1) {
				
				zar = ZAR[0];
			}
			
			if(zarSecim == 2) {
				
				zar = ZAR[1];
			}
		
	
	
C:	printf("Hangi Tas Oynansin\n");
	
	printf("Satir: (0-1): ");
	scanf("%d",&satir);
	
	printf("Sutun: (0-11): ");
	scanf("%d",&sutun);
	
	// ilk önce o taþ 1. oyuncunun mu ona bakalým
	
	for(i=0; i<oyuncu2satir; i++) {
			
			if(oyuncu_2_yerleri[i][0] == satir && oyuncu_2_yerleri[i][1] == sutun ) {
				
				deger = 1; 
				break;
			}
				
	}
	
	
		
		if (deger == 1) {	// Eðer o taþ oyuncunun ise
			
	
			
			
			
			
			if(satir == 0) {
				
				
				for(i=0; i<oyuncu1satir; i++) {
					
						if(sutun-zar == oyuncu_1_yerleri[i][1] && oyuncu_1_yerleri[i][0] == 0) {
							
							goto D;
						}
					
				}
					
						if( sutun - zar >= 0 ) {
							
							
							tavla[0][sutun]--;
							
							tavla[0][sutun-zar]++;
							
							for(e=0; e<oyuncu1satir; e++) {
								
								if(oyuncu_2_yerleri[e][0] == 1 && oyuncu_2_yerleri[e][1] == sutun-zar) {
									
									f = 0;
									break;
								}
								
								else {
									
									f = 1;
								}
								
							}
							
							if (f == 1) {
								
								oyuncu_2_yerleri[oyuncu2satir][0] = 0;
								oyuncu_2_yerleri[oyuncu2satir][1] = sutun-zar;
								oyuncu2satir++;
							}
								
						}
						
					
				
			}
			
			
		if (satir == 1) {
			
			
			
			
				
				if(sutun + zar < 12) { // 1.satýr ve 0-11 sutun aralýðýnda pul oynatma  
				
					for(i=0; i<oyuncu1satir; i++) {
					
						if(sutun+zar == oyuncu_1_yerleri[i][1] && oyuncu_1_yerleri[i][0] == 0 ) {
							
							goto A;
						}
					
				}
					
					tavla[1][sutun]--;
					
					tavla[1][zar+sutun]++;
					
					for(e=0; e<oyuncu1satir; e++) {
								
								if(oyuncu_2_yerleri[e][0] == 1 && oyuncu_2_yerleri[e][1] == sutun+zar) {
									
									f = 0;
									break;
								}
								
								else {
									
									f = 1;
								}
								
							}
							
							if (f == 1) {
								
								oyuncu_2_yerleri[oyuncu2satir][0] = 1;
								oyuncu_2_yerleri[oyuncu2satir][1] = sutun+zar;
								oyuncu2satir++;
							}
					
					
					
					
				}
				
			else if (sutun == 11) { // 11.sutundan pul oynatma
			
				for(i=0; i<oyuncu1satir; i++) {
					
						if(sutun - zar + 1 == oyuncu_1_yerleri[i][1] &&  oyuncu_1_yerleri[i][0] == 1) {
							
							goto A;
						}
					
				}
					
					tavla[1][sutun]--;
					
					int x = sutun - zar + 1;
					
					tavla[0][x]++;
					
					
					for(e=0; e<oyuncu2satir; e++) {
								
								if(oyuncu_2_yerleri[e][0] == 0 && oyuncu_2_yerleri[e][1] == x) {
									
									f = 0;
									break;
								}
								
								else {
									
									f = 1;
								}
								
							}
							
							if (f == 1) {
								
								oyuncu_2_yerleri[oyuncu2satir][0] = 0;
								oyuncu_2_yerleri[oyuncu2satir][1] = x;
								oyuncu2satir++;
							}
					
					
					
					
					
				}
				
				else { // 1.satýr'dan 0.satýra pul oynatma
					
					
			
					
					int tutucu = sutun;
						
					
					for(k=0; k<100; k++) {
						
						if(tutucu == 11) {
							break;
						}
						
						tutucu++;
					}
					
					for(i=0; i<oyuncu1satir; i++) {
					
						if(11 - (zar - k) + 1 == oyuncu_1_yerleri[i][1] && oyuncu_1_yerleri[i][0] == 1) {
							
							goto A;
						}
					
				}
					
					int s = 11 - (zar - k) + 1;
					tavla[1][sutun]--;
					tavla[0][s]++;
					
					
					
					for(e=0; e<oyuncu2satir; e++) {
								
								if(oyuncu_2_yerleri[e][0] == 0 && oyuncu_2_yerleri[e][1] == s) {
									
									f = 0;
									break;
								}
								
								else {
									
									f = 1;
								}
								
							}
							
							if (f == 1) {
								
								oyuncu_2_yerleri[oyuncu2satir][0] = 0;
								oyuncu_2_yerleri[oyuncu2satir][1] = s;
								oyuncu2satir++;
							}
					
					
					
				}
				
			
			}	
			
		}
	
}
	
	ekranaYazdir();
	
	

}
	}
	
	
	
	
	
}
