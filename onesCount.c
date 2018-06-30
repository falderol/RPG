#include <stdint.h>
#include "onesCount.h"

int8_t onesCount(uint16_t countMe){
	countMe -= (countMe >> 1) & 0x5555; /* put count of each 2 bits into those 2 bits */
    countMe = (countMe & 0x3333) + ((countMe >> 2) & 0x3333); /* put count of each 4 bits into those 4 bits */
    countMe = (countMe + (countMe >> 4)) & 0x0F0F; /* put count of each 8 bits into those 8 bits */
    countMe += countMe >>  8;  /* put count of each 16 bits into their lowest 8 bits */
    return countMe & 0x7f;
}