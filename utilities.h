#ifndef ONES_HEADER_FILE
#define ONES_HEADER_FILE

#include <stdint.h>

uint8_t onesCount16(uint16_t countMe);
uint8_t onesCount32(uint32_t countMe);
uint8_t getBit(uint32_t value, uint8_t bitNum);

#endif