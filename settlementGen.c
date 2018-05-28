#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "shopGen.c"

#define NAME_LENGTH 32

//////////
// How to format shopgen command
//shopGen(<FILENAME>,<SHOPNUM>,<FLAGS>, rand());
//////////
// Shop Guide
//"00 - Adventurer's Emporium
//"01 - Alchemist's Shop
//"02 - Arcana Shop
//"03 - Bakery
//"04 - Barber
//"05 - Blacksmith
//"06 - Bookstore
//"07 - Butcher's Shop
//"08 - Fletcher
//"09 - General Store
//"10 - Leatherworker's Shop
//"11 - Music Store
//"12 - Tailor
//"13 - Tavern
//"14 - Shrine
//"15 - Jeweler
//////////
// Flags Guide
//"Bit 00 - Magical
//"Bit 01 - Costal
//"Bit 02 - Rich
//"Bit 03 - Exotic
//"Bit 04 - Frontier
//"Bit 05 - Forest
//"Bit 06 - Industrial
//"Bit 07 - Mining
//"Bit 08 - Pious
//"Bit 09 - Agriculture
//"Bit 10 - Rural
//"Bit 11 - Urban

void settlementCommandReminder(){
	printf(".\\programName <storageLoc.txt> <flags>\n");
	printf("Supported Flags are:\n");
	printf("Bit 00 - Magical\n");
	printf("Bit 01 - Costal\n");
	printf("Bit 02 - Rich\n");
	printf("Bit 03 - Exotic\n");
	printf("Bit 04 - Frontier\n");
	printf("Bit 05 - Forest\n");
	printf("Bit 06 - Industrial\n");
	printf("Bit 07 - Mining\n");
	printf("Bit 08 - Pious\n");
    printf("Bit 09 - Agriculture\n");
	printf("Bit 10 - Rural\n");
	printf("Bit 11 - Urban\n");
	printf("I.E. a magical frontier forest would be 31\n");
}

