#ifndef CONVERT_HEADER_FILE
#define CONVERT_HEADER_FILE

#include <stdint.h>

void convertFromCPreminder();
void convertFromCpAndStore(uint32_t cp, FILE * storeHere, uint8_t type);
void convertFromCp(uint32_t cp, uint8_t type);

#endif