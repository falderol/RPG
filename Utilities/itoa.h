#ifndef ITOA_HEADER_FILE
#define ITOA_HEADER_FILE

#include <stdint.h>

char* myitoa_base(int32_t value, char* result, int32_t base);
char* myitoa(int32_t value, char* result);

#endif