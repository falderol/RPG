#include "settlementGen.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "itoa.h"
#include "shopGen.h"
#include "nameGen.h"
#include "flagDefines.h"

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

void settlementCommandReminder(){
	printf("Command format is: ");
	printf(".\\programName <storageLoc.txt> <size 1-100> <flags>\n");
	printf("Supported Flags are:\n");
	printf("Bit 00 - Costal      /* To include add    1 to the flag */\n");
	printf("Bit 01 - Mountain    /* To include add    2 to the flag */\n");
	printf("Bit 02 - Agriculture /* To include add    4 to the flag */\n");
	printf("Bit 03 - Forest      /* To include add    8 to the flag */\n");
	printf("Bit 04 - Commerce    /* To include add   16 to the flag */\n");
	printf("Bit 05 - Frontier    /* To include add   32 to the flag */\n");
	printf("Bit 06 - Industrial  /* To include add   64 to the flag */\n");
	printf("Bit 07 - Rural       /* To include add  128 to the flag */\n");
	printf("Bit 08 - Urban       /* To include add  256 to the flag */\n");
    printf("Bit 09 - Exotic      /* To include add  512 to the flag */\n");
	printf("Bit 10 - Pious       /* To include add 1024 to the flag */\n");
	printf("Bit 11 - Magical     /* To include add 2048 to the flag */\n");
	printf("I.E. a Magical, Frontier, Forest would be 49\n");
	printf("I.E. a Commerce, Pious, Urban area would be 2308\n");
}

