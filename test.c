#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "shopGen.c"

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


int main (){
	srand(time(NULL));
	//shopGen(<FILENAME>,<SHOPNUM>,<FLAGS>, rand());

	return 0;
}