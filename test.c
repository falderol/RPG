#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "WorldGen/settlementGen.h"
#include "WorldGen/shopGen.h"
#include "RPGutilities/convertFromCp.h"
#include "WorldGen/nameGen.h"
#include "WorldGen/region.h"

/************************************************/
/* How to format shopgen command                */
/*shopGen(<FILENAME>,<SHOPNUM>,<FLAGS>);        */
/************************************************/
/* Shop Guide                                   */
/*"00 - Adventurer's Emporium                   */
/*"01 - Alchemist's Shop                        */
/*"02 - Arcana Shop                             */
/*"03 - Bakery                                  */
/*"04 - Barber                                  */
/*"05 - Blacksmith                              */
/*"06 - Bookstore                               */
/*"07 - Butcher's Shop                          */
/*"08 - Fletcher                                */
/*"09 - General Store                           */
/*"10 - Leatherworker's Shop                    */
/*"11 - Music Store                             */
/*"12 - Tailor                                  */
/*"13 - Tavern                                  */
/*"14 - Shrine                                  */
/*"15 - Jeweler                                 */
/************************************************/
/* Flags Guide                                  */
/*"Bit 00 - Magical                             */
/*"Bit 01 - Coastal                             */
/*"Bit 02 - Commerce                            */
/*"Bit 03 - Exotic                              */
/*"Bit 04 - Frontier                            */
/*"Bit 05 - Forest                              */
/*"Bit 06 - Industrial                          */
/*"Bit 07 - Mountain                            */
/*"Bit 08 - Pious                               */
/*"Bit 09 - Agriculture                         */
/*"Bit 10 - Rural                               */
/*"Bit 11 - Urban                               */

void commandReminder(){
	printf("Command Unrecognized...\n\n");
	printf("Recognized commands are:\n");
	printf("settlementGen <filename.txt> <size> <flags>\n");
	printf("autoSettlementGen <filename.txt> <flags>\n");
	printf("shopGen <filename.txt> <shop number> <flags>\n");
	printf("shopnameGen\n");
	printf("townnameGen\n");
	printf("convertFromCP <cp value> <currency type>\n");
	printf("\nFor more info on any of these commands type them without any arguments\n");
}

int main (int argc, char* argv[]){

	srand(time(NULL));

	if (argc < 2){
		commandReminder();
	}
	else if(!(strcmp("settlementGen", argv[1]))){ /* Manual Settlement Gen*/
		/*settlementGen(char * filename, uint8_t settlementSize, uint16_t flags )*/
		if(argc != 5){
			settlementCommandReminder();
			return -1;
		}
		
		settlementGen(argv[2], atoi(argv[3]), atoi(argv[4]));
	}
	else if(!(strcmp("autoSettlementGen", argv[1]))){ /* Auto Settlement Gen*/
		/*settlementGen(char * filename, uint8_t settlementSize, uint16_t flags )*/

		settlementGen(argv[2], rand()%100, atoi(argv[3]));
	}
	else if (!(strcmp("shopGen", argv[1]))){ /* shop generator */
		/*shopGen(char* filename,uint8_t shopNum,uint16_t flags)*/
		if(argc != 5){
			shopCommandReminder();
			return -1;
		}
		shopGen(argv[2], atoi(argv[3]), atoi(argv[4]));
	}
	else if (!(strcmp("shopnameGen", argv[1]))){ /* shop name generator */
		/*shopnameGen()*/
		if(argc != 2){
			printf("This function has no arguments");
			return -1;
		}
		shopnameGen();
	}
	else if (!(strcmp("townnameGen", argv[1]))){ /* town name generator */
		/*townnameGen()*/
		if(argc != 2){
			printf("This function has no arguments");
			return -1;
		}
		townnameGen();
	}
	else if (!(strcmp("convertFromCP", argv[1]))){/* currency converter */
		/*convertFromCp(uint32_t cp, uint8_t type)*/
		if(argc != 4){
			convertFromCPreminder();
			return -1;
		}
		convertFromCP(atoi(argv[2]), atoi(argv[3]));
	}
	else if (!(strcmp("regionGen", argv[1]))){
		if(argc != 3){
			regionCommandReminder();
			return -1;
		}
		regionGen(argv[2]);
	}
	else{
		commandReminder();
	}
	return 0;
}