void townnameGen(FILE * storeHere){
	uint8_t numFirst = 57;
	char first[numFirst][NAME_LENGTH];
	strcpy(first[0],"Milwau");
	strcpy(first[1],"Madi");
	strcpy(first[2],"Keno");
	strcpy(first[3],"Green");
	strcpy(first[4],"Blue");
	strcpy(first[5],"Red");
	strcpy(first[6],"Yellow");
	strcpy(first[7],"Wauke");
	strcpy(first[8],"Osh");
	strcpy(first[9],"Winne");
	strcpy(first[10],"Champ");
	strcpy(first[11],"Chica");
	strcpy(first[12],"Urban");
	strcpy(first[13],"Winth");
	strcpy(first[14],"Winne");
	strcpy(first[15],"Lond");
	strcpy(first[16],"Up");
	strcpy(first[17],"Eden");
	strcpy(first[18],"Edin");
	strcpy(first[19],"Ham");
	strcpy(first[20],"Minne");
	strcpy(first[21],"Rock");
	strcpy(first[21],"River");
	strcpy(first[23],"Spring");
	strcpy(first[24],"Aur");
	strcpy(first[25],"Joil");
	strcpy(first[26],"Elg");
	strcpy(first[27],"Peor");
	strcpy(first[28],"Rac");
	strcpy(first[29],"Sup");
	strcpy(first[30],"Du");
	strcpy(first[31],"Roch");
	strcpy(first[32],"Dul");
	strcpy(first[33],"Mad");
	strcpy(first[34],"Dun");
	strcpy(first[35],"Kin");
	strcpy(first[36],"Ler");
	strcpy(first[37],"Orrin");
	strcpy(first[38],"Maccels");
	strcpy(first[39],"Skarg");
	strcpy(first[40],"Bull");
	strcpy(first[41],"Black");
	strcpy(first[42],"Jarl");
	strcpy(first[43],"Knight");
	strcpy(first[44],"Earth");
	strcpy(first[45],"Old");
	strcpy(first[46],"New");
	strcpy(first[47],"North");
	strcpy(first[48],"South");
	strcpy(first[49],"East");
	strcpy(first[50],"West");
	strcpy(first[51],"Dame");
	strcpy(first[52],"Storm");
	strcpy(first[53],"White");
	strcpy(first[54],"Mud");
	strcpy(first[55],"Burr");
	strcpy(first[56],"Mack");
	
	uint8_t numLast = 57;
	char last[numLast][NAME_LENGTH];
	strcpy(last[0],"ton");
	strcpy(last[1],"in");
	strcpy(last[2],"ville");
	strcpy(last[3],"shire");
	strcpy(last[4],"on");
	strcpy(last[5],"field");
	strcpy(last[6],"town");
	strcpy(last[7],"sha");
	strcpy(last[8],"ine");
	strcpy(last[9],"ton");
	strcpy(last[10],"kee");
	strcpy(last[11],"go");
	strcpy(last[12],"ion");
	strcpy(last[13],"an");
	strcpy(last[14],"son");
	strcpy(last[15],"gan");
	strcpy(last[16],"ing");
	strcpy(last[17],"ane");
	strcpy(last[18],"ay");
	strcpy(last[19],"sin");
	strcpy(last[20],"field");
	strcpy(last[21],"aire");
	strcpy(last[22],"osh");
	strcpy(last[23],"ago");
	strcpy(last[24],"land");
	strcpy(last[25],"mer");
	strcpy(last[26],"ange");
	strcpy(last[27],"ana");
	strcpy(last[28],"port");
	strcpy(last[29],"rop");
	strcpy(last[30],"borough");
	strcpy(last[31],"polis");
	strcpy(last[32],"ford");
	strcpy(last[33],"fort");
	strcpy(last[34],"dem");
	strcpy(last[35],"ora");
	strcpy(last[36],"et");
	strcpy(last[37],"aign");
	strcpy(last[38],"ia");
	strcpy(last[39],"ois");
	strcpy(last[40],"ota");
	strcpy(last[41],"uth");
	strcpy(last[42],"burg");
	strcpy(last[43],"castel");
	strcpy(last[44],"wich");
	strcpy(last[45],"caster");
	strcpy(last[46],"stey");
	strcpy(last[47],"ick");
	strcpy(last[48],"ness");
	strcpy(last[49],"run");
	strcpy(last[50],"scar");
	strcpy(last[51],"vein");
	strcpy(last[52],"garde");
	strcpy(last[53],"wind");
	strcpy(last[54],"cliffe");
	strcpy(last[55],"shade");
	strcpy(last[56],"holde");
	
	fprintf(storeHere,"%s%s\n", first[rand()%numFirst],last[rand()%numLast]);
}	


