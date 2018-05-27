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
	char* filename = argv[1];
	FILE * townFile = fopen(filename, "w+");
	uint16_t flags = atoi(argv[2]);
	srand(time(NULL));
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
	
	if(settlementSize == 20){
		if (((rand()%20)+1)==20){
			fprintf(townFile, "The City of ");
			townnameGen(townFile);
			int population = (abs(rand()%8)+1)*10*settlementSize*8;
			population += (abs(rand()%8)+1)*10*settlementSize*8;
			population += (abs(rand()%8)+1)*10*settlementSize*8;
			population += (abs(rand()%8)+1)*10*settlementSize*8;
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
		int population = (abs(rand()%8)+1)*10*settlementSize;
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
	
	for (int i = 0; i < numAE; ++i){
		shopGen(filename, 0, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numALC; ++i){
		shopGen(filename, 1, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numARC; ++i){
		shopGen(filename, 2, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBAK; ++i){
		shopGen(filename, 3, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBRB; ++i){
		shopGen(filename, 4, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBLK; ++i){
		shopGen(filename, 5, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBOK; ++i){
		shopGen(filename, 6, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numBCH; ++i){
		shopGen(filename, 7, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numFLC; ++i){
		shopGen(filename, 8, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numGEN; ++i){
		shopGen(filename, 9, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numLEA; ++i){
		shopGen(filename, 10, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numMUS; ++i){
		shopGen(filename, 11, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numTLR; ++i){
		shopGen(filename, 12, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numTVN; ++i){
		shopGen(filename, 13, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numSRN; ++i){
		shopGen(filename, 14, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	for (int i = 0; i < numJWL; ++i){
		shopGen(filename, 15, flags, rand());
		townFile = fopen(filename, "a+");
		fprintf(townFile,"\n\n");
		fclose(townFile);
	}
	
	return 0;
}