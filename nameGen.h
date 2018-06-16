#ifndef NAMEGEN_HEADER_FILE
#define NAMEGEN_HEADER_FILE

#include <stdint.h>

void nameGen(FILE* storeHere, uint16_t flags);
void shopnameGen(FILE* storeHere);
void townnameGen(FILE * storeHere);

#endif