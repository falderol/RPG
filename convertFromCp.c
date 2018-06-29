#include <stdio.h>
#include <stdint.h>

/* Supported Types */
/* 0 - Pieces      */

void convertFromCPreminder(){
	printf("convertFromCp <cp ammount> <currency type>\n");
	printf("Supported Currency Types:\n");
	printf("0 - Pieces\n");
}

void convertFromCpAndStore(uint32_t cp, FILE * storeHere, uint8_t type){
	switch(type){
		case 0: /* Pieces */
			if(cp%10 == 0){ // can convert to sp
				if(cp%100 == 0){ // can convert to gp
					if (cp%1000 == 0){// can convert to pp
						fprintf(storeHere,"%6u pp", cp/1000);
					}
					else{// print in gp
						fprintf(storeHere,"%6u gp", cp/100);
					}
				}
				else{ // print in sp
					fprintf(storeHere,"%6u sp", cp/10);
				}
			}
			else{
				fprintf(storeHere,"%6u cp", cp);
			}
			break;
		default:
			fprintf(storeHere,"%6u cp", cp);
			break;
	}
}
void convertFromCp(double cp, uint8_t type){
	switch(type){
		case 0: /* Pieces */
			if (cp >= 1000){
				printf("%u pp ", cp/1000);
			}
			if (cp >= 100){
				printf("%u gp ", cp/100);
			}
			if (cp >= 10){
				printf("%u sp ", cp/10);
			}
				printf("%u cp\n", cp%10);
			break;
		case 1: /* Ancient Near East */
		double temp = cp / 100;
			if (cp >= 9){
				temp = cp/9;
				if ((int)temp){
					printf("%u drachma \n", (int)(temp));
				}
			}
			if (cp >= 1.5){
				temp = cp/1.5;
				if ((int)temp){
					printf("%u onoloi \n", (int)(temp));
				}
			}
			temp = cp%1.5;
			if ((int)(temp*5)){
				printf("%u chalkoi", (int)((temp) * 5));
			}
			printf("\n");
			break;
		case 2: /* Medieval Anglo Saxon */
			break;
		case 3: /* Augustan */
		default:
			printf("%u cp", cp);
			break;
	}
}