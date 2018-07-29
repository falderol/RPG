/* Linux does not have ITOA */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "itoa.h"

#define DEFAULT_BASE 10

	char* myitoa_base(int32_t value, char* result, int32_t base) {
		/* check that the base if valid */
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int32_t tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		/* Apply negative sign */
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}

	char* myitoa(int32_t value, char* result) {

		char* ptr = result, *ptr1 = result, tmp_char;
		int32_t tmp_value;

		do {
			tmp_value = value;
			value /= DEFAULT_BASE;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * DEFAULT_BASE)];
		} while ( value );

		/* Apply negative sign */
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}