int main(int argc, char* argv[]){
	if (argc != 3){
		settlementCommandReminder();
		return -1;
	}
	char* filename = argv[1];
	FILE * townFile = fopen(filename, "w+");
	uint16_t flags = atoi(argv[2]);
	srand(time(NULL));
	
	char townFileName[64];
	strcpy(townFileName, filename);
	
	uint8_t doMe = 1;
	uint8_t settlementSize = (rand()%20)+1;
	
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
	int population;
	if(settlementSize == 20){
		if (((rand()%20)+1)>15){
			fprintf(townFile, "The City of ");
			townnameGen(townFile);
			population = ((rand()%5)+1)*10*settlementSize*5;
			population += ((rand()%5)+1)*10*settlementSize*5;
			population += ((rand()%5)+1)*10*settlementSize*5;
			population += ((rand()%5)+1)*10*settlementSize*5;
			population += rand()%1000;
			fprintf(townFile, "Population: %d\n\n\n",population);
			fclose(townFile);
			uint8_t shopAmount = (settlementSize/3)*(rand()%4+rand()%4+5);
			for (int i = 0; i < shopAmount; ++i){
				uint8_t shopnum = 0;
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
			doMe = 0;
		}
		else{
			
		}
	}
	if (doMe){
		population = (abs(rand()%8)+1)*10*settlementSize;
		if (population < 500){
			fprintf(townFile, "The Village of ");
		}
		else{
			fprintf(townFile, "The Town of ");
		}
		townnameGen(townFile);
		fprintf(townFile, "Population: %d\n\n\n",population);
		fclose(townFile);
		uint8_t shopAmount = (settlementSize/3)+3;
		for (int i = 0; i < shopAmount; ++i){
			uint8_t shopnum = 0;
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
		shopGen(filename, 0, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numALC; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 1, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numARC; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 2, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBAK; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 3, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBRB; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 4, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBLK; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 5, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBOK; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 6, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBCH; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 7, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numFLC; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 8, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numGEN; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 9, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numLEA; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 10, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numMUS; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 11, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numTLR; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 12, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numTVN; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 13, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numSRN; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 14, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numJWL; ++i){
		townFile = fopen(filename, "a+");
		fprintf(townFile, "BUILDING %02d\n", currentShopPrinting);
		fclose(townFile);
		++currentShopPrinting;
		shopGen(filename, 15, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	printf("Settlement has been generated\n");
	// End of city generation
	// Number of buildings to number
	// print a * border
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
	FILE * townMapFile = fopen(mapFilename, "w+");
	// Make Border
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
	//////////
	// Place Roads and Rivers
	
	uint8_t numRoadRiv = (rand()%4)+2;
	if (settlementSize == 20){
		++numRoadRiv;
	}
	uint8_t hasRiver = 0;
	for (int i = 0; i < numRoadRiv; ++i){
		uint8_t startSide = rand()%3;
		int startX = 0;
		int startY = 0;
		uint8_t riverRoad = rand()%3;
		switch(startSide){
			case 0://North
				startX = rand()%(mapWidth/4)*2+(mapWidth/4);
				startY = 2;
				while((startX < mapWidth-8)&&(startX > 7)&&(startY <= mapHeight-3)&&(startY >= 2)){
					if((riverRoad)||(hasRiver>1)){//road
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
					else{//river
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
			case 1://South
				startX = rand()%(mapWidth/4)*2+(mapWidth/4);
				startY = mapHeight-3;
				while((startX <= mapWidth-4)&&(startX >= 3)&&(startY <= mapHeight-3)&&(startY >= 2)){
					if((riverRoad)||(hasRiver>1)){//road
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
					else{//river
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
			case 2://East
				startX = 3;
				startY = rand()%(mapHeight/2)+(mapHeight/4);
				while((startX <= mapWidth-4)&&(startX >= 3)&&(startY <= mapHeight-3)&&(startY >= 2)){
					if((riverRoad)||(hasRiver>1)){//road
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
					else{//river
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
			case 3://West
				startX = mapWidth-4;
				startY = rand()%(mapHeight/2)+(mapHeight/4);
				while((startX <= mapWidth-4)&&(startX >= 3)&&(startY <= mapHeight-3)&&(startY >= 2)){
					if((riverRoad)||(hasRiver>1)){//road
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
					else{//river
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
	
	//////////
	// Place Buildings
	
	uint8_t squareBuildingHeight = 6;
	uint8_t squareBuildingWidth = 12;
	char squareBuilding[squareBuildingHeight][squareBuildingWidth];
	strcpy(squareBuilding[0], " __________ ");
	strcpy(squareBuilding[1], "|          |");
	strcpy(squareBuilding[2], "|          |");
	strcpy(squareBuilding[3], "|          |");
	strcpy(squareBuilding[4], "|          |");
	strcpy(squareBuilding[5], "|__________|");
	
	uint8_t rectLongBuildingHeight = 12;
	uint8_t rectLongBuildingWidth = 12;
	char rectLongBuilding[rectLongBuildingHeight][rectLongBuildingWidth];
	strcpy(rectLongBuilding[0],  " __________ ");
	strcpy(rectLongBuilding[1],  "|          |");
	strcpy(rectLongBuilding[2],  "|          |");
	strcpy(rectLongBuilding[3],  "|          |");
	strcpy(rectLongBuilding[4],  "|          |");
	strcpy(rectLongBuilding[5],  "|          |");
	strcpy(rectLongBuilding[6],  "|          |");
	strcpy(rectLongBuilding[7],  "|          |");
	strcpy(rectLongBuilding[8],  "|          |");
	strcpy(rectLongBuilding[9],  "|          |");
	strcpy(rectLongBuilding[10], "|          |");
	strcpy(rectLongBuilding[11], "|__________|");
	
	uint8_t rectWideBuildingHeight = 6;
	uint8_t rectWideBuildingWidth = 24;
	char rectWideBuilding[rectWideBuildingHeight][rectWideBuildingWidth];
	strcpy(rectWideBuilding[0], " ______________________ ");
	strcpy(rectWideBuilding[1], "|                      |");
	strcpy(rectWideBuilding[2], "|                      |");
	strcpy(rectWideBuilding[3], "|                      |");
	strcpy(rectWideBuilding[4], "|                      |");
	strcpy(rectWideBuilding[5], "|______________________|");
	
	uint8_t lDownLeftBuildingHeight = 12;
	uint8_t lDownLeftBuildingWidth = 24;
	char lDownLeftBuilding[lDownLeftBuildingHeight][lDownLeftBuildingWidth];
	strcpy(lDownLeftBuilding[0],  "             __________ ");
	strcpy(lDownLeftBuilding[1],  "            |          |");
	strcpy(lDownLeftBuilding[2],  "            |          |");
	strcpy(lDownLeftBuilding[3],  "            |          |");
	strcpy(lDownLeftBuilding[4],  "            |          |");
	strcpy(lDownLeftBuilding[5],  "            |          |");
	strcpy(lDownLeftBuilding[6],  " ___________|          |");
	strcpy(lDownLeftBuilding[7],  "|                      |");
	strcpy(lDownLeftBuilding[8],  "|                      |");
	strcpy(lDownLeftBuilding[9],  "|                      |");
	strcpy(lDownLeftBuilding[10], "|                      |");
	strcpy(lDownLeftBuilding[11], "|______________________|");
	
	uint8_t lDownRightBuildingHeight = 12;
	uint8_t lDownRightBuildingWidth = 24;
	char lDownRightBuilding[lDownRightBuildingHeight][lDownRightBuildingWidth];
	strcpy(lDownRightBuilding[0],  " __________            ");
	strcpy(lDownRightBuilding[1],  "|          |           ");
	strcpy(lDownRightBuilding[2],  "|          |           ");
	strcpy(lDownRightBuilding[3],  "|          |           ");
	strcpy(lDownRightBuilding[4],  "|          |           ");
	strcpy(lDownRightBuilding[5],  "|          |           ");
	strcpy(lDownRightBuilding[6],  "|          |___________");
	strcpy(lDownRightBuilding[7],  "|                      |");
	strcpy(lDownRightBuilding[8],  "|                      |");
	strcpy(lDownRightBuilding[9],  "|                      |");
	strcpy(lDownRightBuilding[10], "|                      |");
	strcpy(lDownRightBuilding[11], "|______________________|");
	
	uint8_t lUpLeftBuildingHeight = 12;
	uint8_t lUpLeftBuildingWidth = 24;
	char lUpLeftBuilding[lUpLeftBuildingHeight][lUpLeftBuildingWidth];
	strcpy(lUpLeftBuilding[0],  " ______________________ ");
	strcpy(lUpLeftBuilding[1],  "|                      |");
	strcpy(lUpLeftBuilding[2],  "|                      |");
	strcpy(lUpLeftBuilding[3],  "|                      |");
	strcpy(lUpLeftBuilding[4],  "|                      |");
	strcpy(lUpLeftBuilding[5],  "|___________           |");
	strcpy(lUpLeftBuilding[6],  "            |          |");
	strcpy(lUpLeftBuilding[7],  "            |          |");
	strcpy(lUpLeftBuilding[8],  "            |          |");
	strcpy(lUpLeftBuilding[9],  "            |          |");
	strcpy(lUpLeftBuilding[10], "            |          |");
	strcpy(lUpLeftBuilding[11], "            |__________|");
	
	uint8_t lUpRightBuildingHeight = 12;
	uint8_t lUpRightBuildingWidth = 24;
	char lUpRightBuilding[lUpRightBuildingHeight][lUpRightBuildingWidth];
	strcpy(lUpRightBuilding[0],  " _____________________ ");
	strcpy(lUpRightBuilding[1],  "|                     |");
	strcpy(lUpRightBuilding[2],  "|                     |");
	strcpy(lUpRightBuilding[3],  "|                     |");
	strcpy(lUpRightBuilding[4],  "|                     |");
	strcpy(lUpRightBuilding[5],  "|           __________|");
	strcpy(lUpRightBuilding[6],  "|          |           ");
	strcpy(lUpRightBuilding[7],  "|          |           ");
	strcpy(lUpRightBuilding[8],  "|          |           ");
	strcpy(lUpRightBuilding[9],  "|          |           ");
	strcpy(lUpRightBuilding[10], "|          |           ");
	strcpy(lUpRightBuilding[11], "|__________|           ");
	
	
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
		if (noSuccess > 300){// Magic Number
			randX = ((rand()%((mapWidth/2)-1))*2)+2;
			randY = ((rand()%((mapHeight)-1)))+2;
		}
		else if (noSuccess > 210){//Magic Number
			randX = ((rand()%((mapWidth/4)-1))*2)+2+(mapWidth/2-mapWidth/8);
			randY = ((rand()%((mapHeight/2)-1)))+2+(mapHeight/2-mapHeight/4);
		}
		else if (noSuccess > 120){//Magic Number
			randX = ((rand()%((mapWidth/8)-1))*2)+2+(mapWidth/2-mapWidth/16);
			randY = ((rand()%((mapHeight/4)-1)))+2+(mapHeight/2-mapHeight/8);
		}
		else if (noSuccess > 30){//Magic Number
			randX = ((rand()%((mapWidth/10)-1))*2)+2+(mapWidth/2-mapWidth/20);
			randY = ((rand()%((mapHeight/5)-1)))+2+(mapHeight/2-mapHeight/10);
		}
		++noSuccess;
		uint8_t numSimpleBuildingType = 2;
		uint8_t numBuildingTypes = 12;
		uint8_t chooseBuilding = rand()%numBuildingTypes;
		if(currentBuilding < numSHOPS){
			chooseBuilding = rand()%(numBuildingTypes-numSimpleBuildingType)+numSimpleBuildingType;
		}
		switch(chooseBuilding){
			case 0://square 25x25
			case 1:
				if(randX < (mapWidth-squareBuildingWidth-1)){
					if(randY < (mapHeight-squareBuildingHeight-1)){// Can fit squareBuilding in map
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
											itoa(currentBuilding/10,&map[i+randY][j+randX],10);
										}
										else if((i==3)&&(j==6)){
											itoa(currentBuilding%10,&map[i+randY][j+randX],10);
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
						else{//Space not empty
						}
					}
					else{// Cant fits square building
					}
				}
				else{// Can't fit building
				}
				break;
			case 2:
			case 3:
			case 4:
				if(randX < (mapWidth-rectLongBuildingWidth-1)){
					if(randY < (mapHeight-rectLongBuildingHeight-1)){// Can fit rectLongBuilding in map
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
											itoa(currentBuilding/10,&map[i+randY][j+randX],10);
										}
										else if((i==6)&&(j==6)){
											itoa(currentBuilding%10,&map[i+randY][j+randX],10);
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
						else{//Space not empty
							
						}
					}
					else{// Cant fits square building
						
					}
				}
				else{// Can't fit building
					
				}
				break;
			case 5:
			case 6:
			case 7:
				if(randX < (mapWidth-rectWideBuildingWidth-1)){
					if(randY < (mapHeight-rectWideBuildingHeight-1)){// Can fit rectWideBuilding in map
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
											itoa(currentBuilding/10,&map[i+randY][j+randX],10);
										}
										else if((i==3)&&(j==12)){
											itoa(currentBuilding%10,&map[i+randY][j+randX],10);
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
						else{//Space not empty
							
						}
					}
					else{// Cant fits rectWide building
						
					}
				}
				else{// Can't fit building
					
				}
				break;
			case 8: // DownLeft
				if(randX < (mapWidth-lDownLeftBuildingWidth-1)){
					if(randY < (mapHeight-lDownLeftBuildingHeight-1)){// Can fit lDownLeftBuilding in map
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
										if((i==9)&&(j==11)){
											itoa(currentBuilding/10,&map[i+randY][j+randX],10);
										}
										else if((i==9)&&(j==12)){
											itoa(currentBuilding%10,&map[i+randY][j+randX],10);
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
						else{//Space not empty
							
						}
					}
					else{// Cant fits lDownLeft building
						
					}
				}
				else{// Can't fit building
					
				}
				break;
			case 9://DownRight
				if(randX < (mapWidth-lDownRightBuildingWidth-1)){
					if(randY < (mapHeight-lDownRightBuildingHeight-1)){// Can fit lDownRightBuilding in map
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
										if((i==9)&&(j==11)){
											itoa(currentBuilding/10,&map[i+randY][j+randX],10);
										}
										else if((i==9)&&(j==12)){
											itoa(currentBuilding%10,&map[i+randY][j+randX],10);
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
						else{//Space not empty
							
						}
					}
					else{// Cant fits lDownRight building
						
					}
				}
				else{// Can't fit building
					
				}
				break;
			case 10://UpLeft
				if(randX < (mapWidth-lUpLeftBuildingWidth-1)){
					if(randY < (mapHeight-lUpLeftBuildingHeight-1)){// Can fit lUpLeftBuilding in map
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
										if((i==3)&&(j==11)){
											itoa(currentBuilding/10,&map[i+randY][j+randX],10);
										}
										else if((i==3)&&(j==12)){
											itoa(currentBuilding%10,&map[i+randY][j+randX],10);
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
						else{//Space not empty
							
						}
					}
					else{// Cant fits lUpLeft building
						
					}
				}
				else{// Can't fit building
					
				}
				break;
			case 11://UpRight
				if(randX < (mapWidth-lUpRightBuildingWidth-1)){
					if(randY < (mapHeight-lUpRightBuildingHeight-1)){// Can fit lUpRightBuilding in map
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
										if((i==3)&&(j==11)){
											itoa(currentBuilding/10,&map[i+randY][j+randX],10);
										}
										else if((i==3)&&(j==12)){
											itoa(currentBuilding%10,&map[i+randY][j+randX],10);
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
						else{//Space not empty
							
						}
					}
					else{// Cant fits lUpRight building
						
					}
				}
				else{// Can't fit building
					
				}
				break;
			default:
				break;
		}
	}
	
	//////////
	// Print Map
	for (int i = 0; i < mapHeight; ++i){
		for (int j = 0; j < mapWidth; ++j){
			fprintf(townMapFile,"%c", map[i][j]);
		}
		fprintf(townMapFile, "\n");
	}
	fclose(townMapFile);
	printf("Map has been generated\n");
	// Open two files to be merged
	townMapFile = fopen(mapFilename, "r");
	townFile = fopen(townFileName, "r");
	
	// Open file to store the result
	printf("Town stored at: %s\nMap stored at: %s\n",townFileName, mapFilename);
	strcat(token,"Full.txt");
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
	
	return 0;
}