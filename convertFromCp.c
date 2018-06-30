#include <stdio.h>
#include <stdint.h>

/* Supported Types */
/* 0 - Pieces      */

void convertFromCPreminder(){
	printf("convertFromCp <cp ammount> <currency type>\n");
	printf("Supported Currency Types:\n");
	printf("0 - Pieces\n");
	printf("1 - Ancient Near East\n");
	printf("2 - Medieval Anglo Saxon\n");
	printf("3 - Augustan\n");
}

void convertFromCPandStore(uint32_t cp, FILE * storeHere, uint8_t type){
	switch(type){
		case 0: /* Pieces */
			if(cp%10 == 0){ /* can convert to sp */
				if(cp%100 == 0){ /* can convert to gp */
					if (cp%1000 == 0){/* can convert to pp */
						fprintf(storeHere,"%6u pp", cp/1000);
					}
					else{/* print in gp */
						fprintf(storeHere,"%6u gp", cp/100);
					}
				}
				else{ /* print in sp */
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
void convertFromCP(uint64_t cp, uint8_t type){
	uint64_t amountLeft;
	uint64_t amountOf;
	uint64_t baseAmount;
	switch(type){
		case 0: /* Pieces */
			amountLeft = cp;
			amountOf = amountLeft/1000;
			if (amountOf){
				printf("%lu pp ", amountOf);
			}
			amountLeft = amountLeft%1000;
			amountOf = amountLeft/100;
			if (amountOf){
				printf("%lu gp ", amountOf);
			}
			amountLeft = amountLeft%100;
			amountOf = amountLeft/10;
			if (amountOf){
				printf("%lu sp ", amountOf);
			}
			amountLeft = amountLeft%10;
			amountOf = amountLeft/5;
			if (amountOf){
				printf("%lu ep ", amountOf);
			}
			amountLeft = amountLeft%5;
			amountOf = amountLeft;
			if (amountOf){
				printf("%lu cp", amountOf);
			}
			printf("\n");
			break;
		case 1: /* Ancient Near East */
			baseAmount = cp * 5.376;
			amountLeft = baseAmount;
			amountOf = baseAmount/201600;
			if (amountOf){
				printf("%lu talent ",amountOf);
			}
			amountLeft = amountLeft%201600;
			amountOf = amountLeft/3360;
			if(amountOf){
				printf("%lu mina ",amountOf);
			}
			amountLeft = amountLeft%3360;
			amountOf = amountLeft/48;
			if (amountOf){
				printf("%lu drachmae ",amountOf);
			}
			amountLeft = amountLeft%48;
			amountOf = amountLeft/8;
			if (amountOf){
				printf("%lu obolus ", amountOf);
			}
			amountLeft = amountLeft%8;
			if (amountLeft){
				printf("%lu chalkus", amountLeft);
			}
			printf("\n");
			break;
		case 2: /* Medieval Anglo Saxon */
			baseAmount = cp * 1.923;
			amountLeft = baseAmount;
			amountOf = baseAmount/960;
			if (amountOf){
				printf("%lu pounds ",amountOf);
			}
			amountLeft = amountLeft%960;
			amountOf = amountLeft/240;
			if (amountOf){
				printf("%lu crowns ",amountOf);
			}
			amountLeft = amountLeft%240;
			amountOf = amountLeft/48;
			if (amountOf){
				printf("%lu shilling ",amountOf);
			}
			amountLeft = amountLeft%48;
			amountOf = amountLeft/4;
			if (amountOf){
				printf("%lu pence ", amountOf);
			}
			amountLeft = amountLeft%4;
			if (amountLeft){
				printf("%lu farthing", amountLeft);
			}
			printf("\n");
			break;
		case 3: /* Augustan */
			baseAmount = cp * 0.8;
			amountLeft = baseAmount;
			amountOf = baseAmount/100;
			if (amountOf){
				printf("%lu aureus ",amountOf);
			}
			amountLeft = amountLeft%100;
			amountOf = amountLeft/50;
			if(amountOf){
				printf("%lu quinarius aureus ",amountOf);
			}
			amountLeft = amountLeft%50;
			amountOf = amountLeft/4;
			if (amountOf){
				printf("%lu denarius ",amountOf);
			}
			amountLeft = amountLeft%4;
			amountOf = amountLeft/2;
			if (amountOf){
				printf("%lu quinarius argenteus ", amountOf);
			}
			amountLeft = amountLeft%2;
			if (amountLeft){
				printf("%lu sesterius", amountLeft);
			}
			printf("\n");
			break;
		default:
			printf("%lu cp", cp);
			break;
	}
}