void settlementGen(char * filename, uint8_t settlementSize, uint16_t flags ){
	FILE * townFile = fopen(filename, "w");
	/*srand(time(NULL); Replace with windows and linux specific funtion if you keep here */
	char townFileName[128];
	strcpy(townFileName, filename);
	
	uint8_t numAE = 0;
	uint8_t numALC = 0;
	uint8_t numARC = 0;
	uint8_t numBAK = 0;
	uint8_t numBRB = 0;
	uint8_t numBLK = 0;
	uint8_t numBOK = 0;
	uint8_t numBCH = 0;
	uint8_t numFLC = 0;
	uint8_t numGEN = 0;
	uint8_t numLEA = 0;
	uint8_t numMUS = 0;
	uint8_t numTLR = 0;
	uint8_t numTVN = 0;
	uint8_t numSRN = 0;
	uint8_t numJWL = 0;
	uint8_t numSHOPS = 0;
	int population = 0;
	if(settlementSize >= 100){
		fprintf(townFile, "The City of ");
		townnameGenAndStore(townFile);
		population = (((rand()%5)+1)*settlementSize*5);
		population += (((rand()%5)+1)*settlementSize*5);
		population += (((rand()%5)+1)*settlementSize*5);
		//population += (((rand()%5)+1)*settlementSize*5);
		population += rand()%1000;
		fprintf(townFile, "Population: %d\n\n\n",population);
		fclose(townFile);
		uint8_t shopAmount = (settlementSize/15)*(rand()%4+rand()%4+5)+rand()%7;
		for (int i = 0; i < shopAmount; ++i){
			/* uint8_t shopnum = 0; */
			switch((rand()%20)+1){
				case 1:
				case 2:
				case 3:
				case 4:
					++numTVN;
					break;
				case 5:
					++numFLC;
					break;
				case 6:
					++numLEA;
					break;
				case 7:
				case 8:
				case 9:
					++numGEN;
					break;
				case 10:
				case 11:
					++numBLK;
					break;
				case 12:
				case 13:
					++numTLR;
					break;
				case 14:
					++numAE;
					break;
				case 15:
					++numARC;
					break;
				case 16:
					++numALC;
					break;
				case 17:
				case 18:
					++numSRN;
					break;
				case 19:
				case 20:
					switch((rand()%8)+1){
						case 1:
							++numMUS;
							break;
						case 2:
							++numBOK;
							break;
						case 3:
							++numJWL;
							break;
						case 4:
						case 5:
							++numBCH;
							break;
						case 6:
						case 7:
							++numBAK;
							break;
						case 8:
							++numBRB;
							break;
						default:
							break;
					}
				default:
					break;
			}
		}
	}
	else {
		population = (rand()%7+1)*settlementSize + rand()%(settlementSize*5);
		if (settlementSize <= 1){
			population = 0;
			fprintf(townFile, "The Abandoned %s of ", rand()%4 ? "Village" : "Town");
		}
		else if (population < 500){
			fprintf(townFile, "The Village of ");
		}
		else{
			fprintf(townFile, "The Town of ");
		}
		townnameGenAndStore(townFile);
		fprintf(townFile, "Population: %d\n\n\n",population);
		fclose(townFile);
		uint8_t shopAmount = (settlementSize/15)+2+rand()%3;
		for (int i = 0; i < shopAmount; ++i){
			/* uint8_t shopnum = 0; */
			switch((rand()%20)+1){
				case 1:
				case 2:
				case 3:
				case 4:
					++numTVN;
					break;
				case 5:
					++numFLC;
					break;
				case 6:
					++numLEA;
					break;
				case 7:
				case 8:
				case 9:
					++numGEN;
					break;
				case 10:
				case 11:
					++numBLK;
					break;
				case 12:
				case 13:
					++numTLR;
					break;
				case 14:
					++numAE;
					break;
				case 15:
					++numARC;
					break;
				case 16:
					++numALC;
					break;
				case 17:
				case 18:
					++numSRN;
					break;
				case 19:
				case 20:
					switch((rand()%8)+1){
						case 1:
							++numMUS;
							break;
						case 2:
							++numBOK;
							break;
						case 3:
							++numJWL;
							break;
						case 4:
						case 5:
							++numBCH;
							break;
						case 6:
						case 7:
							++numBAK;
							break;
						case 8:
							++numBRB;
							break;
						default:
							break;
					}
				default:
					break;
			}
		}
	}
	int currentShopPrinting = 0;
	for (int i = 0; i < numAE; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 0, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numALC; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 1, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numARC; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 2, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBAK; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 3, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBRB; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 4, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBLK; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 5, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBOK; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 6, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBCH; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 7, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numFLC; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 8, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numGEN; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 9, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numLEA; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 10, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numMUS; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 11, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numTLR; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 12, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numTVN; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 13, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numSRN; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 14, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numJWL; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 15, flags);
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	printf("Settlement has been generated\n");
	/* End of city generation        */
	/* Number of buildings to number */
	/* print a * border              */
	numSHOPS = numAE + numALC + numARC + numBAK + numBRB + numBLK + numBOK + numBCH + numFLC + numGEN + numLEA + numMUS + numTLR + numTVN + numSRN + numJWL;
    int mapHeight = 510;
	int mapWidth = mapHeight * 2;
	char map[mapHeight][mapWidth];
	for (int i = 0; i < mapHeight; ++i){
		for (int j = 0; j < mapWidth; ++j){
			map[i][j] = ' ';
		}
	}
	char* token;
	char mapFilename[64];
	for (int i = 0; i < 64; ++i){
		mapFilename[i] = '\0';
	}
	token = strtok(filename,".");
	strcpy(mapFilename, token);
	strcat(mapFilename,"Map.txt");
	FILE * townMapFile = fopen(mapFilename, "w");
	/* Make Border */
	for (int i = 0; i < mapHeight; ++i){
		for (int j = 0; j < mapWidth; ++j){
			if(i == 0){
				if (j%2){
					map[i][j] = ' ';
				}
				else{
					map[i][j] = '*';
				}
				if (j == (mapWidth/2)-2){
					map[i][j] = 'N';
				}
				else if (j == (mapWidth/2)-1){
					map[i][j] = 'O';
				}
				else if (j == (mapWidth/2)){
					map[i][j] = 'R';
				}
				else if (j == (mapWidth/2)+1){
					map[i][j] = 'T';
				}
				else if (j == (mapWidth/2)+2){
					map[i][j] = 'H';
				}
			}
			else if (i == mapHeight - 1){
				if (j%2){
					map[i][j] = ' ';
				}
				else{
					map[i][j] = '*';
				}
				if (j == (mapWidth/2)-2){
					map[i][j] = 'S';
				}
				else if (j == (mapWidth/2)-1){
					map[i][j] = 'O';
				}
				else if (j == (mapWidth/2)){
					map[i][j] = 'U';
				}
				else if (j == (mapWidth/2)+1){
					map[i][j] = 'T';
				}
				else if (j == (mapWidth/2)+2){
					map[i][j] = 'H';
				}
			}
			else if (j == 0){
				map[i][j] = '*';
				if (i == (mapHeight/2)-2){
					map[i][j] = 'E';
				}
				else if (i == (mapHeight/2)-1){
					map[i][j] = 'A';
				}
				else if (i == (mapHeight/2)){
					map[i][j] = 'S';
				}
				else if (i == (mapHeight/2)+1){
					map[i][j] = 'T';
				}
			}
			else if (j == mapWidth - 1){
				map[i][j] = '*';
				if (i == (mapHeight/2)-2){
					map[i][j] = 'W';
				}
				else if (i == (mapHeight/2)-1){
					map[i][j] = 'E';
				}
				else if (i == (mapHeight/2)){
					map[i][j] = 'S';
				}
				else if (i == (mapHeight/2)+1){
					map[i][j] = 'T';
				}
			}
		}
	}
	/************************************************/
	/* Place Roads and Rivers                       */
	
	uint8_t numRoadRiv = (rand()%((settlementSize/20)+1)+1);
	if (settlementSize >= 100){
		++numRoadRiv;
	}
	uint8_t hasRiver = 0;
	for (int i = 0; i < numRoadRiv; ++i){
		uint8_t startSide = rand()%3;
		int startX = 0;
		int startY = 0;
		uint8_t riverRoad = rand()%3;
		switch(startSide){
			case 0:/* Travel North */
				startX = rand()%(mapWidth/4)*2+(mapWidth/4);
				startY = 2;
				while((startX < mapWidth-8)&&(startX > 7)&&(startY <= mapHeight-3)&&(startY >= 2)){
					if((riverRoad)||(hasRiver>3)){/* road */
						map[startY][startX] = 'H';
						map[startY][startX-2] = 'H';
						map[startY][startX+2] = 'H';
						map[startY+1][startX] = 'H';
						map[startY+1][startX-2] = 'H';
						map[startY+1][startX+2] = 'H';
						map[startY-1][startX] = 'H';
						map[startY-1][startX-2] = 'H';
						map[startY-1][startX+2] = 'H';
						
					}
					else{/* river */
						if((startY+2<mapHeight)? (map[startY+2][startX] != 'W') : 1 ){
							map[startY][startX] = 'W';
							map[startY][startX-2] = 'W';
							map[startY][startX+2] = 'W';
							map[startY+1][startX] = 'W';
							map[startY+1][startX-2] = 'W';
							map[startY+1][startX+2] = 'W';
							map[startY-1][startX] = 'W';
							map[startY-1][startX-2] = 'W';
							map[startY-1][startX+2] = 'W';
						}
						else {
							map[startY][startX] = 'W';
							map[startY][startX-2] = 'W';
							map[startY][startX+2] = 'W';
							map[startY+1][startX] = 'W';
							map[startY+1][startX-2] = 'W';
							map[startY+1][startX+2] = 'W';
							map[startY-1][startX] = 'W';
							map[startY-1][startX-2] = 'W';
							map[startY-1][startX+2] = 'W';
							map[startY+2][startX] = 'W';
							map[startY+2][startX-2] = 'W';
							map[startY+2][startX+2] = 'W';
							break;
						}
					}
					if(rand()%2){
						++startY;
					}
					else{
						if(rand()%2){
							++startX;
							++startX;
						}
						else{
							--startX;
							--startX;
						}
					}
				}
				if (riverRoad == 0){
					++hasRiver;
				}
				break;
			case 1:/* Travel South */
				startX = rand()%(mapWidth/4)*2+(mapWidth/4);
				startY = mapHeight-3;
				while((startX <= mapWidth-4)&&(startX >= 3)&&(startY <= mapHeight-3)&&(startY >= 2)){
					if((riverRoad)||(hasRiver>3)){/* road */
						map[startY][startX] = 'H';
						map[startY][startX-2] = 'H';
						map[startY][startX+2] = 'H';
						map[startY+1][startX] = 'H';
						map[startY+1][startX-2] = 'H';
						map[startY+1][startX+2] = 'H';
						map[startY-1][startX] = 'H';
						map[startY-1][startX-2] = 'H';
						map[startY-1][startX+2] = 'H';
						
					}
					else{/* river */
						if((startY-2>0)? (map[startY-2][startX] != 'W') : 1 ){
							map[startY][startX] = 'W';
							map[startY][startX-2] = 'W';
							map[startY][startX+2] = 'W';
							map[startY+1][startX] = 'W';
							map[startY+1][startX-2] = 'W';
							map[startY+1][startX+2] = 'W';
							map[startY-1][startX] = 'W';
							map[startY-1][startX-2] = 'W';
							map[startY-1][startX+2] = 'W';
						}
						else {
							map[startY][startX] = 'W';
							map[startY][startX-2] = 'W';
							map[startY][startX+2] = 'W';
							map[startY+1][startX] = 'W';
							map[startY+1][startX-2] = 'W';
							map[startY+1][startX+2] = 'W';
							map[startY-1][startX] = 'W';
							map[startY-1][startX-2] = 'W';
							map[startY-1][startX+2] = 'W';
							map[startY-2][startX] = 'W';
							map[startY-2][startX-2] = 'W';
							map[startY-2][startX+2] = 'W';
							
							break;
						}
					}
					if(rand()%2){
						--startY;
					}
					else{
						if(rand()%2){
							++startX;
							++startX;
						}
						else{
							--startX;
							--startX;
						}
					}
				}
				if (riverRoad == 0){
					++hasRiver;
				}
				break;
			case 2:/* Travel East */
				startX = 3;
				startY = rand()%(mapHeight/2)+(mapHeight/4);
				while((startX <= mapWidth-4)&&(startX >= 3)&&(startY <= mapHeight-3)&&(startY >= 2)){
					if((riverRoad)||(hasRiver>3)){/* road */
						map[startY][startX] = 'H';
						map[startY][startX-2] = 'H';
						map[startY][startX+2] = 'H';
						map[startY+1][startX] = 'H';
						map[startY+1][startX-2] = 'H';
						map[startY+1][startX+2] = 'H';
						map[startY-1][startX] = 'H';
						map[startY-1][startX-2] = 'H';
						map[startY-1][startX+2] = 'H';
						
					}
					else{/* river */
						if((startX+4>0)? (map[startY][startX+4] != 'W') : 1 ){
							map[startY][startX] = 'W';
							map[startY][startX-2] = 'W';
							map[startY][startX+2] = 'W';
							map[startY+1][startX] = 'W';
							map[startY+1][startX-2] = 'W';
							map[startY+1][startX+2] = 'W';
							map[startY-1][startX] = 'W';
							map[startY-1][startX-2] = 'W';
							map[startY-1][startX+2] = 'W';
						}
						else {
							map[startY][startX] = 'W';
							map[startY][startX-2] = 'W';
							map[startY][startX+2] = 'W';
							map[startY+1][startX] = 'W';
							map[startY+1][startX-2] = 'W';
							map[startY+1][startX+2] = 'W';
							map[startY-1][startX] = 'W';
							map[startY-1][startX-2] = 'W';
							map[startY-1][startX+2] = 'W';
							map[startY+1][startX+4] = 'W';
							map[startY][startX+4] = 'W';
							map[startY-1][startX+4] = 'W';
							break;
						}
					}
					if(rand()%2){
						++startX;
						++startX;
					}
					else{
						if(rand()%2){
							++startY;
						}
						else{
							--startY;
						}
					}
				}
				if (riverRoad == 0){
					++hasRiver;
				}
				break;
			case 3:/* Travel West */
				startX = mapWidth-4;
				startY = rand()%(mapHeight/2)+(mapHeight/4);
				while((startX <= mapWidth-4)&&(startX >= 3)&&(startY <= mapHeight-3)&&(startY >= 2)){
					if((riverRoad)||(hasRiver>3)){/* road */
						map[startY][startX] = 'H';
						map[startY][startX-2] = 'H';
						map[startY][startX+2] = 'H';
						map[startY+1][startX] = 'H';
						map[startY+1][startX-2] = 'H';
						map[startY+1][startX+2] = 'H';
						map[startY-1][startX] = 'H';
						map[startY-1][startX-2] = 'H';
						map[startY-1][startX+2] = 'H';
						
					}
					else{/* river */
						if((startX-4<mapWidth)? (map[startY][startX-4] != 'W') : 1 ){
							map[startY][startX] = 'W';
							map[startY][startX-2] = 'W';
							map[startY][startX+2] = 'W';
							map[startY+1][startX] = 'W';
							map[startY+1][startX-2] = 'W';
							map[startY+1][startX+2] = 'W';
							map[startY-1][startX] = 'W';
							map[startY-1][startX-2] = 'W';
							map[startY-1][startX+2] = 'W';
						}
						else {
							map[startY][startX] = 'W';
							map[startY][startX-2] = 'W';
							map[startY][startX+2] = 'W';
							map[startY+1][startX] = 'W';
							map[startY+1][startX-2] = 'W';
							map[startY+1][startX+2] = 'W';
							map[startY-1][startX] = 'W';
							map[startY-1][startX-2] = 'W';
							map[startY-1][startX+2] = 'W';
							map[startY+1][startX-4] = 'W';
							map[startY][startX-4] = 'W';
							map[startY-1][startX-4] = 'W';
							break;
						}
					}
					if(rand()%2){
						--startX;
						--startX;
					}
					else{
						if(rand()%2){
							++startY;
						}
						else{
							--startY;
						}
					}
				}
				if (riverRoad == 0){
					++hasRiver;
				}
				break;
			default:
				break;
		}
	}
	
	/************************************************/
	/* Place Buildings                              */
	
	uint8_t squareBuildingHeight = 6;
	uint8_t squareBuildingWidth = 12;
	char squareBuilding[squareBuildingHeight][squareBuildingWidth];
	sprintf(squareBuilding[0],"%12s", " __________ ");
	sprintf(squareBuilding[1],"%12s", "|          |");
	sprintf(squareBuilding[2],"%12s", "|          |");
	sprintf(squareBuilding[3],"%12s", "|          |");
	sprintf(squareBuilding[4],"%12s", "|          |");
	sprintf(squareBuilding[5],"%12s", "|__________|");
	
	uint8_t roundBuildingHeight = 10;
	uint8_t roundBuildingWidth = 20;
	char roundBuilding[roundBuildingHeight][roundBuildingWidth];
	sprintf(roundBuilding[0],"%20s", "     __________     ");
	sprintf(roundBuilding[1],"%20s", "   _|          |_   ");
	sprintf(roundBuilding[2],"%20s", " _|              |_ ");
	sprintf(roundBuilding[3],"%20s", "|                  |");
	sprintf(roundBuilding[4],"%20s", "|                  |");
	sprintf(roundBuilding[5],"%20s", "|                  |");
	sprintf(roundBuilding[6],"%20s", "|                  |");
	sprintf(roundBuilding[7],"%20s", "|_                _|");
	sprintf(roundBuilding[8],"%20s", "  |_            _|  ");
	sprintf(roundBuilding[9],"%20s", "    |__________|    ");
	
	uint8_t rectLongBuildingHeight = 12;
	uint8_t rectLongBuildingWidth = 12;
	char rectLongBuilding[rectLongBuildingHeight][rectLongBuildingWidth];
	sprintf(rectLongBuilding[0],"%12s",  " __________ ");
	sprintf(rectLongBuilding[1],"%12s",  "|          |");
	sprintf(rectLongBuilding[2],"%12s",  "|          |");
	sprintf(rectLongBuilding[3],"%12s",  "|          |");
	sprintf(rectLongBuilding[4],"%12s",  "|          |");
	sprintf(rectLongBuilding[5],"%12s",  "|          |");
	sprintf(rectLongBuilding[6],"%12s",  "|          |");
	sprintf(rectLongBuilding[7],"%12s",  "|          |");
	sprintf(rectLongBuilding[8],"%12s",  "|          |");
	sprintf(rectLongBuilding[9],"%12s",  "|          |");
	sprintf(rectLongBuilding[10],"%12s", "|          |");
	sprintf(rectLongBuilding[11],"%12s", "|__________|");
	
	uint8_t rectWideBuildingHeight = 6;
	uint8_t rectWideBuildingWidth = 24;
	char rectWideBuilding[rectWideBuildingHeight][rectWideBuildingWidth];
	sprintf(rectWideBuilding[0],"%24s", " ______________________ ");
	sprintf(rectWideBuilding[1],"%24s", "|                      |");
	sprintf(rectWideBuilding[2],"%24s", "|                      |");
	sprintf(rectWideBuilding[3],"%24s", "|                      |");
	sprintf(rectWideBuilding[4],"%24s", "|                      |");
	sprintf(rectWideBuilding[5],"%24s", "|______________________|");
	
	uint8_t lDownLeftBuildingHeight = 12;
	uint8_t lDownLeftBuildingWidth = 24;
	char lDownLeftBuilding[lDownLeftBuildingHeight][lDownLeftBuildingWidth];
	sprintf(lDownLeftBuilding[0],"%24s",  "             __________ ");
	sprintf(lDownLeftBuilding[1],"%24s",  "            |          |");
	sprintf(lDownLeftBuilding[2],"%24s",  "            |          |");
	sprintf(lDownLeftBuilding[3],"%24s",  "            |          |");
	sprintf(lDownLeftBuilding[4],"%24s",  "            |          |");
	sprintf(lDownLeftBuilding[5],"%24s",  "            |          |");
	sprintf(lDownLeftBuilding[6],"%24s",  " ___________|          |");
	sprintf(lDownLeftBuilding[7],"%24s",  "|                      |");
	sprintf(lDownLeftBuilding[8],"%24s",  "|                      |");
	sprintf(lDownLeftBuilding[9],"%24s",  "|                      |");
	sprintf(lDownLeftBuilding[10],"%24s", "|                      |");
	sprintf(lDownLeftBuilding[11],"%24s", "|______________________|");
	
	uint8_t lDownRightBuildingHeight = 12;
	uint8_t lDownRightBuildingWidth = 24;
	char lDownRightBuilding[lDownRightBuildingHeight][lDownRightBuildingWidth];
	sprintf(lDownRightBuilding[0],"%24s",  " __________             ");
	sprintf(lDownRightBuilding[1],"%24s",  "|          |            ");
	sprintf(lDownRightBuilding[2],"%24s",  "|          |            ");
	sprintf(lDownRightBuilding[3],"%24s",  "|          |            ");
	sprintf(lDownRightBuilding[4],"%24s",  "|          |            ");
	sprintf(lDownRightBuilding[5],"%24s",  "|          |            ");
	sprintf(lDownRightBuilding[6],"%24s",  "|          |___________ ");
	sprintf(lDownRightBuilding[7],"%24s",  "|                      |");
	sprintf(lDownRightBuilding[8],"%24s",  "|                      |");
	sprintf(lDownRightBuilding[9],"%24s",  "|                      |");
	sprintf(lDownRightBuilding[10],"%24s", "|                      |");
	sprintf(lDownRightBuilding[11],"%24s", "|______________________|");
	
	uint8_t lUpLeftBuildingHeight = 12;
	uint8_t lUpLeftBuildingWidth = 24;
	char lUpLeftBuilding[lUpLeftBuildingHeight][lUpLeftBuildingWidth];
	sprintf(lUpLeftBuilding[0],"%24s",  " ______________________ ");
	sprintf(lUpLeftBuilding[1],"%24s",  "|                      |");
	sprintf(lUpLeftBuilding[2],"%24s",  "|                      |");
	sprintf(lUpLeftBuilding[3],"%24s",  "|                      |");
	sprintf(lUpLeftBuilding[4],"%24s",  "|                      |");
	sprintf(lUpLeftBuilding[5],"%24s",  "|___________           |");
	sprintf(lUpLeftBuilding[6],"%24s",  "            |          |");
	sprintf(lUpLeftBuilding[7],"%24s",  "            |          |");
	sprintf(lUpLeftBuilding[8],"%24s",  "            |          |");
	sprintf(lUpLeftBuilding[9],"%24s",  "            |          |");
	sprintf(lUpLeftBuilding[10],"%24s", "            |          |");
	sprintf(lUpLeftBuilding[11],"%24s", "            |__________|");
	
	uint8_t lUpRightBuildingHeight = 12;
	uint8_t lUpRightBuildingWidth = 24;
	char lUpRightBuilding[lUpRightBuildingHeight][lUpRightBuildingWidth];
	sprintf(lUpRightBuilding[0],"%24s",  " _____________________ ");
	sprintf(lUpRightBuilding[1],"%24s",  "|                     |");
	sprintf(lUpRightBuilding[2],"%24s",  "|                     |");
	sprintf(lUpRightBuilding[3],"%24s",  "|                     |");
	sprintf(lUpRightBuilding[4],"%24s",  "|                     |");
	sprintf(lUpRightBuilding[5],"%24s",  "|           __________|");
	sprintf(lUpRightBuilding[6],"%24s",  "|          |           ");
	sprintf(lUpRightBuilding[7],"%24s",  "|          |           ");
	sprintf(lUpRightBuilding[8],"%24s",  "|          |           ");
	sprintf(lUpRightBuilding[9],"%24s",  "|          |           ");
	sprintf(lUpRightBuilding[10],"%24s", "|          |           ");
	sprintf(lUpRightBuilding[11],"%24s", "|__________|           ");
	
	uint8_t lTRightBuildingHeight = 12;
	uint8_t lTRightBuildingWidth = 24;
	char lTRightBuilding[lTRightBuildingHeight][lTRightBuildingWidth];
	sprintf(lTRightBuilding[0],"%24s",  " __________            ");
	sprintf(lTRightBuilding[1],"%24s",  "|          |           ");
	sprintf(lTRightBuilding[2],"%24s",  "|          |           ");
	sprintf(lTRightBuilding[3],"%24s",  "|          |__________ ");
	sprintf(lTRightBuilding[4],"%24s",  "|                     |");
	sprintf(lTRightBuilding[5],"%24s",  "|                     |");
	sprintf(lTRightBuilding[6],"%24s",  "|                     |");
	sprintf(lTRightBuilding[7],"%24s",  "|                     |");
	sprintf(lTRightBuilding[8],"%24s",  "|           __________|");
	sprintf(lTRightBuilding[9],"%24s",  "|          |           ");
	sprintf(lTRightBuilding[10],"%24s", "|          |           ");
	sprintf(lTRightBuilding[11],"%24s", "|__________|           ");
	
	uint8_t lTLeftBuildingHeight = 12;
	uint8_t lTLeftBuildingWidth = 24;
	char lTLeftBuilding[lTLeftBuildingHeight][lTLeftBuildingWidth];
	sprintf(lTLeftBuilding[0],"%24s",  "            __________ ");
	sprintf(lTLeftBuilding[1],"%24s",  "           |          |");
	sprintf(lTLeftBuilding[2],"%24s",  "           |          |");
	sprintf(lTLeftBuilding[3],"%24s",  " __________|          |");
	sprintf(lTLeftBuilding[4],"%24s",  "|                     |");
	sprintf(lTLeftBuilding[5],"%24s",  "|                     |");
	sprintf(lTLeftBuilding[6],"%24s",  "|                     |");
	sprintf(lTLeftBuilding[7],"%24s",  "|                     |");
	sprintf(lTLeftBuilding[8],"%24s",  "|__________           |");
	sprintf(lTLeftBuilding[9],"%24s",  "           |          |");
	sprintf(lTLeftBuilding[10],"%24s", "           |          |");
	sprintf(lTLeftBuilding[11],"%24s", "           |__________|");
	
	uint8_t lTDownBuildingHeight = 12;
	uint8_t lTDownBuildingWidth = 24;
	char lTDownBuilding[lTDownBuildingHeight][lTDownBuildingWidth];
	sprintf(lTDownBuilding[0],"%24s",  " ______________________ ");
	sprintf(lTDownBuilding[1],"%24s",  "|                      |");
	sprintf(lTDownBuilding[2],"%24s",  "|                      |");
	sprintf(lTDownBuilding[3],"%24s",  "|                      |");
	sprintf(lTDownBuilding[4],"%24s",  "|                      |");
	sprintf(lTDownBuilding[5],"%24s",  "|_____            _____|");
	sprintf(lTDownBuilding[6],"%24s",  "      |          |      ");
	sprintf(lTDownBuilding[7],"%24s",  "      |          |      ");
	sprintf(lTDownBuilding[8],"%24s",  "      |          |      ");
	sprintf(lTDownBuilding[9],"%24s",  "      |          |      ");
	sprintf(lTDownBuilding[10],"%24s", "      |          |      ");
	sprintf(lTDownBuilding[11],"%24s", "      |__________|      ");
	
	uint8_t lTUpBuildingHeight = 12;
	uint8_t lTUpBuildingWidth = 24;
	char lTUpBuilding[lTUpBuildingHeight][lTUpBuildingWidth];
	sprintf(lTUpBuilding[0],"%24s", "        _________       ");
	sprintf(lTUpBuilding[1],"%24s", "       |         |      ");
	sprintf(lTUpBuilding[2],"%24s", "       |         |      ");
	sprintf(lTUpBuilding[3],"%24s", "       |         |      ");
	sprintf(lTUpBuilding[4],"%24s", "       |         |      ");
	sprintf(lTUpBuilding[5],"%24s", "       |         |      ");
	sprintf(lTUpBuilding[6],"%24s", " ______|         |_____ ");
	sprintf(lTUpBuilding[7],"%24s", "|                      |");
	sprintf(lTUpBuilding[8],"%24s", "|                      |");
	sprintf(lTUpBuilding[9],"%24s", "|                      |");
	sprintf(lTUpBuilding[10],"%24s","|                      |");
	sprintf(lTUpBuilding[11],"%24s","|______________________|");

	/* Temp Fix */
	squareBuilding[0][0] = ' ';
	roundBuilding[0][0] = ' ';
	rectLongBuilding[0][0] = ' ';
	rectWideBuilding[0][0] = ' ';
	lTDownBuilding[0][0] = ' ';
	lTLeftBuilding[0][0] = ' ';
	lTRightBuilding[0][0] = ' ';
	lTUpBuilding[0][0] = ' ';
	lUpLeftBuilding[0][0] = ' ';
	lUpRightBuilding[0][0] = ' ';
	lDownLeftBuilding[0][0] = ' ';
	lDownRightBuilding[0][0] = ' ';
	
	printf("There are %u shops\n", numSHOPS);
	printf("There are %d people\n", population);
	printf("There are %d houses\n", population/8);
	int numBuildings = numSHOPS + population/8;
	int currentBuilding = 0;
	printf("There are %d buildings\n",numBuildings);
	int noSuccess = 0;
	while(currentBuilding <= numBuildings){
		int randX = ((rand()%((mapWidth/16)-1))*2)+2+(mapWidth/2-mapWidth/32);
		int randY = ((rand()%((mapHeight/8)-1)))+2+(mapHeight/2-mapHeight/16);
		if (noSuccess > 300){/* Magic Number */
			randX = ((rand()%((mapWidth/2)-1))*2)+2;
			randY = ((rand()%((mapHeight)-1)))+2;
		}
		else if (noSuccess > 210){/* Magic Number */
			randX = ((rand()%((mapWidth/4)-1))*2)+2+(mapWidth/2-mapWidth/8);
			randY = ((rand()%((mapHeight/2)-1)))+2+(mapHeight/2-mapHeight/4);
		}
		else if (noSuccess > 120){/* Magic Number */
			randX = ((rand()%((mapWidth/8)-1))*2)+2+(mapWidth/2-mapWidth/16);
			randY = ((rand()%((mapHeight/4)-1)))+2+(mapHeight/2-mapHeight/8);
		}
		else if (noSuccess > 30){/* Magic Number */
			randX = ((rand()%((mapWidth/10)-1))*2)+2+(mapWidth/2-mapWidth/20);
			randY = ((rand()%((mapHeight/5)-1)))+2+(mapHeight/2-mapHeight/10);
		}
		++noSuccess;
		uint8_t numSimpleBuildingType = 2;
		uint8_t numBuildingTypes = 17;
		uint8_t chooseBuilding = rand()%numBuildingTypes;
		if(currentBuilding < numSHOPS){
			chooseBuilding = rand()%(numBuildingTypes-numSimpleBuildingType)+numSimpleBuildingType;
		}
		switch(chooseBuilding){
			case 0:/* square 25x25 */
			case 1:
				if(randX < (mapWidth-squareBuildingWidth-1)){
					if(randY < (mapHeight-squareBuildingHeight-1)){/* Can fit squareBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')
						   ){
							for (int i = 0; i < squareBuildingHeight; ++i){
								for (int j = 0; j < squareBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==3)&&(j==5)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==3)&&(j==6)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = squareBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = squareBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
						}
					}
					else{/* Cant fits building */
					}
				}
				else{/* Can't fit building */
				}
				break;
			case 2:
				if(randX < (mapWidth-roundBuildingWidth-1)){
					if(randY < (mapHeight-roundBuildingHeight-1)){/* Can fit roundBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')
						){
							for (int i = 0; i < roundBuildingHeight; ++i){
								for (int j = 0; j < roundBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==5)&&(j==9)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==5)&&(j==10)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = roundBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = roundBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
						}
					}
					else{/* Cant fits round building */
					}
				}
				else{/* Can't fit building */
				}
				break;
			case 3:
			case 4:
			case 5:
				if(randX < (mapWidth-rectLongBuildingWidth-1)){
					if(randY < (mapHeight-rectLongBuildingHeight-1)){/* Can fit rectLongBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')
						   ){
							for (int i = 0; i < rectLongBuildingHeight; ++i){
								for (int j = 0; j < rectLongBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==6)&&(j==5)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==6)&&(j==6)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = rectLongBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = rectLongBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 6:
			case 7:
			case 8:
				if(randX < (mapWidth-rectWideBuildingWidth-1)){
					if(randY < (mapHeight-rectWideBuildingHeight-1)){/* Can fit rectWideBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')
						   ){
							
							for (int i = 0; i < rectWideBuildingHeight; ++i){
								for (int j = 0; j < rectWideBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==3)&&(j==11)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==3)&&(j==12)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = rectWideBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = rectWideBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits rectWide building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 9: /* DownLeft */
				if(randX < (mapWidth-lDownLeftBuildingWidth-1)){
					if(randY < (mapHeight-lDownLeftBuildingHeight-1)){/* Can fit lDownLeftBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&(map[randY+6][randX+21]==' ')&&(map[randY+6][randX+22]==' ')&&(map[randY+6][randX+23]==' ')&&(map[randY+6][randX+24]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&(map[randY+7][randX+21]==' ')&&(map[randY+7][randX+22]==' ')&&(map[randY+7][randX+23]==' ')&&(map[randY+7][randX+24]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&(map[randY+8][randX+21]==' ')&&(map[randY+8][randX+22]==' ')&&(map[randY+8][randX+23]==' ')&&(map[randY+8][randX+24]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')&&(map[randY+9][randX+21]==' ')&&(map[randY+9][randX+22]==' ')&&(map[randY+9][randX+23]==' ')&&(map[randY+9][randX+24]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&(map[randY+10][randX+13]==' ')&&(map[randY+10][randX+14]==' ')&&(map[randY+10][randX+15]==' ')&&(map[randY+10][randX+16]==' ')&&(map[randY+10][randX+17]==' ')&&(map[randY+10][randX+18]==' ')&&(map[randY+10][randX+19]==' ')&&(map[randY+10][randX+20]==' ')&&(map[randY+10][randX+21]==' ')&&(map[randY+10][randX+22]==' ')&&(map[randY+10][randX+23]==' ')&&(map[randY+10][randX+24]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')&&(map[randY+11][randX+13]==' ')&&(map[randY+11][randX+14]==' ')&&(map[randY+11][randX+15]==' ')&&(map[randY+11][randX+16]==' ')&&(map[randY+11][randX+17]==' ')&&(map[randY+11][randX+18]==' ')&&(map[randY+11][randX+19]==' ')&&(map[randY+11][randX+20]==' ')&&(map[randY+11][randX+21]==' ')&&(map[randY+11][randX+22]==' ')&&(map[randY+11][randX+23]==' ')&&(map[randY+11][randX+24]==' ')
						   ){
							
							for (int i = 0; i < lDownLeftBuildingHeight; ++i){
								for (int j = 0; j < lDownLeftBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==9)&&(j==16)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==9)&&(j==17)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = lDownLeftBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = lDownLeftBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits lDownLeft building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 10:/* DownRight */
				if(randX < (mapWidth-lDownRightBuildingWidth-1)){
					if(randY < (mapHeight-lDownRightBuildingHeight-1)){/* Can fit lDownRightBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&(map[randY+6][randX+21]==' ')&&(map[randY+6][randX+22]==' ')&&(map[randY+6][randX+23]==' ')&&(map[randY+6][randX+24]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&(map[randY+7][randX+21]==' ')&&(map[randY+7][randX+22]==' ')&&(map[randY+7][randX+23]==' ')&&(map[randY+7][randX+24]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&(map[randY+8][randX+21]==' ')&&(map[randY+8][randX+22]==' ')&&(map[randY+8][randX+23]==' ')&&(map[randY+8][randX+24]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')&&(map[randY+9][randX+21]==' ')&&(map[randY+9][randX+22]==' ')&&(map[randY+9][randX+23]==' ')&&(map[randY+9][randX+24]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&(map[randY+10][randX+13]==' ')&&(map[randY+10][randX+14]==' ')&&(map[randY+10][randX+15]==' ')&&(map[randY+10][randX+16]==' ')&&(map[randY+10][randX+17]==' ')&&(map[randY+10][randX+18]==' ')&&(map[randY+10][randX+19]==' ')&&(map[randY+10][randX+20]==' ')&&(map[randY+10][randX+21]==' ')&&(map[randY+10][randX+22]==' ')&&(map[randY+10][randX+23]==' ')&&(map[randY+10][randX+24]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')&&(map[randY+11][randX+13]==' ')&&(map[randY+11][randX+14]==' ')&&(map[randY+11][randX+15]==' ')&&(map[randY+11][randX+16]==' ')&&(map[randY+11][randX+17]==' ')&&(map[randY+11][randX+18]==' ')&&(map[randY+11][randX+19]==' ')&&(map[randY+11][randX+20]==' ')&&(map[randY+11][randX+21]==' ')&&(map[randY+11][randX+22]==' ')&&(map[randY+11][randX+23]==' ')&&(map[randY+11][randX+24]==' ')
						   ){
							for (int i = 0; i < lDownRightBuildingHeight; ++i){
								for (int j = 0; j < lDownRightBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==9)&&(j==5)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==9)&&(j==6)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = lDownRightBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = lDownRightBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits lDownRight building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 11:/* UpLeft */
				if(randX < (mapWidth-lUpLeftBuildingWidth-1)){
					if(randY < (mapHeight-lUpLeftBuildingHeight-1)){/* Can fit lUpLeftBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&(map[randY+6][randX+21]==' ')&&(map[randY+6][randX+22]==' ')&&(map[randY+6][randX+23]==' ')&&(map[randY+6][randX+24]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&(map[randY+7][randX+21]==' ')&&(map[randY+7][randX+22]==' ')&&(map[randY+7][randX+23]==' ')&&(map[randY+7][randX+24]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&(map[randY+8][randX+21]==' ')&&(map[randY+8][randX+22]==' ')&&(map[randY+8][randX+23]==' ')&&(map[randY+8][randX+24]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')&&(map[randY+9][randX+21]==' ')&&(map[randY+9][randX+22]==' ')&&(map[randY+9][randX+23]==' ')&&(map[randY+9][randX+24]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&(map[randY+10][randX+13]==' ')&&(map[randY+10][randX+14]==' ')&&(map[randY+10][randX+15]==' ')&&(map[randY+10][randX+16]==' ')&&(map[randY+10][randX+17]==' ')&&(map[randY+10][randX+18]==' ')&&(map[randY+10][randX+19]==' ')&&(map[randY+10][randX+20]==' ')&&(map[randY+10][randX+21]==' ')&&(map[randY+10][randX+22]==' ')&&(map[randY+10][randX+23]==' ')&&(map[randY+10][randX+24]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')&&(map[randY+11][randX+13]==' ')&&(map[randY+11][randX+14]==' ')&&(map[randY+11][randX+15]==' ')&&(map[randY+11][randX+16]==' ')&&(map[randY+11][randX+17]==' ')&&(map[randY+11][randX+18]==' ')&&(map[randY+11][randX+19]==' ')&&(map[randY+11][randX+20]==' ')&&(map[randY+11][randX+21]==' ')&&(map[randY+11][randX+22]==' ')&&(map[randY+11][randX+23]==' ')&&(map[randY+11][randX+24]==' ')
						   ){
							
							for (int i = 0; i < lUpLeftBuildingHeight; ++i){
								for (int j = 0; j < lUpLeftBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==3)&&(j==16)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==3)&&(j==17)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = lUpLeftBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = lUpLeftBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits lUpLeft building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 12:/* UpRight */
				if(randX < (mapWidth-lUpRightBuildingWidth-1)){
					if(randY < (mapHeight-lUpRightBuildingHeight-1)){/* Can fit lUpRightBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&(map[randY+6][randX+21]==' ')&&(map[randY+6][randX+22]==' ')&&(map[randY+6][randX+23]==' ')&&(map[randY+6][randX+24]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&(map[randY+7][randX+21]==' ')&&(map[randY+7][randX+22]==' ')&&(map[randY+7][randX+23]==' ')&&(map[randY+7][randX+24]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&(map[randY+8][randX+21]==' ')&&(map[randY+8][randX+22]==' ')&&(map[randY+8][randX+23]==' ')&&(map[randY+8][randX+24]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')&&(map[randY+9][randX+21]==' ')&&(map[randY+9][randX+22]==' ')&&(map[randY+9][randX+23]==' ')&&(map[randY+9][randX+24]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&(map[randY+10][randX+13]==' ')&&(map[randY+10][randX+14]==' ')&&(map[randY+10][randX+15]==' ')&&(map[randY+10][randX+16]==' ')&&(map[randY+10][randX+17]==' ')&&(map[randY+10][randX+18]==' ')&&(map[randY+10][randX+19]==' ')&&(map[randY+10][randX+20]==' ')&&(map[randY+10][randX+21]==' ')&&(map[randY+10][randX+22]==' ')&&(map[randY+10][randX+23]==' ')&&(map[randY+10][randX+24]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')&&(map[randY+11][randX+13]==' ')&&(map[randY+11][randX+14]==' ')&&(map[randY+11][randX+15]==' ')&&(map[randY+11][randX+16]==' ')&&(map[randY+11][randX+17]==' ')&&(map[randY+11][randX+18]==' ')&&(map[randY+11][randX+19]==' ')&&(map[randY+11][randX+20]==' ')&&(map[randY+11][randX+21]==' ')&&(map[randY+11][randX+22]==' ')&&(map[randY+11][randX+23]==' ')&&(map[randY+11][randX+24]==' ')
						   ){
							
							for (int i = 0; i < lUpRightBuildingHeight; ++i){
								for (int j = 0; j < lUpRightBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==3)&&(j==5)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==3)&&(j==6)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = lUpRightBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = lUpRightBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits lUpRight building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 13:
				if(randX < (mapWidth-lTRightBuildingWidth-1)){
					if(randY < (mapHeight-lTRightBuildingHeight-1)){/* Can fit lTRightBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&(map[randY+6][randX+21]==' ')&&(map[randY+6][randX+22]==' ')&&(map[randY+6][randX+23]==' ')&&(map[randY+6][randX+24]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&(map[randY+7][randX+21]==' ')&&(map[randY+7][randX+22]==' ')&&(map[randY+7][randX+23]==' ')&&(map[randY+7][randX+24]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&(map[randY+8][randX+21]==' ')&&(map[randY+8][randX+22]==' ')&&(map[randY+8][randX+23]==' ')&&(map[randY+8][randX+24]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')&&(map[randY+9][randX+21]==' ')&&(map[randY+9][randX+22]==' ')&&(map[randY+9][randX+23]==' ')&&(map[randY+9][randX+24]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&(map[randY+10][randX+13]==' ')&&(map[randY+10][randX+14]==' ')&&(map[randY+10][randX+15]==' ')&&(map[randY+10][randX+16]==' ')&&(map[randY+10][randX+17]==' ')&&(map[randY+10][randX+18]==' ')&&(map[randY+10][randX+19]==' ')&&(map[randY+10][randX+20]==' ')&&(map[randY+10][randX+21]==' ')&&(map[randY+10][randX+22]==' ')&&(map[randY+10][randX+23]==' ')&&(map[randY+10][randX+24]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')&&(map[randY+11][randX+13]==' ')&&(map[randY+11][randX+14]==' ')&&(map[randY+11][randX+15]==' ')&&(map[randY+11][randX+16]==' ')&&(map[randY+11][randX+17]==' ')&&(map[randY+11][randX+18]==' ')&&(map[randY+11][randX+19]==' ')&&(map[randY+11][randX+20]==' ')&&(map[randY+11][randX+21]==' ')&&(map[randY+11][randX+22]==' ')&&(map[randY+11][randX+23]==' ')&&(map[randY+11][randX+24]==' ')
						   ){
							
							for (int i = 0; i < lTRightBuildingHeight; ++i){
								for (int j = 0; j < lTRightBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==6)&&(j==5)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==6)&&(j==6)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = lTRightBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = lTRightBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits lTRight building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 14:
				if(randX < (mapWidth-lTLeftBuildingWidth-1)){
					if(randY < (mapHeight-lTLeftBuildingHeight-1)){/* Can fit lTLeftBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&(map[randY+6][randX+21]==' ')&&(map[randY+6][randX+22]==' ')&&(map[randY+6][randX+23]==' ')&&(map[randY+6][randX+24]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&(map[randY+7][randX+21]==' ')&&(map[randY+7][randX+22]==' ')&&(map[randY+7][randX+23]==' ')&&(map[randY+7][randX+24]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&(map[randY+8][randX+21]==' ')&&(map[randY+8][randX+22]==' ')&&(map[randY+8][randX+23]==' ')&&(map[randY+8][randX+24]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')&&(map[randY+9][randX+21]==' ')&&(map[randY+9][randX+22]==' ')&&(map[randY+9][randX+23]==' ')&&(map[randY+9][randX+24]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&(map[randY+10][randX+13]==' ')&&(map[randY+10][randX+14]==' ')&&(map[randY+10][randX+15]==' ')&&(map[randY+10][randX+16]==' ')&&(map[randY+10][randX+17]==' ')&&(map[randY+10][randX+18]==' ')&&(map[randY+10][randX+19]==' ')&&(map[randY+10][randX+20]==' ')&&(map[randY+10][randX+21]==' ')&&(map[randY+10][randX+22]==' ')&&(map[randY+10][randX+23]==' ')&&(map[randY+10][randX+24]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')&&(map[randY+11][randX+13]==' ')&&(map[randY+11][randX+14]==' ')&&(map[randY+11][randX+15]==' ')&&(map[randY+11][randX+16]==' ')&&(map[randY+11][randX+17]==' ')&&(map[randY+11][randX+18]==' ')&&(map[randY+11][randX+19]==' ')&&(map[randY+11][randX+20]==' ')&&(map[randY+11][randX+21]==' ')&&(map[randY+11][randX+22]==' ')&&(map[randY+11][randX+23]==' ')&&(map[randY+11][randX+24]==' ')
						   ){
							
							for (int i = 0; i < lTLeftBuildingHeight; ++i){
								for (int j = 0; j < lTLeftBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==6)&&(j==16)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==6)&&(j==17)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = lTLeftBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = lTLeftBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits lTLeft building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 15:
				if(randX < (mapWidth-lTUpBuildingWidth-1)){
					if(randY < (mapHeight-lTUpBuildingHeight-1)){/* Can fit lTUpBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&(map[randY+6][randX+21]==' ')&&(map[randY+6][randX+22]==' ')&&(map[randY+6][randX+23]==' ')&&(map[randY+6][randX+24]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&(map[randY+7][randX+21]==' ')&&(map[randY+7][randX+22]==' ')&&(map[randY+7][randX+23]==' ')&&(map[randY+7][randX+24]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&(map[randY+8][randX+21]==' ')&&(map[randY+8][randX+22]==' ')&&(map[randY+8][randX+23]==' ')&&(map[randY+8][randX+24]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')&&(map[randY+9][randX+21]==' ')&&(map[randY+9][randX+22]==' ')&&(map[randY+9][randX+23]==' ')&&(map[randY+9][randX+24]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&(map[randY+10][randX+13]==' ')&&(map[randY+10][randX+14]==' ')&&(map[randY+10][randX+15]==' ')&&(map[randY+10][randX+16]==' ')&&(map[randY+10][randX+17]==' ')&&(map[randY+10][randX+18]==' ')&&(map[randY+10][randX+19]==' ')&&(map[randY+10][randX+20]==' ')&&(map[randY+10][randX+21]==' ')&&(map[randY+10][randX+22]==' ')&&(map[randY+10][randX+23]==' ')&&(map[randY+10][randX+24]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')&&(map[randY+11][randX+13]==' ')&&(map[randY+11][randX+14]==' ')&&(map[randY+11][randX+15]==' ')&&(map[randY+11][randX+16]==' ')&&(map[randY+11][randX+17]==' ')&&(map[randY+11][randX+18]==' ')&&(map[randY+11][randX+19]==' ')&&(map[randY+11][randX+20]==' ')&&(map[randY+11][randX+21]==' ')&&(map[randY+11][randX+22]==' ')&&(map[randY+11][randX+23]==' ')&&(map[randY+11][randX+24]==' ')
						   ){
							
							for (int i = 0; i < lTUpBuildingHeight; ++i){
								for (int j = 0; j < lTUpBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==9)&&(j==11)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==9)&&(j==12)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = lTUpBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = lTUpBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits lTUp building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			case 16:
				if(randX < (mapWidth-lTDownBuildingWidth-1)){
					if(randY < (mapHeight-lTDownBuildingHeight-1)){/* Can fit lTDownBuilding in map */
						if (
							(map[randY][randX-1]==' ')&&(map[randY][randX]==' ')&&(map[randY][randX+1]==' ')&&(map[randY][randX+2]==' ')&&(map[randY][randX+3]==' ')&&(map[randY][randX+4]==' ')&&(map[randY][randX+5]==' ')&&(map[randY][randX+6]==' ')&&(map[randY][randX+7]==' ')&&(map[randY][randX+8]==' ')&&(map[randY][randX+9]==' ')&&(map[randY][randX+10]==' ')&&(map[randY][randX+11]==' ')&&(map[randY][randX+12]==' ')&&(map[randY][randX+13]==' ')&&(map[randY][randX+14]==' ')&&(map[randY][randX+15]==' ')&&(map[randY][randX+16]==' ')&&(map[randY][randX+17]==' ')&&(map[randY][randX+18]==' ')&&(map[randY][randX+19]==' ')&&(map[randY][randX+20]==' ')&&(map[randY][randX+21]==' ')&&(map[randY][randX+22]==' ')&&(map[randY][randX+23]==' ')&&(map[randY][randX+24]==' ')&&
							(map[randY+1][randX-1]==' ')&&(map[randY+1][randX]==' ')&&(map[randY+1][randX+1]==' ')&&(map[randY+1][randX+2]==' ')&&(map[randY+1][randX+3]==' ')&&(map[randY+1][randX+4]==' ')&&(map[randY+1][randX+5]==' ')&&(map[randY+1][randX+6]==' ')&&(map[randY+1][randX+7]==' ')&&(map[randY+1][randX+8]==' ')&&(map[randY+1][randX+9]==' ')&&(map[randY+1][randX+10]==' ')&&(map[randY+1][randX+11]==' ')&&(map[randY+1][randX+12]==' ')&&(map[randY+1][randX+13]==' ')&&(map[randY+1][randX+14]==' ')&&(map[randY+1][randX+15]==' ')&&(map[randY+1][randX+16]==' ')&&(map[randY+1][randX+17]==' ')&&(map[randY+1][randX+18]==' ')&&(map[randY+1][randX+19]==' ')&&(map[randY+1][randX+20]==' ')&&(map[randY+1][randX+21]==' ')&&(map[randY+1][randX+22]==' ')&&(map[randY+1][randX+23]==' ')&&(map[randY+1][randX+24]==' ')&&
							(map[randY+2][randX-1]==' ')&&(map[randY+2][randX]==' ')&&(map[randY+2][randX+1]==' ')&&(map[randY+2][randX+2]==' ')&&(map[randY+2][randX+3]==' ')&&(map[randY+2][randX+4]==' ')&&(map[randY+2][randX+5]==' ')&&(map[randY+2][randX+6]==' ')&&(map[randY+2][randX+7]==' ')&&(map[randY+2][randX+8]==' ')&&(map[randY+2][randX+9]==' ')&&(map[randY+2][randX+10]==' ')&&(map[randY+2][randX+11]==' ')&&(map[randY+2][randX+12]==' ')&&(map[randY+2][randX+13]==' ')&&(map[randY+2][randX+14]==' ')&&(map[randY+2][randX+15]==' ')&&(map[randY+2][randX+16]==' ')&&(map[randY+2][randX+17]==' ')&&(map[randY+2][randX+18]==' ')&&(map[randY+2][randX+19]==' ')&&(map[randY+2][randX+20]==' ')&&(map[randY+2][randX+21]==' ')&&(map[randY+2][randX+22]==' ')&&(map[randY+2][randX+23]==' ')&&(map[randY+2][randX+24]==' ')&&
							(map[randY+3][randX-1]==' ')&&(map[randY+3][randX]==' ')&&(map[randY+3][randX+1]==' ')&&(map[randY+3][randX+2]==' ')&&(map[randY+3][randX+3]==' ')&&(map[randY+3][randX+4]==' ')&&(map[randY+3][randX+5]==' ')&&(map[randY+3][randX+6]==' ')&&(map[randY+3][randX+7]==' ')&&(map[randY+3][randX+8]==' ')&&(map[randY+3][randX+9]==' ')&&(map[randY+3][randX+10]==' ')&&(map[randY+3][randX+11]==' ')&&(map[randY+3][randX+12]==' ')&&(map[randY+3][randX+13]==' ')&&(map[randY+3][randX+14]==' ')&&(map[randY+3][randX+15]==' ')&&(map[randY+3][randX+16]==' ')&&(map[randY+3][randX+17]==' ')&&(map[randY+3][randX+18]==' ')&&(map[randY+3][randX+19]==' ')&&(map[randY+3][randX+20]==' ')&&(map[randY+3][randX+21]==' ')&&(map[randY+3][randX+22]==' ')&&(map[randY+3][randX+23]==' ')&&(map[randY+3][randX+24]==' ')&&
							(map[randY+4][randX-1]==' ')&&(map[randY+4][randX]==' ')&&(map[randY+4][randX+1]==' ')&&(map[randY+4][randX+2]==' ')&&(map[randY+4][randX+3]==' ')&&(map[randY+4][randX+4]==' ')&&(map[randY+4][randX+5]==' ')&&(map[randY+4][randX+6]==' ')&&(map[randY+4][randX+7]==' ')&&(map[randY+4][randX+8]==' ')&&(map[randY+4][randX+9]==' ')&&(map[randY+4][randX+10]==' ')&&(map[randY+4][randX+11]==' ')&&(map[randY+4][randX+12]==' ')&&(map[randY+4][randX+13]==' ')&&(map[randY+4][randX+14]==' ')&&(map[randY+4][randX+15]==' ')&&(map[randY+4][randX+16]==' ')&&(map[randY+4][randX+17]==' ')&&(map[randY+4][randX+18]==' ')&&(map[randY+4][randX+19]==' ')&&(map[randY+4][randX+20]==' ')&&(map[randY+4][randX+21]==' ')&&(map[randY+4][randX+22]==' ')&&(map[randY+4][randX+23]==' ')&&(map[randY+4][randX+24]==' ')&&
							(map[randY+5][randX-1]==' ')&&(map[randY+5][randX]==' ')&&(map[randY+5][randX+1]==' ')&&(map[randY+5][randX+2]==' ')&&(map[randY+5][randX+3]==' ')&&(map[randY+5][randX+4]==' ')&&(map[randY+5][randX+5]==' ')&&(map[randY+5][randX+6]==' ')&&(map[randY+5][randX+7]==' ')&&(map[randY+5][randX+8]==' ')&&(map[randY+5][randX+9]==' ')&&(map[randY+5][randX+10]==' ')&&(map[randY+5][randX+11]==' ')&&(map[randY+5][randX+12]==' ')&&(map[randY+5][randX+13]==' ')&&(map[randY+5][randX+14]==' ')&&(map[randY+5][randX+15]==' ')&&(map[randY+5][randX+16]==' ')&&(map[randY+5][randX+17]==' ')&&(map[randY+5][randX+18]==' ')&&(map[randY+5][randX+19]==' ')&&(map[randY+5][randX+20]==' ')&&(map[randY+5][randX+21]==' ')&&(map[randY+5][randX+22]==' ')&&(map[randY+5][randX+23]==' ')&&(map[randY+5][randX+24]==' ')&&
							(map[randY+6][randX-1]==' ')&&(map[randY+6][randX]==' ')&&(map[randY+6][randX+1]==' ')&&(map[randY+6][randX+2]==' ')&&(map[randY+6][randX+3]==' ')&&(map[randY+6][randX+4]==' ')&&(map[randY+6][randX+5]==' ')&&(map[randY+6][randX+6]==' ')&&(map[randY+6][randX+7]==' ')&&(map[randY+6][randX+8]==' ')&&(map[randY+6][randX+9]==' ')&&(map[randY+6][randX+10]==' ')&&(map[randY+6][randX+11]==' ')&&(map[randY+6][randX+12]==' ')&&(map[randY+6][randX+13]==' ')&&(map[randY+6][randX+14]==' ')&&(map[randY+6][randX+15]==' ')&&(map[randY+6][randX+16]==' ')&&(map[randY+6][randX+17]==' ')&&(map[randY+6][randX+18]==' ')&&(map[randY+6][randX+19]==' ')&&(map[randY+6][randX+20]==' ')&&(map[randY+6][randX+21]==' ')&&(map[randY+6][randX+22]==' ')&&(map[randY+6][randX+23]==' ')&&(map[randY+6][randX+24]==' ')&&
							(map[randY+7][randX-1]==' ')&&(map[randY+7][randX]==' ')&&(map[randY+7][randX+1]==' ')&&(map[randY+7][randX+2]==' ')&&(map[randY+7][randX+3]==' ')&&(map[randY+7][randX+4]==' ')&&(map[randY+7][randX+5]==' ')&&(map[randY+7][randX+6]==' ')&&(map[randY+7][randX+7]==' ')&&(map[randY+7][randX+8]==' ')&&(map[randY+7][randX+9]==' ')&&(map[randY+7][randX+10]==' ')&&(map[randY+7][randX+11]==' ')&&(map[randY+7][randX+12]==' ')&&(map[randY+7][randX+13]==' ')&&(map[randY+7][randX+14]==' ')&&(map[randY+7][randX+15]==' ')&&(map[randY+7][randX+16]==' ')&&(map[randY+7][randX+17]==' ')&&(map[randY+7][randX+18]==' ')&&(map[randY+7][randX+19]==' ')&&(map[randY+7][randX+20]==' ')&&(map[randY+7][randX+21]==' ')&&(map[randY+7][randX+22]==' ')&&(map[randY+7][randX+23]==' ')&&(map[randY+7][randX+24]==' ')&&
							(map[randY+8][randX-1]==' ')&&(map[randY+8][randX]==' ')&&(map[randY+8][randX+1]==' ')&&(map[randY+8][randX+2]==' ')&&(map[randY+8][randX+3]==' ')&&(map[randY+8][randX+4]==' ')&&(map[randY+8][randX+5]==' ')&&(map[randY+8][randX+6]==' ')&&(map[randY+8][randX+7]==' ')&&(map[randY+8][randX+8]==' ')&&(map[randY+8][randX+9]==' ')&&(map[randY+8][randX+10]==' ')&&(map[randY+8][randX+11]==' ')&&(map[randY+8][randX+12]==' ')&&(map[randY+8][randX+13]==' ')&&(map[randY+8][randX+14]==' ')&&(map[randY+8][randX+15]==' ')&&(map[randY+8][randX+16]==' ')&&(map[randY+8][randX+17]==' ')&&(map[randY+8][randX+18]==' ')&&(map[randY+8][randX+19]==' ')&&(map[randY+8][randX+20]==' ')&&(map[randY+8][randX+21]==' ')&&(map[randY+8][randX+22]==' ')&&(map[randY+8][randX+23]==' ')&&(map[randY+8][randX+24]==' ')&&
							(map[randY+9][randX-1]==' ')&&(map[randY+9][randX]==' ')&&(map[randY+9][randX+1]==' ')&&(map[randY+9][randX+2]==' ')&&(map[randY+9][randX+3]==' ')&&(map[randY+9][randX+4]==' ')&&(map[randY+9][randX+5]==' ')&&(map[randY+9][randX+6]==' ')&&(map[randY+9][randX+7]==' ')&&(map[randY+9][randX+8]==' ')&&(map[randY+9][randX+9]==' ')&&(map[randY+9][randX+10]==' ')&&(map[randY+9][randX+11]==' ')&&(map[randY+9][randX+12]==' ')&&(map[randY+9][randX+13]==' ')&&(map[randY+9][randX+14]==' ')&&(map[randY+9][randX+15]==' ')&&(map[randY+9][randX+16]==' ')&&(map[randY+9][randX+17]==' ')&&(map[randY+9][randX+18]==' ')&&(map[randY+9][randX+19]==' ')&&(map[randY+9][randX+20]==' ')&&(map[randY+9][randX+21]==' ')&&(map[randY+9][randX+22]==' ')&&(map[randY+9][randX+23]==' ')&&(map[randY+9][randX+24]==' ')&&
							(map[randY+10][randX-1]==' ')&&(map[randY+10][randX]==' ')&&(map[randY+10][randX+1]==' ')&&(map[randY+10][randX+2]==' ')&&(map[randY+10][randX+3]==' ')&&(map[randY+10][randX+4]==' ')&&(map[randY+10][randX+5]==' ')&&(map[randY+10][randX+6]==' ')&&(map[randY+10][randX+7]==' ')&&(map[randY+10][randX+8]==' ')&&(map[randY+10][randX+9]==' ')&&(map[randY+10][randX+10]==' ')&&(map[randY+10][randX+11]==' ')&&(map[randY+10][randX+12]==' ')&&(map[randY+10][randX+13]==' ')&&(map[randY+10][randX+14]==' ')&&(map[randY+10][randX+15]==' ')&&(map[randY+10][randX+16]==' ')&&(map[randY+10][randX+17]==' ')&&(map[randY+10][randX+18]==' ')&&(map[randY+10][randX+19]==' ')&&(map[randY+10][randX+20]==' ')&&(map[randY+10][randX+21]==' ')&&(map[randY+10][randX+22]==' ')&&(map[randY+10][randX+23]==' ')&&(map[randY+10][randX+24]==' ')&&
							(map[randY+11][randX-1]==' ')&&(map[randY+11][randX]==' ')&&(map[randY+11][randX+1]==' ')&&(map[randY+11][randX+2]==' ')&&(map[randY+11][randX+3]==' ')&&(map[randY+11][randX+4]==' ')&&(map[randY+11][randX+5]==' ')&&(map[randY+11][randX+6]==' ')&&(map[randY+11][randX+7]==' ')&&(map[randY+11][randX+8]==' ')&&(map[randY+11][randX+9]==' ')&&(map[randY+11][randX+10]==' ')&&(map[randY+11][randX+11]==' ')&&(map[randY+11][randX+12]==' ')&&(map[randY+11][randX+13]==' ')&&(map[randY+11][randX+14]==' ')&&(map[randY+11][randX+15]==' ')&&(map[randY+11][randX+16]==' ')&&(map[randY+11][randX+17]==' ')&&(map[randY+11][randX+18]==' ')&&(map[randY+11][randX+19]==' ')&&(map[randY+11][randX+20]==' ')&&(map[randY+11][randX+21]==' ')&&(map[randY+11][randX+22]==' ')&&(map[randY+11][randX+23]==' ')&&(map[randY+11][randX+24]==' ')
						   ){
							
							for (int i = 0; i < lTDownBuildingHeight; ++i){
								for (int j = 0; j < lTDownBuildingWidth; ++j){
									if (currentBuilding < numSHOPS){
										if((i==3)&&(j==11)){
											myitoa(currentBuilding/10,&map[i+randY][j+randX]);
										}
										else if((i==3)&&(j==12)){
											myitoa(currentBuilding%10,&map[i+randY][j+randX]);
										}
										else{
											map[i+randY][j+randX] = lTDownBuilding[i][j];
										}
									}
									else{
										map[i+randY][j+randX] = lTDownBuilding[i][j];
									}
								}
							}	
							++currentBuilding;
							--noSuccess;
						}
						else{/* Space not empty */
							
						}
					}
					else{/* Cant fits lTDown building */
						
					}
				}
				else{/* Can't fit building */
					
				}
				break;
			default:
				break;
		}
	}
	/************************************************/
	/* Add . in blank space                         */
	uint8_t inside = 0;
	for (int i = 1; i <mapHeight-1; i+=1){
		for (int j = 0; j < mapWidth; j+=1){
			if(map[i][j] == '|'){
				inside = !inside;
			}
			if (!inside){
				if ((map[i][j] == ' ')&&(j%2)){
					map[i][j] = '.';
				}
			}
		}
	}
	
	/************************************************/
	/* Print Map                                    */
	for (int i = 0; i < mapHeight; ++i){
		for (int j = 0; j < mapWidth; ++j){
			fprintf(townMapFile,"%c", map[i][j]);
		}
		fprintf(townMapFile, "\n");
	}
	fclose(townMapFile);
	printf("Map has been generated\n");
	/* Open two files to be merged */
	townMapFile = fopen(mapFilename, "r");
	townFile = fopen(townFileName, "r");
	
	/* Open file to store the result */
	printf("Town stored at: %s\nMap stored at: %s\n",townFileName, mapFilename);
	strcat(token,"Settlement.txt");
	printf("Combined stored at: %s\n",token);
	FILE *fullFile = fopen(token, "w");
	char c;
 
	if (townFile == NULL || townMapFile == NULL || fullFile == NULL)
	{
        printf("ERROR WITH FILENAMES\n");
        exit(0);
	}
 
	while ((c = fgetc(townMapFile)) != EOF)
		fputc(c, fullFile);
	fputs("\n\n",fullFile);
	while ((c = fgetc(townFile)) != EOF)
		fputc(c, fullFile);
   
	fclose(townMapFile);
	fclose(townFile);
	fclose(fullFile);
	
	printf("Full Settlement has been generated\n");
	
}