#ifndef SHOP_HEADER_FILE
#define SHOP_HEADER_FILE

#include <stdio.h>
#include <stdint.h>

void makeAdventurerEmporium(FILE* storeHere, uint16_t flags);
void makeAlchemist(FILE* storeHere, uint16_t flags);
void makeArcana(FILE* storeHere, uint16_t flags);
void makeBakery(FILE* storeHere, uint16_t flags);
void makeBarber(FILE* storeHere, uint16_t flags);
void makeBlacksmith(FILE* storeHere, uint16_t flags);
void makeBookstore(FILE* storeHere, uint16_t flags);
void makeButcher(FILE* storeHere, uint16_t flags);
void makeCobbler(FILE* storeHere, uint16_t flags);
void makeFletcher(FILE* storeHere, uint16_t flags);
void makeGeneral(FILE* storeHere, uint16_t flags);
void makeLeather(FILE* storeHere, uint16_t flags);
void makeMusic(FILE* storeHere, uint16_t flags);
void makeTailor(FILE* storeHere, uint16_t flags);
void makeTavern(FILE* storeHere, uint16_t flags);
void makeShrine(FILE* storeHere, uint16_t flags);
void makeJeweler(FILE* storeHere, uint16_t flags);
void shopCommandReminder();
int shopGen(char* filename,uint8_t shopNum,uint16_t flags);

#endif