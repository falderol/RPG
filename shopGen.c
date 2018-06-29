/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Testing things out in here
#include "shopGen.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "onesCount.h"
#include "convertFromCp.h"
#include "nameGen.h"

#define NAME_LENGTH 32

//////////
// Ones count that is used for the flags
// Knew this would come in handy one day

struct shopItem{
	char name[NAME_LENGTH];
	uint32_t lowPrice; // lowest price the shopkeeper will sell for
	uint32_t midPrice; // normal price the shopkeeper will sell for
	uint32_t highPrice; // highest price the shopkeeper will sell for
	int8_t stock;// Number from 0 to 20
	uint16_t biasFlags;
	//////////
	// Bias flags
	// Bit 00 - Magical
	// Bit 01 - Costal
	// Bit 02 - Rich
	// Bit 03 - Exotic
	// Bit 04 - Frontier
	// Bit 05 - Forest
	// Bit 06 - Industrial
	// Bit 07 - Mining
	// Bit 08 - Pious
    // Bit 09 - Agrigulture
	// Bit 10 - Rural
	// Bit 11 - Urban
	// Bit 14 - Firearms TOBE implemented
	// Bit 15 - Invalid
};

struct gemstone{
	char name[17];
	uint8_t amount;
};

//////////
// Adventurer's Emporium
void makeAdventurerEmporium(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 177;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Armor Section Name
	strcpy(inventory[0].name,"ARMOR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Padded Armor
	strcpy(inventory[1].name,"Padded");
	inventory[1].lowPrice = 300;
	inventory[1].midPrice = 500;
	inventory[1].highPrice = 800;
	inventory[1].stock = 5;
	inventory[1].biasFlags = 0;
	// Leather Armor
	strcpy(inventory[2].name,"Leather");
	inventory[2].lowPrice = 700;
	inventory[2].midPrice = 1000;
	inventory[2].highPrice = 1500;
	inventory[2].stock = 5;
	inventory[2].biasFlags = 0;
	// Studded Armor
	strcpy(inventory[3].name,"Studded");
	inventory[3].lowPrice = 3300;
	inventory[3].midPrice = 4500;
	inventory[3].highPrice = 6800;
	inventory[3].stock = 15;
	inventory[3].biasFlags = 0;
	// Studded Armor
	strcpy(inventory[4].name,"Hide");
	inventory[4].lowPrice = 70;
	inventory[4].midPrice = 100;
	inventory[4].highPrice = 1500;
	inventory[4].stock = 3;
	inventory[4].biasFlags = 0;

	// Weapons Section Name
	strcpy(inventory[8].name,"WEAPONS");
	inventory[8].lowPrice = 0;
	inventory[8].midPrice = 0;
	inventory[8].highPrice = 0;
	inventory[8].stock = 0;
	inventory[8].biasFlags = 0;
	// Club
	strcpy(inventory[9].name,"Club");
	inventory[9].lowPrice = 7;
	inventory[9].midPrice = 10;
	inventory[9].highPrice = 20;
	inventory[9].stock = 1;
	inventory[9].biasFlags = 0x10;
	// Dagger
	strcpy(inventory[10].name,"Dagger");
	inventory[10].lowPrice = 100;
	inventory[10].midPrice = 200;
	inventory[10].highPrice = 300;
	inventory[10].stock = 1;
	inventory[10].biasFlags = 0x0;
	// Greatclub
	strcpy(inventory[11].name,"Greatclub");
	inventory[11].lowPrice = 10;
	inventory[11].midPrice = 20;
	inventory[11].highPrice = 30;
	inventory[11].stock = 5;
	inventory[11].biasFlags = 0x10;
	// Greatclub
	strcpy(inventory[12].name,"Handaxe");
	inventory[12].lowPrice = 300;
	inventory[12].midPrice = 500;
	inventory[12].highPrice = 800;
	inventory[12].stock = 3;
	inventory[12].biasFlags = 0x220;
	// Light Hammer
	strcpy(inventory[13].name,"Light Hammer");
	inventory[13].lowPrice = 100;
	inventory[13].midPrice = 200;
	inventory[13].highPrice = 300;
	inventory[13].stock = 5;
	inventory[13].biasFlags = 0x280;
	// Quarterstaff
	strcpy(inventory[14].name,"Quarterstaff");
	inventory[14].lowPrice = 10;
	inventory[14].midPrice = 20;
	inventory[14].highPrice = 30;
	inventory[14].stock = 5;
	inventory[14].biasFlags = 0x1;
	// Spear
	strcpy(inventory[15].name,"Spear");
	inventory[15].lowPrice = 70;
	inventory[15].midPrice = 100;
	inventory[15].highPrice = 200;
	inventory[15].stock = 2;
	inventory[15].biasFlags = 0x600;
	// Light Crossbow
	strcpy(inventory[16].name,"Light Crossbow");
	inventory[16].lowPrice = 1800;
	inventory[16].midPrice = 2500;
	inventory[16].highPrice = 3800;
	inventory[16].stock = 5;
	inventory[16].biasFlags = 0x0;
	// Dart
	strcpy(inventory[17].name,"Dart");
	inventory[17].lowPrice = 3;
	inventory[17].midPrice = 5;
	inventory[17].highPrice = 8;
	inventory[17].stock = 3;
	inventory[17].biasFlags = 0x800;
	// Shortbow
	strcpy(inventory[18].name,"Shortbow");
	inventory[18].lowPrice = 1800;
	inventory[18].midPrice = 2500;
	inventory[18].highPrice = 3800;
	inventory[18].stock = 5;
	inventory[18].biasFlags = 0x600;
	// Sling
	strcpy(inventory[19].name,"Sling");
	inventory[19].lowPrice = 7;
	inventory[19].midPrice = 10;
	inventory[19].highPrice = 20;
	inventory[19].stock = 3;
	inventory[19].biasFlags = 0x600;
	// Whip
	strcpy(inventory[20].name,"Whip");
	inventory[20].lowPrice = 10;
	inventory[20].midPrice = 20;
	inventory[20].highPrice = 30;
	inventory[20].stock = 5;
	inventory[20].biasFlags = 0x200;
	// Blowgun
	strcpy(inventory[21].name,"Blowgun");
	inventory[21].lowPrice = 700;
	inventory[21].midPrice = 1000;
	inventory[21].highPrice = 1500;
	inventory[21].stock = 7;
	inventory[21].biasFlags = 0x828;
	// Hand Crossbow
	strcpy(inventory[22].name,"Hand Crossbow");
	inventory[22].lowPrice = 5600;
	inventory[22].midPrice = 7500;
	inventory[22].highPrice = 11300;
	inventory[22].stock = 15;
	inventory[22].biasFlags = 0x804;
	// Heavy Crossbow
	strcpy(inventory[23].name,"Heavy Crossbow");
	inventory[23].lowPrice = 3800;
	inventory[23].midPrice = 5000;
	inventory[23].highPrice = 7500;
	inventory[23].stock = 10;
	inventory[23].biasFlags = 0x0;
	// Longbow
	strcpy(inventory[24].name,"Longbow");
	inventory[24].lowPrice = 3800;
	inventory[24].midPrice = 5000;
	inventory[24].highPrice = 7500;
	inventory[24].stock = 5;
	inventory[24].biasFlags = 0x600;
	
	// Gear Section Name
	strcpy(inventory[27].name,"GEAR");
	inventory[27].lowPrice = 0;
	inventory[27].midPrice = 0;
	inventory[27].highPrice = 0;
	inventory[27].stock = 0;
	inventory[27].biasFlags = 0;
	// Arrows
	strcpy(inventory[28].name,"Arrows (20)");
	inventory[28].lowPrice = 70;
	inventory[28].midPrice = 100;
	inventory[28].highPrice = 200;
	inventory[28].stock = 2;
	inventory[28].biasFlags = 0x0;
	// Blowgun Needles
	strcpy(inventory[29].name,"Blowgun Needles (50)");
	inventory[29].lowPrice = 70;
	inventory[29].midPrice = 100;
	inventory[29].highPrice = 200;
	inventory[29].stock = 7;
	inventory[29].biasFlags = 0x828;
	// Crossbow Bolts
	strcpy(inventory[30].name,"Crossbow Bolts (20)");
	inventory[30].lowPrice = 70;
	inventory[30].midPrice = 100;
	inventory[30].highPrice = 200;
	inventory[30].stock = 3;
	inventory[30].biasFlags = 0x0;
	// Sling Bullets
	strcpy(inventory[31].name,"Sling Bullets (20)");
	inventory[31].lowPrice = 3;
	inventory[31].midPrice = 4;
	inventory[31].highPrice = 6;
	inventory[31].stock = 3;
	inventory[31].biasFlags = 0x400;
	// Bakcpack
	strcpy(inventory[32].name,"Backpack");
	inventory[32].lowPrice = 100;
	inventory[32].midPrice = 200;
	inventory[32].highPrice = 300;
	inventory[32].stock = 1;
	inventory[32].biasFlags = 0x10;
	// Bedroll
	strcpy(inventory[33].name,"Bedroll");
	inventory[33].lowPrice = 70;
	inventory[33].midPrice = 100;
	inventory[33].highPrice = 200;
	inventory[33].stock = 2;
	inventory[33].biasFlags = 0x10;
	// Blanket
	strcpy(inventory[34].name,"Blanket");
	inventory[34].lowPrice = 30;
	inventory[34].midPrice = 50;
	inventory[34].highPrice = 80;
	inventory[34].stock = 1;
	inventory[34].biasFlags = 0x0;
	// Glass Bottle
	strcpy(inventory[35].name,"Glass Bottle");
	inventory[35].lowPrice = 100;
	inventory[35].midPrice = 200;
	inventory[35].highPrice = 300;
	inventory[35].stock = 3;
	inventory[35].biasFlags = 0x1;
	// Candle
	strcpy(inventory[36].name,"Candle");
	inventory[36].lowPrice = 1;
	inventory[36].midPrice = 1;
	inventory[36].highPrice = 3;
	inventory[36].stock = 5;
	inventory[36].biasFlags = 0x1;
	// Crossbow Bolt Case
	strcpy(inventory[37].name,"Crossbow Bolt Case");
	inventory[37].lowPrice = 70;
	inventory[37].midPrice = 100;
	inventory[37].highPrice = 200;
	inventory[37].stock = 5;
	inventory[37].biasFlags = 0x0;
	// Scroll Case
	strcpy(inventory[38].name,"Scroll Case");
	inventory[38].lowPrice = 70;
	inventory[38].midPrice = 100;
	inventory[38].highPrice = 200;
	inventory[38].stock = 5;
	inventory[38].biasFlags = 0x1;
	// Chain
	strcpy(inventory[39].name,"Chain (10 ft.)");
	inventory[39].lowPrice = 300;
	inventory[39].midPrice = 500;
	inventory[39].highPrice = 800;
	inventory[39].stock = 5;
	inventory[39].biasFlags = 0x2C0;
	// Chest
	strcpy(inventory[40].name,"Chest");
	inventory[40].lowPrice = 300;
	inventory[40].midPrice = 500;
	inventory[40].highPrice = 800;
	inventory[40].stock = 5;
	inventory[40].biasFlags = 0x4;
	// Climber's Kit
	strcpy(inventory[41].name,"Climber's Kit");
	inventory[41].lowPrice = 1800;
	inventory[41].midPrice = 2500;
	inventory[41].highPrice = 3800;
	inventory[41].stock = 5;
	inventory[41].biasFlags = 0x80;
	// Traveler's Clothes
	strcpy(inventory[42].name,"Traveler's Clothes");
	inventory[42].lowPrice = 100;
	inventory[42].midPrice = 200;
	inventory[42].highPrice = 300;
	inventory[42].stock = 3;
	inventory[42].biasFlags = 0x10;
	// Crowbar
	strcpy(inventory[43].name,"Crowbar");
	inventory[43].lowPrice = 100;
	inventory[43].midPrice = 200;
	inventory[43].highPrice = 300;
	inventory[43].stock = 3;
	inventory[43].biasFlags = 0x800;
	// Flask
	strcpy(inventory[44].name,"Flask");
	inventory[44].lowPrice = 1;
	inventory[44].midPrice = 2;
	inventory[44].highPrice = 4;
	inventory[44].stock = 3;
	inventory[44].biasFlags = 0x0;
	// Grappling Hook
	strcpy(inventory[45].name,"Grappling Hook");
	inventory[45].lowPrice = 100;
	inventory[45].midPrice = 200;
	inventory[45].highPrice = 300;
	inventory[45].stock = 4;
	inventory[45].biasFlags = 0x0;
	// Hammer
	strcpy(inventory[46].name,"Hammer");
	inventory[46].lowPrice = 70;
	inventory[46].midPrice = 100;
	inventory[46].highPrice = 200;
	inventory[46].stock = 2;
	inventory[46].biasFlags = 0x2C0;
	// Healer's Kit
	strcpy(inventory[47].name,"Healer's Kit");
	inventory[47].lowPrice = 300;
	inventory[47].midPrice = 500;
	inventory[47].highPrice = 800;
	inventory[47].stock = 15;
	inventory[47].biasFlags = 0x0;
	// Hourglass
	strcpy(inventory[48].name,"Hourglass");
	inventory[48].lowPrice = 1800;
	inventory[48].midPrice = 2500;
	inventory[48].highPrice = 3800;
	inventory[48].stock = 18;
	inventory[48].biasFlags = 0x805;
	// Hunting Trap
	strcpy(inventory[49].name,"Hunting Trap");
	inventory[49].lowPrice = 300;
	inventory[49].midPrice = 500;
	inventory[49].highPrice = 800;
	inventory[49].stock = 5;
	inventory[49].biasFlags = 0x430;
	// Ink (1 fl. oz.)
	strcpy(inventory[50].name,"Ink (1 fl. oz.)");
	inventory[50].lowPrice = 700;
	inventory[50].midPrice = 1000;
	inventory[50].highPrice = 1500;
	inventory[50].stock = 15;
	inventory[50].biasFlags = 0x841;
	// Jug
	strcpy(inventory[51].name,"Jug");
	inventory[51].lowPrice = 1;
	inventory[51].midPrice = 2;
	inventory[51].highPrice = 3;
	inventory[51].stock = 1;
	inventory[51].biasFlags = 0x4;
	// Ladder (10 ft.)
	strcpy(inventory[52].name,"Ladder (10 ft.)");
	inventory[52].lowPrice = 7;
	inventory[52].midPrice = 10;
	inventory[52].highPrice = 20;
	inventory[52].stock = 5;
	inventory[52].biasFlags = 0xC0;
	// Lantern (hodded)
	strcpy(inventory[53].name,"Latern (hooded)");
	inventory[53].lowPrice = 300;
	inventory[53].midPrice = 500;
	inventory[53].highPrice = 800;
	inventory[53].stock = 2;
	inventory[53].biasFlags = 0x80;
	// Lock
	strcpy(inventory[54].name,"Lock");
	inventory[54].lowPrice = 700;
	inventory[54].midPrice = 1000;
	inventory[54].highPrice = 1500;
	inventory[54].stock = 18;
	inventory[54].biasFlags = 0x804;
	// Mess Kit
	strcpy(inventory[55].name,"Mess Kit");
	inventory[55].lowPrice = 10;
	inventory[55].midPrice = 20;
	inventory[55].highPrice = 30;
	inventory[55].stock = 5;
	inventory[55].biasFlags = 0x0;
	// Paper
	strcpy(inventory[56].name,"Paper (1)");
	inventory[56].lowPrice = 10;
	inventory[56].midPrice = 20;
	inventory[56].highPrice = 30;
	inventory[56].stock = 18;
	inventory[56].biasFlags = 0x841;
	// Parchment
	strcpy(inventory[57].name,"Parchment (1)");
	inventory[57].lowPrice = 7;
	inventory[57].midPrice = 10;
	inventory[57].highPrice = 20;
	inventory[57].stock = 5;
	inventory[57].biasFlags = 0x441;
	// Pick (mining)
	strcpy(inventory[58].name,"Pick (mining)");
	inventory[58].lowPrice = 100;
	inventory[58].midPrice = 200;
	inventory[58].highPrice = 300;
	inventory[58].stock = 5;
	inventory[58].biasFlags = 0x80;
	// Piton
	strcpy(inventory[59].name,"Piton");
	inventory[59].lowPrice = 3;
	inventory[59].midPrice = 5;
	inventory[59].highPrice = 8;
	inventory[59].stock = 5;
	inventory[59].biasFlags = 0x0;
	// Pole (10 ft.)
	strcpy(inventory[60].name,"Pole (10 ft.)");
	inventory[60].lowPrice = 3;
	inventory[60].midPrice = 5;
	inventory[60].highPrice = 10;
	inventory[60].stock = 7;
	inventory[60].biasFlags = 0x0;
	// Pot
	strcpy(inventory[61].name,"Pot");
	inventory[61].lowPrice = 100;
	inventory[61].midPrice = 200;
	inventory[61].highPrice = 300;
	inventory[61].stock = 1;
	inventory[61].biasFlags = 0x0;
	// Pouch
	strcpy(inventory[62].name,"Pouch");
	inventory[62].lowPrice = 30;
	inventory[62].midPrice = 50;
	inventory[62].highPrice = 80;
	inventory[62].stock = 1;
	inventory[62].biasFlags = 0x0;
	// Pulley
	strcpy(inventory[63].name,"Pulley");
	inventory[63].lowPrice = 70;
	inventory[63].midPrice = 100;
	inventory[63].highPrice = 200;
	inventory[63].stock = 8;
	inventory[63].biasFlags = 0xC0;
	// Quill
	strcpy(inventory[64].name,"Quill");
	inventory[64].lowPrice = 1;
	inventory[64].midPrice = 2;
	inventory[64].highPrice = 3;
	inventory[64].stock = 15;
	inventory[64].biasFlags = 0x41;
	// Quiver
	strcpy(inventory[65].name,"Quiver");
	inventory[65].lowPrice = 70;
	inventory[65].midPrice = 100;
	inventory[65].highPrice = 200;
	inventory[65].stock = 3;
	inventory[65].biasFlags = 0x20;
	// Ration (1 day)
	strcpy(inventory[66].name,"Ration (1 day)");
	inventory[66].lowPrice = 30;
	inventory[66].midPrice = 50;
	inventory[66].highPrice = 80;
	inventory[66].stock = 5;
	inventory[66].biasFlags = 0x0;
	// Hemp Rope
	strcpy(inventory[67].name,"Hemp Rope (50 ft.)");
	inventory[67].lowPrice = 70;
	inventory[67].midPrice = 100;
	inventory[67].highPrice = 200;
	inventory[67].stock = 3;
	inventory[67].biasFlags = 0x2C0;
	// Silk Rope
	strcpy(inventory[68].name,"Silk Rope (50 ft.)");
	inventory[68].lowPrice = 700;
	inventory[68].midPrice = 1000;
	inventory[68].highPrice = 2000;
	inventory[68].stock = 15;
	inventory[68].biasFlags = 0x4;
	// Sack
	strcpy(inventory[69].name,"Sack");
	inventory[69].lowPrice = 1;
	inventory[69].midPrice = 1;
	inventory[69].highPrice = 2;
	inventory[69].stock = 2;
	inventory[69].biasFlags = 0x0;
	// Shovel
	strcpy(inventory[70].name,"Shovel");
	inventory[70].lowPrice = 100;
	inventory[70].midPrice = 200;
	inventory[70].highPrice = 300;
	inventory[70].stock = 3;
	inventory[70].biasFlags = 0x280;
	// Signal Whistle
	strcpy(inventory[71].name,"Signal Whistle");
	inventory[71].lowPrice = 3;
	inventory[71].midPrice = 5;
	inventory[71].highPrice = 8;
	inventory[71].stock = 7;
	inventory[71].biasFlags = 0x0;
	// Signet Ring
	strcpy(inventory[72].name,"Signet Ring");
	inventory[72].lowPrice = 300;
	inventory[72].midPrice = 500;
	inventory[72].highPrice = 800;
	inventory[72].stock = 18;
	inventory[72].biasFlags = 0x4;
	// Spyglass
	strcpy(inventory[73].name,"Spyglass");
	inventory[73].lowPrice = 75000;
	inventory[73].midPrice = 100000;
	inventory[73].highPrice = 150000;
	inventory[73].stock = 18;
	inventory[73].biasFlags = 0x16;
	// Tent
	strcpy(inventory[74].name,"Tent");
	inventory[74].lowPrice = 100;
	inventory[74].midPrice = 200;
	inventory[74].highPrice = 300;
	inventory[74].stock = 2;
	inventory[74].biasFlags = 0x10;
	// Tinderbox
	strcpy(inventory[75].name,"Tinderbox");
	inventory[75].lowPrice = 30;
	inventory[75].midPrice = 50;
	inventory[75].highPrice = 80;
	inventory[75].stock = 2;
	inventory[75].biasFlags = 0x410;
	// Torch
	strcpy(inventory[76].name,"Torch");
	inventory[76].lowPrice = 1;
	inventory[76].midPrice = 1;
	inventory[76].highPrice = 2;
	inventory[76].stock = 2;
	inventory[76].biasFlags = 0x410;
	// Vial
	strcpy(inventory[77].name,"Vial");
	inventory[77].lowPrice = 70;
	inventory[77].midPrice = 100;
	inventory[77].highPrice = 200;
	inventory[77].stock = 3;
	inventory[77].biasFlags = 0x1;
	// Waterskin
	strcpy(inventory[78].name,"Waterskin");
	inventory[78].lowPrice = 10;
	inventory[78].midPrice = 20;
	inventory[78].highPrice = 30;
	inventory[78].stock = 2;
	inventory[78].biasFlags = 0x412;
	if ((flags&0x2)>>1){// If we are costal
		// Net
		strcpy(inventory[80].name,"Net");
		inventory[80].lowPrice = 70;
		inventory[80].midPrice = 100;
		inventory[80].highPrice = 200;
		inventory[80].stock = 2;
		inventory[80].biasFlags = 0x0;
		// Fishing Tackle
		strcpy(inventory[81].name,"Fishing Tackle");
		inventory[81].lowPrice = 70;
		inventory[81].midPrice = 100;
		inventory[81].highPrice = 200;
		inventory[81].stock = 1;
		inventory[81].biasFlags = 0x0;
		// Rowboat
		strcpy(inventory[82].name,"Rowboat");
		inventory[82].lowPrice = 3800;
		inventory[82].midPrice = 5000;
		inventory[82].highPrice = 7500;
		inventory[82].stock = 5;
		inventory[82].biasFlags = 0x0;
		// Bait
		strcpy(inventory[80].name,"Bait");
		inventory[80].lowPrice = 3;
		inventory[80].midPrice = 5;
		inventory[80].highPrice = 8;
		inventory[80].stock = 1;
		inventory[80].biasFlags = 0x0;
	}
	
	// Tools Section Name
	strcpy(inventory[87].name,"TOOLS");
	inventory[87].lowPrice = 0;
	inventory[87].midPrice = 0;
	inventory[87].highPrice = 0;
	inventory[87].stock = 0;
	inventory[87].biasFlags = 0x0;
	// Cartographer's Tools
	strcpy(inventory[88].name,"Cartographer's Tools");
	inventory[88].lowPrice = 1100;
	inventory[88].midPrice = 1500;
	inventory[88].highPrice = 2300;
	inventory[88].stock = 10;
	inventory[88].biasFlags = 0x14;
	// Herbalism Kit
	strcpy(inventory[89].name,"Herbalism Kit");
	inventory[89].lowPrice = 300;
	inventory[89].midPrice = 500;
	inventory[89].highPrice = 800;
	inventory[89].stock = 10;
	inventory[89].biasFlags = 0x210;
	// Jeweler's Tools
	strcpy(inventory[90].name,"Jeweler's Tools");
	inventory[90].lowPrice = 1800;
	inventory[90].midPrice = 2500;
	inventory[90].highPrice = 3800;
	inventory[90].stock = 18;
	inventory[90].biasFlags = 0x804;
	// Navigator's Tools
	strcpy(inventory[91].name,"Navigator's Tools");
	inventory[91].lowPrice = 1800;
	inventory[91].midPrice = 2500;
	inventory[91].highPrice = 3800;
	inventory[91].stock = 3;
	inventory[91].biasFlags = 0x12;
	
	// Foodstuffs Section Name
	strcpy(inventory[105].name,"FOODSTUFFS");
	inventory[105].lowPrice = 0;
	inventory[105].midPrice = 0;
	inventory[105].highPrice = 0;
	inventory[105].stock = 0;
	inventory[105].biasFlags = 0x0;
	// Apples
	strcpy(inventory[106].name,"Apples (1 lb.)");
	inventory[106].lowPrice = 1;
	inventory[106].midPrice = 2;
	inventory[106].highPrice = 10;
	inventory[106].stock = 5;
	inventory[106].biasFlags = 0x220;
	// Common Brandy
	strcpy(inventory[107].name,"Common Brandy (1 qt.)");
	inventory[107].lowPrice = 20;
	inventory[107].midPrice = 30;
	inventory[107].highPrice = 50;
	inventory[107].stock = 10;
	inventory[107].biasFlags = 0x200;
	// Good Brandy
	strcpy(inventory[108].name,"Good Brandy (1 qt.)");
	inventory[108].lowPrice = 10;
	inventory[108].midPrice = 150;
	inventory[108].highPrice = 200;
	inventory[108].stock = 15;
	inventory[108].biasFlags = 0x204;
	// Bread
	strcpy(inventory[109].name,"Bread (1 lb.)");
	inventory[109].lowPrice = 5;
	inventory[109].midPrice = 8;
	inventory[109].highPrice = 10;
	inventory[109].stock = 5;
	inventory[109].biasFlags = 0x200;
	// Common Cheese
	strcpy(inventory[110].name,"Common Cheese (1 lb.)");
	inventory[110].lowPrice = 10;
	inventory[110].midPrice = 15;
	inventory[110].highPrice = 20;
	inventory[110].stock = 7;
	inventory[110].biasFlags = 0x200;
	// Cider
	strcpy(inventory[111].name,"Cider (1 qt.)");
	inventory[111].lowPrice = 20;
	inventory[111].midPrice = 30;
	inventory[111].highPrice = 50;
	inventory[111].stock = 7;
	inventory[111].biasFlags = 0x220;
	// Corn
	strcpy(inventory[112].name,"Corn (1 lb.)");
	inventory[112].lowPrice = 4;
	inventory[112].midPrice = 6;
	inventory[112].highPrice = 8;
	inventory[112].stock = 5;
	inventory[112].biasFlags = 0x200;
	// Feed Corn
	strcpy(inventory[113].name,"Feed Corn (1 lb.)");
	inventory[113].lowPrice = 1;
	inventory[113].midPrice = 1;
	inventory[113].highPrice = 2;
	inventory[113].stock = 1;
	inventory[113].biasFlags = 0x200;
	// Cornmeal
	strcpy(inventory[114].name,"Cornmeal (1 lb.)");
	inventory[114].lowPrice = 6;
	inventory[114].midPrice = 8;
	inventory[114].highPrice = 10;
	inventory[114].stock = 2;
	inventory[114].biasFlags = 0x200;
	// Flour
	strcpy(inventory[115].name,"Flour (1 lb.)");
	inventory[115].lowPrice = 4;
	inventory[115].midPrice = 5;
	inventory[115].highPrice = 7;
	inventory[115].stock = 2;
	inventory[115].biasFlags = 0x200;
	// Garlic
	strcpy(inventory[116].name,"Garlic (1 lb.)");
	inventory[116].lowPrice = 2;
	inventory[116].midPrice = 3;
	inventory[116].highPrice = 5;
	inventory[116].stock = 7;
	inventory[116].biasFlags = 0x200;
	// Honey
	strcpy(inventory[117].name,"Honey (1 qt.)");
	inventory[117].lowPrice = 6;
	inventory[117].midPrice = 7;
	inventory[117].highPrice = 8;
	inventory[117].stock = 10;
	inventory[117].biasFlags = 0x200;
	// Mead
	strcpy(inventory[118].name,"Mead (1 qt.)");
	inventory[118].lowPrice = 30;
	inventory[118].midPrice = 50;
	inventory[118].highPrice = 80;
	inventory[118].stock = 10;
	inventory[118].biasFlags = 0x200;
	// Nuts
	strcpy(inventory[119].name,"Nuts (1 lb.)");
	inventory[119].lowPrice = 3;
	inventory[119].midPrice = 5;
	inventory[119].highPrice = 8;
	inventory[119].stock = 2;
	inventory[119].biasFlags = 0x200;
	// Onions
	strcpy(inventory[120].name,"Onions (1 lb.)");
	inventory[120].lowPrice = 1;
	inventory[120].midPrice = 2;
	inventory[120].highPrice = 5;
	inventory[120].stock = 2;
	inventory[120].biasFlags = 0x200;
	// Popcorn Kernels
	strcpy(inventory[121].name,"Popcorn Kernels (1 lb.)");
	inventory[121].lowPrice = 10;
	inventory[121].midPrice = 12;
	inventory[121].highPrice = 14;
	inventory[121].stock = 7;
	inventory[121].biasFlags = 0x200;
	// Potatoes
	strcpy(inventory[122].name,"Potatoes (1 lb.)");
	inventory[122].lowPrice = 1;
	inventory[122].midPrice = 2;
	inventory[122].highPrice = 3;
	inventory[122].stock = 1;
	inventory[122].biasFlags = 0x200;
	// Rice
	strcpy(inventory[123].name,"Rice (1 lb.)");
	inventory[123].lowPrice = 1;
	inventory[123].midPrice = 1;
	inventory[123].highPrice = 2;
	inventory[123].stock = 1;
	inventory[123].biasFlags = 0x200;
	// Salt
	strcpy(inventory[124].name,"Salt (1 lb.)");
	inventory[124].lowPrice = 3;
	inventory[124].midPrice = 5;
	inventory[124].highPrice = 8;
	inventory[124].stock = 5;
	inventory[124].biasFlags = 0x280;
	// Common Spirit
	strcpy(inventory[125].name,"Common Spirit (1 qt.)");
	inventory[125].lowPrice = 20;
	inventory[125].midPrice = 30;
	inventory[125].highPrice = 50;
	inventory[125].stock = 10;
	inventory[125].biasFlags = 0x200;
	// Good Spirit
	strcpy(inventory[126].name,"Good Spirit (1 qt.)");
	inventory[126].lowPrice = 50;
	inventory[126].midPrice = 70;
	inventory[126].highPrice = 100;
	inventory[126].stock = 15;
	inventory[126].biasFlags = 0x204;
	// Tallow
	strcpy(inventory[127].name,"Tallow (1 lb.)");
	inventory[127].lowPrice = 40;
	inventory[127].midPrice = 60;
	inventory[127].highPrice = 80;
	inventory[127].stock = 10;
	inventory[127].biasFlags = 0x200;
	// Wheat
	strcpy(inventory[128].name,"Wheat (1 lb.)");
	inventory[128].lowPrice = 1;
	inventory[128].midPrice = 2;
	inventory[128].highPrice = 3;
	inventory[128].stock = 2;
	inventory[128].biasFlags = 0x200;
	// Common Wine
	strcpy(inventory[129].name,"Common Wine (1 lb.)");
	inventory[129].lowPrice = 10;
	inventory[129].midPrice = 20;
	inventory[129].highPrice = 30;
	inventory[129].stock = 10;
	inventory[129].biasFlags = 0x200;
	// Good Wine
	strcpy(inventory[130].name,"Good Wine (1 qt.)");
	inventory[130].lowPrice = 70;
	inventory[130].midPrice = 100;
	inventory[130].highPrice = 150;
	inventory[130].stock = 15;
	inventory[130].biasFlags = 0x204;
	
	// Dishes Section Header
	strcpy(inventory[143].name,"DISHES");
	inventory[143].lowPrice = 0;
	inventory[143].midPrice = 0;
	inventory[143].highPrice = 0;
	inventory[143].stock = 0;
	inventory[143].biasFlags = 0x0;
	// Biscuits
	strcpy(inventory[144].name,"Biscuits");
	inventory[144].lowPrice = 7;
	inventory[144].midPrice = 10;
	inventory[144].highPrice = 20;
	inventory[144].stock = 10;
	inventory[144].biasFlags = 0x200;
	// Hardtack
	strcpy(inventory[145].name,"Hardtack");
	inventory[145].lowPrice = 6;
	inventory[145].midPrice = 8;
	inventory[145].highPrice = 10;
	inventory[145].stock = 5;
	inventory[145].biasFlags = 0x410;
	// Beef Jerky
	strcpy(inventory[146].name,"Beef Jerky");
	inventory[146].lowPrice = 160;
	inventory[146].midPrice = 200;
	inventory[146].highPrice = 300;
	inventory[146].stock = 10;
	inventory[146].biasFlags = 0x610;
	// Pemmican
	strcpy(inventory[147].name,"Pemmican");
	inventory[147].lowPrice = 160;
	inventory[147].midPrice = 200;
	inventory[147].highPrice = 300;
	inventory[147].stock = 10;
	inventory[147].biasFlags = 0x10;
	// Salted Pork
	strcpy(inventory[148].name,"Salted Pork");
	inventory[148].lowPrice = 90;
	inventory[148].midPrice = 120;
	inventory[148].highPrice = 200;
	inventory[148].stock = 5;
	inventory[148].biasFlags = 0x10;
	// Sauerkraut
	strcpy(inventory[149].name,"Sauerkraut");
	inventory[149].lowPrice = 1;
	inventory[149].midPrice = 2;
	inventory[149].highPrice = 4;
	inventory[149].stock = 10;
	inventory[149].biasFlags = 0x200;
	// Chorizo
	strcpy(inventory[150].name,"Chorizo");
	inventory[150].lowPrice = 20;
	inventory[150].midPrice = 22;
	inventory[150].highPrice = 26;
	inventory[150].stock = 10;
	inventory[150].biasFlags = 0x208;
	// Beef Summer Sausage
	strcpy(inventory[151].name,"Beef Summer Sausage");
	inventory[151].lowPrice = 32;
	inventory[151].midPrice = 34;
	inventory[151].highPrice = 38;
	inventory[151].stock = 10;
	inventory[151].biasFlags = 0x610;
	// Pork Summer Sausage
	strcpy(inventory[152].name,"Pork Summer Sausage");
	inventory[152].lowPrice = 18;
	inventory[152].midPrice = 20;
	inventory[152].highPrice = 24;
	inventory[152].stock = 10;
	inventory[152].biasFlags = 0x610;
	
	if (flags&0x4000){//Firearms
		// Firearms Section Title
		strcpy(inventory[167].name,"FIREARMS");
		inventory[167].lowPrice = 0;
		inventory[167].midPrice = 0;
		inventory[167].highPrice = 0;
		inventory[167].stock = 5;
		inventory[167].biasFlags = 0x0;
		// Ball and Powder
		strcpy(inventory[168].name,"Ball and Powder (20)");
		inventory[168].lowPrice = 70;
		inventory[168].midPrice = 100;
		inventory[168].highPrice = 150;
		inventory[168].stock = 5;
		inventory[168].biasFlags = 0x410;
		// Buckshot
		strcpy(inventory[169].name,"Buckshot (20)");
		inventory[169].lowPrice = 70;
		inventory[169].midPrice = 100;
		inventory[169].highPrice = 150;
		inventory[169].stock = 5;
		inventory[169].biasFlags = 0x410;
		// Duckshot
		strcpy(inventory[170].name,"Duckshot (20)");
		inventory[170].lowPrice = 70;
		inventory[170].midPrice = 100;
		inventory[170].highPrice = 150;
		inventory[170].stock = 5;
		inventory[170].biasFlags = 0x410;
		// Revolver Ammo
		strcpy(inventory[171].name,"Revolver Ammo (20)");
		inventory[171].lowPrice = 20;
		inventory[171].midPrice = 50;
		inventory[171].highPrice = 100;
		inventory[171].stock = 5;
		inventory[171].biasFlags = 0x800;
		// Rifle Ammo
		strcpy(inventory[172].name,"Rifle Ammo (20)");
		inventory[172].lowPrice = 100;
		inventory[172].midPrice = 150;
		inventory[172].highPrice = 200;
		inventory[172].stock = 7;
		inventory[172].biasFlags = 0x410;
		// Carbine
		strcpy(inventory[173].name,"Carbine");
		inventory[173].lowPrice = 1000;
		inventory[173].midPrice = 1200;
		inventory[173].highPrice = 1500;
		inventory[173].stock = 10;
		inventory[173].biasFlags = 0x410;
		// Derringer
		strcpy(inventory[174].name,"Derringer");
		inventory[174].lowPrice = 500;
		inventory[174].midPrice = 600;
		inventory[174].highPrice = 1000;
		inventory[174].stock = 15;
		inventory[174].biasFlags = 0x840;
		// Revolver
		strcpy(inventory[175].name,"Revolver");
		inventory[175].lowPrice = 800;
		inventory[175].midPrice = 1000;
		inventory[175].highPrice = 1500;
		inventory[175].stock = 10;
		inventory[175].biasFlags = 0x800;
		// Shotgun
		strcpy(inventory[176].name,"Shotgun");
		inventory[176].lowPrice = 1600;
		inventory[176].midPrice = 2000;
		inventory[176].highPrice = 2500;
		inventory[176].stock = 7;
		inventory[176].biasFlags = 0x410;
	}
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	if (flags&0x4000){
		fprintf(storeHere, "\nQuestions about Firearms? See the Demagus True Reference PDF\n");
	}
	
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeAlchemist(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 46;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Armor Section Name
	strcpy(inventory[0].name,"GEAR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Acid
	strcpy(inventory[2].name,"Acid (vial)");
	inventory[2].lowPrice = 1800;
	inventory[2].midPrice = 2500;
	inventory[2].highPrice = 3800;
	inventory[2].stock = 5;
	inventory[2].biasFlags = 0x41;
	// Alchemist's Fire
	strcpy(inventory[3].name,"Alchemist's Fire (flask)");
	inventory[3].lowPrice = 3800;
	inventory[3].midPrice = 5000;
	inventory[3].highPrice = 7500;
	inventory[3].stock = 8;
	inventory[3].biasFlags = 0x41;
	// Antitoxen
	strcpy(inventory[4].name,"Antitoxin (vial)");
	inventory[4].lowPrice = 3800;
	inventory[4].midPrice = 5000;
	inventory[4].highPrice = 7500;
	inventory[4].stock = 3;
	inventory[4].biasFlags = 0x5;
	// Component Pouch
	strcpy(inventory[5].name,"Component Pouch");
	inventory[5].lowPrice = 1800;
	inventory[5].midPrice = 2500;
	inventory[5].highPrice = 3800;
	inventory[5].stock = 5;
	inventory[5].biasFlags = 0x1;
	// Flask
	strcpy(inventory[6].name,"Flask");
	inventory[6].lowPrice = 1;
	inventory[6].midPrice = 2;
	inventory[6].highPrice = 3;
	inventory[6].stock = 1;
	inventory[6].biasFlags = 0x1;
	// Glass Bottle
	strcpy(inventory[7].name,"Glass Bottle");
	inventory[7].lowPrice = 100;
	inventory[7].midPrice = 200;
	inventory[7].highPrice = 300;
	inventory[7].stock = 1;
	inventory[7].biasFlags = 0x1;
	// Healer's Kit
	strcpy(inventory[8].name,"Healer's Kit");
	inventory[8].lowPrice = 300;
	inventory[8].midPrice = 500;
	inventory[8].highPrice = 800;
	inventory[8].stock = 5;
	inventory[8].biasFlags = 0x41;
	// Ink
	strcpy(inventory[9].name,"Ink (1 fl. oz.)");
	inventory[9].lowPrice = 700;
	inventory[9].midPrice = 1000;
	inventory[9].highPrice = 1500;
	inventory[9].stock = 15;
	inventory[9].biasFlags = 0x41;
	// Jug
	strcpy(inventory[10].name,"Jug");
	inventory[10].lowPrice = 1;
	inventory[10].midPrice = 2;
	inventory[10].highPrice = 3;
	inventory[10].stock = 1;
	inventory[10].biasFlags = 0x0;
	// Oil
	strcpy(inventory[11].name,"Oil (flask)");
	inventory[11].lowPrice = 7;
	inventory[11].midPrice = 10;
	inventory[11].highPrice = 20;
	inventory[11].stock = 1;
	inventory[11].biasFlags = 0x40;
	// Perfume
	strcpy(inventory[12].name,"Perfume (vial)");
	inventory[12].lowPrice = 300;
	inventory[12].midPrice = 500;
	inventory[12].highPrice = 800;
	inventory[12].stock = 18;
	inventory[12].biasFlags = 0x815;
	// Vial
	strcpy(inventory[13].name,"Vial");
	inventory[13].lowPrice = 70;
	inventory[13].midPrice = 100;
	inventory[13].highPrice = 200;
	inventory[13].stock = 1;
	inventory[13].biasFlags = 0x0;
	
	//  Tools Section Header
	strcpy(inventory[15].name,"TOOLS");
	inventory[15].lowPrice = 0;
	inventory[15].midPrice = 0;
	inventory[15].highPrice = 0;
	inventory[15].stock = 0;
	inventory[15].biasFlags = 0x0;
	//  Alchemist's Supplies
	strcpy(inventory[16].name,"Alchemist's Supplies");
	inventory[16].lowPrice = 3800;
	inventory[16].midPrice = 5000;
	inventory[16].highPrice = 7500;
	inventory[16].stock = 5;
	inventory[16].biasFlags = 0x1;
	//  Brewer's's Supplies
	strcpy(inventory[17].name,"Brewer's Supplies");
	inventory[17].lowPrice = 1500;
	inventory[17].midPrice = 2000;
	inventory[17].highPrice = 3000;
	inventory[17].stock = 2;
	inventory[17].biasFlags = 0xD51;
	//  Cook's Utensils
	strcpy(inventory[18].name,"Cook's Utensils");
	inventory[18].lowPrice = 70;
	inventory[18].midPrice = 100;
	inventory[18].highPrice = 200;
	inventory[18].stock = 5;
	inventory[18].biasFlags = 0x0;
	// Herbalism Kit
	strcpy(inventory[19].name,"Herbalism Kit");
	inventory[19].lowPrice = 30;
	inventory[19].midPrice = 50;
	inventory[19].highPrice = 80;
	inventory[19].stock = 5;
	inventory[19].biasFlags = 0x0;
	// Poisioner's Kit
	strcpy(inventory[20].name,"Poisioner's Kit");
	inventory[20].lowPrice = 3800;
	inventory[20].midPrice = 5000;
	inventory[20].highPrice = 7500;
	inventory[20].stock = 12;
	inventory[20].biasFlags = 0x4;
	
	// Potions Section Header
	strcpy(inventory[23].name,"POTIONS");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0x0;
	// Healing
	strcpy(inventory[24].name,"Healing");
	inventory[24].lowPrice = 3800;
	inventory[24].midPrice = 5000;
	inventory[24].highPrice = 7500;
	inventory[24].stock = 3;
	inventory[24].biasFlags = 0x1;
	// Climbing
	strcpy(inventory[25].name,"Climbing");
	inventory[25].lowPrice = 3800;
	inventory[25].midPrice = 5000;
	inventory[25].highPrice = 7500;
	inventory[25].stock = 3;
	inventory[25].biasFlags = 0x1;
	// Water Breathing
	strcpy(inventory[26].name,"Water Breathing");
	inventory[26].lowPrice = 17500;
	inventory[26].midPrice = 25000;
	inventory[26].highPrice = 37500;
	inventory[26].stock = 3;
	inventory[26].biasFlags = 0x1;
	// Greater Healing
	strcpy(inventory[27].name,"Greater Healing");
	inventory[27].lowPrice = 17500;
	inventory[27].midPrice = 25000;
	inventory[27].highPrice = 37500;
	inventory[27].stock = 5;
	inventory[27].biasFlags = 0x1;
	// Resistance
	strcpy(inventory[28].name,"Resistance");
	inventory[28].lowPrice = 17500;
	inventory[28].midPrice = 25000;
	inventory[28].highPrice = 37500;
	inventory[28].stock = 5;
	inventory[28].biasFlags = 0x1;
	// Animal Friendship
	strcpy(inventory[29].name,"Animal Friendship");
	inventory[29].lowPrice = 17500;
	inventory[29].midPrice = 25000;
	inventory[29].highPrice = 37500;
	inventory[29].stock = 10;
	inventory[29].biasFlags = 0x1;
	// Growth
	strcpy(inventory[30].name,"Growth");
	inventory[30].lowPrice = 17500;
	inventory[30].midPrice = 25000;
	inventory[30].highPrice = 37500;
	inventory[30].stock = 10;
	inventory[30].biasFlags = 0x1;
	// Oil of Slipperiness
	strcpy(inventory[31].name,"Oil of Slipperiness");
	inventory[31].lowPrice = 17500;
	inventory[31].midPrice = 25000;
	inventory[31].highPrice = 37500;
	inventory[31].stock = 16;
	inventory[31].biasFlags = 0x1;
	// Philter of Love
	strcpy(inventory[32].name,"Philter of Love");
	inventory[32].lowPrice = 17500;
	inventory[32].midPrice = 25000;
	inventory[32].highPrice = 37500;
	inventory[32].stock = 16;
	inventory[32].biasFlags = 0x5;
	// Fire Breath
	strcpy(inventory[33].name,"Fire Breath");
	inventory[33].lowPrice = 17500;
	inventory[33].midPrice = 25000;
	inventory[33].highPrice = 37500;
	inventory[33].stock = 16;
	inventory[33].biasFlags = 0x1;
	// Gaseous Form
	strcpy(inventory[34].name,"Gaseous Form");
	inventory[34].lowPrice = 175000;
	inventory[34].midPrice = 250000;
	inventory[34].highPrice = 375000;
	inventory[34].stock = 4;
	inventory[34].biasFlags = 0x1;
	// Elixir of Health
	strcpy(inventory[35].name,"Elixir of Health");
	inventory[35].lowPrice = 175000;
	inventory[35].midPrice = 250000;
	inventory[35].highPrice = 375000;
	inventory[35].stock = 6;
	inventory[35].biasFlags = 0x1;
	// Diminution
	strcpy(inventory[36].name,"Diminution");
	inventory[36].lowPrice = 175000;
	inventory[36].midPrice = 250000;
	inventory[36].highPrice = 375000;
	inventory[36].stock = 6;
	inventory[36].biasFlags = 0x1;
	// Heroism
	strcpy(inventory[37].name,"Heroism");
	inventory[37].lowPrice = 175000;
	inventory[37].midPrice = 250000;
	inventory[37].highPrice = 375000;
	inventory[37].stock = 11;
	inventory[37].biasFlags = 0x5;
	// Superior Healing
	strcpy(inventory[38].name,"Superior Healling");
	inventory[38].lowPrice = 175000;
	inventory[38].midPrice = 250000;
	inventory[38].highPrice = 375000;
	inventory[38].stock = 11;
	inventory[38].biasFlags = 0x1;
	// Clairvoyance`
	strcpy(inventory[39].name,"Clairvoyance");
	inventory[39].lowPrice = 175000;
	inventory[39].midPrice = 250000;
	inventory[39].highPrice = 375000;
	inventory[39].stock = 11;
	inventory[39].biasFlags = 0x5;
	// Frost Giant 
	strcpy(inventory[40].name,"Frost Giant Strength");
	inventory[40].lowPrice = 175000;
	inventory[40].midPrice = 250000;
	inventory[40].highPrice = 375000;
	inventory[40].stock = 11;
	inventory[40].biasFlags = 0x1;
	// Stone Giant
	strcpy(inventory[41].name,"Stone Giant Strength");
	inventory[41].lowPrice = 175000;
	inventory[41].midPrice = 250000;
	inventory[41].highPrice = 375000;
	inventory[41].stock = 11;
	inventory[41].biasFlags = 0x1;
	// Fire Giant
	strcpy(inventory[42].name,"Fire Giant Strength");
	inventory[42].lowPrice = 175000;
	inventory[42].midPrice = 250000;
	inventory[42].highPrice = 375000;
	inventory[42].stock = 17;
	inventory[42].biasFlags = 0x1;
	// Oil of Etherealness
	strcpy(inventory[43].name,"Oil of Etherealness");
	inventory[43].lowPrice = 175000;
	inventory[43].midPrice = 250000;
	inventory[43].highPrice = 375000;
	inventory[43].stock = 17;
	inventory[43].biasFlags = 0x1;
	// Invulnerability
	strcpy(inventory[44].name,"Invulnerability");
	inventory[44].lowPrice = 175000;
	inventory[44].midPrice = 250000;
	inventory[44].highPrice = 375000;
	inventory[44].stock = 17;
	inventory[44].biasFlags = 0x1;
	// Mind Reading
	strcpy(inventory[45].name,"Mind Reading");
	inventory[45].lowPrice = 175000;
	inventory[45].midPrice = 250000;
	inventory[45].highPrice = 375000;
	inventory[45].stock = 17;
	inventory[45].biasFlags = 0x5;
	
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	if (shopStock >= 17){// Shop has posions
		fprintf(storeHere,"\nPOSIONS\n");
		fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
		fprintf(storeHere, "%c", dividerChar); 
		fprintf(storeHere, "   %s   ", "Type"); // Type Colum
		fprintf(storeHere, "%c",dividerChar);
		fprintf(storeHere, "   %s  ", "Price"); // Price Colum
		fprintf(storeHere, "%c",dividerChar);
		fprintf(storeHere, "   %s   ", "Description"); // Description Colum
		fprintf(storeHere, "\n");
		if ((rand()%2)==0){// Assassins Blood
			fprintf(storeHere, "%32s", "Assassins Blood");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Ingested");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(15000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 10 Constitution throw, on fail 1d12(6) poison damage and poisoned for 24 hours. On success half damage,\n                                                     creature isn’t poisoned.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%3)==0){// Burnt Othur Fumes
			fprintf(storeHere, "%32s", "Burnt Othur Fumes");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Inhaled");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(50000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 13 Constitution or 3d6(10) poison damage, repeating throw at start of each of its turns taking 1d6(3) on\n                                                     successive fails. After three saves poison ends");
			fprintf(storeHere, "\n");
		}
		if ((rand()%2)==0){// Carrion Crawler Mucus
			fprintf(storeHere, "%32s", "Carrion Crawler Mucus");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Contact");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(20000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 13 Constitution or be poisoned for 1 minute. Poisoned creature is paralyzed. Repeat throw at end of each turn,\n                                                     ending on success.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%2)==0){// Drow
			fprintf(storeHere, "%32s", "Drow");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Injury");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(20000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 13 Constitution or poisoned for 1 hour. If throw failed by 5 or more creatures is unconscious. Wakened by damage\n                                                     or if another creature takes an action to shake it awake.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%3)==0){// Essence of Ether
			fprintf(storeHere, "%32s", "Essence of Ether");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Inhaled");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(30000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 15 Constitution or poisoned for 8 hours. Poisoned creature is unconscious. Wakened by damage or if another\n                                                     creature takes an action to shake it awake.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%2)==0){// Love
			fprintf(storeHere, "%32s", "Love Stimulant");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Ingested");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(1000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 10 Wisdom, on fail creature becomes infatuated with first creature it sees after ingesting for 1 hour. Creature\n                                                     refuses to leave the side of creature it is infatuated with and will resist violently if necessary.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%2)==0){// Malice
			fprintf(storeHere, "%32s", "Malice");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Inhaled");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(25000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "Dc 15 Constitution or poisoned for 1 hour. Poisoned creature is blinded.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%4)==0){// Midnight Tears
			fprintf(storeHere, "%32s", "Midnight Tears");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Inhaled");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(150000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "No effect until midnight. At midnight DC 17 Constitution or 9d6(31) poison damage. Half on success.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%3)==0){// Oil of Taggit
			fprintf(storeHere, "%32s", "Oil of Taggit");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Contact");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(40000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 13 Constitution or poisoned for 24 hours. Poisoned creature is unconscious. Creature wakes if takes damage.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%2)==0){// Pale Tincture
			fprintf(storeHere, "%32s", "Pale Tincture");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Ingested");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(25000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 16 Constitution or 1d6(3) poison damage and becomes poisoned. Repeat throw every 24 hours. Take 1d6(3) on\n                                                     failed save. Until poison ends damage dealt by poison cannot be healed. 7 successful saves end the effects. ");
			fprintf(storeHere, "\n");
		}
		if ((rand()%4)==0){// Purple Worm Poison
			fprintf(storeHere, "%32s", "Purple Worm Poison");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Injury");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(200000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 19 Constitution taking 12d6(42) poison damage on fail, half on success. ");
			fprintf(storeHere, "\n");
		}
		if ((rand()%10)==0){// Glove Cleaner
			fprintf(storeHere, "%32s", "Glove Cleaner");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Ingested");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(1000000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "Upon ingestion creature dies. Dose must be ingested within 1 minute of the target coming within 5 feet, or\n                                                     they become immune to the dose.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%2)==0){// Serpent Venom
			fprintf(storeHere, "%32s", "Serpent Venom");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Injury");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(20000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 11 Constitution taking 3d6(10) poison damage on fail, half on success.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%3)==0){// Torpor
			fprintf(storeHere, "%32s", "Torpor");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Ingested");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(60000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 15 Constitution or poisoned for 4d6 hours. Poisoned creature is incapacitated.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%2)==0){// Truth Serum
			fprintf(storeHere, "%32s", "Truth Serum");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Ingested");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(15000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "Dc 11 Constitution or poisoned for 1 hour. Poisoned creature can’t knowingly speak a lie.");
			fprintf(storeHere, "\n");
		}
		if ((rand()%5)==0){// Wyvern Posion
			fprintf(storeHere, "%32s", "Wyvern Posion");
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "%9s", "Injury");
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(120000, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			fprintf(storeHere, "DC 15 Constitution taking 7d6(24) poison damage on a fail, half on a success.");
			fprintf(storeHere, "\n");
		}
		fprintf(storeHere, "\nFor more information on posion prices and effects see the Demagus True Reference PDF\n");
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeArcana(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 49;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Armor Section Name
	strcpy(inventory[0].name,"WEAPONS");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Quarterstaff
	strcpy(inventory[1].name,"Quarterstaff");
	inventory[1].lowPrice = 10;
	inventory[1].midPrice = 20;
	inventory[1].highPrice = 30;
	inventory[1].stock = 2;
	inventory[1].biasFlags = 0x20;
	
	// Gear
	strcpy(inventory[2].name,"GEAR");
	inventory[2].lowPrice = 0;
	inventory[2].midPrice = 0;
	inventory[2].highPrice = 0;
	inventory[2].stock = 0;
	inventory[2].biasFlags = 0;
	// Abacus
	strcpy(inventory[3].name,"Abacus");
	inventory[3].lowPrice = 100;
	inventory[3].midPrice = 200;
	inventory[3].highPrice = 300;
	inventory[3].stock = 5;
	inventory[3].biasFlags = 0x41;
	// Candle
	strcpy(inventory[4].name,"Candle");
	inventory[4].lowPrice = 1;
	inventory[4].midPrice = 1;
	inventory[4].highPrice = 2;
	inventory[4].stock = 2;
	inventory[4].biasFlags = 0x141;
	// Scroll Case
	strcpy(inventory[5].name,"Scroll Case");
	inventory[5].lowPrice = 70;
	inventory[5].midPrice = 100;
	inventory[5].highPrice = 200;
	inventory[5].stock = 5;
	inventory[5].biasFlags = 0x101;
	// Crystal
	strcpy(inventory[6].name,"Crystal");
	inventory[6].lowPrice = 700;
	inventory[6].midPrice = 1000;
	inventory[6].highPrice = 1500;
	inventory[6].stock = 1;
	inventory[6].biasFlags = 0x5;
	// Component Pouch
	strcpy(inventory[7].name,"Component Pouch");
	inventory[7].lowPrice = 1800;
	inventory[7].midPrice = 2500;
	inventory[7].highPrice = 3800;
	inventory[7].stock = 15;
	inventory[7].biasFlags = 0x1;
	// Glass Bottle
	strcpy(inventory[8].name,"Glass Bottle");
	inventory[8].lowPrice = 100;
	inventory[8].midPrice = 200;
	inventory[8].highPrice = 300;
	inventory[8].stock = 1;
	inventory[8].biasFlags = 0x1;
	// Hourglass
	strcpy(inventory[9].name,"Hourglass");
	inventory[9].lowPrice = 1800;
	inventory[9].midPrice = 2500;
	inventory[9].highPrice = 3800;
	inventory[9].stock = 18;
	inventory[9].biasFlags = 0x45;
	// Ink
	strcpy(inventory[10].name,"Ink (1 fl. oz.)");
	inventory[10].lowPrice = 700;
	inventory[10].midPrice = 1000;
	inventory[10].highPrice = 1500;
	inventory[10].stock = 5;
	inventory[10].biasFlags = 0x141;
	// Ink Pen
	strcpy(inventory[11].name,"Ink Pen");
	inventory[11].lowPrice = 1;
	inventory[11].midPrice = 2;
	inventory[11].highPrice = 3;
	inventory[11].stock = 5;
	inventory[11].biasFlags = 0x141;
	// Orb
	strcpy(inventory[12].name,"Orb");
	inventory[12].lowPrice = 1500;
	inventory[12].midPrice = 2000;
	inventory[12].highPrice = 3000;
	inventory[12].stock = 5;
	inventory[12].biasFlags = 0x1;
	// Paper
	strcpy(inventory[13].name,"Paper (1)");
	inventory[13].lowPrice = 10;
	inventory[13].midPrice = 20;
	inventory[13].highPrice = 30;
	inventory[13].stock = 5;
	inventory[13].biasFlags = 0x141;
	// Parchment
	strcpy(inventory[14].name,"Parchment (1)");
	inventory[14].lowPrice = 7;
	inventory[14].midPrice = 10;
	inventory[14].highPrice = 20;
	inventory[14].stock = 1;
	inventory[14].biasFlags = 0x141;
	// Pouch
	strcpy(inventory[15].name,"Pouch");
	inventory[15].lowPrice = 30;
	inventory[15].midPrice = 50;
	inventory[15].highPrice = 80;
	inventory[15].stock = 5;
	inventory[15].biasFlags = 0x1;
	// Robes
	strcpy(inventory[16].name,"Robes");
	inventory[16].lowPrice = 70;
	inventory[16].midPrice = 100;
	inventory[16].highPrice = 200;
	inventory[16].stock = 5;
	inventory[16].biasFlags = 0x101;
	// Rod
	strcpy(inventory[17].name,"Rod");
	inventory[17].lowPrice = 70;
	inventory[17].midPrice = 100;
	inventory[17].highPrice = 1500;
	inventory[17].stock = 5;
	inventory[17].biasFlags = 0x801;
	// Spellbook
	strcpy(inventory[18].name,"Spellbook");
	inventory[18].lowPrice = 3800;
	inventory[18].midPrice = 5000;
	inventory[18].highPrice = 7500;
	inventory[18].stock = 7;
	inventory[18].biasFlags = 0x1;
	// Mistletoe
	strcpy(inventory[19].name,"Sprig of Mistletoe");
	inventory[19].lowPrice = 70;
	inventory[19].midPrice = 100;
	inventory[19].highPrice = 200;
	inventory[19].stock = 3;
	inventory[19].biasFlags = 0x801;
	// Staff
	strcpy(inventory[20].name,"Staff");
	inventory[20].lowPrice = 300;
	inventory[20].midPrice = 500;
	inventory[20].highPrice = 800;
	inventory[20].stock = 3;
	inventory[20].biasFlags = 0x1;
	// Wooden Staff
	strcpy(inventory[21].name,"Wooden Staff");
	inventory[21].lowPrice = 100;
	inventory[21].midPrice = 200;
	inventory[21].highPrice = 300;
	inventory[21].stock = 2;
	inventory[21].biasFlags = 0x1;
	// Totem
	strcpy(inventory[22].name,"Totem");
	inventory[22].lowPrice = 70;
	inventory[22].midPrice = 100;
	inventory[22].highPrice = 200;
	inventory[22].stock = 3;
	inventory[22].biasFlags = 0x401;
	// Wand
	strcpy(inventory[23].name,"Wand");
	inventory[23].lowPrice = 700;
	inventory[23].midPrice = 1000;
	inventory[23].highPrice = 1500;
	inventory[23].stock = 2;
	inventory[23].biasFlags = 0x1;
	// Yew Wand
	strcpy(inventory[24].name,"Yew Wand");
	inventory[24].lowPrice = 700;
	inventory[24].midPrice = 1000;
	inventory[24].highPrice = 1500;
	inventory[24].stock = 5;
	inventory[24].biasFlags = 0x1;
	
	// Tools Section Header
	strcpy(inventory[27].name,"TOOLS");
	inventory[27].lowPrice = 0;
	inventory[27].midPrice = 0;
	inventory[27].highPrice = 0;
	inventory[27].stock = 0;
	inventory[27].biasFlags = 0;
	// Alchemist's Supplies
	strcpy(inventory[28].name,"Alchemist's Supplies");
	inventory[28].lowPrice = 3800;
	inventory[28].midPrice = 5000;
	inventory[28].highPrice = 7500;
	inventory[28].stock = 5;
	inventory[28].biasFlags = 0x0;
	// Calligrapher's Supplies
	strcpy(inventory[29].name,"Calligrapher's Supplies");
	inventory[29].lowPrice = 700;
	inventory[29].midPrice = 1000;
	inventory[29].highPrice = 1500;
	inventory[29].stock = 5;
	inventory[29].biasFlags = 0x4;
	// Lute
	strcpy(inventory[30].name,"Lute");
	inventory[30].lowPrice = 2600;
	inventory[30].midPrice = 3500;
	inventory[30].highPrice = 5300;
	inventory[30].stock = 10;
	inventory[30].biasFlags = 0x4;
	// Lyre
	strcpy(inventory[31].name,"Lyre");
	inventory[31].lowPrice = 2600;
	inventory[31].midPrice = 3500;
	inventory[31].highPrice = 5300;
	inventory[31].stock = 18;
	inventory[31].biasFlags = 0x4;
	
	// Magical Items Section Header
	strcpy(inventory[39].name,"MAGIC SCROLLS");
	inventory[39].lowPrice = 0;
	inventory[39].midPrice = 0;
	inventory[39].highPrice = 0;
	inventory[39].stock = 0;
	inventory[39].biasFlags = 0;
	// Cantrip
	strcpy(inventory[40].name,"Cantrip");
	inventory[40].lowPrice = 3800;
	inventory[40].midPrice = 5000;
	inventory[40].highPrice = 7500;
	inventory[40].stock = 3;
	inventory[40].biasFlags = 0x5;
	// Level 1
	strcpy(inventory[41].name,"Level 1");
	inventory[41].lowPrice = 7500;
	inventory[41].midPrice = 10000;
	inventory[41].highPrice = 15000;
	inventory[41].stock = 5;
	inventory[41].biasFlags = 0x5;
	// Level 2
	strcpy(inventory[42].name,"Level 2");
	inventory[42].lowPrice = 18700;
	inventory[42].midPrice = 25000;
	inventory[42].highPrice = 37500;
	inventory[42].stock = 8;
	inventory[42].biasFlags = 0x1;
	// Level 3
	strcpy(inventory[43].name,"Level 3");
	inventory[43].lowPrice = 37500;
	inventory[43].midPrice = 50000;
	inventory[43].highPrice = 75000;
	inventory[43].stock = 11;
	inventory[43].biasFlags = 0x5;
	// Level 4
	strcpy(inventory[44].name,"Level 4");
	inventory[44].lowPrice = 187000;
	inventory[44].midPrice = 250000;
	inventory[44].highPrice = 375000;
	inventory[44].stock = 14;
	inventory[44].biasFlags = 0x5;
	// Level 5
	strcpy(inventory[45].name,"Level 5");
	inventory[45].lowPrice = 375000;
	inventory[45].midPrice = 500000;
	inventory[45].highPrice = 750000;
	inventory[45].stock = 17;
	inventory[45].biasFlags = 0x5;
	
	// Services
	strcpy(inventory[47].name,"SERVICES");
	inventory[47].lowPrice = 0;
	inventory[47].midPrice = 0;
	inventory[47].highPrice = 0;
	inventory[47].stock = 0;
	inventory[47].biasFlags = 0;
	// Identify
	strcpy(inventory[48].name,"Identify");
	inventory[48].lowPrice = 7500;
	inventory[48].midPrice = 10000;
	inventory[48].highPrice = 15000;
	inventory[48].stock = 2;
	inventory[48].biasFlags = 0x1;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeBakery(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 47;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// FOODSTUFFS Section Name
	strcpy(inventory[0].name,"FOODSTUFFS");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Apples
	strcpy(inventory[1].name,"Apples (1 lb.)");
	inventory[1].lowPrice = 1;
	inventory[1].midPrice = 2;
	inventory[1].highPrice = 10;
	inventory[1].stock = 15;
	inventory[1].biasFlags = 0x200;
	// Berries
	strcpy(inventory[2].name,"Berries (1 lb.)");
	inventory[2].lowPrice = 3;
	inventory[2].midPrice = 5;
	inventory[2].highPrice = 10;
	inventory[2].stock = 15;
	inventory[2].biasFlags = 0x204;
	// Butter
	strcpy(inventory[3].name,"Butter (1 lb.)");
	inventory[3].lowPrice = 10;
	inventory[3].midPrice = 20;
	inventory[3].highPrice = 30;
	inventory[3].stock = 10;
	inventory[3].biasFlags = 0x204;
	// Corn
	strcpy(inventory[4].name,"Corn (1 lb.)");
	inventory[4].lowPrice = 4;
	inventory[4].midPrice = 6;
	inventory[4].highPrice = 8;
	inventory[4].stock = 5;
	inventory[4].biasFlags = 0x200;
	// Feed Corn
	strcpy(inventory[5].name,"Feed Corn (1 lb.)");
	inventory[5].lowPrice = 1;
	inventory[5].midPrice = 1;
	inventory[5].highPrice = 2;
	inventory[5].stock = 5;
	inventory[5].biasFlags = 0xA00;
	// Sweet Corn
	strcpy(inventory[6].name,"Sweet Corn (1 lb.)");
	inventory[6].lowPrice = 8;
	inventory[6].midPrice = 10;
	inventory[6].highPrice = 12;
	inventory[6].stock = 7;
	inventory[6].biasFlags = 0x204;
	// Cornmeal
	strcpy(inventory[7].name,"Cornmeal (1 lb.)");
	inventory[7].lowPrice = 6;
	inventory[7].midPrice = 8;
	inventory[7].highPrice = 10;
	inventory[7].stock = 3;
	inventory[7].biasFlags = 0x200;
	// Sweet Cornmeal
	strcpy(inventory[8].name,"Sweet Cornmeal (1 lb.)");
	inventory[8].lowPrice = 12;
	inventory[8].midPrice = 15;
	inventory[8].highPrice = 18;
	inventory[8].stock = 5;
	inventory[8].biasFlags = 0x204;
	// Eggs
	strcpy(inventory[9].name,"Eggs (1 dozen)");
	inventory[9].lowPrice = 4;
	inventory[9].midPrice = 6;
	inventory[9].highPrice = 9;
	inventory[9].stock = 7;
	inventory[9].biasFlags = 0x200;
	// Flour
	strcpy(inventory[10].name,"Flour (1 lb.)");
	inventory[10].lowPrice = 4;
	inventory[10].midPrice = 5;
	inventory[10].highPrice = 7;
	inventory[10].stock = 3;
	inventory[10].biasFlags = 0x200;
	// Grapes
	strcpy(inventory[11].name,"Grapes (1 lb.)");
	inventory[11].lowPrice = 1;
	inventory[11].midPrice = 2;
	inventory[11].highPrice = 10;
	inventory[11].stock = 15;
	inventory[11].biasFlags = 0x204;
	// Honey
	strcpy(inventory[12].name,"Honey (1 qt.)");
	inventory[12].lowPrice = 60;
	inventory[12].midPrice = 70;
	inventory[12].highPrice = 80;
	inventory[12].stock = 10;
	inventory[12].biasFlags = 0x204;
	// Milk
	strcpy(inventory[13].name,"Milk (1 gal.)");
	inventory[13].lowPrice = 1;
	inventory[13].midPrice = 2;
	inventory[13].highPrice = 4;
	inventory[13].stock = 10;
	inventory[13].biasFlags = 0x200;
	// Nuts
	strcpy(inventory[14].name,"Nuts (1 lb.)");
	inventory[14].lowPrice = 3;
	inventory[14].midPrice = 5;
	inventory[14].highPrice = 8;
	inventory[14].stock = 5;
	inventory[14].biasFlags = 0x200;
	// Salt
	strcpy(inventory[15].name,"Salt (1 lb.)");
	inventory[15].lowPrice = 3;
	inventory[15].midPrice = 5;
	inventory[15].highPrice = 8;
	inventory[15].stock = 2;
	inventory[15].biasFlags = 0x200;
	// Tallow
	strcpy(inventory[16].name,"Tallow (1 lb.)");
	inventory[16].lowPrice = 40;
	inventory[16].midPrice = 60;
	inventory[16].highPrice = 80;
	inventory[16].stock = 10;
	inventory[16].biasFlags = 0x200;
	// Wheat
	strcpy(inventory[17].name,"Wheat (1 lb.)");
	inventory[17].lowPrice = 1;
	inventory[17].midPrice = 2;
	inventory[17].highPrice = 3;
	inventory[17].stock = 10;
	inventory[17].biasFlags = 0x200;
	// DISHES Section Name
	strcpy(inventory[23].name,"DISHES");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0;
	// Biscuits 
	strcpy(inventory[24].name,"Biscuits");
	inventory[24].lowPrice = 7;
	inventory[24].midPrice = 10;
	inventory[24].highPrice = 20;
	inventory[24].stock = 7;
	inventory[24].biasFlags = 0x204;
	// Slice of Bread 
	strcpy(inventory[25].name,"Bread (slice)");
	inventory[25].lowPrice = 2;
	inventory[25].midPrice = 3;
	inventory[25].highPrice = 5;
	inventory[25].stock = 5;
	inventory[25].biasFlags = 0x200;
	// Loaf of Bread 
	strcpy(inventory[26].name,"Bread (loaf)");
	inventory[26].lowPrice = 6;
	inventory[26].midPrice = 8;
	inventory[26].highPrice = 10;
	inventory[26].stock = 5;
	inventory[26].biasFlags = 0x200;
	// Slice of White Bread 
	strcpy(inventory[27].name,"White Bread (slice)");
	inventory[27].lowPrice = 4;
	inventory[27].midPrice = 6;
	inventory[27].highPrice = 10;
	inventory[27].stock = 5;
	inventory[27].biasFlags = 0x204;
	// Loaf of White Bread 
	strcpy(inventory[28].name,"White Bread (loaf)");
	inventory[28].lowPrice = 14;
	inventory[28].midPrice = 16;
	inventory[28].highPrice = 20;
	inventory[28].stock = 5;
	inventory[28].biasFlags = 0x204;
	// Slice of Cornbread 
	strcpy(inventory[29].name,"Cornbread (slice)");
	inventory[29].lowPrice = 3;
	inventory[29].midPrice = 4;
	inventory[29].highPrice = 5;
	inventory[29].stock = 5;
	inventory[29].biasFlags = 0x200;
	// Loaf of Cornbread 
	strcpy(inventory[30].name,"Cornbread (loaf)");
	inventory[30].lowPrice = 8;
	inventory[30].midPrice = 11;
	inventory[30].highPrice = 14;
	inventory[30].stock = 5;
	inventory[30].biasFlags = 0x200;
	// Slice of Sweet Cornbread 
	strcpy(inventory[31].name,"Sweet Cornbread (slice)");
	inventory[31].lowPrice = 5;
	inventory[31].midPrice = 6;
	inventory[31].highPrice = 7;
	inventory[31].stock = 5;
	inventory[31].biasFlags = 0x204;
	// Loaf of Sweet Cornbread 
	strcpy(inventory[32].name,"Sweet Cornbread (loaf)");
	inventory[32].lowPrice = 15;
	inventory[32].midPrice = 18;
	inventory[32].highPrice = 22;
	inventory[32].stock = 5;
	inventory[32].biasFlags = 0x204;
	// Doughnut 
	strcpy(inventory[33].name,"Doughnut");
	inventory[33].lowPrice = 1;
	inventory[33].midPrice = 2;
	inventory[33].highPrice = 4;
	inventory[33].stock = 10;
	inventory[33].biasFlags = 0xA41;
	// Dumplings 
	strcpy(inventory[34].name,"Dumplings");
	inventory[34].lowPrice = 3;
	inventory[34].midPrice = 4;
	inventory[34].highPrice = 5;
	inventory[34].stock = 6;
	inventory[34].biasFlags = 0x200;
	// Cheese Dumplings 
	strcpy(inventory[35].name,"Cheese Dumplings");
	inventory[35].lowPrice = 12;
	inventory[35].midPrice = 15;
	inventory[35].highPrice = 18;
	inventory[35].stock = 7;
	inventory[35].biasFlags = 0x200;
	// Potatoe Dumplings 
	strcpy(inventory[36].name,"Potatoe Dumplings");
	inventory[36].lowPrice = 2;
	inventory[36].midPrice = 3;
	inventory[36].highPrice = 4;
	inventory[36].stock = 6;
	inventory[36].biasFlags = 0x200;
	// Meat Dumplings 
	strcpy(inventory[37].name,"Meat Dumplings");
	inventory[37].lowPrice = 12;
	inventory[37].midPrice = 15;
	inventory[37].highPrice = 18;
	inventory[37].stock = 8;
	inventory[37].biasFlags = 0x204;
	// Vegetable Dumplings 
	strcpy(inventory[38].name,"Vegetable Dumplings");
	inventory[38].lowPrice = 7;
	inventory[38].midPrice = 10;
	inventory[38].highPrice = 12;
	inventory[38].stock = 7;
	inventory[38].biasFlags = 0x200;
	// Hardtack 
	strcpy(inventory[39].name,"Hardtack");
	inventory[39].lowPrice = 6;
	inventory[39].midPrice = 8;
	inventory[39].highPrice = 10;
	inventory[39].stock = 10;
	inventory[39].biasFlags = 0x210;
	// Hushpuppy 
	strcpy(inventory[40].name,"Hushpuppy");
	inventory[40].lowPrice = 4;
	inventory[40].midPrice = 6;
	inventory[40].highPrice = 10;
	inventory[40].stock = 12;
	inventory[40].biasFlags = 0x202;
	// Kringle 
	strcpy(inventory[41].name,"Kringle");
	inventory[41].lowPrice = 17;
	inventory[41].midPrice = 20;
	inventory[41].highPrice = 25;
	inventory[41].stock = 15;
	inventory[41].biasFlags = 0x255;
	// Pancake 
	strcpy(inventory[42].name,"Pancake");
	inventory[42].lowPrice = 4;
	inventory[42].midPrice = 6;
	inventory[42].highPrice = 8;
	inventory[42].stock = 7;
	inventory[42].biasFlags = 0x200;
	// Apple Pie 
	strcpy(inventory[43].name,"Apple Pie");
	inventory[43].lowPrice = 10;
	inventory[43].midPrice = 12;
	inventory[43].highPrice = 15;
	inventory[43].stock = 12;
	inventory[43].biasFlags = 0x605;
	// Berry Pie 
	strcpy(inventory[44].name,"Berry Pie");
	inventory[44].lowPrice = 26;
	inventory[44].midPrice = 28;
	inventory[44].highPrice = 35;
	inventory[44].stock = 12;
	inventory[44].biasFlags = 0x205;
	// Nut Pie 
	strcpy(inventory[45].name,"Nut Pie");
	inventory[45].lowPrice = 12;
	inventory[45].midPrice = 15;
	inventory[45].highPrice = 18;
	inventory[45].stock = 12;
	inventory[45].biasFlags = 0x205;
	// Shepherds Pie 
	strcpy(inventory[46].name,"Shepherds Pie");
	inventory[46].lowPrice = 25;
	inventory[46].midPrice = 28;
	inventory[46].highPrice = 32;
	inventory[46].stock = 12;
	inventory[46].biasFlags = 0xA05;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeBarber(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 128;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// WEAPONS Section Name
	strcpy(inventory[0].name,"WEAPONS");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Dagger
	strcpy(inventory[1].name,"Dagger");
	inventory[1].lowPrice = 100;
	inventory[1].midPrice = 200;
	inventory[1].highPrice = 300;
	inventory[1].stock = 5;
	inventory[1].biasFlags = 0x0;
	// GEAR Section Name
	strcpy(inventory[7].name,"GEAR");
	inventory[7].lowPrice = 0;
	inventory[7].midPrice = 0;
	inventory[7].highPrice = 0;
	inventory[7].stock = 0;
	inventory[7].biasFlags = 0;
	// Glass Bottle
	strcpy(inventory[8].name,"Glass Bottle");
	inventory[8].lowPrice = 100;
	inventory[8].midPrice = 200;
	inventory[8].highPrice = 300;
	inventory[8].stock = 5;
	inventory[8].biasFlags = 0x0;
	// Healer's Kit
	strcpy(inventory[9].name,"Healer's kit");
	inventory[9].lowPrice = 300;
	inventory[9].midPrice = 500;
	inventory[9].highPrice = 700;
	inventory[9].stock = 5;
	inventory[9].biasFlags = 0x50;
	// Jug
	strcpy(inventory[10].name,"Jug");
	inventory[10].lowPrice = 1;
	inventory[10].midPrice = 2;
	inventory[10].highPrice = 3;
	inventory[10].stock = 5;
	inventory[10].biasFlags = 0x0;
	
	// TOOLS Section Name
	strcpy(inventory[15].name,"TOOLS");
	inventory[15].lowPrice = 0;
	inventory[15].midPrice = 0;
	inventory[15].highPrice = 0;
	inventory[15].stock = 0;
	inventory[15].biasFlags = 0;
	// Jeweler's Tools
	strcpy(inventory[16].name,"Jeweler's Tools");
	inventory[16].lowPrice = 1800;
	inventory[16].midPrice = 2500;
	inventory[16].highPrice = 3800;
	inventory[16].stock = 18;
	inventory[16].biasFlags = 0x0;
	// Thieves's Tools
	strcpy(inventory[17].name,"Thieves's Tools");
	inventory[17].lowPrice = 1800;
	inventory[17].midPrice = 2500;
	inventory[17].highPrice = 3800;
	inventory[17].stock = 18;
	inventory[17].biasFlags = 0x0;
	
	// SERVICES Section Name
	strcpy(inventory[23].name,"SERVICES");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0;
	// Amputation
	strcpy(inventory[24].name,"Amputation");
	inventory[24].lowPrice = 30;
	inventory[24].midPrice = 50;
	inventory[24].highPrice = 70;
	inventory[24].stock = 1;
	inventory[24].biasFlags = 0x0;
	// Hair Cut
	strcpy(inventory[25].name,"Hair Cut");
	inventory[25].lowPrice = 10;
	inventory[25].midPrice = 20;
	inventory[25].highPrice = 30;
	inventory[25].stock = 1;
	inventory[25].biasFlags = 0x0;
	// Heal
	strcpy(inventory[26].name,"Heal 1 Hit Dice");
	inventory[26].lowPrice = 70;
	inventory[26].midPrice = 100;
	inventory[26].highPrice = 200;
	inventory[26].stock = 5;
	inventory[26].biasFlags = 0x80;
	// Shave
	strcpy(inventory[27].name,"Shave");
	inventory[27].lowPrice = 10;
	inventory[27].midPrice = 20;
	inventory[27].highPrice = 30;
	inventory[27].stock = 1;
	inventory[27].biasFlags = 0x0;
	// Surgery
	strcpy(inventory[28].name,"Amputation");
	inventory[28].lowPrice = 70;
	inventory[28].midPrice = 100;
	inventory[28].highPrice = 200;
	inventory[28].stock = 10;
	inventory[28].biasFlags = 0x80;
	
	// FOODSTUFFS Section Name
	strcpy(inventory[31].name,"FOODSTUFFS");
	inventory[31].lowPrice = 0;
	inventory[31].midPrice = 0;
	inventory[31].highPrice = 0;
	inventory[31].stock = 0;
	inventory[31].biasFlags = 0;
	// Common Spirit
	strcpy(inventory[32].name,"Common Spirit (1 qt.)");
	inventory[32].lowPrice = 20;
	inventory[32].midPrice = 30;
	inventory[32].highPrice = 50;
	inventory[32].stock = 5;
	inventory[32].biasFlags = 0x80;
	// Good Spirit
	strcpy(inventory[33].name,"Good Spirit (1 qt.)");
	inventory[33].lowPrice = 50;
	inventory[33].midPrice = 70;
	inventory[33].highPrice = 100;
	inventory[33].stock = 10;
	inventory[33].biasFlags = 0x80;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeBlacksmith(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 106;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Light Armor Section Name
	strcpy(inventory[0].name,"LIGHT ARMOR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Studded Leather
	strcpy(inventory[1].name,"Studded Leather");
	inventory[1].lowPrice = 3300;
	inventory[1].midPrice = 4500;
	inventory[1].highPrice = 6800;
	inventory[1].stock = 18;
	inventory[1].biasFlags = 0x10;
	
	// Medium Armor Section Name
	strcpy(inventory[3].name,"MEDIUM ARMOR");
	inventory[3].lowPrice = 0;
	inventory[3].midPrice = 0;
	inventory[3].highPrice = 0;
	inventory[3].stock = 0;
	inventory[3].biasFlags = 0;
	// Chain Shirt
	strcpy(inventory[4].name,"Chain Shirt");
	inventory[4].lowPrice = 3800;
	inventory[4].midPrice = 5000;
	inventory[4].highPrice = 7500;
	inventory[4].stock = 3;
	inventory[4].biasFlags = 0x10;
	// Scale Mail
	strcpy(inventory[5].name,"Scale Mail");
	inventory[5].lowPrice = 3800;
	inventory[5].midPrice = 5000;
	inventory[5].highPrice = 7500;
	inventory[5].stock = 5;
	inventory[5].biasFlags = 0x10;
	// Breastplate
	strcpy(inventory[6].name,"Breastplate");
	inventory[6].lowPrice = 30000;
	inventory[6].midPrice = 40000;
	inventory[6].highPrice = 60000;
	inventory[6].stock = 3;
	inventory[6].biasFlags = 0x10;
	// Halfplate
	strcpy(inventory[7].name,"Halfplate");
	inventory[7].lowPrice = 56000;
	inventory[7].midPrice = 75000;
	inventory[7].highPrice = 112000;
	inventory[7].stock = 18;
	inventory[7].biasFlags = 0x10;
	
	// Heavy Armor Section Name
	strcpy(inventory[11].name,"HEAVY ARMOR");
	inventory[11].lowPrice = 0;
	inventory[11].midPrice = 0;
	inventory[11].highPrice = 0;
	inventory[11].stock = 0;
	inventory[11].biasFlags = 0;
	// Ring Mail
	strcpy(inventory[12].name,"Ring Mail");
	inventory[12].lowPrice = 2200;
	inventory[12].midPrice = 3000;
	inventory[12].highPrice = 4500;
	inventory[12].stock = 6;
	inventory[12].biasFlags = 0x10;
	// Chain Mail
	strcpy(inventory[13].name,"Chain Mail");
	inventory[13].lowPrice = 5600;
	inventory[13].midPrice = 7500;
	inventory[13].highPrice = 11200;
	inventory[13].stock = 4;
	inventory[13].biasFlags = 0x10;
	// Splint
	strcpy(inventory[14].name,"Splint");
	inventory[14].lowPrice = 15000;
	inventory[14].midPrice = 20000;
	inventory[14].highPrice = 30000;
	inventory[14].stock = 6;
	inventory[14].biasFlags = 0x10;
	// Plate
	strcpy(inventory[15].name,"Plate");
	inventory[15].lowPrice = 112500;
	inventory[15].midPrice = 150000;
	inventory[15].highPrice = 225000;
	inventory[15].stock = 18;
	inventory[15].biasFlags = 0x10;
	
	// Shield Section Name
	strcpy(inventory[17].name,"SHIELD");
	inventory[17].lowPrice = 0;
	inventory[17].midPrice = 0;
	inventory[17].highPrice = 0;
	inventory[17].stock = 0;
	inventory[17].biasFlags = 0;
	// Shield
	strcpy(inventory[18].name,"Shield");
	inventory[18].lowPrice = 700;
	inventory[18].midPrice = 1000;
	inventory[18].highPrice = 1500;
	inventory[18].stock = 2;
	inventory[18].biasFlags = 0x10;
	
	// Simple Weapons Section Name
	strcpy(inventory[23].name,"SIMPLE WEAPONS");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0;
	// Dagger
	strcpy(inventory[24].name,"Dagger");
	inventory[24].lowPrice = 100;
	inventory[24].midPrice = 200;
	inventory[24].highPrice = 300;
	inventory[24].stock = 3;
	inventory[24].biasFlags = 0x10;
	// Handaxe
	strcpy(inventory[25].name,"Handaxe");
	inventory[25].lowPrice = 300;
	inventory[25].midPrice = 500;
	inventory[25].highPrice = 800;
	inventory[25].stock = 3;
	inventory[25].biasFlags = 0x410;
	// Javelin
	strcpy(inventory[26].name,"Javelin");
	inventory[26].lowPrice = 300;
	inventory[26].midPrice = 500;
	inventory[26].highPrice = 800;
	inventory[26].stock = 5;
	inventory[26].biasFlags = 0x10;
	// Light Hammer
	strcpy(inventory[27].name,"Light Hammer");
	inventory[27].lowPrice = 100;
	inventory[27].midPrice = 200;
	inventory[27].highPrice = 300;
	inventory[27].stock = 5;
	inventory[27].biasFlags = 0xD0;
	// Mace
	strcpy(inventory[28].name,"Mace");
	inventory[28].lowPrice = 300;
	inventory[28].midPrice = 500;
	inventory[28].highPrice = 800;
	inventory[28].stock = 5;
	inventory[28].biasFlags = 0x100;
	// Sickle
	strcpy(inventory[29].name,"Sickle");
	inventory[29].lowPrice = 70;
	inventory[29].midPrice = 100;
	inventory[29].highPrice = 200;
	inventory[29].stock = 5;
	inventory[29].biasFlags = 0x200;
	// Spear
	strcpy(inventory[30].name,"Spear");
	inventory[30].lowPrice = 70;
	inventory[30].midPrice = 100;
	inventory[30].highPrice = 200;
	inventory[30].stock = 3;
	inventory[30].biasFlags = 0x410;
	
	// Martial Weapons Section Name
	strcpy(inventory[35].name,"MARTIAL WEAPONS");
	inventory[35].lowPrice = 0;
	inventory[35].midPrice = 0;
	inventory[35].highPrice = 0;
	inventory[35].stock = 0;
	inventory[35].biasFlags = 0;
	// Battleaxe
	strcpy(inventory[36].name,"Battleaxe");
	inventory[36].lowPrice = 700;
	inventory[36].midPrice = 1000;
	inventory[36].highPrice = 1500;
	inventory[36].stock = 3;
	inventory[36].biasFlags = 0x430;
	// Flail
	strcpy(inventory[37].name,"Flail");
	inventory[37].lowPrice = 700;
	inventory[37].midPrice = 1000;
	inventory[37].highPrice = 1500;
	inventory[37].stock = 5;
	inventory[37].biasFlags = 0x100;
	// Glaive
	strcpy(inventory[38].name,"Glaive");
	inventory[38].lowPrice = 1500;
	inventory[38].midPrice = 2000;
	inventory[38].highPrice = 3000;
	inventory[38].stock = 5;
	inventory[38].biasFlags = 0x10;
	// Greataxe
	strcpy(inventory[39].name,"Greataxe");
	inventory[39].lowPrice = 2200;
	inventory[39].midPrice = 3000;
	inventory[39].highPrice = 4500;
	inventory[39].stock = 5;
	inventory[39].biasFlags = 0x430;
	// Greatsword
	strcpy(inventory[40].name,"Greatsword");
	inventory[40].lowPrice = 3800;
	inventory[40].midPrice = 5000;
	inventory[40].highPrice = 7500;
	inventory[40].stock = 4;
	inventory[40].biasFlags = 0x14;
	// Halberd
	strcpy(inventory[41].name,"Halberd");
	inventory[41].lowPrice = 1500;
	inventory[41].midPrice = 2000;
	inventory[41].highPrice = 3000;
	inventory[41].stock = 8;
	inventory[41].biasFlags = 0x410;
	// Lance
	strcpy(inventory[42].name,"Lance");
	inventory[42].lowPrice = 700;
	inventory[42].midPrice = 1000;
	inventory[42].highPrice = 1500;
	inventory[42].stock = 18;
	inventory[42].biasFlags = 0x4;
	// Longsword
	strcpy(inventory[43].name,"Longsword");
	inventory[43].lowPrice = 1100;
	inventory[43].midPrice = 1500;
	inventory[43].highPrice = 2200;
	inventory[43].stock = 3;
	inventory[43].biasFlags = 0x14;
	// Maul
	strcpy(inventory[44].name,"Maul");
	inventory[44].lowPrice = 700;
	inventory[44].midPrice = 1000;
	inventory[44].highPrice = 1500;
	inventory[44].stock = 5;
	inventory[44].biasFlags = 0x10;
	// Morningstar
	strcpy(inventory[45].name,"Morningstar");
	inventory[45].lowPrice = 1500;
	inventory[45].midPrice = 2000;
	inventory[45].highPrice = 3000;
	inventory[45].stock = 5;
	inventory[45].biasFlags = 0x100;
	// Pike
	strcpy(inventory[46].name,"Pike");
	inventory[46].lowPrice = 300;
	inventory[46].midPrice = 500;
	inventory[46].highPrice = 800;
	inventory[46].stock = 5;
	inventory[46].biasFlags = 0x10;
	// Rapier
	strcpy(inventory[47].name,"Rapier");
	inventory[47].lowPrice = 1800;
	inventory[47].midPrice = 2500;
	inventory[47].highPrice = 3800;
	inventory[47].stock = 18;
	inventory[47].biasFlags = 0x814;
	// Scimitar
	strcpy(inventory[48].name,"Scimitar");
	inventory[48].lowPrice = 1800;
	inventory[48].midPrice = 2500;
	inventory[48].highPrice = 3800;
	inventory[48].stock = 18;
	inventory[48].biasFlags = 0x814;
	// Shortsword
	strcpy(inventory[49].name,"Shortsword");
	inventory[49].lowPrice = 700;
	inventory[49].midPrice = 1000;
	inventory[49].highPrice = 1500;
	inventory[49].stock = 1;
	inventory[49].biasFlags = 0x10;
	// Trident
	strcpy(inventory[50].name,"Trident");
	inventory[50].lowPrice = 300;
	inventory[50].midPrice = 500;
	inventory[50].highPrice = 800;
	inventory[50].stock = 15;
	inventory[50].biasFlags = 0xA;
	// War Pick
	strcpy(inventory[51].name,"War Pick");
	inventory[51].lowPrice = 300;
	inventory[51].midPrice = 500;
	inventory[51].highPrice = 3000;
	inventory[51].stock = 15;
	inventory[51].biasFlags = 0x88;
	// Warhammer
	strcpy(inventory[52].name,"Warhammer");
	inventory[52].lowPrice = 1100;
	inventory[52].midPrice = 1500;
	inventory[52].highPrice = 2200;
	inventory[52].stock = 7;
	inventory[52].biasFlags = 0xD8;
	
	// Gear Section Name
	strcpy(inventory[57].name,"GEAR");
	inventory[57].lowPrice = 0;
	inventory[57].midPrice = 0;
	inventory[57].highPrice = 0;
	inventory[57].stock = 0;
	inventory[57].biasFlags = 0;
	// Ball Bearings
	strcpy(inventory[58].name,"Ball Bearings (1,000)");
	inventory[58].lowPrice = 70;
	inventory[58].midPrice = 100;
	inventory[58].highPrice = 200;
	inventory[58].stock = 5;
	inventory[58].biasFlags = 0x840;
	// Bell
	strcpy(inventory[59].name,"Bell");
	inventory[59].lowPrice = 70;
	inventory[59].midPrice = 100;
	inventory[59].highPrice = 200;
	inventory[59].stock = 8;
	inventory[59].biasFlags = 0x0;
	// Chain
	strcpy(inventory[60].name,"Chain (10 ft.)");
	inventory[60].lowPrice = 300;
	inventory[60].midPrice = 500;
	inventory[60].highPrice = 800;
	inventory[60].stock = 2;
	inventory[60].biasFlags = 0x0;
	// Crowbar
	strcpy(inventory[61].name,"Crowbar");
	inventory[61].lowPrice = 100;
	inventory[61].midPrice = 200;
	inventory[61].highPrice = 300;
	inventory[61].stock = 3;
	inventory[61].biasFlags = 0x0;
	// Grappling Hook
	strcpy(inventory[62].name,"Grappling Hook");
	inventory[62].lowPrice = 100;
	inventory[62].midPrice = 200;
	inventory[62].highPrice = 300;
	inventory[62].stock = 5;
	inventory[62].biasFlags = 0x10;
	// Hammer
	strcpy(inventory[63].name,"Hammer");
	inventory[63].lowPrice = 70;
	inventory[63].midPrice = 100;
	inventory[63].highPrice = 200;
	inventory[63].stock = 1;
	inventory[63].biasFlags = 0x0;
	// Hunting Trap
	strcpy(inventory[64].name,"Hunting Trap");
	inventory[64].lowPrice = 300;
	inventory[64].midPrice = 500;
	inventory[64].highPrice = 800;
	inventory[64].stock = 5;
	inventory[64].biasFlags = 0x430;
	// Lamp
	strcpy(inventory[65].name,"Lamp");
	inventory[65].lowPrice = 30;
	inventory[65].midPrice = 50;
	inventory[65].highPrice = 80;
	inventory[65].stock = 3;
	inventory[65].biasFlags = 0x45;
	// Bullseye Lantern
	strcpy(inventory[66].name,"Lantern (bullseye)");
	inventory[66].lowPrice = 700;
	inventory[66].midPrice = 1000;
	inventory[66].highPrice = 1500;
	inventory[66].stock = 15;
	inventory[66].biasFlags = 0x44;
	// Hooded Lantern
	strcpy(inventory[67].name,"Lantern (hooded)");
	inventory[67].lowPrice = 300;
	inventory[67].midPrice = 500;
	inventory[67].highPrice = 800;
	inventory[67].stock = 5;
	inventory[67].biasFlags = 0x45;
	// Lock
	strcpy(inventory[68].name,"Lock");
	inventory[68].lowPrice = 700;
	inventory[68].midPrice = 1000;
	inventory[68].highPrice = 1500;
	inventory[68].stock = 17;
	inventory[68].biasFlags = 0x841;
	// Manacles
	strcpy(inventory[69].name,"Manacles");
	inventory[69].lowPrice = 100;
	inventory[69].midPrice = 200;
	inventory[69].highPrice = 300;
	inventory[69].stock = 7;
	inventory[69].biasFlags = 0x810;
	// Steel Mirror
	strcpy(inventory[70].name,"Mirror (steel)");
	inventory[70].lowPrice = 300;
	inventory[70].midPrice = 500;
	inventory[70].highPrice = 800;
	inventory[70].stock = 5;
	inventory[70].biasFlags = 0x5;
	// Mining Pick
	strcpy(inventory[71].name,"Mining Pick");
	inventory[71].lowPrice = 100;
	inventory[71].midPrice = 200;
	inventory[71].highPrice = 300;
	inventory[71].stock = 5;
	inventory[71].biasFlags = 0x80;
	// Piton
	strcpy(inventory[72].name,"Piton");
	inventory[72].lowPrice = 3;
	inventory[72].midPrice = 5;
	inventory[72].highPrice = 8;
	inventory[72].stock = 5;
	inventory[72].biasFlags = 0x880;
	// Pot
	strcpy(inventory[73].name,"Pot (iron)");
	inventory[73].lowPrice = 100;
	inventory[73].midPrice = 200;
	inventory[73].highPrice = 300;
	inventory[73].stock = 10;
	inventory[73].biasFlags = 0x0;
	// Pulley
	strcpy(inventory[74].name,"Pulley");
	inventory[74].lowPrice = 70;
	inventory[74].midPrice = 100;
	inventory[74].highPrice = 200;
	inventory[74].stock = 8;
	inventory[74].biasFlags = 0x8C0;
	// Sledgehammer
	strcpy(inventory[75].name,"Sledgehammer");
	inventory[75].lowPrice = 100;
	inventory[75].midPrice = 200;
	inventory[75].highPrice = 300;
	inventory[75].stock = 5;
	inventory[75].biasFlags = 0x0;
	// Spikes
	strcpy(inventory[76].name,"Spikes (iron)");
	inventory[76].lowPrice = 70;
	inventory[76].midPrice = 100;
	inventory[76].highPrice = 200;
	inventory[76].stock = 10;
	inventory[76].biasFlags = 0x0;
	// Whetstone
	strcpy(inventory[77].name,"Whetstone");
	inventory[77].lowPrice = 1;
	inventory[77].midPrice = 1;
	inventory[77].highPrice = 2;
	inventory[77].stock = 2;
	inventory[77].biasFlags = 0x10;
	
	// Tools Section Header
	strcpy(inventory[83].name,"TOOLS");
	inventory[83].lowPrice = 0;
	inventory[83].midPrice = 0;
	inventory[83].highPrice = 0;
	inventory[83].stock = 0;
	inventory[83].biasFlags = 0;
	// Carpenter's Tools
	strcpy(inventory[84].name,"Carpenter's Tools");
	inventory[84].lowPrice = 600;
	inventory[84].midPrice = 800;
	inventory[84].highPrice = 1200;
	inventory[84].stock = 5;
	inventory[84].biasFlags = 0x800;
	// Horn
	strcpy(inventory[85].name,"Horn");
	inventory[85].lowPrice = 700;
	inventory[85].midPrice = 1000;
	inventory[85].highPrice = 1500;
	inventory[85].stock = 15;
	inventory[85].biasFlags = 0x800;
	// Mason's Tools
	strcpy(inventory[86].name,"Mason's Tools");
	inventory[86].lowPrice = 700;
	inventory[86].midPrice = 1000;
	inventory[86].highPrice = 1500;
	inventory[86].stock = 5;
	inventory[86].biasFlags = 0x800;
	// Smith's Tools
	strcpy(inventory[87].name,"Smith's Tools");
	inventory[87].lowPrice = 1500;
	inventory[87].midPrice = 2000;
	inventory[87].highPrice = 3000;
	inventory[87].stock = 5;
	inventory[87].biasFlags = 0x800;
	// Tinker's Tools
	strcpy(inventory[88].name,"Tinker's Tools");
	inventory[88].lowPrice = 3800;
	inventory[88].midPrice = 5000;
	inventory[88].highPrice = 7500;
	inventory[88].stock = 17;
	inventory[88].biasFlags = 0x801;
	
	// Metals Section Header
	strcpy(inventory[91].name,"METALS");
	inventory[91].lowPrice = 0;
	inventory[91].midPrice = 0;
	inventory[91].highPrice = 0;
	inventory[91].stock = 0;
	inventory[91].biasFlags = 0;
	// Adamantine
	strcpy(inventory[92].name,"Adamantine (1 lb.)");
	inventory[92].lowPrice = 60000;
	inventory[92].midPrice = 80000;
	inventory[92].highPrice = 110000;
	inventory[92].stock = 17;
	inventory[92].biasFlags = 0xC1;
	// Aluminum
	strcpy(inventory[93].name,"Aluminum (1 lb.)");
	inventory[93].lowPrice = 600;
	inventory[93].midPrice = 1000;
	inventory[93].highPrice = 2000;
	inventory[93].stock = 15;
	inventory[93].biasFlags = 0xC0;
	// Bronze
	strcpy(inventory[94].name,"Bronze (1 lb.)");
	inventory[94].lowPrice = 80;
	inventory[94].midPrice = 100;
	inventory[94].highPrice = 200;
	inventory[94].stock = 10;
	inventory[94].biasFlags = 0xC0;
	// Bronze
	strcpy(inventory[95].name,"Bronze (1 lb.)");
	inventory[95].lowPrice = 80;
	inventory[95].midPrice = 100;
	inventory[95].highPrice = 200;
	inventory[95].stock = 10;
	inventory[95].biasFlags = 0xC0;
	// Copper
	strcpy(inventory[96].name,"Copper (1 lb.)");
	inventory[96].lowPrice = 30;
	inventory[96].midPrice = 50;
	inventory[96].highPrice = 80;
	inventory[96].stock = 5;
	inventory[96].biasFlags = 0xC0;
	// Gold
	strcpy(inventory[97].name,"Gold (1 lb.)");
	inventory[97].lowPrice = 3000;
	inventory[97].midPrice = 5000;
	inventory[97].highPrice = 8000;
	inventory[97].stock = 10;
	inventory[97].biasFlags = 0xC0;
	// Iron
	strcpy(inventory[98].name,"Iron (1 lb.)");
	inventory[98].lowPrice = 7;
	inventory[98].midPrice = 10;
	inventory[98].highPrice = 20;
	inventory[98].stock = 3;
	inventory[98].biasFlags = 0xC0;
	// Lead
	strcpy(inventory[99].name,"Lead (1 lb.)");
	inventory[99].lowPrice = 30;
	inventory[99].midPrice = 50;
	inventory[99].highPrice = 80;
	inventory[99].stock = 4;
	inventory[99].biasFlags = 0xC1;
	// Mercury
	strcpy(inventory[100].name,"Bronze (1 lb.)");
	inventory[100].lowPrice = 500;
	inventory[100].midPrice = 700;
	inventory[100].highPrice = 1000;
	inventory[100].stock = 15;
	inventory[100].biasFlags = 0xC0;
	// Mithral
	strcpy(inventory[101].name,"Mithral (1 lb.)");
	inventory[101].lowPrice = 30000;
	inventory[101].midPrice = 50000;
	inventory[101].highPrice = 80000;
	inventory[101].stock = 17;
	inventory[101].biasFlags = 0xC1;
	// Platinum
	strcpy(inventory[102].name,"Platinum (1 lb.)");
	inventory[102].lowPrice = 30000;
	inventory[102].midPrice = 50000;
	inventory[102].highPrice = 80000;
	inventory[102].stock = 17;
	inventory[102].biasFlags = 0xC0;
	// Silver
	strcpy(inventory[103].name,"Silver (1 lb.)");
	inventory[103].lowPrice = 300;
	inventory[103].midPrice = 500;
	inventory[103].highPrice = 800;
	inventory[103].stock = 10;
	inventory[103].biasFlags = 0xC0;
	// Steel
	strcpy(inventory[104].name,"Steel (1 lb.)");
	inventory[104].lowPrice = 100;
	inventory[104].midPrice = 200;
	inventory[104].highPrice = 300;
	inventory[104].stock = 7;
	inventory[104].biasFlags = 0xC0;
	// Tin
	strcpy(inventory[105].name,"Tin (1 lb.)");
	inventory[105].lowPrice = 100;
	inventory[105].midPrice = 200;
	inventory[105].highPrice = 400;
	inventory[105].stock = 10;
	inventory[105].biasFlags = 0xC0;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeBookstore(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 29;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Gear Section Name
	strcpy(inventory[0].name,"GEAR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Candle
	strcpy(inventory[1].name,"Candle");
	inventory[1].lowPrice = 1;
	inventory[1].midPrice = 1;
	inventory[1].highPrice = 2;
	inventory[1].stock = 2;
	inventory[1].biasFlags = 0x45;
	// Case
	strcpy(inventory[2].name,"Case (scroll");
	inventory[2].lowPrice = 70;
	inventory[2].midPrice = 100;
	inventory[2].highPrice = 200;
	inventory[2].stock = 5;
	inventory[2].biasFlags = 0x45;
	// Ink
	strcpy(inventory[3].name,"Ink (1 fl. oz.)");
	inventory[3].lowPrice = 700;
	inventory[3].midPrice = 1000;
	inventory[3].highPrice = 1500;
	inventory[3].stock = 5;
	inventory[3].biasFlags = 0x45;
	// Ink Pen
	strcpy(inventory[4].name,"Ink Pen");
	inventory[4].lowPrice = 1;
	inventory[4].midPrice = 2;
	inventory[4].highPrice = 3;
	inventory[4].stock = 5;
	inventory[4].biasFlags = 0x45;
	// Paper
	strcpy(inventory[5].name,"Paper (1)");
	inventory[5].lowPrice = 10;
	inventory[5].midPrice = 20;
	inventory[5].highPrice = 30;
	inventory[5].stock = 5;
	inventory[5].biasFlags = 0x45;
	// Parchment
	strcpy(inventory[6].name,"Parchment (1)");
	inventory[6].lowPrice = 7;
	inventory[6].midPrice = 10;
	inventory[6].highPrice = 20;
	inventory[6].stock = 2;
	inventory[6].biasFlags = 0x45;
	// Magnifying Glass
	strcpy(inventory[7].name,"Magnifying Glass");
	inventory[7].lowPrice = 9000;
	inventory[7].midPrice = 10000;
	inventory[7].highPrice = 12500;
	inventory[7].stock = 15;
	inventory[7].biasFlags = 0x5;
	// Spellbook
	strcpy(inventory[8].name,"Spellbook");
	inventory[8].lowPrice = 3000;
	inventory[8].midPrice = 5000;
	inventory[8].highPrice = 7000;
	inventory[8].stock = 10;
	inventory[8].biasFlags = 0x1;
	
	// Tools Section Name
	strcpy(inventory[11].name,"TOOLS");
	inventory[11].lowPrice = 0;
	inventory[11].midPrice = 0;
	inventory[11].highPrice = 0;
	inventory[11].stock = 0;
	inventory[11].biasFlags = 0;
	// Calligrapher's Supplies
	strcpy(inventory[12].name,"Calligrapher's Supplies");
	inventory[12].lowPrice = 700;
	inventory[12].midPrice = 1000;
	inventory[12].highPrice = 1500;
	inventory[12].stock = 5;
	inventory[12].biasFlags = 0x45;
	// Cartographer's Tools
	strcpy(inventory[13].name,"Cartographer's Tools");
	inventory[13].lowPrice = 1100;
	inventory[13].midPrice = 1500;
	inventory[13].highPrice = 2300;
	inventory[13].stock = 10;
	inventory[13].biasFlags = 0x45;
	// Draughtsman's Tools
	strcpy(inventory[14].name,"Draughtsman's Tools");
	inventory[14].lowPrice = 1100;
	inventory[14].midPrice = 1500;
	inventory[14].highPrice = 2300;
	inventory[14].stock = 10;
	inventory[14].biasFlags = 0x45;
	// Tinker's Tools
	strcpy(inventory[15].name,"Tinker's Tools");
	inventory[15].lowPrice = 3800;
	inventory[15].midPrice = 5000;
	inventory[15].highPrice = 7500;
	inventory[15].stock = 10;
	inventory[15].biasFlags = 0x45;
	
	// Services Section Name
	strcpy(inventory[19].name,"SERVICES");
	inventory[19].lowPrice = 0;
	inventory[19].midPrice = 0;
	inventory[19].highPrice = 0;
	inventory[19].stock = 0;
	inventory[19].biasFlags = 0;
	// Book Appraisal
	strcpy(inventory[20].name,"Book Appraisal");
	inventory[20].lowPrice = 0;
	inventory[20].midPrice = 1;
	inventory[20].highPrice = 1;
	inventory[20].stock = 1;
	inventory[20].biasFlags = 0x0;
	// Book Binding
	strcpy(inventory[21].name,"Book Binding");
	inventory[21].lowPrice = 700;
	inventory[21].midPrice = 1000;
	inventory[21].highPrice = 1500;
	inventory[21].stock = 15;
	inventory[21].biasFlags = 0x5;
	// Book Translation
	strcpy(inventory[22].name,"Book Translation");
	inventory[22].lowPrice = 700;
	inventory[22].midPrice = 1000;
	inventory[22].highPrice = 1500;
	inventory[22].stock = 10;
	inventory[22].biasFlags = 05;
	
	// Books Section Name
	strcpy(inventory[23].name,"BOOKS");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0;
	// Common Books
	strcpy(inventory[24].name,"Common Books");
	inventory[24].lowPrice = 2000;
	inventory[24].midPrice = 3000;
	inventory[24].highPrice = 5000;
	inventory[24].stock = 1;
	inventory[24].biasFlags = 0x5;
	// Uncommon Books
	strcpy(inventory[25].name,"Uncommon Books");
	inventory[25].lowPrice = 7000;
	inventory[25].midPrice = 10000;
	inventory[25].highPrice = 15000;
	inventory[25].stock = 6;
	inventory[25].biasFlags = 0x5;
	// Rare Books
	strcpy(inventory[26].name,"Rare Books");
	inventory[26].lowPrice = 90000;
	inventory[26].midPrice = 100000;
	inventory[26].highPrice = 150000;
	inventory[26].stock = 14;
	inventory[26].biasFlags = 0x5;
	// Very Rare Books
	strcpy(inventory[27].name,"Very Rare Books");
	inventory[27].lowPrice = 400000;
	inventory[27].midPrice = 500000;
	inventory[27].highPrice = 750000;
	inventory[27].stock = 18;
	inventory[27].biasFlags = 0x5;
	// Legendary Books
	strcpy(inventory[28].name,"Legendary Books");
	inventory[28].lowPrice = 900000;
	inventory[28].midPrice = 1000000;
	inventory[28].highPrice = 2000000;
	inventory[28].stock = 20;
	inventory[28].biasFlags = 0x5;
	
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeButcher(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 63;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Armor Section Name
	strcpy(inventory[0].name,"WEAPONS");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Dagger
	strcpy(inventory[1].name,"Dagger");
	inventory[1].lowPrice = 100;
	inventory[1].midPrice = 200;
	inventory[1].highPrice = 300;
	inventory[1].stock = 15;
	inventory[1].biasFlags = 0x0;
	// Handaxe
	strcpy(inventory[2].name,"Handaxe");
	inventory[2].lowPrice = 300;
	inventory[2].midPrice = 500;
	inventory[2].highPrice = 800;
	inventory[2].stock = 15;
	inventory[2].biasFlags = 0x0;
	// Light Hammer
	strcpy(inventory[3].name,"Light Hammer");
	inventory[3].lowPrice = 100;
	inventory[3].midPrice = 200;
	inventory[3].highPrice = 300;
	inventory[3].stock = 15;
	inventory[3].biasFlags = 0x0;
	
	// Foodstuffs Section Name
	strcpy(inventory[7].name,"FOODSTUFFS");
	inventory[7].lowPrice = 0;
	inventory[7].midPrice = 0;
	inventory[7].highPrice = 0;
	inventory[7].stock = 0;
	inventory[7].biasFlags = 0;
	// Beef
	strcpy(inventory[8].name,"Beef (1 lb.)");
	inventory[8].lowPrice = 40;
	inventory[8].midPrice = 60;
	inventory[8].highPrice = 80;
	inventory[8].stock = 7;
	inventory[8].biasFlags = 0xA00;
	// Bread
	strcpy(inventory[9].name,"Bread (loaf)");
	inventory[9].lowPrice = 5;
	inventory[9].midPrice = 8;
	inventory[9].highPrice = 10;
	inventory[9].stock = 15;
	inventory[9].biasFlags = 0xA00;
	// White Bread
	strcpy(inventory[10].name,"White Bread (loaf)");
	inventory[10].lowPrice = 10;
	inventory[10].midPrice = 15;
	inventory[10].highPrice = 20;
	inventory[10].stock = 18;
	inventory[10].biasFlags = 0xA00;
	// Butter
	strcpy(inventory[11].name,"Butter (1 lb.)");
	inventory[11].lowPrice = 10;
	inventory[11].midPrice = 20;
	inventory[11].highPrice = 30;
	inventory[11].stock = 10;
	inventory[11].biasFlags = 0xA00;
	// Chicken
	strcpy(inventory[12].name,"Chicken (1 lb.)");
	inventory[12].lowPrice = 10;
	inventory[12].midPrice = 20;
	inventory[12].highPrice = 40;
	inventory[12].stock = 5;
	inventory[12].biasFlags = 0xA00;
	// Fish
	strcpy(inventory[13].name,"Fish (1 lb.)");
	inventory[13].lowPrice = 20;
	inventory[13].midPrice = 100;
	inventory[13].highPrice = 200;
	inventory[13].stock = 12;
	inventory[13].biasFlags = 0x802;
	// Eggs
	strcpy(inventory[14].name,"Eggs (dozen)");
	inventory[14].lowPrice = 4;
	inventory[14].midPrice = 6;
	inventory[14].highPrice = 9;
	inventory[14].stock = 10;
	inventory[14].biasFlags = 0xA00;
	// Mutton
	strcpy(inventory[15].name,"Mutton (1 lb.)");
	inventory[15].lowPrice = 10;
	inventory[15].midPrice = 20;
	inventory[15].highPrice = 40;
	inventory[15].stock = 6;
	inventory[15].biasFlags = 0xA00;
	// Pork
	strcpy(inventory[16].name,"Pork (1 lb.)");
	inventory[16].lowPrice = 10;
	inventory[16].midPrice = 20;
	inventory[16].highPrice = 40;
	inventory[16].stock = 5;
	inventory[16].biasFlags = 0xA00;
	// Salt
	strcpy(inventory[17].name,"Salt (1 lb.)");
	inventory[17].lowPrice = 3;
	inventory[17].midPrice = 5;
	inventory[17].highPrice = 8;
	inventory[17].stock = 7;
	inventory[17].biasFlags = 0x880;
	// Common SPice
	strcpy(inventory[18].name,"Common Spice (1 lb.)");
	inventory[18].lowPrice = 80;
	inventory[18].midPrice = 100;
	inventory[18].highPrice = 200;
	inventory[18].stock = 7;
	inventory[18].biasFlags = 0xB0D;
	// Uncommon Spice
	strcpy(inventory[19].name,"Uncommon Spice (1 lb.)");
	inventory[19].lowPrice = 100;
	inventory[19].midPrice = 200;
	inventory[19].highPrice = 400;
	inventory[19].stock = 15;
	inventory[19].biasFlags = 0xB0D;
	// Tallow
	strcpy(inventory[20].name,"Tallow (1 lb.)");
	inventory[20].lowPrice = 40;
	inventory[20].midPrice = 60;
	inventory[20].highPrice = 80;
	inventory[20].stock = 5;
	inventory[20].biasFlags = 0xA00;
	
	// Livestock Section Name
	strcpy(inventory[23].name,"LIVESTOCK");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0;
	// Chicken
	strcpy(inventory[24].name,"Chicken");
	inventory[24].lowPrice = 40;
	inventory[24].midPrice = 60;
	inventory[24].highPrice = 80;
	inventory[24].stock = 1;
	inventory[24].biasFlags = 0x200;
	// Cow
	strcpy(inventory[25].name,"Cow");
	inventory[25].lowPrice = 3200;
	inventory[25].midPrice = 4000;
	inventory[25].highPrice = 5200;
	inventory[25].stock = 5;
	inventory[25].biasFlags = 0x200;
	// Goat
	strcpy(inventory[26].name,"Goat");
	inventory[26].lowPrice = 600;
	inventory[26].midPrice = 800;
	inventory[26].highPrice = 1200;
	inventory[26].stock = 2;
	inventory[26].biasFlags = 0x200;
	// Ox
	strcpy(inventory[27].name,"Ox");
	inventory[27].lowPrice = 4000;
	inventory[27].midPrice = 5200;
	inventory[27].highPrice = 6000;
	inventory[27].stock = 12;
	inventory[27].biasFlags = 0x200;
	// Pig
	strcpy(inventory[28].name,"Pig");
	inventory[28].lowPrice = 1200;
	inventory[28].midPrice = 1500;
	inventory[28].highPrice = 2000;
	inventory[28].stock = 3;
	inventory[28].biasFlags = 0x201;
	// Rabbit
	strcpy(inventory[29].name,"Rabbit");
	inventory[29].lowPrice = 10;
	inventory[29].midPrice = 30;
	inventory[29].highPrice = 40;
	inventory[29].stock = 2;
	inventory[29].biasFlags = 0x201;
	// Sheep
	strcpy(inventory[30].name,"Sheep");
	inventory[30].lowPrice = 600;
	inventory[30].midPrice = 800;
	inventory[30].highPrice = 1200;
	inventory[30].stock = 5;
	inventory[30].biasFlags = 0x200;
	
	// Dishes Section Name
	strcpy(inventory[35].name,"Dishes");
	inventory[35].lowPrice = 0;
	inventory[35].midPrice = 0;
	inventory[35].highPrice = 0;
	inventory[35].stock = 0;
	inventory[35].biasFlags = 0;
	// Beef Sandwich
	strcpy(inventory[36].name,"Beef Sandwich");
	inventory[36].lowPrice = 18;
	inventory[36].midPrice = 22;
	inventory[36].highPrice = 30;
	inventory[36].stock = 17;
	inventory[36].biasFlags = 0xA00;
	// Chicken
	strcpy(inventory[37].name,"Chicken");
	inventory[37].lowPrice = 15;
	inventory[37].midPrice = 20;
	inventory[37].highPrice = 25;
	inventory[37].stock = 5;
	inventory[37].biasFlags = 0xA00;
	// Chicken Sandwich
	strcpy(inventory[38].name,"Chicken Sandwich");
	inventory[38].lowPrice = 12;
	inventory[38].midPrice = 16;
	inventory[38].highPrice = 22;
	inventory[38].stock = 17;
	inventory[38].biasFlags = 0xA00;
	// Fried Chicken
	strcpy(inventory[39].name,"Fried Chicken");
	inventory[39].lowPrice = 17;
	inventory[39].midPrice = 22;
	inventory[39].highPrice = 27;
	inventory[39].stock = 5;
	inventory[39].biasFlags = 0xA00;
	// Fried Fish
	strcpy(inventory[40].name,"Fried Fish");
	inventory[40].lowPrice = 24;
	inventory[40].midPrice = 100;
	inventory[40].highPrice = 200;
	inventory[40].stock = 15;
	inventory[40].biasFlags = 0xA00;
	// Brown Gravy
	strcpy(inventory[41].name,"Brown Gravy");
	inventory[41].lowPrice = 1;
	inventory[41].midPrice = 2;
	inventory[41].highPrice = 3;
	inventory[41].stock = 17;
	inventory[41].biasFlags = 0xA00;
	// White Gravy
	strcpy(inventory[42].name,"White Gravy");
	inventory[42].lowPrice = 2;
	inventory[42].midPrice = 4;
	inventory[42].highPrice = 6;
	inventory[42].stock = 17;
	inventory[42].biasFlags = 0xA00;
	// Fish Sandwich
	strcpy(inventory[43].name,"Fish Sandwich");
	inventory[43].lowPrice = 12;
	inventory[43].midPrice = 50;
	inventory[43].highPrice = 75;
	inventory[43].stock = 17;
	inventory[43].biasFlags = 0xA00;
	// Beef Jerky
	strcpy(inventory[44].name,"Beef Jerky");
	inventory[44].lowPrice = 160;
	inventory[44].midPrice = 200;
	inventory[44].highPrice = 300;
	inventory[44].stock = 10;
	inventory[44].biasFlags = 0xA00;
	// Mutton Leg
	strcpy(inventory[45].name,"Mutton Leg");
	inventory[45].lowPrice = 15;
	inventory[45].midPrice = 20;
	inventory[45].highPrice = 25;
	inventory[45].stock = 5;
	inventory[45].biasFlags = 0xA00;
	// Pemmican
	strcpy(inventory[46].name,"Pemmican");
	inventory[46].lowPrice = 15;
	inventory[46].midPrice = 20;
	inventory[46].highPrice = 25;
	inventory[46].stock = 18;
	inventory[46].biasFlags = 0x210;
	// Shepherds Pie
	strcpy(inventory[47].name,"Shepherds Pie");
	inventory[47].lowPrice = 25;
	inventory[47].midPrice = 28;
	inventory[47].highPrice = 32;
	inventory[47].stock = 17;
	inventory[47].biasFlags = 0xA00;
	// Fried Pork
	strcpy(inventory[48].name,"Fried Pork");
	inventory[48].lowPrice = 14;
	inventory[48].midPrice = 18;
	inventory[48].highPrice = 24;
	inventory[48].stock = 5;
	inventory[48].biasFlags = 0xA00;
	// Pork Sandwich
	strcpy(inventory[49].name,"Pork Sandwich");
	inventory[49].lowPrice = 12;
	inventory[49].midPrice = 16;
	inventory[49].highPrice = 22;
	inventory[49].stock = 17;
	inventory[49].biasFlags = 0xA00;
	// Porkchop
	strcpy(inventory[50].name,"Porkchop");
	inventory[50].lowPrice = 30;
	inventory[50].midPrice = 40;
	inventory[50].highPrice = 50;
	inventory[50].stock = 5;
	inventory[50].biasFlags = 0xA00;
	// Salted Pork
	strcpy(inventory[51].name,"Salted Pork");
	inventory[51].lowPrice = 90;
	inventory[51].midPrice = 120;
	inventory[51].highPrice = 200;
	inventory[51].stock = 7;
	inventory[51].biasFlags = 0xA10;
	// Beef Sausage
	strcpy(inventory[52].name,"Beef Sausage");
	inventory[52].lowPrice = 24;
	inventory[52].midPrice = 26;
	inventory[52].highPrice = 30;
	inventory[52].stock = 2;
	inventory[52].biasFlags = 0xA00;
	// Brat
	strcpy(inventory[53].name,"Bratwurst");
	inventory[53].lowPrice = 16;
	inventory[53].midPrice = 18;
	inventory[53].highPrice = 20;
	inventory[53].stock = 2;
	inventory[53].biasFlags = 0xA00;
	// Chorizo
	strcpy(inventory[54].name,"Chorizo");
	inventory[54].lowPrice = 20;
	inventory[54].midPrice = 22;
	inventory[54].highPrice = 26;
	inventory[54].stock = 3;
	inventory[54].biasFlags = 0xA08;
	// Indeterminate Sausage
	strcpy(inventory[55].name,"Indeterminate Sausage");
	inventory[55].lowPrice = 6;
	inventory[55].midPrice = 8;
	inventory[55].highPrice = 10;
	inventory[55].stock = 1;
	inventory[55].biasFlags = 0xA00;
	// Italian Sausage
	strcpy(inventory[56].name,"Italian Sausage");
	inventory[56].lowPrice = 20;
	inventory[56].midPrice = 22;
	inventory[56].highPrice = 26;
	inventory[56].stock = 2;
	inventory[56].biasFlags = 0xA00;
	// Polish
	strcpy(inventory[57].name,"Polish");
	inventory[57].lowPrice = 18;
	inventory[57].midPrice = 20;
	inventory[57].highPrice = 24;
	inventory[57].stock = 2;
	inventory[57].biasFlags = 0xA00;
	// Pork Sausage
	strcpy(inventory[58].name,"Pork Sausage");
	inventory[58].lowPrice = 11;
	inventory[58].midPrice = 13;
	inventory[58].highPrice = 15;
	inventory[58].stock = 2;
	inventory[58].biasFlags = 0xA00;
	// Beef Summer Sausage
	strcpy(inventory[59].name,"Beef Summer Sausage");
	inventory[59].lowPrice = 32;
	inventory[59].midPrice = 34;
	inventory[59].highPrice = 38;
	inventory[59].stock = 4;
	inventory[59].biasFlags = 0xA00;
	// Pork Summer Sausage
	strcpy(inventory[60].name,"Pork Summer Sausage");
	inventory[60].lowPrice = 18;
	inventory[60].midPrice = 20;
	inventory[60].highPrice = 24;
	inventory[60].stock = 4;
	inventory[60].biasFlags = 0xA00;
	// Steak
	strcpy(inventory[61].name,"Steak");
	inventory[61].lowPrice = 40;
	inventory[61].midPrice = 60;
	inventory[61].highPrice = 80;
	inventory[61].stock = 7;
	inventory[61].biasFlags = 0xA00;
	// Fried Steak
	strcpy(inventory[62].name,"Fried Steak");
	inventory[62].lowPrice = 30;
	inventory[62].midPrice = 50;
	inventory[62].highPrice = 70;
	inventory[62].stock = 7;
	inventory[62].biasFlags = 0xA00;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeCobbler(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 128;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Armor Section Name
	strcpy(inventory[0].name,"WEAPONS");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Quarterstaff
	strcpy(inventory[1].name,"Quarterstaff");
	inventory[1].lowPrice = 10;
	inventory[1].midPrice = 20;
	inventory[1].highPrice = 30;
	inventory[1].stock = 2;
	inventory[1].biasFlags = 0x20;
	
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeFletcher(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 25;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Simple Weapons Section Name
	strcpy(inventory[0].name,"SIMPLE WEAPONS");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Light Crossbow
	strcpy(inventory[1].name,"Light Crossbow");
	inventory[1].lowPrice = 1800;
	inventory[1].midPrice = 2500;
	inventory[1].highPrice = 3800;
	inventory[1].stock = 5;
	inventory[1].biasFlags = 0x810;
	// Shortbow
	strcpy(inventory[2].name,"Shortbow");
	inventory[2].lowPrice = 1800;
	inventory[2].midPrice = 2500;
	inventory[2].highPrice = 3800;
	inventory[2].stock = 1;
	inventory[2].biasFlags = 0x10;
	
	// Martial Weapons Section Name
	strcpy(inventory[4].name,"MARTIAL WEAPONS");
	inventory[4].lowPrice = 0;
	inventory[4].midPrice = 0;
	inventory[4].highPrice = 0;
	inventory[4].stock = 0;
	inventory[4].biasFlags = 0;
	// Hand Crossbow
	strcpy(inventory[5].name,"Hand Crossbow");
	inventory[5].lowPrice = 5600;
	inventory[5].midPrice = 7500;
	inventory[5].highPrice = 11300;
	inventory[5].stock = 13;
	inventory[5].biasFlags = 0x814;
	// Heavy Crossbow
	strcpy(inventory[6].name,"Heavy Crossbow");
	inventory[6].lowPrice = 3800;
	inventory[6].midPrice = 5000;
	inventory[6].highPrice = 7500;
	inventory[6].stock = 10;
	inventory[6].biasFlags = 0x10;
	// Longbow
	strcpy(inventory[7].name,"Longbow");
	inventory[7].lowPrice = 3800;
	inventory[7].midPrice = 5000;
	inventory[7].highPrice = 7500;
	inventory[7].stock = 5;
	inventory[7].biasFlags = 0x410;
	
	// Gear Weapons Section Name
	strcpy(inventory[10].name,"GEAR");
	inventory[10].lowPrice = 0;
	inventory[10].midPrice = 0;
	inventory[10].highPrice = 0;
	inventory[10].stock = 0;
	inventory[10].biasFlags = 0;
	// Arrows
	strcpy(inventory[11].name,"Arrows (20)");
	inventory[11].lowPrice = 70;
	inventory[11].midPrice = 100;
	inventory[11].highPrice = 200;
	inventory[11].stock = 1;
	inventory[11].biasFlags = 0x0;
	// Bolts
	strcpy(inventory[12].name,"Bolts (20)");
	inventory[12].lowPrice = 70;
	inventory[12].midPrice = 100;
	inventory[12].highPrice = 200;
	inventory[12].stock = 4;
	inventory[12].biasFlags = 0x0;
	// Bolt Case
	strcpy(inventory[13].name,"Bolt Case");
	inventory[13].lowPrice = 70;
	inventory[13].midPrice = 100;
	inventory[13].highPrice = 200;
	inventory[13].stock = 7;
	inventory[13].biasFlags = 0x0;
	// Quiver
	strcpy(inventory[14].name,"Quiver");
	inventory[14].lowPrice = 70;
	inventory[14].midPrice = 100;
	inventory[14].highPrice = 200;
	inventory[14].stock = 2;
	inventory[14].biasFlags = 0x0;
	
	// Wood Weapons Section Name
	strcpy(inventory[15].name,"WOOD");
	inventory[15].lowPrice = 0;
	inventory[15].midPrice = 0;
	inventory[15].highPrice = 0;
	inventory[15].stock = 0;
	inventory[15].biasFlags = 0;
	// Ash
	strcpy(inventory[16].name,"Ash (1 lb.)");
	inventory[16].lowPrice = 10;
	inventory[16].midPrice = 20;
	inventory[16].highPrice = 50;
	inventory[16].stock = 10;
	inventory[16].biasFlags = 0x20;
	// Cedar
	strcpy(inventory[17].name,"Cedar (1 lb.)");
	inventory[17].lowPrice = 30;
	inventory[17].midPrice = 50;
	inventory[17].highPrice = 80;
	inventory[17].stock = 10;
	inventory[17].biasFlags = 0x20;
	// Darkwood
	strcpy(inventory[18].name,"Darkwood (1 lb.)");
	inventory[18].lowPrice = 5000;
	inventory[18].midPrice = 15000;
	inventory[18].highPrice = 25000;
	inventory[18].stock = 17;
	inventory[18].biasFlags = 0x21;
	// Ironwood
	strcpy(inventory[19].name,"Ironwood (1 lb.)");
	inventory[19].lowPrice = 10000;
	inventory[19].midPrice = 30000;
	inventory[19].highPrice = 50000;
	inventory[19].stock = 17;
	inventory[19].biasFlags = 0x21;
	// Maple
	strcpy(inventory[20].name,"Maple (1 lb.)");
	inventory[20].lowPrice = 30;
	inventory[20].midPrice = 50;
	inventory[20].highPrice = 80;
	inventory[20].stock = 10;
	inventory[20].biasFlags = 0x20;
	// Pine
	strcpy(inventory[21].name,"Pine (1 lb.)");
	inventory[21].lowPrice = 10;
	inventory[21].midPrice = 20;
	inventory[21].highPrice = 40;
	inventory[21].stock = 8;
	inventory[21].biasFlags = 0x20;
	// Oak
	strcpy(inventory[22].name,"Oak (1 lb.)");
	inventory[22].lowPrice = 10;
	inventory[22].midPrice = 20;
	inventory[22].highPrice = 40;
	inventory[22].stock = 3;
	inventory[22].biasFlags = 0x20;
	// Osage Orange
	strcpy(inventory[23].name,"Osage Orange (1 lb.)");
	inventory[23].lowPrice = 100;
	inventory[23].midPrice = 200;
	inventory[23].highPrice = 400;
	inventory[23].stock = 15;
	inventory[23].biasFlags = 0x20;
	// Yew
	strcpy(inventory[24].name,"Yew (1 lb.)");
	inventory[24].lowPrice = 100;
	inventory[24].midPrice = 200;
	inventory[24].highPrice = 400;
	inventory[24].stock = 15;
	inventory[24].biasFlags = 0x20;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeGeneral(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 98;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Gear Section Name
	strcpy(inventory[0].name,"GEAR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Abacus
	strcpy(inventory[1].name,"Abacus");
	inventory[1].lowPrice = 100;
	inventory[1].midPrice = 200;
	inventory[1].highPrice = 300;
	inventory[1].stock = 7;
	inventory[1].biasFlags = 0x41;
	// Barrel
	strcpy(inventory[2].name,"Barrel");
	inventory[2].lowPrice = 100;
	inventory[2].midPrice = 200;
	inventory[2].highPrice = 300;
	inventory[2].stock = 5;
	inventory[2].biasFlags = 0x240;
	// Blanket
	strcpy(inventory[3].name,"Blanket");
	inventory[3].lowPrice = 30;
	inventory[3].midPrice = 50;
	inventory[3].highPrice = 80;
	inventory[3].stock = 1;
	inventory[3].biasFlags = 0x0;
	// Bucket
	strcpy(inventory[4].name,"Bucket");
	inventory[4].lowPrice = 3;
	inventory[4].midPrice = 5;
	inventory[4].highPrice = 8;
	inventory[4].stock = 3;
	inventory[4].biasFlags = 0x240;
	// Candle
	strcpy(inventory[5].name,"Candle");
	inventory[5].lowPrice = 1;
	inventory[5].midPrice = 1;
	inventory[5].highPrice = 2;
	inventory[5].stock = 2;
	inventory[5].biasFlags = 0x45;
	// Chest
	strcpy(inventory[6].name,"Chest");
	inventory[6].lowPrice = 300;
	inventory[6].midPrice = 500;
	inventory[6].highPrice = 800;
	inventory[6].stock = 7;
	inventory[6].biasFlags = 0x44;
	// Common Clothes
	strcpy(inventory[7].name,"Common Clothes");
	inventory[7].lowPrice = 30;
	inventory[7].midPrice = 50;
	inventory[7].highPrice = 80;
	inventory[7].stock = 5;
	inventory[7].biasFlags = 0x0;
	// Fine Clothes
	strcpy(inventory[8].name,"Fine Clothes");
	inventory[8].lowPrice = 1100;
	inventory[8].midPrice = 1500;
	inventory[8].highPrice = 2300;
	inventory[8].stock = 18;
	inventory[8].biasFlags = 0x804;
	// Flask
	strcpy(inventory[9].name,"Flask");
	inventory[9].lowPrice = 1;
	inventory[9].midPrice = 2;
	inventory[9].highPrice = 3;
	inventory[9].stock = 1;
	inventory[9].biasFlags = 0x0;
	// Glass Bottle
	strcpy(inventory[10].name,"Glass Bottle");
	inventory[10].lowPrice = 100;
	inventory[10].midPrice = 200;
	inventory[10].highPrice = 300;
	inventory[10].stock = 5;
	inventory[10].biasFlags = 0x65;
	// Hammer
	strcpy(inventory[11].name,"Abacus");
	inventory[11].lowPrice = 70;
	inventory[11].midPrice = 100;
	inventory[11].highPrice = 200;
	inventory[11].stock = 5;
	inventory[11].biasFlags = 0x40;
	// Ink
	strcpy(inventory[12].name,"Ink (1 fl. oz.)");
	inventory[12].lowPrice = 700;
	inventory[12].midPrice = 1000;
	inventory[12].highPrice = 1500;
	inventory[12].stock = 3;
	inventory[12].biasFlags = 0x41;
	// Ink Pen
	strcpy(inventory[13].name,"Ink Pen");
	inventory[13].lowPrice = 100;
	inventory[13].midPrice = 200;
	inventory[13].highPrice = 300;
	inventory[13].stock = 7;
	inventory[13].biasFlags = 0x41;
	// Jug
	strcpy(inventory[14].name,"Jug");
	inventory[14].lowPrice = 1;
	inventory[14].midPrice = 2;
	inventory[14].highPrice = 3;
	inventory[14].stock = 7;
	inventory[14].biasFlags = 0x0;
	// Ladder
	strcpy(inventory[15].name,"Ladder (10 ft.)");
	inventory[15].lowPrice = 7;
	inventory[15].midPrice = 10;
	inventory[15].highPrice = 20;
	inventory[15].stock = 7;
	inventory[15].biasFlags = 0x40;
	// Hooded Lantern
	strcpy(inventory[16].name,"Lantern (hooded)");
	inventory[16].lowPrice = 300;
	inventory[16].midPrice = 500;
	inventory[16].highPrice = 800;
	inventory[16].stock = 5;
	inventory[16].biasFlags = 0x40;
	// Lamp
	strcpy(inventory[17].name,"Lamp");
	inventory[17].lowPrice = 300;
	inventory[17].midPrice = 500;
	inventory[17].highPrice = 800;
	inventory[17].stock = 4;
	inventory[17].biasFlags = 0xC5;
	// Lock
	strcpy(inventory[18].name,"Lock");
	inventory[18].lowPrice = 700;
	inventory[18].midPrice = 1000;
	inventory[18].highPrice = 1500;
	inventory[18].stock = 15;
	inventory[18].biasFlags = 0x844;
	// Mess Kit
	strcpy(inventory[19].name,"Mess Kit");
	inventory[19].lowPrice = 10;
	inventory[19].midPrice = 20;
	inventory[19].highPrice = 30;
	inventory[19].stock = 5;
	inventory[19].biasFlags = 0x40;
	// Miner's Pick
	strcpy(inventory[20].name,"Miner's Pick");
	inventory[20].lowPrice = 100;
	inventory[20].midPrice = 200;
	inventory[20].highPrice = 300;
	inventory[20].stock = 8;
	inventory[20].biasFlags = 0x80;
	// Steel Mirror
	strcpy(inventory[21].name,"Mirror (steel)");
	inventory[21].lowPrice = 300;
	inventory[21].midPrice = 500;
	inventory[21].highPrice = 800;
	inventory[21].stock = 8;
	inventory[21].biasFlags = 0x1;
	// Paper
	strcpy(inventory[22].name,"Paper (1)");
	inventory[22].lowPrice = 10;
	inventory[22].midPrice = 20;
	inventory[22].highPrice = 30;
	inventory[22].stock = 7;
	inventory[22].biasFlags = 0x41;
	// Parchment
	strcpy(inventory[23].name,"Parchment (1)");
	inventory[23].lowPrice = 7;
	inventory[23].midPrice = 10;
	inventory[23].highPrice = 20;
	inventory[23].stock = 2;
	inventory[23].biasFlags = 0x41;
	// Pot
	strcpy(inventory[24].name,"Pot (iron)");
	inventory[24].lowPrice = 100;
	inventory[24].midPrice = 200;
	inventory[24].highPrice = 300;
	inventory[24].stock = 1;
	inventory[24].biasFlags = 0x0;
	// Pouch
	strcpy(inventory[25].name,"Pouch");
	inventory[25].lowPrice = 30;
	inventory[25].midPrice = 50;
	inventory[25].highPrice = 80;
	inventory[25].stock = 3;
	inventory[25].biasFlags = 0x0;
	// Rope
	strcpy(inventory[26].name,"Hemp Rope (50 ft.)");
	inventory[26].lowPrice = 70;
	inventory[26].midPrice = 100;
	inventory[26].highPrice = 200;
	inventory[26].stock = 2;
	inventory[26].biasFlags = 0x2C2;
	// Silk Rope
	strcpy(inventory[27].name,"Silk Rope (50 ft.)");
	inventory[27].lowPrice = 700;
	inventory[27].midPrice = 1000;
	inventory[27].highPrice = 1500;
	inventory[27].stock = 18;
	inventory[27].biasFlags = 0xC;
	// Sack
	strcpy(inventory[28].name,"Sack");
	inventory[28].lowPrice = 1;
	inventory[28].midPrice = 1;
	inventory[28].highPrice = 2;
	inventory[28].stock = 1;
	inventory[28].biasFlags = 0x0;
	// Scale
	strcpy(inventory[29].name,"Scale");
	inventory[29].lowPrice = 300;
	inventory[29].midPrice = 500;
	inventory[29].highPrice = 800;
	inventory[29].stock = 8;
	inventory[29].biasFlags = 0x45;
	// Shovel
	strcpy(inventory[30].name,"Shovel");
	inventory[30].lowPrice = 100;
	inventory[30].midPrice = 200;
	inventory[30].highPrice = 300;
	inventory[30].stock = 5;
	inventory[30].biasFlags = 0x280;
	// Signet Ring
	strcpy(inventory[31].name,"Signet Ring");
	inventory[31].lowPrice = 300;
	inventory[31].midPrice = 500;
	inventory[31].highPrice = 800;
	inventory[31].stock = 12;
	inventory[31].biasFlags = 0x94d;
	// Soap
	strcpy(inventory[32].name,"Soap");
	inventory[32].lowPrice = 1;
	inventory[32].midPrice = 2;
	inventory[32].highPrice = 3;
	inventory[32].stock = 5;
	inventory[32].biasFlags = 0x5;
	// Vial
	strcpy(inventory[33].name,"Vial");
	inventory[33].lowPrice = 70;
	inventory[33].midPrice = 100;
	inventory[33].highPrice = 200;
	inventory[33].stock = 5;
	inventory[33].biasFlags = 0x41;
	
	// Tools Section Header
	strcpy(inventory[39].name,"TOOLS");
	inventory[39].lowPrice = 0;
	inventory[39].midPrice = 0;
	inventory[39].highPrice = 0;
	inventory[39].stock = 0;
	inventory[39].biasFlags = 0x0;
	// Carpenter's Tools
	strcpy(inventory[40].name,"Carpenter's Tools");
	inventory[40].lowPrice = 1100;
	inventory[40].midPrice = 1500;
	inventory[40].highPrice = 2300;
	inventory[40].stock = 3;
	inventory[40].biasFlags = 0x40;
	// Cobbler's Tools
	strcpy(inventory[41].name,"Cobbler's Tools");
	inventory[41].lowPrice = 300;
	inventory[41].midPrice = 500;
	inventory[41].highPrice = 800;
	inventory[41].stock = 5;
	inventory[41].biasFlags = 0x40;
	// Cook's Utensils
	strcpy(inventory[42].name,"Cook's Utensils");
	inventory[42].lowPrice = 70;
	inventory[42].midPrice = 100;
	inventory[42].highPrice = 200;
	inventory[42].stock = 2;
	inventory[42].biasFlags = 0x40;
	// Glassblower's Tools
	strcpy(inventory[43].name,"Glassblower's Tools");
	inventory[43].lowPrice = 2200;
	inventory[43].midPrice = 3000;
	inventory[43].highPrice = 4500;
	inventory[43].stock = 18;
	inventory[43].biasFlags = 0x40;
	// Leatherworker's Tools
	strcpy(inventory[44].name,"Leatherworker's Tools");
	inventory[44].lowPrice = 300;
	inventory[44].midPrice = 500;
	inventory[44].highPrice = 800;
	inventory[44].stock = 5;
	inventory[44].biasFlags = 0x40;
	// Mason's Tools
	strcpy(inventory[45].name,"Mason's Tools");
	inventory[45].lowPrice = 700;
	inventory[45].midPrice = 1000;
	inventory[45].highPrice = 1500;
	inventory[45].stock = 3;
	inventory[45].biasFlags = 0x40;
	// Potter's Tools
	strcpy(inventory[46].name,"Potter's Tools");
	inventory[46].lowPrice = 700;
	inventory[46].midPrice = 1000;
	inventory[46].highPrice = 1500;
	inventory[46].stock = 5;
	inventory[46].biasFlags = 0x40;
	// Smith's Tools
	strcpy(inventory[47].name,"Smith's Tools");
	inventory[47].lowPrice = 700;
	inventory[47].midPrice = 1500;
	inventory[47].highPrice = 2000;
	inventory[47].stock = 15;
	inventory[47].biasFlags = 0x40;
	// Weaver's Tools
	strcpy(inventory[48].name,"Weaver's Tools");
	inventory[48].lowPrice = 70;
	inventory[48].midPrice = 100;
	inventory[48].highPrice = 200;
	inventory[48].stock = 5;
	inventory[48].biasFlags = 0x40;
	// Woodcarver's Tools
	strcpy(inventory[49].name,"Woodcarver's Tools");
	inventory[49].lowPrice = 70;
	inventory[49].midPrice = 100;
	inventory[49].highPrice = 200;
	inventory[49].stock = 3;
	inventory[49].biasFlags = 0x40;
	
	// Foodstuffs Section Header
	strcpy(inventory[51].name,"FOODSTUFFS");
	inventory[51].lowPrice = 0;
	inventory[51].midPrice = 0;
	inventory[51].highPrice = 0;
	inventory[51].stock = 0;
	inventory[51].biasFlags = 0;
	// Apples
	strcpy(inventory[52].name,"Apples (1 lb.)");
	inventory[52].lowPrice = 1;
	inventory[52].midPrice = 2;
	inventory[52].highPrice = 10;
	inventory[52].stock = 3;
	inventory[52].biasFlags = 0x400;
	// Beans
	strcpy(inventory[53].name,"Beans (1 lb.)");
	inventory[53].lowPrice = 1;
	inventory[53].midPrice = 2;
	inventory[53].highPrice = 3;
	inventory[53].stock = 2;
	inventory[53].biasFlags = 0x400;
	// Beer
	strcpy(inventory[54].name,"Beer (1 qt.)");
	inventory[54].lowPrice = 7;
	inventory[54].midPrice = 10;
	inventory[54].highPrice = 20;
	inventory[54].stock = 4;
	inventory[54].biasFlags = 0x400;
	// Berries
	strcpy(inventory[55].name,"Berries (1 lb.)");
	inventory[55].lowPrice = 3;
	inventory[55].midPrice = 5;
	inventory[55].highPrice = 10;
	inventory[55].stock = 3;
	inventory[55].biasFlags = 0x400;
	// Common Brandy
	strcpy(inventory[56].name,"Common Brandy (1 qt.)");
	inventory[56].lowPrice = 20;
	inventory[56].midPrice = 30;
	inventory[56].highPrice = 50;
	inventory[56].stock = 12;
	inventory[56].biasFlags = 0x400;
	// Good Brandy
	strcpy(inventory[57].name,"Good Brandy (1 qt.)");
	inventory[57].lowPrice = 100;
	inventory[57].midPrice = 150;
	inventory[57].highPrice = 300;
	inventory[57].stock = 17;
	inventory[57].biasFlags = 0x405;
	// Bread
	strcpy(inventory[58].name,"Bread (1 lb.)");
	inventory[58].lowPrice = 5;
	inventory[58].midPrice = 8;
	inventory[58].highPrice = 10;
	inventory[58].stock = 4;
	inventory[58].biasFlags = 0x400;
	// White Bread
	strcpy(inventory[59].name,"White Bread (1 lb.)");
	inventory[59].lowPrice = 10;
	inventory[59].midPrice = 15;
	inventory[59].highPrice = 20;
	inventory[59].stock = 10;
	inventory[59].biasFlags = 0x804;
	// Butter
	strcpy(inventory[60].name,"Butter (1 lb.)");
	inventory[60].lowPrice = 10;
	inventory[60].midPrice = 20;
	inventory[60].highPrice = 30;
	inventory[60].stock = 5;
	inventory[60].biasFlags = 0x400;
	// Carrots
	strcpy(inventory[61].name,"Carrots (1 lb.)");
	inventory[61].lowPrice = 1;
	inventory[61].midPrice = 2;
	inventory[61].highPrice = 4;
	inventory[61].stock = 2;
	inventory[61].biasFlags = 0x400;
	// Common Cheese
	strcpy(inventory[62].name,"Common Cheese (1 lb.)");
	inventory[62].lowPrice = 10;
	inventory[62].midPrice = 15;
	inventory[62].highPrice = 20;
	inventory[62].stock = 3;
	inventory[62].biasFlags = 0x400;
	// Cider
	strcpy(inventory[63].name,"Cider (1 qt.)");
	inventory[63].lowPrice = 20;
	inventory[63].midPrice = 30;
	inventory[63].highPrice = 50;
	inventory[63].stock = 5;
	inventory[63].biasFlags = 0x400;
	// Coffee
	strcpy(inventory[64].name,"Coffee (1 lb.)");
	inventory[64].lowPrice = 20;
	inventory[64].midPrice = 30;
	inventory[64].highPrice = 50;
	inventory[64].stock = 7;
	inventory[64].biasFlags = 0x401;
	// Corn
	strcpy(inventory[65].name,"Corn (1 lb.)");
	inventory[65].lowPrice = 4;
	inventory[65].midPrice = 6;
	inventory[65].highPrice = 8;
	inventory[65].stock = 3;
	inventory[65].biasFlags = 0x400;
	// Feed Corn
	strcpy(inventory[66].name,"Feed Corn (1 lb.)");
	inventory[66].lowPrice = 1;
	inventory[66].midPrice = 1;
	inventory[66].highPrice = 2;
	inventory[66].stock = 1;
	inventory[66].biasFlags = 0x400;
	// Sweet Corn
	strcpy(inventory[67].name,"Sweet Corn (1 lb.)");
	inventory[67].lowPrice = 8;
	inventory[67].midPrice = 10;
	inventory[67].highPrice = 12;
	inventory[67].stock = 15;
	inventory[67].biasFlags = 0x400;
	// Eggs
	strcpy(inventory[68].name,"Eggs (dozen)");
	inventory[68].lowPrice = 4;
	inventory[68].midPrice = 6;
	inventory[68].highPrice = 9;
	inventory[68].stock = 2;
	inventory[68].biasFlags = 0x400;
	// Flour
	strcpy(inventory[69].name,"Flour (1 lb.)");
	inventory[69].lowPrice = 4;
	inventory[69].midPrice = 5;
	inventory[69].highPrice = 7;
	inventory[69].stock = 2;
	inventory[69].biasFlags = 0x400;
	// White Flour
	strcpy(inventory[70].name,"White Flour (1 lb.)");
	inventory[70].lowPrice = 8;
	inventory[70].midPrice = 10;
	inventory[70].highPrice = 12;
	inventory[70].stock = 7;
	inventory[70].biasFlags = 0x800;
	// Garlic
	strcpy(inventory[71].name,"Garlic (1 lb.)");
	inventory[71].lowPrice = 2;
	inventory[71].midPrice = 3;
	inventory[71].highPrice = 5;
	inventory[71].stock = 5;
	inventory[71].biasFlags = 0x401;
	// Gourds
	strcpy(inventory[72].name,"Gourds (1 lb.)");
	inventory[72].lowPrice = 7;
	inventory[72].midPrice = 9;
	inventory[72].highPrice = 12;
	inventory[72].stock = 3;
	inventory[72].biasFlags = 0x400;
	// Grapes
	strcpy(inventory[73].name,"Grapes (1 lb.)");
	inventory[73].lowPrice = 1;
	inventory[73].midPrice = 2;
	inventory[73].highPrice = 10;
	inventory[73].stock = 12;
	inventory[73].biasFlags = 0x404;
	// Greens
	strcpy(inventory[74].name,"Greens (1 lb.)");
	inventory[74].lowPrice = 2;
	inventory[74].midPrice = 4;
	inventory[74].highPrice = 6;
	inventory[74].stock = 1;
	inventory[74].biasFlags = 0x400;
	// Honey
	strcpy(inventory[75].name,"Honey (1 qt.)");
	inventory[75].lowPrice = 6;
	inventory[75].midPrice = 7;
	inventory[75].highPrice = 8;
	inventory[75].stock = 10;
	inventory[75].biasFlags = 0x400;
	// Mead
	strcpy(inventory[76].name,"Mead (1 qt.)");
	inventory[76].lowPrice = 30;
	inventory[76].midPrice = 50;
	inventory[76].highPrice = 80;
	inventory[76].stock = 12;
	inventory[76].biasFlags = 0x400;
	// Melons
	strcpy(inventory[77].name,"Melons (1 lb.)");
	inventory[77].lowPrice = 7;
	inventory[77].midPrice = 9;
	inventory[77].highPrice = 12;
	inventory[77].stock = 5;
	inventory[77].biasFlags = 0x400;
	// Milk
	strcpy(inventory[78].name,"Milk (1 gal.)");
	inventory[78].lowPrice = 1;
	inventory[78].midPrice = 2;
	inventory[78].highPrice = 4;
	inventory[78].stock = 2;
	inventory[78].biasFlags = 0x400;
	// Nuts
	strcpy(inventory[79].name,"Nuts (1 lb.)");
	inventory[79].lowPrice = 3;
	inventory[79].midPrice = 5;
	inventory[79].highPrice = 8;
	inventory[79].stock = 5;
	inventory[79].biasFlags = 0x400;
	// Onions
	strcpy(inventory[80].name,"Onions (1 lb.)");
	inventory[80].lowPrice = 1;
	inventory[80].midPrice = 2;
	inventory[80].highPrice = 5;
	inventory[80].stock = 2;
	inventory[80].biasFlags = 0x401;
	// Orange
	strcpy(inventory[81].name,"Oranges (1 lb.)");
	inventory[81].lowPrice = 1;
	inventory[81].midPrice = 2;
	inventory[81].highPrice = 10;
	inventory[81].stock = 15;
	inventory[81].biasFlags = 0x404;
	// Popcorn Kernels
	strcpy(inventory[82].name,"Popcorn Kernels (1 lb.)");
	inventory[82].lowPrice = 10;
	inventory[82].midPrice = 12;
	inventory[82].highPrice = 14;
	inventory[82].stock = 12;
	inventory[82].biasFlags = 0x400;
	// Potatoes
	strcpy(inventory[83].name,"Potatoes (1 lb.)");
	inventory[83].lowPrice = 1;
	inventory[83].midPrice = 2;
	inventory[83].highPrice = 3;
	inventory[83].stock = 1;
	inventory[83].biasFlags = 0x400;
	// Radish
	strcpy(inventory[84].name,"Radish (1 lb.)");
	inventory[84].lowPrice = 1;
	inventory[84].midPrice = 2;
	inventory[84].highPrice = 4;
	inventory[84].stock = 3;
	inventory[84].biasFlags = 0x400;
	// Rice
	strcpy(inventory[85].name,"Rice (1 lb.)");
	inventory[85].lowPrice = 1;
	inventory[85].midPrice = 1;
	inventory[85].highPrice = 2;
	inventory[85].stock = 2;
	inventory[85].biasFlags = 0x400;
	// Salt
	strcpy(inventory[86].name,"Salt (1 lb.)");
	inventory[86].lowPrice = 3;
	inventory[86].midPrice = 5;
	inventory[86].highPrice = 8;
	inventory[86].stock = 2;
	inventory[86].biasFlags = 0x400;
	// Common Spice 
	strcpy(inventory[87].name,"Common Spice (1 lb.)");
	inventory[87].lowPrice = 80;
	inventory[87].midPrice = 100;
	inventory[87].highPrice = 200;
	inventory[87].stock = 2;
	inventory[87].biasFlags = 0x400;
	// Uncommon Spice
	strcpy(inventory[88].name,"Uncommon Spice (1 lb.)");
	inventory[88].lowPrice = 100;
	inventory[88].midPrice = 200;
	inventory[88].highPrice = 400;
	inventory[88].stock = 7;
	inventory[88].biasFlags = 0x400;
	// Common Spirit
	strcpy(inventory[89].name,"Common Spirit (1 qt.)");
	inventory[89].lowPrice = 20;
	inventory[89].midPrice = 30;
	inventory[89].highPrice = 50;
	inventory[89].stock = 5;
	inventory[89].biasFlags = 0x400;
	// Good Spirit
	strcpy(inventory[90].name,"Good Spirit (1 qt.)");
	inventory[90].lowPrice = 50;
	inventory[90].midPrice = 70;
	inventory[90].highPrice = 100;
	inventory[90].stock = 10;
	inventory[90].biasFlags = 0x400;
	// Tea
	strcpy(inventory[91].name,"Tea (1 lb.)");
	inventory[91].lowPrice = 10;
	inventory[91].midPrice = 12;
	inventory[91].highPrice = 15;
	inventory[91].stock = 7;
	inventory[91].biasFlags = 0x404;
	// Tomato
	strcpy(inventory[92].name,"Tomato (1 lb.)");
	inventory[92].lowPrice = 7;
	inventory[92].midPrice = 9;
	inventory[92].highPrice = 12;
	inventory[92].stock = 3;
	inventory[92].biasFlags = 0x400;
	// Watermelon
	strcpy(inventory[93].name,"Watermelon (1 lb.)");
	inventory[93].lowPrice = 5;
	inventory[93].midPrice = 7;
	inventory[93].highPrice = 10;
	inventory[93].stock = 3;
	inventory[93].biasFlags = 0x400;
	// Wheat
	strcpy(inventory[94].name,"Wheat (1 lb.)");
	inventory[94].lowPrice = 1;
	inventory[94].midPrice = 2;
	inventory[94].highPrice = 3;
	inventory[94].stock = 3;
	inventory[94].biasFlags = 0x400;
	// Common Wine
	strcpy(inventory[95].name,"Common Wine (1 qt.)");
	inventory[95].lowPrice = 10;
	inventory[95].midPrice = 20;
	inventory[95].highPrice = 30;
	inventory[95].stock = 5;
	inventory[95].biasFlags = 0x400;
	// Good Wine
	strcpy(inventory[96].name,"Good Wine (1 qt.)");
	inventory[96].lowPrice = 70;
	inventory[96].midPrice = 100;
	inventory[96].highPrice = 150;
	inventory[96].stock = 15;
	inventory[96].biasFlags = 0x400;
	// Yams
	strcpy(inventory[97].name,"Yams (1 lb.)");
	inventory[97].lowPrice = 1;
	inventory[97].midPrice = 2;
	inventory[97].highPrice = 4;
	inventory[97].stock = 5;
	inventory[97].biasFlags = 0x400;
	
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeLeather(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 28;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Light Armor Section Name
	strcpy(inventory[0].name,"LIGHT ARMOR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Leather
	strcpy(inventory[1].name,"Leather");
	inventory[1].lowPrice = 700;
	inventory[1].midPrice = 1000;
	inventory[1].highPrice = 1500;
	inventory[1].stock = 2;
	inventory[1].biasFlags = 0x10;
	// Studded Leather
	strcpy(inventory[2].name,"Studded Leather");
	inventory[2].lowPrice = 3300;
	inventory[2].midPrice = 4500;
	inventory[2].highPrice = 6800;
	inventory[2].stock = 5;
	inventory[2].biasFlags = 0x10;
	
	// Medium Armor Section Name
	strcpy(inventory[3].name,"MEDIUM ARMOR");
	inventory[3].lowPrice = 0;
	inventory[3].midPrice = 0;
	inventory[3].highPrice = 0;
	inventory[3].stock = 0;
	inventory[3].biasFlags = 0;
	// Hide
	strcpy(inventory[4].name,"Hide");
	inventory[4].lowPrice = 700;
	inventory[4].midPrice = 1000;
	inventory[4].highPrice = 1500;
	inventory[4].stock = 2;
	inventory[4].biasFlags = 0x10;
	
	// Shield Armor Section Name
	strcpy(inventory[5].name,"SHIELD");
	inventory[5].lowPrice = 0;
	inventory[5].midPrice = 0;
	inventory[5].highPrice = 0;
	inventory[5].stock = 0;
	inventory[5].biasFlags = 0;
	// Shield
	strcpy(inventory[6].name,"Shield");
	inventory[6].lowPrice = 700;
	inventory[6].midPrice = 1000;
	inventory[6].highPrice = 1500;
	inventory[6].stock = 4;
	inventory[6].biasFlags = 0x10;
	
	// Weapons Section Name
	strcpy(inventory[7].name,"WEAPONS");
	inventory[7].lowPrice = 0;
	inventory[7].midPrice = 0;
	inventory[7].highPrice = 0;
	inventory[7].stock = 0;
	inventory[7].biasFlags = 0;
	// Hide
	strcpy(inventory[8].name,"Sling");
	inventory[8].lowPrice = 7;
	inventory[8].midPrice = 10;
	inventory[8].highPrice = 20;
	inventory[8].stock = 5;
	inventory[8].biasFlags = 0x10;
	
	// Gear Section Name
	strcpy(inventory[11].name,"GEAR");
	inventory[11].lowPrice = 0;
	inventory[11].midPrice = 0;
	inventory[11].highPrice = 0;
	inventory[11].stock = 0;
	inventory[11].biasFlags = 0;
	// Barding
	strcpy(inventory[12].name,"Barding (Mount Armor)");
	inventory[12].lowPrice = 0;
	inventory[12].midPrice = 0;
	inventory[12].highPrice = 0;
	inventory[12].stock = 15;
	inventory[12].biasFlags = 0x14;
	// Bit and Bridle
	strcpy(inventory[13].name,"Bit & Bridle");
	inventory[13].lowPrice = 100;
	inventory[13].midPrice = 200;
	inventory[13].highPrice = 300;
	inventory[13].stock = 5;
	inventory[13].biasFlags = 0x14;
	// Pack Saddle
	strcpy(inventory[14].name,"Pack Saddle");
	inventory[14].lowPrice = 300;
	inventory[14].midPrice = 500;
	inventory[14].highPrice = 1000;
	inventory[14].stock = 2;
	inventory[14].biasFlags = 0x10;
	// Riding Saddle
	strcpy(inventory[15].name,"Riding Saddle");
	inventory[15].lowPrice = 800;
	inventory[15].midPrice = 1000;
	inventory[15].highPrice = 1500;
	inventory[15].stock = 5;
	inventory[15].biasFlags = 0x04;
	// Military Saddle
	strcpy(inventory[16].name,"Military Saddle");
	inventory[16].lowPrice = 1500;
	inventory[16].midPrice = 2000;
	inventory[16].highPrice = 3000;
	inventory[16].stock = 10;
	inventory[16].biasFlags = 0x14;
	// Exotic Saddle
	strcpy(inventory[17].name,"Exotic Saddle");
	inventory[17].lowPrice = 5000;
	inventory[17].midPrice = 6000;
	inventory[17].highPrice = 8000;
	inventory[17].stock = 17;
	inventory[17].biasFlags = 0x1D;
	// Saddlebags
	strcpy(inventory[18].name,"Saddlebags");
	inventory[18].lowPrice = 200;
	inventory[18].midPrice = 400;
	inventory[18].highPrice = 700;
	inventory[18].stock = 5;
	inventory[18].biasFlags = 0x10;
	// Waterskin
	strcpy(inventory[19].name,"Waterskin");
	inventory[19].lowPrice = 10;
	inventory[19].midPrice = 20;
	inventory[19].highPrice = 30;
	inventory[19].stock = 1;
	inventory[19].biasFlags = 0x10;
	
	// Tools Section Name
	strcpy(inventory[23].name,"TOOLS");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0;
	// Bagpipes
	strcpy(inventory[24].name,"Bagpipes");
	inventory[24].lowPrice = 2200;
	inventory[24].midPrice = 3000;
	inventory[24].highPrice = 4500;
	inventory[24].stock = 20;
	inventory[24].biasFlags = 0x111;
	// Cobbler's Tools
	strcpy(inventory[25].name,"Cobbler's Tools");
	inventory[25].lowPrice = 300;
	inventory[25].midPrice = 500;
	inventory[25].highPrice = 800;
	inventory[25].stock = 5;
	inventory[25].biasFlags = 0x0;
	// Drums
	strcpy(inventory[26].name,"Drums");
	inventory[26].lowPrice = 400;
	inventory[26].midPrice = 600;
	inventory[26].highPrice = 900;
	inventory[26].stock = 4;
	inventory[26].biasFlags = 0x0;
	// Leatherworker's Tools
	strcpy(inventory[27].name,"Leatherworker's Tools");
	inventory[27].lowPrice = 300;
	inventory[27].midPrice = 500;
	inventory[27].highPrice = 800;
	inventory[27].stock = 2;
	inventory[27].biasFlags = 0x0;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				if (strcmp(inventory[i].name,"Barding (Mount Armor)")){
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
					fprintf(storeHere, "%c", dividerChar);
					convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
					fprintf(storeHere, "%c", dividerChar);
					convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
					fprintf(storeHere, "\n");
				}
				else { // Is Barding
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "%9s", "3x MtCost");
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "%9s", "4x MtCost");
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "%9s", "5x MtCost");
					fprintf(storeHere, "\n");
				}
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeMusic(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 33;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Instruments Section Name
	strcpy(inventory[0].name,"INSTRUMENTS");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Bagpipes
	strcpy(inventory[1].name,"Bagpipes");
	inventory[1].lowPrice = 2200;
	inventory[1].midPrice = 3000;
	inventory[1].highPrice = 4500;
	inventory[1].stock = 10;
	inventory[1].biasFlags = 0x10;
	// Drum
	strcpy(inventory[2].name,"Drum");
	inventory[2].lowPrice = 400;
	inventory[2].midPrice = 600;
	inventory[2].highPrice = 900;
	inventory[2].stock = 1;
	inventory[2].biasFlags = 0x10;
	// Dulcimer
	strcpy(inventory[3].name,"Dulcimer");
	inventory[3].lowPrice = 400;
	inventory[3].midPrice = 600;
	inventory[3].highPrice = 900;
	inventory[3].stock = 7;
	inventory[3].biasFlags = 0x4;
	// Flute
	strcpy(inventory[4].name,"Flute");
	inventory[4].lowPrice = 100;
	inventory[4].midPrice = 200;
	inventory[4].highPrice = 300;
	inventory[4].stock = 1;
	inventory[4].biasFlags = 0x1;
	// Glockenspiel
	strcpy(inventory[5].name,"Glockenspiel");
	inventory[5].lowPrice = 800;
	inventory[5].midPrice = 1000;
	inventory[5].highPrice = 1500;
	inventory[5].stock = 5;
	inventory[5].biasFlags = 0x4;
	// Horn
	strcpy(inventory[6].name,"Horn");
	inventory[6].lowPrice = 200;
	inventory[6].midPrice = 300;
	inventory[6].highPrice = 500;
	inventory[6].stock = 1;
	inventory[6].biasFlags = 0x4;
	// Hurdy Gurdy
	strcpy(inventory[7].name,"Hurdy Gurdy");
	inventory[7].lowPrice = 2600;
	inventory[7].midPrice = 3500;
	inventory[7].highPrice = 5200;
	inventory[7].stock = 15;
	inventory[7].biasFlags = 0x4;
	// Lute
	strcpy(inventory[8].name,"Lute");
	inventory[8].lowPrice = 2600;
	inventory[8].midPrice = 3500;
	inventory[8].highPrice = 5200;
	inventory[8].stock = 15;
	inventory[8].biasFlags = 0x4;
	// Lyre
	strcpy(inventory[9].name,"Lyre");
	inventory[9].lowPrice = 2200;
	inventory[9].midPrice = 3000;
	inventory[9].highPrice = 4500;
	inventory[9].stock = 5;
	inventory[9].biasFlags = 0x4;
	// Mandolin
	strcpy(inventory[10].name,"Mandolin");
	inventory[10].lowPrice = 2200;
	inventory[10].midPrice = 3000;
	inventory[10].highPrice = 4500;
	inventory[10].stock = 5;
	inventory[10].biasFlags = 0x4;
	// Oboe
	strcpy(inventory[11].name,"Oboe");
	inventory[11].lowPrice = 1500;
	inventory[11].midPrice = 2000;
	inventory[11].highPrice = 3000;
	inventory[11].stock = 5;
	inventory[11].biasFlags = 0x4;
	// Ocarina
	strcpy(inventory[12].name,"Ocarina");
	inventory[12].lowPrice = 900;
	inventory[12].midPrice = 1200;
	inventory[12].highPrice = 1800;
	inventory[12].stock = 5;
	inventory[12].biasFlags = 0x4;
	// Pan Flute
	strcpy(inventory[13].name,"Pan Flute");
	inventory[13].lowPrice = 900;
	inventory[13].midPrice = 1200;
	inventory[13].highPrice = 1800;
	inventory[13].stock = 10;
	inventory[13].biasFlags = 0x4;
	// Shawm
	strcpy(inventory[14].name,"Shawm");
	inventory[14].lowPrice = 100;
	inventory[14].midPrice = 200;
	inventory[14].highPrice = 300;
	inventory[14].stock = 2;
	inventory[14].biasFlags = 0x4;
	// Trombone
	strcpy(inventory[15].name,"Trombone");
	inventory[15].lowPrice = 2200;
	inventory[15].midPrice = 3000;
	inventory[15].highPrice = 4500;
	inventory[15].stock = 10;
	inventory[15].biasFlags = 0x4;
	// Trumpet
	strcpy(inventory[16].name,"Trumpet");
	inventory[16].lowPrice = 1500;
	inventory[16].midPrice = 2000;
	inventory[16].highPrice = 3000;
	inventory[16].stock = 7;
	inventory[16].biasFlags = 0x14;
	// Tuba
	strcpy(inventory[17].name,"Tuba");
	inventory[17].lowPrice = 2200;
	inventory[17].midPrice = 3000;
	inventory[17].highPrice = 4500;
	inventory[17].stock = 10;
	inventory[17].biasFlags = 0x4;
	// Viol
	strcpy(inventory[18].name,"Viol");
	inventory[18].lowPrice = 2200;
	inventory[18].midPrice = 3000;
	inventory[18].highPrice = 4500;
	inventory[18].stock = 5;
	inventory[18].biasFlags = 0x4;
	
	// Tools Section Header
	strcpy(inventory[23].name,"TOOLS");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0;
	// Leatherworker's Tools
	strcpy(inventory[24].name,"Leatherworker's Tools");
	inventory[24].lowPrice = 300;
	inventory[24].midPrice = 500;
	inventory[24].highPrice = 800;
	inventory[24].stock = 15;
	inventory[24].biasFlags = 0x4;
	// Tinker's Tools
	strcpy(inventory[25].name,"Tinker's Tools");
	inventory[25].lowPrice = 3800;
	inventory[25].midPrice = 5000;
	inventory[25].highPrice = 7500;
	inventory[25].stock = 12;
	inventory[25].biasFlags = 0x4;
	// Leatherworker's Tools
	strcpy(inventory[26].name,"Smith's Tools");
	inventory[26].lowPrice = 700;
	inventory[26].midPrice = 1500;
	inventory[26].highPrice = 2000;
	inventory[26].stock = 15;
	inventory[26].biasFlags = 0x4;
	
	// Services Section Header
	strcpy(inventory[31].name,"SERVICES");
	inventory[31].lowPrice = 0;
	inventory[31].midPrice = 0;
	inventory[31].highPrice = 0;
	inventory[31].stock = 0;
	inventory[31].biasFlags = 0;
	// Leatherworker's Tools
	strcpy(inventory[32].name,"Music Lesson");
	inventory[32].lowPrice = 50;
	inventory[32].midPrice = 100;
	inventory[32].highPrice = 200;
	inventory[32].stock = 7;
	inventory[32].biasFlags = 0x4;
	
	
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeTailor(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 27;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Gear Section Name
	strcpy(inventory[0].name,"GEAR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Backpack
	strcpy(inventory[1].name,"Backpack");
	inventory[1].lowPrice = 100;
	inventory[1].midPrice = 200;
	inventory[1].highPrice = 300;
	inventory[1].stock = 5;
	inventory[1].biasFlags = 0x0;
	// Basket
	strcpy(inventory[2].name,"Basket");
	inventory[2].lowPrice = 30;
	inventory[2].midPrice = 40;
	inventory[2].highPrice = 60;
	inventory[2].stock = 2;
	inventory[2].biasFlags = 0x0;
	// Bedroll
	strcpy(inventory[3].name,"Bedroll");
	inventory[3].lowPrice = 70;
	inventory[3].midPrice = 100;
	inventory[3].highPrice = 200;
	inventory[3].stock = 5;
	inventory[3].biasFlags = 0x400;
	// Blanket
	strcpy(inventory[4].name,"Blanket");
	inventory[4].lowPrice = 30;
	inventory[4].midPrice = 50;
	inventory[4].highPrice = 80;
	inventory[4].stock = 1;
	inventory[4].biasFlags = 0x0;
	// Pouch
	strcpy(inventory[5].name,"Pouch");
	inventory[5].lowPrice = 30;
	inventory[5].midPrice = 50;
	inventory[5].highPrice = 80;
	inventory[5].stock = 1;
	inventory[5].biasFlags = 0x0;
	// Sack
	strcpy(inventory[6].name,"Sack");
	inventory[6].lowPrice = 1;
	inventory[6].midPrice = 1;
	inventory[6].highPrice = 2;
	inventory[6].stock = 1;
	inventory[6].biasFlags = 0x0;
	// Tent
	strcpy(inventory[7].name,"Tent");
	inventory[7].lowPrice = 100;
	inventory[7].midPrice = 200;
	inventory[7].highPrice = 300;
	inventory[7].stock = 3;
	inventory[7].biasFlags = 0x400;
	
	// Clothes Section Name
	strcpy(inventory[11].name,"CLOTHES");
	inventory[11].lowPrice = 0;
	inventory[11].midPrice = 0;
	inventory[11].highPrice = 0;
	inventory[11].stock = 0;
	inventory[11].biasFlags = 0;
	// Common
	strcpy(inventory[12].name,"Common");
	inventory[12].lowPrice = 30;
	inventory[12].midPrice = 50;
	inventory[12].highPrice = 80;
	inventory[12].stock = 1;
	inventory[12].biasFlags = 0x0;
	// Costume
	strcpy(inventory[13].name,"Costume");
	inventory[13].lowPrice = 30;
	inventory[13].midPrice = 50;
	inventory[13].highPrice = 80;
	inventory[13].stock = 17;
	inventory[13].biasFlags = 0x0;
	// Fine
	strcpy(inventory[14].name,"Fine");
	inventory[14].lowPrice = 1300;
	inventory[14].midPrice = 1500;
	inventory[14].highPrice = 2300;
	inventory[14].stock = 10;
	inventory[14].biasFlags = 0x4;
	// Robes
	strcpy(inventory[15].name,"Robes");
	inventory[15].lowPrice = 70;
	inventory[15].midPrice = 100;
	inventory[15].highPrice = 200;
	inventory[15].stock = 10;
	inventory[15].biasFlags = 0x105;
	// Traveler's
	strcpy(inventory[16].name,"Traveler's");
	inventory[16].lowPrice = 100;
	inventory[16].midPrice = 200;
	inventory[16].highPrice = 300;
	inventory[16].stock = 7;
	inventory[16].biasFlags = 0x50;
	
	// Tools Section Name
	strcpy(inventory[19].name,"TOOLS");
	inventory[19].lowPrice = 0;
	inventory[19].midPrice = 0;
	inventory[19].highPrice = 0;
	inventory[19].stock = 0;
	inventory[19].biasFlags = 0;
	// Weaver's Tools
	strcpy(inventory[20].name,"Weaver's Tools");
	inventory[20].lowPrice = 70;
	inventory[20].midPrice = 100;
	inventory[20].highPrice = 200;
	inventory[20].stock = 2;
	inventory[20].biasFlags = 0x0;
	
	// Textiles Section Name
	strcpy(inventory[23].name,"TEXTILES");
	inventory[23].lowPrice = 0;
	inventory[23].midPrice = 0;
	inventory[23].highPrice = 0;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0;
	// Canvas
	strcpy(inventory[24].name,"Canvas (1 sq. yd.)");
	inventory[24].lowPrice = 7;
	inventory[24].midPrice = 10;
	inventory[24].highPrice = 20;
	inventory[24].stock = 2;
	inventory[24].biasFlags = 0x4F2;
	// Linen
	strcpy(inventory[25].name,"Linen (1 sq. yd.)");
	inventory[25].lowPrice = 400;
	inventory[25].midPrice = 500;
	inventory[25].highPrice = 700;
	inventory[25].stock = 7;
	inventory[25].biasFlags = 0x905;
	// Silk
	strcpy(inventory[26].name,"Silk (1 sq. yd.)");
	inventory[26].lowPrice = 800;
	inventory[26].midPrice = 1000;
	inventory[26].highPrice = 1300;
	inventory[26].stock = 15;
	inventory[26].biasFlags = 0x104;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeTavern(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 128;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	uint8_t numDishes = 43;
	// DISHES Section Name
	strcpy(inventory[0].name,"DISHES");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Baked Beans
	strcpy(inventory[1].name,"Baked Beans");
	inventory[1].lowPrice = 1;
	inventory[1].midPrice = 2;
	inventory[1].highPrice = 3;
	inventory[1].stock = 0;
	inventory[1].biasFlags = 0x0;
	// Beef Sandwich
	strcpy(inventory[2].name,"Beef Sandwich");
	inventory[2].lowPrice = 18;
	inventory[2].midPrice = 22;
	inventory[2].highPrice = 30;
	inventory[2].stock = 0;
	inventory[2].biasFlags = 0x0;
	// Biscuits
	strcpy(inventory[3].name,"Biscuits");
	inventory[3].lowPrice = 7;
	inventory[3].midPrice = 10;
	inventory[3].highPrice = 20;
	inventory[3].stock = 0;
	inventory[3].biasFlags = 0x0;
	// Exotic Cheese
	strcpy(inventory[4].name,"Exotic Cheese Chunk");
	inventory[4].lowPrice = 12;
	inventory[4].midPrice = 16;
	inventory[4].highPrice = 24;
	inventory[4].stock = 0;
	inventory[4].biasFlags = 0x0;
	// Chicken
	strcpy(inventory[5].name,"Chicken");
	inventory[5].lowPrice = 15;
	inventory[5].midPrice = 20;
	inventory[5].highPrice = 25;
	inventory[5].stock = 0;
	inventory[5].biasFlags = 0x0;
	// Fried Chicken
	strcpy(inventory[6].name,"Fried Chicken");
	inventory[6].lowPrice = 17;
	inventory[6].midPrice = 22;
	inventory[6].highPrice = 27;
	inventory[6].stock = 0;
	inventory[6].biasFlags = 0x0;
	// Chicken Sandwich
	strcpy(inventory[7].name,"Chicken Sandwich");
	inventory[7].lowPrice = 7;
	inventory[7].midPrice = 10;
	inventory[7].highPrice = 20;
	inventory[7].stock = 0;
	inventory[7].biasFlags = 0x0;
	// Sweet Cornbread
	strcpy(inventory[8].name,"Sweet Cornbread");
	inventory[8].lowPrice = 15;
	inventory[8].midPrice = 18;
	inventory[8].highPrice = 22;
	inventory[8].stock = 0;
	inventory[8].biasFlags = 0x0;
	// Doughnut
	strcpy(inventory[9].name,"Doughnut");
	inventory[9].lowPrice = 1;
	inventory[9].midPrice = 2;
	inventory[9].highPrice = 4;
	inventory[9].stock = 0;
	inventory[9].biasFlags = 0x0;
	// Dumpling
	strcpy(inventory[10].name,"Dumplings (dough)");
	inventory[10].lowPrice = 3;
	inventory[10].midPrice = 4;
	inventory[10].highPrice = 5;
	inventory[10].stock = 0;
	inventory[10].biasFlags = 0x0;
	// Cheese Dumplings
	strcpy(inventory[11].name,"Cheese Dumplings");
	inventory[11].lowPrice = 12;
	inventory[11].midPrice = 15;
	inventory[11].highPrice = 18;
	inventory[11].stock = 0;
	inventory[11].biasFlags = 0x0;
	// Potatoe Dumplings
	strcpy(inventory[12].name,"Potatoe Dumplings");
	inventory[12].lowPrice = 2;
	inventory[12].midPrice = 3;
	inventory[12].highPrice = 4;
	inventory[12].stock = 0;
	inventory[12].biasFlags = 0x0;
	// Meat Dumplings
	strcpy(inventory[13].name,"Meat Dumplings");
	inventory[13].lowPrice = 12;
	inventory[13].midPrice = 15;
	inventory[13].highPrice = 18;
	inventory[13].stock = 0;
	inventory[13].biasFlags = 0x0;
	// Vegetable Dumplings
	strcpy(inventory[14].name,"Vegetable Dumplings");
	inventory[14].lowPrice = 7;
	inventory[14].midPrice = 10;
	inventory[14].highPrice = 12;
	inventory[14].stock = 0;
	inventory[14].biasFlags = 0x0;
	// Eggs
	strcpy(inventory[15].name,"Eggs");
	inventory[15].lowPrice = 1;
	inventory[15].midPrice = 1;
	inventory[15].highPrice = 2;
	inventory[15].stock = 0;
	inventory[15].biasFlags = 0x0;
	// Fried Fish
	strcpy(inventory[16].name,"Fried Fish");
	inventory[16].lowPrice = 24;
	inventory[16].midPrice = 100;
	inventory[16].highPrice = 200;
	inventory[16].stock = 0;
	inventory[16].biasFlags = 0x0;
	// Fish Sandwich
	strcpy(inventory[17].name,"Fish Sandwich");
	inventory[17].lowPrice = 12;
	inventory[17].midPrice = 50;
	inventory[17].highPrice = 75;
	inventory[17].stock = 0;
	inventory[17].biasFlags = 0x0;
	// Fried Cheese
	strcpy(inventory[18].name,"Fried Cheese");
	inventory[18].lowPrice = 5;
	inventory[18].midPrice = 7;
	inventory[18].highPrice = 10;
	inventory[18].stock = 0;
	inventory[18].biasFlags = 0x0;
	// Fried Onion
	strcpy(inventory[19].name,"Fried Onion");
	inventory[19].lowPrice = 1;
	inventory[19].midPrice = 1;
	inventory[19].highPrice = 2;
	inventory[19].stock = 0;
	inventory[19].biasFlags = 0x0;
	// Brown Gravy
	strcpy(inventory[20].name,"Brown Gravy");
	inventory[20].lowPrice = 1;
	inventory[20].midPrice = 2;
	inventory[20].highPrice = 3;
	inventory[20].stock = 0;
	inventory[20].biasFlags = 0x0;
	// White Gravy
	strcpy(inventory[21].name,"White Gravy");
	inventory[21].lowPrice = 2;
	inventory[21].midPrice = 4;
	inventory[21].highPrice = 6;
	inventory[21].stock = 0;
	inventory[21].biasFlags = 0x0;
	// Hushpuppy
	strcpy(inventory[22].name,"Hushpuppy");
	inventory[22].lowPrice = 4;
	inventory[22].midPrice = 6;
	inventory[22].highPrice = 10;
	inventory[22].stock = 0;
	inventory[22].biasFlags = 0x0;
	// Kringle
	strcpy(inventory[23].name,"Kringle");
	inventory[23].lowPrice = 17;
	inventory[23].midPrice = 20;
	inventory[23].highPrice = 25;
	inventory[23].stock = 0;
	inventory[23].biasFlags = 0x0;
	// Leg of Mutton
	strcpy(inventory[24].name,"Leg of Mutton");
	inventory[24].lowPrice = 15;
	inventory[24].midPrice = 20;
	inventory[24].highPrice = 25;
	inventory[24].stock = 0;
	inventory[24].biasFlags = 0x0;
	// Pancakes
	strcpy(inventory[25].name,"Pancakes");
	inventory[25].lowPrice = 4;
	inventory[25].midPrice = 6;
	inventory[25].highPrice = 8;
	inventory[25].stock = 0;
	inventory[25].biasFlags = 0x0;
	// Apple Pie
	strcpy(inventory[26].name,"Apple Pie");
	inventory[26].lowPrice = 10;
	inventory[26].midPrice = 12;
	inventory[26].highPrice = 15;
	inventory[26].stock = 0;
	inventory[26].biasFlags = 0x0;
	// Berry Pie
	strcpy(inventory[27].name,"Berry Pie");
	inventory[27].lowPrice = 26;
	inventory[27].midPrice = 28;
	inventory[27].highPrice = 35;
	inventory[27].stock = 0;
	inventory[27].biasFlags = 0x0;
	// Nut Pie
	strcpy(inventory[28].name,"Nut Pie");
	inventory[28].lowPrice = 12;
	inventory[28].midPrice = 15;
	inventory[28].highPrice = 18;
	inventory[28].stock = 0;
	inventory[28].biasFlags = 0x0;
	// Shepherds Pie
	strcpy(inventory[29].name,"Shepherd's Pie");
	inventory[29].lowPrice = 25;
	inventory[29].midPrice = 28;
	inventory[29].highPrice = 32;
	inventory[29].stock = 0;
	inventory[29].biasFlags = 0x0;
	// Fried Pork
	strcpy(inventory[30].name,"Fried Pork");
	inventory[30].lowPrice = 14;
	inventory[30].midPrice = 18;
	inventory[30].highPrice = 24;
	inventory[30].stock = 0;
	inventory[30].biasFlags = 0x0;
	// Pork Sandwich
	strcpy(inventory[31].name,"Pork Sandwich");
	inventory[31].lowPrice = 12;
	inventory[31].midPrice = 16;
	inventory[31].highPrice = 22;
	inventory[31].stock = 0;
	inventory[31].biasFlags = 0x0;
	// Porkchop
	strcpy(inventory[32].name,"Porkchop");
	inventory[32].lowPrice = 30;
	inventory[32].midPrice = 40;
	inventory[32].highPrice = 50;
	inventory[32].stock = 0;
	inventory[32].biasFlags = 0x0;
	// Baked Potatoe
	strcpy(inventory[33].name,"Baked Potatoe");
	inventory[33].lowPrice = 1;
	inventory[33].midPrice = 1;
	inventory[33].highPrice = 2;
	inventory[33].stock = 0;
	inventory[33].biasFlags = 0x0;
	// Fried Potatoe
	strcpy(inventory[34].name,"Fried Potatoe");
	inventory[34].lowPrice = 1;
	inventory[34].midPrice = 2;
	inventory[34].highPrice = 4;
	inventory[34].stock = 0;
	inventory[34].biasFlags = 0x0;
	// Sauerkraut
	strcpy(inventory[35].name,"Sauerkraut");
	inventory[35].lowPrice = 1;
	inventory[35].midPrice = 2;
	inventory[35].highPrice = 4;
	inventory[35].stock = 0;
	inventory[35].biasFlags = 0x0;
	// Bratwurst
	strcpy(inventory[36].name,"Bratwurst");
	inventory[36].lowPrice = 16;
	inventory[36].midPrice = 18;
	inventory[36].highPrice = 20;
	inventory[36].stock = 0;
	inventory[36].biasFlags = 0x0;
	// Chorizo
	strcpy(inventory[37].name,"Chorizo");
	inventory[37].lowPrice = 20;
	inventory[37].midPrice = 22;
	inventory[37].highPrice = 26;
	inventory[37].stock = 0;
	inventory[37].biasFlags = 0x0;
	// Indeterminate Sausage
	strcpy(inventory[38].name,"Indeterminate Sausage");
	inventory[38].lowPrice = 6;
	inventory[38].midPrice = 8;
	inventory[38].highPrice = 10;
	inventory[38].stock = 0;
	inventory[38].biasFlags = 0x0;
	// Italian Sausage
	strcpy(inventory[39].name,"Italian Sausage");
	inventory[39].lowPrice = 20;
	inventory[39].midPrice = 22;
	inventory[39].highPrice = 26;
	inventory[39].stock = 0;
	inventory[39].biasFlags = 0x0;
	// Polish Sausage
	strcpy(inventory[40].name,"Polish Sausage");
	inventory[40].lowPrice = 18;
	inventory[40].midPrice = 20;
	inventory[40].highPrice = 24;
	inventory[40].stock = 0;
	inventory[40].biasFlags = 0x0;
	// Spiced Nuts
	strcpy(inventory[41].name,"Spiced Nuts");
	inventory[41].lowPrice = 4;
	inventory[41].midPrice = 6;
	inventory[41].highPrice = 10;
	inventory[41].stock = 0;
	inventory[41].biasFlags = 0x0;
	// Steak
	strcpy(inventory[42].name,"Steak");
	inventory[42].lowPrice = 40;
	inventory[42].midPrice = 60;
	inventory[42].highPrice = 80;
	inventory[42].stock = 0;
	inventory[42].biasFlags = 0x0;
	// Fried Steak
	strcpy(inventory[43].name,"Fried Steak");
	inventory[43].lowPrice = 30;
	inventory[43].midPrice = 50;
	inventory[43].highPrice = 70;
	inventory[43].stock = 0;
	inventory[43].biasFlags = 0x0;
	// Boiled Vegetables
	strcpy(inventory[44].name,"Boiled Vegetables");
	inventory[44].lowPrice = 1;
	inventory[44].midPrice = 2;
	inventory[44].highPrice = 3;
	inventory[44].stock = 0;
	inventory[44].biasFlags = 0x0;
	
	
	
	uint8_t numDrinks = 21;
	// Drinks Section Name
	strcpy(inventory[45].name,"DRINKS");
	inventory[45].lowPrice = 0;
	inventory[45].midPrice = 0;
	inventory[45].highPrice = 0;
	inventory[45].stock = 0;
	inventory[45].biasFlags = 0x0;
	// Coffee
	strcpy(inventory[46].name,"Coffee");
	inventory[46].lowPrice = 1;
	inventory[46].midPrice = 1;
	inventory[46].highPrice = 2;
	inventory[46].stock = 0;
	inventory[46].biasFlags = 0x0;
	// Grog
	strcpy(inventory[47].name,"Grog");
	inventory[47].lowPrice = 2;
	inventory[47].midPrice = 3;
	inventory[47].highPrice = 5;
	inventory[47].stock = 0;
	inventory[47].biasFlags = 0x0;
	// Martini
	strcpy(inventory[48].name,"Martini");
	inventory[48].lowPrice = 20;
	inventory[48].midPrice = 25;
	inventory[48].highPrice = 30;
	inventory[48].stock = 0;
	inventory[48].biasFlags = 0x0;
	// Manhattan
	strcpy(inventory[49].name,"Manhattan");
	inventory[49].lowPrice = 20;
	inventory[49].midPrice = 30;
	inventory[49].highPrice = 50;
	inventory[49].stock = 0;
	inventory[49].biasFlags = 0x0;
	// Mulled Wine
	strcpy(inventory[50].name,"Mulled Wine");
	inventory[50].lowPrice = 32;
	inventory[50].midPrice = 37;
	inventory[50].highPrice = 42;
	inventory[50].stock = 0;
	inventory[50].biasFlags = 0x0;
	// Old Fashion Weird
	strcpy(inventory[51].name,"Old Fashioned, Simple");
	inventory[51].lowPrice = 20;
	inventory[51].midPrice = 30;
	inventory[51].highPrice = 50;
	inventory[51].stock = 0;
	inventory[51].biasFlags = 0x0;
	// Old Fasion Wisconsin
	strcpy(inventory[52].name,"Old Fashioned, Traditional");
	inventory[52].lowPrice = 30;
	inventory[52].midPrice = 50;
	inventory[52].highPrice = 70;
	inventory[52].stock = 0;
	inventory[52].biasFlags = 0x0;
	// Tea
	strcpy(inventory[53].name,"Tea");
	inventory[53].lowPrice = 1;
	inventory[53].midPrice = 2;
	inventory[53].highPrice = 3;
	inventory[53].stock = 0;
	inventory[53].biasFlags = 0x0;
	// Sweat Tea
	strcpy(inventory[54].name,"Sweet Tea");
	inventory[54].lowPrice = 2;
	inventory[54].midPrice = 3;
	inventory[54].highPrice = 5;
	inventory[54].stock = 0;
	inventory[54].biasFlags = 0x0;
	// Ale
	strcpy(inventory[55].name,"Ale");
	inventory[55].lowPrice = 7;
	inventory[55].midPrice = 10;
	inventory[55].highPrice = 20;
	inventory[55].stock = 0;
	inventory[55].biasFlags = 0x0;
	// Beer
	strcpy(inventory[56].name,"Beer");
	inventory[56].lowPrice = 7;
	inventory[56].midPrice = 10;
	inventory[56].highPrice = 20;
	inventory[56].stock = 0;
	inventory[56].biasFlags = 0x0;
	// Common Brandy
	strcpy(inventory[57].name,"Common Brandy");
	inventory[57].lowPrice = 20;
	inventory[57].midPrice = 30;
	inventory[57].highPrice = 50;
	inventory[57].stock = 0;
	inventory[57].biasFlags = 0x0;
	// Good Brandy
	strcpy(inventory[58].name,"Good Brandy");
	inventory[58].lowPrice = 100;
	inventory[58].midPrice = 150;
	inventory[58].highPrice = 300;
	inventory[58].stock = 0;
	inventory[58].biasFlags = 0x0;
	// Fine Brandy
	strcpy(inventory[59].name,"Fine Brandy");
	inventory[59].lowPrice = 1000;
	inventory[59].midPrice = 1500;
	inventory[59].highPrice = 3000;
	inventory[59].stock = 0;
	inventory[59].biasFlags = 0x0;
	// Mead
	strcpy(inventory[60].name,"Mead");
	inventory[60].lowPrice = 30;
	inventory[60].midPrice = 50;
	inventory[60].highPrice = 80;
	inventory[60].stock = 0;
	inventory[60].biasFlags = 0x0;
	// Milk
	strcpy(inventory[61].name,"Milk");
	inventory[61].lowPrice = 1;
	inventory[61].midPrice = 1;
	inventory[61].highPrice = 2;
	inventory[61].stock = 0;
	inventory[61].biasFlags = 0x0;
	// Common Spirit
	strcpy(inventory[62].name,"Common Spirit");
	inventory[62].lowPrice = 20;
	inventory[62].midPrice = 30;
	inventory[62].highPrice = 50;
	inventory[62].stock = 0;
	inventory[62].biasFlags = 0x0;
	// Good Spirit
	strcpy(inventory[63].name,"Good Spirit");
	inventory[63].lowPrice = 50;
	inventory[63].midPrice = 70;
	inventory[63].highPrice = 100;
	inventory[63].stock = 0;
	inventory[63].biasFlags = 0x0;
	// Fine Spirit
	strcpy(inventory[64].name,"Fine Spirit");
	inventory[64].lowPrice = 100;
	inventory[64].midPrice = 150;
	inventory[64].highPrice = 300;
	inventory[64].stock = 0;
	inventory[64].biasFlags = 0x0;
	// Common Wine
	strcpy(inventory[65].name,"Common Wine");
	inventory[65].lowPrice = 10;
	inventory[65].midPrice = 20;
	inventory[65].highPrice = 30;
	inventory[65].stock = 0;
	inventory[65].biasFlags = 0x0;
	// Good Wine
	strcpy(inventory[66].name,"Good Wine");
	inventory[66].lowPrice = 70;
	inventory[66].midPrice = 100;
	inventory[66].highPrice = 150;
	inventory[66].stock = 0;
	inventory[66].biasFlags = 0x0;
	// Fine Wine
	strcpy(inventory[67].name,"Fine Wine");
	inventory[67].lowPrice = 700;
	inventory[67].midPrice = 1000;
	inventory[67].highPrice = 1500;
	inventory[67].stock = 0;
	inventory[67].biasFlags = 0x0;
	
	char dividerChar = ' ';
	//12 for each colum with 1 in between
	fprintf(storeHere,"\n");
	fprintf(storeHere,"%-12s: %s\n", "Squalid", "Sleep in stable, Bowl of questionable stew, roll a 1d6, on 1 get food posioning.");
	fprintf(storeHere,"%-12s: %s\n", "Poor", "Sleep in storeroom or loft, Unlimited bowls of stew or cheap food.");
	fprintf(storeHere,"%-12s: %s\n", "Modest", "Bed with blankets and a rough pillow, may have to share, Round meal, little meat, some vegetables, non water drink.");
	fprintf(storeHere,"%-12s: %s\n", "Comfortable", "Your own room with your own comfy bed, A dish, some sides, and a small desert. Not particularly fancy.");
	fprintf(storeHere,"%-12s: %s\n", "Wealthy", "Silk blanket, feather pillow, room service, Any dish on the menu, some sides, a good drink, and desert. Staff jumps to fufill your needs.");
	fprintf(storeHere,"%-12s: %s\n", "Aristocratic", "You have an attached room for a few servents, everything is fine, Your meal is served in courses, appetizers, main course, deserts and the like with enough for guests. You have a personal staff member assigned to keeping you happy.");
	fprintf(storeHere,"\n");
	fprintf(storeHere,"        Per Night                  Per Meal       \n");
	fprintf(storeHere,"%-12s %-12s", "Squalid", "7 cp");
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere,"%-12s %-12s", "Squalid", "3 cp");
	fprintf(storeHere,"\n");
	fprintf(storeHere,"%-12s %-12s", "Poor", "1 sp");
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere,"%-12s %-12s", "Poor", "6 cp");
	fprintf(storeHere,"\n");
	fprintf(storeHere,"%-12s %-12s", "Modest", "5 sp");
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere,"%-12s %-12s", "Modest", "3 sp");
	fprintf(storeHere,"\n");
	fprintf(storeHere,"%-12s %-12s", "Comfertable", "8 sp");
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere,"%-12s %-12s", "Comfertable", "5 sp");
	fprintf(storeHere,"\n");
	fprintf(storeHere,"%-12s %-12s", "Wealthy", "2 gp");
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere,"%-12s %-12s", "Wealthy", "8 sp");
	fprintf(storeHere,"\n");
	fprintf(storeHere,"%-12s %-12s", "Aristocratic", "4 gp");
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere,"%-12s %-12s", "Aristocratic", "2 gp");
	fprintf(storeHere,"\n");
	fprintf(storeHere,"\n");
	fprintf(storeHere,"                                 MENU\n");
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	//int8_t shopStock = ((rand())%20)+1; //FIXME Something Special for Taverns
	//printf("Shop stock num %u", shopStock);
	
	
	fprintf(storeHere, "%-32s\n", inventory[0].name);
	fprintf(storeHere, "%32s", "Pottage");
	fprintf(storeHere, "%c", dividerChar);
	convertFromCPandStore(0, storeHere, 0);
	fprintf(storeHere, "%c", dividerChar);
	convertFromCPandStore(1, storeHere, 0);
	fprintf(storeHere, "%c", dividerChar);
	convertFromCPandStore(1, storeHere, 0);
	fprintf(storeHere, "\n");
	int8_t numDishesServed = 8 + (rand()%5)-3;
	uint8_t chosenDishes[numDishesServed];
	for (int i = 0; i <numDishesServed; ++i){
		chosenDishes[i] = 0;
	}
	for(int i = 0; i < numDishesServed; ++i){// DISHES
		uint8_t redo=1;
		uint8_t chooseMe;
		while(redo){
			chooseMe = (rand()%numDishes)+1; //FIXME
			redo = 0;
			for (int j = 0; j <numDishesServed; ++j){
				if(chosenDishes[j] == chooseMe){
					redo = 1;
				}
			}
		}
		chosenDishes[i] = chooseMe;
		if (inventory[chooseMe].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			fprintf(storeHere, "%32s", inventory[chooseMe].name);
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(inventory[chooseMe].lowPrice, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(inventory[chooseMe].midPrice, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(inventory[chooseMe].highPrice, storeHere, 0);
			fprintf(storeHere, "\n");
		}
	}
	fprintf(storeHere, "%-32s\n", inventory[45].name);
	fprintf(storeHere, "%32s", "Water");
	fprintf(storeHere, "%c", dividerChar);
	convertFromCPandStore(0, storeHere, 0);
	fprintf(storeHere, "%c", dividerChar);
	convertFromCPandStore(0, storeHere, 0);
	fprintf(storeHere, "%c", dividerChar);
	convertFromCPandStore(1, storeHere, 0);
	fprintf(storeHere, "\n");
	int8_t numDrinksServed = 4+(rand()%3)-1;
	uint8_t chosenDrinks[numDrinksServed];
	for (int i = 0; i <numDrinksServed; ++i){
		chosenDrinks[i] = 0;
	}
	for(int i = 0; i < numDrinksServed; ++i){// Drinks
		uint8_t redo=1;
		uint8_t chooseMe;
		while(redo){
			chooseMe = (rand()%numDrinks)+46; //FIXME
			redo = 0;
			for (int j = 0; j <numDrinksServed; ++j){
				if(chosenDrinks[j] == chooseMe){
					redo = 1;
				}
			}
		}
		chosenDrinks[i] = chooseMe;
		if (inventory[chooseMe].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			fprintf(storeHere, "%32s", inventory[chooseMe].name);
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(inventory[chooseMe].lowPrice, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(inventory[chooseMe].midPrice, storeHere, 0);
			fprintf(storeHere, "%c", dividerChar);
			convertFromCPandStore(inventory[chooseMe].highPrice, storeHere, 0);
			fprintf(storeHere, "\n");
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeShrine(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 33;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Gear Section Name
	strcpy(inventory[0].name,"GEAR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Alms Box
	strcpy(inventory[1].name,"Alms Box");
	inventory[1].lowPrice = 300;
	inventory[1].midPrice = 500;
	inventory[1].highPrice = 800;
	inventory[1].stock = 8;
	inventory[1].biasFlags = 0x104;
	// Bell
	strcpy(inventory[2].name,"Bell");
	inventory[2].lowPrice = 70;
	inventory[2].midPrice = 100;
	inventory[2].highPrice = 200;
	inventory[2].stock = 5;
	inventory[2].biasFlags = 0x100;
	// Blanket
	strcpy(inventory[3].name,"Blanket");
	inventory[3].lowPrice = 30;
	inventory[3].midPrice = 50;
	inventory[3].highPrice = 80;
	inventory[3].stock = 3;
	inventory[3].biasFlags = 0x100;
	// Book of Scripture
	strcpy(inventory[4].name,"Book of Scripture");
	inventory[4].lowPrice = 1800;
	inventory[4].midPrice = 2500;
	inventory[4].highPrice = 3800;
	inventory[4].stock = 1;
	inventory[4].biasFlags = 0x100;
	// Scroll Case
	strcpy(inventory[5].name,"Scroll Case");
	inventory[5].lowPrice = 70;
	inventory[5].midPrice = 100;
	inventory[5].highPrice = 200;
	inventory[5].stock = 5;
	inventory[5].biasFlags = 0x100;
	// Censer
	strcpy(inventory[6].name,"Censer");
	inventory[6].lowPrice = 30;
	inventory[6].midPrice = 50;
	inventory[6].highPrice = 200;
	inventory[6].stock = 3;
	inventory[6].biasFlags = 0x100;
	// Chalk
	strcpy(inventory[7].name,"Chalk (1)");
	inventory[7].lowPrice = 1;
	inventory[7].midPrice = 1;
	inventory[7].highPrice = 2;
	inventory[7].stock = 5;
	inventory[7].biasFlags = 0x100;
	// Flask
	strcpy(inventory[8].name,"Flask");
	inventory[8].lowPrice = 1;
	inventory[8].midPrice = 2;
	inventory[8].highPrice = 2;
	inventory[8].stock = 2;
	inventory[8].biasFlags = 0x100;
	// Healer's Kit
	strcpy(inventory[9].name,"Healer's Kit");
	inventory[9].lowPrice = 30;
	inventory[9].midPrice = 50;
	inventory[9].highPrice = 80;
	inventory[9].stock = 3;
	inventory[9].biasFlags = 0x140;
	// Holy Symbol
	strcpy(inventory[10].name,"Holy Symbol");
	inventory[10].lowPrice = 300;
	inventory[10].midPrice = 500;
	inventory[10].highPrice = 800;
	inventory[10].stock = 1;
	inventory[10].biasFlags = 0x100;
	// Holy Water
	strcpy(inventory[11].name,"Holy Water (flask)");
	inventory[11].lowPrice = 1800;
	inventory[11].midPrice = 2500;
	inventory[11].highPrice = 3800;
	inventory[11].stock = 1;
	inventory[11].biasFlags = 0x100;
	// Incense
	strcpy(inventory[12].name,"Incense (block)");
	inventory[12].lowPrice = 1;
	inventory[12].midPrice = 1;
	inventory[12].highPrice = 2;
	inventory[12].stock = 8;
	inventory[12].biasFlags = 0x101;
	// Ink
	strcpy(inventory[13].name,"Ink (1 fl. oz.)");
	inventory[13].lowPrice = 700;
	inventory[13].midPrice = 1000;
	inventory[13].highPrice = 1500;
	inventory[13].stock = 5;
	inventory[13].biasFlags = 0x141;
	// Ink Pen
	strcpy(inventory[14].name,"Ink Pen");
	inventory[14].lowPrice = 1;
	inventory[14].midPrice = 2;
	inventory[14].highPrice = 3;
	inventory[14].stock = 5;
	inventory[14].biasFlags = 0x141;
	// Hooded Lantern
	strcpy(inventory[15].name,"Lantern (hooded)");
	inventory[15].lowPrice = 300;
	inventory[15].midPrice = 500;
	inventory[15].highPrice = 800;
	inventory[15].stock = 5;
	inventory[15].biasFlags = 0x185;
	// Oil
	strcpy(inventory[16].name,"Oil (flask)");
	inventory[16].lowPrice = 7;
	inventory[16].midPrice = 10;
	inventory[16].highPrice = 20;
	inventory[16].stock = 2;
	inventory[16].biasFlags = 0x100;
	// Paper
	strcpy(inventory[17].name,"Paper (1)");
	inventory[17].lowPrice = 10;
	inventory[17].midPrice = 20;
	inventory[17].highPrice = 30;
	inventory[17].stock = 15;
	inventory[17].biasFlags = 0x141;
	// Parchment
	strcpy(inventory[18].name,"Parchment (1)");
	inventory[18].lowPrice = 7;
	inventory[18].midPrice = 10;
	inventory[18].highPrice = 20;
	inventory[18].stock = 5;
	inventory[18].biasFlags = 0x141;
	// Perfume
	strcpy(inventory[19].name,"Perfume (vial)");
	inventory[19].lowPrice = 300;
	inventory[19].midPrice = 500;
	inventory[19].highPrice = 800;
	inventory[19].stock = 18;
	inventory[19].biasFlags = 0x945;
	// Potion of Healing
	strcpy(inventory[20].name,"Potion of Healing");
	inventory[20].lowPrice = 3800;
	inventory[20].midPrice = 5000;
	inventory[20].highPrice = 7500;
	inventory[20].stock = 15;
	inventory[20].biasFlags = 0x141;
	// Ration
	strcpy(inventory[21].name,"Ration");
	inventory[21].lowPrice = 30;
	inventory[21].midPrice = 50;
	inventory[21].highPrice = 80;
	inventory[21].stock = 5;
	inventory[21].biasFlags = 0x110;
	// Torch
	strcpy(inventory[22].name,"Torch");
	inventory[22].lowPrice = 1;
	inventory[22].midPrice = 1;
	inventory[22].highPrice = 2;
	inventory[22].stock = 3;
	inventory[22].biasFlags = 0x0;
	// Vial
	strcpy(inventory[23].name,"Vial");
	inventory[23].lowPrice = 70;
	inventory[23].midPrice = 100;
	inventory[23].highPrice = 200;
	inventory[23].stock = 2;
	inventory[23].biasFlags = 0x0;
	// Waterskin
	strcpy(inventory[24].name,"Waterskin");
	inventory[24].lowPrice = 10;
	inventory[24].midPrice = 20;
	inventory[24].highPrice = 30;
	inventory[24].stock = 3;
	inventory[24].biasFlags = 0x10;
	
	// Tools Section Header
	strcpy(inventory[27].name,"TOOLS");
	inventory[27].lowPrice = 0;
	inventory[27].midPrice = 0;
	inventory[27].highPrice = 0;
	inventory[27].stock = 0;
	inventory[27].biasFlags = 0;
	// Calligrapher's Supplies
	strcpy(inventory[28].name,"Calligrapher's Supplies");
	inventory[28].lowPrice = 700;
	inventory[28].midPrice = 1000;
	inventory[28].highPrice = 1500;
	inventory[28].stock = 8;
	inventory[28].biasFlags = 0x100;
	// Flute
	strcpy(inventory[29].name,"Flute");
	inventory[29].lowPrice = 100;
	inventory[29].midPrice = 200;
	inventory[29].highPrice = 300;
	inventory[29].stock = 15;
	inventory[29].biasFlags = 0x0;
	// Herbalism Kit
	strcpy(inventory[30].name,"Herbalism Kit");
	inventory[30].lowPrice = 300;
	inventory[30].midPrice = 500;
	inventory[30].highPrice = 800;
	inventory[30].stock = 5;
	inventory[30].biasFlags = 0x10;
	// Horn
	strcpy(inventory[31].name,"Horn");
	inventory[31].lowPrice = 200;
	inventory[31].midPrice = 300;
	inventory[31].highPrice = 500;
	inventory[31].stock = 15;
	inventory[31].biasFlags = 0x0;
	// Lyre
	strcpy(inventory[32].name,"Lyre");
	inventory[32].lowPrice = 2200;
	inventory[32].midPrice = 3000;
	inventory[32].highPrice = 4500;
	inventory[32].stock = 18;
	inventory[32].biasFlags = 0x0;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n");
}

void makeJeweler(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 128;
	struct shopItem inventory[inventorySize];
	// Father forgive me for i have sinned
	for(int i = 0; i < inventorySize; ++i){
		memset(inventory[i].name, '\0', NAME_LENGTH);
		inventory[i].lowPrice = 0;
		inventory[i].midPrice = 0;
		inventory[i].highPrice = 0;
		inventory[i].stock = 0;
		inventory[i].biasFlags = 0x8000;
	}
	// Gear Section Name
	strcpy(inventory[0].name,"GEAR");
	inventory[0].lowPrice = 0;
	inventory[0].midPrice = 0;
	inventory[0].highPrice = 0;
	inventory[0].stock = 0;
	inventory[0].biasFlags = 0;
	// Arcane Crystal
	strcpy(inventory[1].name,"Crystal (arcane)");
	inventory[1].lowPrice = 800;
	inventory[1].midPrice = 1000;
	inventory[1].highPrice = 1500;
	inventory[1].stock = 5;
	inventory[1].biasFlags = 0x21;
	// Gold Earrings
	strcpy(inventory[2].name,"Gold Earings");
	inventory[2].lowPrice = 300;
	inventory[2].midPrice = 400;
	inventory[2].highPrice = 600;
	inventory[2].stock = 5;
	inventory[2].biasFlags = 0xC0;
	// Gold Necklace
	strcpy(inventory[3].name,"Gold Necklace");
	inventory[3].lowPrice = 300;
	inventory[3].midPrice = 500;
	inventory[3].highPrice = 800;
	inventory[3].stock = 5;
	inventory[3].biasFlags = 0xC0;
	// Gold Ring
	strcpy(inventory[4].name,"Gold Ring");
	inventory[4].lowPrice = 200;
	inventory[4].midPrice = 300;
	inventory[4].highPrice = 400;
	inventory[4].stock = 5;
	inventory[4].biasFlags = 0xC1;
	// Arcane Orb
	strcpy(inventory[5].name,"Orb (arcane)");
	inventory[5].lowPrice = 1500;
	inventory[5].midPrice = 2000;
	inventory[5].highPrice = 3000;
	inventory[5].stock = 15;
	inventory[5].biasFlags = 0x21;
	// Platinum Earrings
	strcpy(inventory[6].name,"Platinum Earings");
	inventory[6].lowPrice = 3000;
	inventory[6].midPrice = 4000;
	inventory[6].highPrice = 6000;
	inventory[6].stock = 15;
	inventory[6].biasFlags = 0xC0;
	// Platinum Necklace
	strcpy(inventory[7].name,"Platinum Necklace");
	inventory[7].lowPrice = 3000;
	inventory[7].midPrice = 5000;
	inventory[7].highPrice = 8000;
	inventory[7].stock = 15;
	inventory[7].biasFlags = 0xC0;
	// Platinum Ring
	strcpy(inventory[8].name,"Platinum Ring");
	inventory[8].lowPrice = 2000;
	inventory[8].midPrice = 3000;
	inventory[8].highPrice = 4000;
	inventory[8].stock = 15;
	inventory[8].biasFlags = 0xC1;
	// Signet Ring
	strcpy(inventory[9].name,"Signet Ring");
	inventory[9].lowPrice = 300;
	inventory[9].midPrice = 500;
	inventory[9].highPrice = 800;
	inventory[9].stock = 5;
	inventory[9].biasFlags = 0x145;
	// Silver Earrings
	strcpy(inventory[10].name,"Silver Earings");
	inventory[10].lowPrice = 30;
	inventory[10].midPrice = 40;
	inventory[10].highPrice = 60;
	inventory[10].stock = 2;
	inventory[10].biasFlags = 0xC0;
	// Silver Necklace
	strcpy(inventory[11].name,"Silver Necklace");
	inventory[11].lowPrice = 30;
	inventory[11].midPrice = 50;
	inventory[11].highPrice = 80;
	inventory[11].stock = 2;
	inventory[11].biasFlags = 0xC0;
	// Silver Ring
	strcpy(inventory[12].name,"Silver Ring");
	inventory[12].lowPrice = 20;
	inventory[12].midPrice = 30;
	inventory[12].highPrice = 40;
	inventory[12].stock = 2;
	inventory[12].biasFlags = 0xC1;
	
	// Tools Section Header
	strcpy(inventory[15].name,"TOOLS");
	inventory[15].lowPrice = 0;
	inventory[15].midPrice = 0;
	inventory[15].highPrice = 0;
	inventory[15].stock = 0;
	inventory[15].biasFlags = 0;
	// Jeweler's Tools
	strcpy(inventory[16].name,"Jeweler's Tools");
	inventory[16].lowPrice = 1800;
	inventory[16].midPrice = 2500;
	inventory[16].highPrice = 3800;
	inventory[16].stock = 3;
	inventory[16].biasFlags = 0xC0;
	
	// Services Section Header
	strcpy(inventory[19].name,"SERVICES");
	inventory[19].lowPrice = 0;
	inventory[19].midPrice = 0;
	inventory[19].highPrice = 0;
	inventory[19].stock = 0;
	inventory[19].biasFlags = 0;
	// Gemstone Appraisal
	strcpy(inventory[19].name,"Gemstone Appraisal");
	inventory[19].lowPrice = 30;
	inventory[19].midPrice = 50;
	inventory[19].highPrice = 80;
	inventory[19].stock = 1;
	inventory[19].biasFlags = 0x0;
	// Resizing Jewelry
	strcpy(inventory[19].name,"Resizing Jewelry");
	inventory[19].lowPrice = 800;
	inventory[19].midPrice = 1000;
	inventory[19].highPrice = 1500;
	inventory[19].stock = 2;
	inventory[19].biasFlags = 0x20;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	
	int8_t shopStock = ((rand())%20)+1;
	//printf("Shop stock num %u", shopStock);
	
	for(int i = 0; i < inventorySize; ++i){
		if (inventory[i].biasFlags == 0x8000){ // There is no name, empty entry
			continue;
		}
		else{
			if(inventory[i].stock == 0){ // Section Title
				fprintf(storeHere, "%-32s\n", inventory[i].name);
			}
			else if (inventory[i].stock + ((rand()%3)-1) - onesCount(flags & inventory[i].biasFlags) <= shopStock){ // Item is in stock
				fprintf(storeHere, "%32s", inventory[i].name);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].lowPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].midPrice, storeHere, 0);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCPandStore(inventory[i].highPrice, storeHere, 0);
				fprintf(storeHere, "\n");
			}
			else { // Item is out of stock or error
				if (inventory[i].stock <= 20){ // Item out of stock
					/*
					fprintf(storeHere, "%32s", inventory[i].name);
					fprintf(storeHere, "%c", dividerChar);
					fprintf(storeHere, "           OUT OF STOCK         \n");
					*/
				}
				else{// ERROR
					continue;
				}
			}
		}
	}
	if (2 + ((rand()%3)-1) - onesCount(flags & 0x85) <= shopStock){
		fprintf(storeHere, "%32s", "Set Gem");
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","23%% gem");//Low Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","23%% gem");//Medium Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","30%% gem");//High Jewelry price
		fprintf(storeHere, "\n");
	}
	if (8 + ((rand()%3)-1) - onesCount(flags & 0x85) <= shopStock){
		fprintf(storeHere, "%32s", "Stonecutting");
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","23%% gem");//Low Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","25%% gem");//Medium Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","30%% gem");//High Jewelry price
		fprintf(storeHere, "\n");
	}
	fprintf(storeHere, "%-32s\n", "JEWELRY");
	if (19 + ((rand()%3)-1) - onesCount(flags & 0x85) <= shopStock){
		fprintf(storeHere, "%32s", "Custom Adamantine Jewelry");
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+70pp");//Low Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+80pp");//Medium Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%10s","Gem+100pp");//High Jewelry price
		fprintf(storeHere, "\n");
	}
	if (5 + ((rand()%3)-1) - onesCount(flags & 0x85) <= shopStock){
		fprintf(storeHere, "%32s", "Custom Gold Jewelry");
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+38gp");//Low Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+50gp");//Medium Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+75gp");//High Jewelry price
		fprintf(storeHere, "\n");
	}
	if (17 + ((rand()%3)-1) - onesCount(flags & 0x85) <= shopStock){
		fprintf(storeHere, "%32s", "Custom Mithril Jewelry");
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+40pp");//Low Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+50pp");//Medium Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+75pp");//High Jewelry price
		fprintf(storeHere, "\n");
	}
	if (15 + ((rand()%3)-1) - onesCount(flags & 0x85) <= shopStock){
		fprintf(storeHere, "%32s", "Custom Platinum Jewelry");
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+38pp");//Low Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+50pp");//Medium Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+75pp");//High Jewelry price
		fprintf(storeHere, "\n");
	}
	if (2 + ((rand()%3)-1) - onesCount(flags & 0x85) <= shopStock){
		fprintf(storeHere, "%32s", "Custom Silver Jewelry");
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+4gp");//Low Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+5gp");//Medium Jewelry Price
		fprintf(storeHere, "%c", dividerChar);
		fprintf(storeHere,"%9s","Gem+8gp");//High Jewelry price
		fprintf(storeHere, "\n");
	}
	//Gemstones
	uint8_t sizeGem10gp = 12;
	struct gemstone gem10gp[sizeGem10gp];
	for (int i = 0; i < sizeGem10gp; ++i){
		gem10gp[i].amount = 0;
	}
	strcpy(gem10gp[0].name,"Azurite");
	strcpy(gem10gp[1].name,"Banded Agate");
	strcpy(gem10gp[2].name,"Blue Quartz");
	strcpy(gem10gp[3].name,"Eye Agate");
	strcpy(gem10gp[4].name,"Hematite");
	strcpy(gem10gp[5].name,"Lapis Lazuli");
	strcpy(gem10gp[6].name,"Malachite");
	strcpy(gem10gp[7].name,"Moss Agate");
	strcpy(gem10gp[8].name,"Obsidian");
	strcpy(gem10gp[9].name,"Rhodochrosite");
	strcpy(gem10gp[10].name,"Tiger Eye");
	strcpy(gem10gp[11].name,"Turquoise");
	
	uint8_t sizeGem50gp = 12;
	struct gemstone gem50gp[sizeGem50gp];
	for (int i = 0; i < sizeGem50gp; ++i){
		gem50gp[i].amount = 0;
	}
	strcpy(gem50gp[0].name,"Bloodstone");
	strcpy(gem50gp[1].name,"Carnelian");
	strcpy(gem50gp[2].name,"Chalcedony");
	strcpy(gem50gp[3].name,"Chrysoprase");
	strcpy(gem50gp[4].name,"Citrine");
	strcpy(gem50gp[5].name,"Jasper");
	strcpy(gem50gp[6].name,"Moonstone");
	strcpy(gem50gp[7].name,"Onyx");
	strcpy(gem50gp[8].name,"Quartz");
	strcpy(gem50gp[9].name,"Sardonyx");
	strcpy(gem50gp[10].name,"Star Rose Quartz");
	strcpy(gem50gp[11].name,"Zircon");
	
	uint8_t sizeGem100gp = 10;
	struct gemstone gem100gp[sizeGem100gp];
	for (int i = 0; i < sizeGem100gp; ++i){
		gem100gp[i].amount = 0;
	}
	strcpy(gem100gp[0].name,"Amber");
	strcpy(gem100gp[1].name,"Amethyst");
	strcpy(gem100gp[2].name,"Chrysoberyl");
	strcpy(gem100gp[3].name,"Coral");
	strcpy(gem100gp[4].name,"Garnet");
	strcpy(gem100gp[5].name,"Jade");
	strcpy(gem100gp[6].name,"Jet");
	strcpy(gem100gp[7].name,"Pearl");
	strcpy(gem100gp[8].name,"Spinel");
	strcpy(gem100gp[9].name,"Tourmaline");
	
	uint8_t sizeGem500gp = 6;
	struct gemstone gem500gp[sizeGem500gp];
	for (int i = 0; i < sizeGem500gp; ++i){
		gem500gp[i].amount = 0;
	}
	strcpy(gem500gp[0].name,"Alexandrite");
	strcpy(gem500gp[1].name,"Aquamarine");
	strcpy(gem500gp[2].name,"Black Pearl");
	strcpy(gem500gp[3].name,"Blue Spinel");
	strcpy(gem500gp[4].name,"Peridot");
	strcpy(gem500gp[5].name,"Topaz");
	
	uint8_t sizeGem1000gp = 8;
	struct gemstone gem1000gp[sizeGem1000gp];
	for (int i = 0; i < sizeGem1000gp; ++i){
		gem1000gp[i].amount = 0;
	}
	strcpy(gem1000gp[0].name,"Black Opal");
	strcpy(gem1000gp[1].name,"Blue Sapphire");
	strcpy(gem1000gp[2].name,"Emerald");
	strcpy(gem1000gp[3].name,"Fire Opal");
	strcpy(gem1000gp[4].name,"Opal");
	strcpy(gem1000gp[5].name,"Star Ruby");
	strcpy(gem1000gp[6].name,"Star Sapphire");
	strcpy(gem1000gp[7].name,"Yellow Sapphire");
	
	uint8_t sizeGem5000gp = 4;
	struct gemstone gem5000gp[sizeGem5000gp];
	for (int i = 0; i < sizeGem5000gp; ++i){
		gem5000gp[i].amount = 0;
	}
	strcpy(gem5000gp[0].name,"Black Sapphire");
	strcpy(gem5000gp[1].name,"Diamond");
	strcpy(gem5000gp[2].name,"Jacinth");
	strcpy(gem5000gp[3].name,"Ruby");
	
	/////
	// Decide amount
	int tempGem;
	if(shopStock <8){
		int temp = (rand()%5)+5;
		for (int i = 0; i < temp; ++i){
			tempGem = rand()%sizeGem10gp;
			gem10gp[tempGem].amount = gem10gp[tempGem].amount + 1;
		}
		tempGem = rand()%sizeGem50gp;
		gem50gp[tempGem].amount+=1;
	}
	else if (shopStock < 16){
		int temp = (rand()%10)+10;
		for (int i = 0; i < temp; ++i){
			gem10gp[rand()%sizeGem10gp].amount+=1;
		}
		temp = (rand()%5)+5;
		for (int i = 0; i < temp; ++i){
			gem50gp[rand()%sizeGem50gp].amount+=1;
		}
		gem100gp[rand()%sizeGem100gp].amount+=1;
		gem100gp[rand()%sizeGem100gp].amount+=1;
	}
	else if (shopStock < 18){
		for (int i = 0; i < sizeGem10gp; ++i){
			gem10gp[i].amount = 6 + rand()%3 - 1;
		}
		int temp = (rand()%10)+10;
		for (int i = 0; i < temp; ++i){
			gem50gp[rand()%sizeGem50gp].amount+=1;
		}
		temp = (rand()%5)+5;
		for (int i = 0; i < temp; ++i){
			gem100gp[rand()%sizeGem100gp].amount+=1;
		}
		gem500gp[rand()%sizeGem500gp].amount+=1;
		gem500gp[rand()%sizeGem500gp].amount+=1;
		gem500gp[rand()%sizeGem500gp].amount+=1;
		
		gem1000gp[rand()%sizeGem1000gp].amount+=1;
	}
	else{
		for (int i = 0; i < sizeGem10gp; ++i){
			gem10gp[i].amount = 12 + rand()%5 - 3;
		}
		for (int i = 0; i < sizeGem50gp; ++i){
			gem50gp[i].amount = 6 + rand()%3 - 1;
		}
		int temp = (rand()%10)+10;
		for (int i = 0; i < temp; ++i){
			gem100gp[rand()%sizeGem100gp].amount+=1;
		}
		temp = (rand()%5)+5;
		for (int i = 0; i < temp; ++i){
			gem500gp[rand()%sizeGem500gp].amount+=1;
		}
		gem1000gp[rand()%sizeGem1000gp].amount+=1;
		gem1000gp[rand()%sizeGem1000gp].amount+=1;
		gem1000gp[rand()%sizeGem1000gp].amount+=1;
		gem1000gp[rand()%sizeGem1000gp].amount+=1;
	}
	fprintf(storeHere,"\n");
	fprintf(storeHere,"    Gem Name         Amount         Low       Mid      High\n" );
	for (int i = 0; i < sizeGem10gp; ++i){
		if(gem10gp[i].amount != 0){
			fprintf(storeHere,"%16s", gem10gp[i].name);
			fprintf(storeHere," %8d      ", gem10gp[i].amount);
			fprintf(storeHere,"%6s gp ","8");
			fprintf(storeHere,"%6s gp ","10");
			fprintf(storeHere,"%6s gp\n","15");
		}
	}
	for (int i = 0; i < sizeGem50gp; ++i){
		if(gem50gp[i].amount != 0){
			fprintf(storeHere,"%16s", gem50gp[i].name);
			fprintf(storeHere," %8d      ", gem50gp[i].amount);
			fprintf(storeHere,"%6s gp %6s gp %6s gp\n","38","50","75");
		}
	}
	for (int i = 0; i < sizeGem100gp; ++i){
		if(gem100gp[i].amount != 0){
			fprintf(storeHere,"%16s", gem100gp[i].name);
			fprintf(storeHere," %8d      ", gem100gp[i].amount);
			fprintf(storeHere,"%6s gp %6s gp %6s gp\n","75","100","150");
		}
	}
	for (int i = 0; i < sizeGem500gp; ++i){
		if(gem500gp[i].amount != 0){
			fprintf(storeHere,"%16s", gem500gp[i].name);
			fprintf(storeHere," %8d      ", gem500gp[i].amount);
			fprintf(storeHere,"%6s gp %6s gp %6s gp\n","375","500","750");
		}
	}
	for (int i = 0; i < sizeGem1000gp; ++i){
		if(gem1000gp[i].amount != 0){
			fprintf(storeHere,"%16s", gem1000gp[i].name);
			fprintf(storeHere," %8d      ", gem1000gp[i].amount);
			fprintf(storeHere,"%6s gp %6s gp %6s gp\n","750","1000","1500");
		}
	}
	for (int i = 0; i < sizeGem5000gp; ++i){
		if(gem5000gp[i].amount != 0){
			fprintf(storeHere,"%16s", gem5000gp[i].name);
			fprintf(storeHere," %8d      ", gem5000gp[i].amount);
			fprintf(storeHere,"%6s gp %6s gp %6s gp\n","3750","5000","7500");
		}
	}
	fprintf(storeHere, "\nQuestions? See the Demagus True Reference PDF\n\n");
}

void shopCommandReminder(){
	printf(".\\programName <storageLoc.txt> <shopType> <flags>\n");
	printf("Supported shopTypes are:\n");
	printf("00 - Adventurer's Emporium\n");
	printf("01 - Alchemist's Shop\n");
	printf("02 - Arcana Shop\n");
	printf("03 - Bakery\n");
	printf("04 - Barber\n");
	printf("05 - Blacksmith\n");
	printf("06 - Bookstore\n");
	printf("07 - Butcher's Shop\n");
	//printf("08 - Cobbler's Shop\n");
	printf("08 - Fletcher\n");
	printf("09 - General Store\n");
	printf("10 - Leatherworker's Shop\n");
	printf("11 - Music Store\n");
	printf("12 - Tailor\n");
	printf("13 - Tavern\n");
	printf("14 - Shrine\n");
	printf("15 - Jeweler\n");
	//printf("16 - Wizard's Tower\n");
	printf("Supported Flags are:\n");
	printf("Bit 00 - Magical\n");
	printf("Bit 01 - Costal\n");
	printf("Bit 02 - Rich\n");
	printf("Bit 03 - Exotic\n");
	printf("Bit 04 - Frontier\n");
	printf("Bit 05 - Forest\n");
	printf("Bit 06 - Industrial\n");
	printf("Bit 07 - Mining\n");
	printf("Bit 08 - Pious\n");
    printf("Bit 09 - Agriculture\n");
	printf("Bit 10 - Rural\n");
	printf("Bit 11 - Urban\n");
}

enum shopType{Adventurer, Alchemist, Arcana, Baker, Barber, Blacksmith, Book, Butcher, Cobbler, Fletcher,
              General, Leather, Music, Tailor, Tavern, Shady, Shrine, Jeweler, Wizard };
			  


int shopGen(char* filename,uint8_t shopNum,uint16_t flags){
	FILE * shopFile = fopen(filename, "a+");
	switch(shopNum){
		case 0:
			fprintf(shopFile, "Adventurer's Emporium\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeAdventurerEmporium(shopFile, flags);
			break;
		case 1:
			fprintf(shopFile, "Alchemist's Shop\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeAlchemist(shopFile, flags);
			break;
		case 2:
			fprintf(shopFile, "Arcana Shop\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeArcana(shopFile, flags);
			break;
		case 3:
			fprintf(shopFile, "Bakery\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeBakery(shopFile, flags);
			break;
		case 4:
			fprintf(shopFile, "Barbershop\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeBarber(shopFile, flags);
			break;
		case 5:
			fprintf(shopFile, "Blacksmith\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeBlacksmith(shopFile, flags);
			break;
		case 6:
			fprintf(shopFile, "Bookstore\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeBookstore(shopFile, flags);
			break;
		case 7:
			fprintf(shopFile, "Butcher Shop\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeButcher(shopFile, flags);
			break;
		case 8:
			fprintf(shopFile, "Fletcher\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeFletcher(shopFile, flags);
			break;
		case 9:
			fprintf(shopFile, "General Store\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeGeneral(shopFile, flags);
			break;
		case 10:
			fprintf(shopFile, "Leatherworker's Shop\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeLeather(shopFile, flags);
			break;
		case 11:
			fprintf(shopFile, "Music Store\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeMusic(shopFile, flags);
			break;
		case 12:
			fprintf(shopFile, "Tailor\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeTailor(shopFile, flags);
			break;
		case 13:
			fprintf(shopFile, "Tavern\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeTavern(shopFile, flags);
			break;
		case 14:
			fprintf(shopFile, "Shrine\n");
			fprintf(shopFile, "Our ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeShrine(shopFile, flags);
			break;
		case 15:
			fprintf(shopFile, "Jeweler\n");
			fprintf(shopFile, "The ");
			shopnameGenAndStore(shopFile);// Store Owners Name
			//nameGen(shopFile, 0xFF);
			makeJeweler(shopFile, flags);
			break;
		default:
			printf("ERROR, INVALID STORE\n");
			shopCommandReminder();
	}
	fclose(shopFile);
	return 0;
}
/*
int main(int argc, char* argv[]){
	uint16_t flags = atoi(argv[3]);
	srand(time(NULL));
	if (argc != 4){
		shopCommandReminder();
		return -1;
	}
	else{
		FILE * shopFile = fopen(argv[1], "w+");
		uint8_t shopNum = atoi(argv[2]);
		switch(shopNum){
			case 0:
				fprintf(shopFile, "Adventurer's Emporium\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeAdventurerEmporium(shopFile, flags);
				break;
			case 1:
				fprintf(shopFile, "Alchemist's Shop\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeAlchemist(shopFile, flags);
				break;
			case 2:
				fprintf(shopFile, "Arcana Shop\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeArcana(shopFile, flags);
				break;
			case 3:
				fprintf(shopFile, "Bakery\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeBakery(shopFile, flags);
				break;
			case 4:
				fprintf(shopFile, "Barbershop\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeBarber(shopFile, flags);
				break;
			case 5:
				fprintf(shopFile, "Blacksmith\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeBlacksmith(shopFile, flags);
				break;
			case 6:
				fprintf(shopFile, "Bookstore\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeBookstore(shopFile, flags);
				break;
			case 7:
				fprintf(shopFile, "Butcher Shop\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeButcher(shopFile, flags);
				break;

			case 8:
				fprintf(shopFile, "Fletcher\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeFletcher(shopFile, flags);
				break;
			case 9:
				fprintf(shopFile, "General Store\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeGeneral(shopFile, flags);
				break;
			case 10:
				fprintf(shopFile, "Leatherworker's Shop\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeLeather(shopFile, flags);
				break;
			case 11:
				fprintf(shopFile, "Music Store\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeMusic(shopFile, flags);
				break;
			case 12:
				fprintf(shopFile, "Tailor\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeTailor(shopFile, flags);
				break;
			case 13:
				fprintf(shopFile, "Tavern\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeTavern(shopFile, flags);
				break;
			case 14:
				fprintf(shopFile, "Shrine\n");
				fprintf(shopFile, "Our ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeShrine(shopFile, flags);
				break;
			case 15:
				fprintf(shopFile, "Jeweler\n");
				fprintf(shopFile, "The ");
				shopnameGenAndStore(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeJeweler(shopFile, flags);
				break;
			default:
				printf("ERROR, INVALID STORE\n");
				shopCommandReminder();
		}
		fclose(shopFile);
	}
	return 0;
}
*/