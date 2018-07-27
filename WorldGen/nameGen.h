#ifndef NAMEGEN_HEADER_FILE
#define NAMEGEN_HEADER_FILE

#include <stdint.h>

void nameGen(FILE* storeHere, uint16_t flags);
void shopnameGenAndStore(FILE* storeHere);
void townnameGenAndStore(FILE * storeHere);
void shopnameGen();
void townnameGen();

#endif