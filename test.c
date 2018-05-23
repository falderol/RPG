/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Testing things out in here

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define NAME_LENGTH 32

//////////
// Ones count that is used for the flags
// Knew this would come in handy one day
int8_t onesCount(uint16_t countMe){
	countMe -= (countMe >> 1) & 0x5555; //put count of each 2 bits into those 2 bits
    countMe = (countMe & 0x3333) + ((countMe >> 2) & 0x3333); //put count of each 4 bits into those 4 bits 
    countMe = (countMe + (countMe >> 4)) & 0x0F0F; //put count of each 8 bits into those 8 bits 
    countMe += countMe >>  8;  //put count of each 16 bits into their lowest 8 bits
    return countMe & 0x7f;
}

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
	// Bit 02 - Hills
	// Bit 03 - Exotic
	// Bit 04 - Frontier
	// Bit 05 - Forest
	// Bit 06 - Industrial
	// Bit 07 - Mining
	// Bit 08 - Pious
    // Bit 09 - Orchard
	// Bit 10 - Rural
	// Bit 11 - Urban
	// Bit 14 - Firearms TOBE implemented
	// Bit 15 - Invalid
};

void convertFromCp(uint32_t cp, FILE * storeHere){
	if(cp%10 == 0){ // can convert to sp
		if(cp%100 == 0){ // can convert to gp
			if (cp%1000 == 0){// can convert to pp
				fprintf(storeHere,"%6u pp", cp/1000);
			}
			else{// print in gp
				fprintf(storeHere,"%6u gp", cp/100);
			}
		}
		else{ // print in sp
			fprintf(storeHere,"%6u sp", cp/10);
		}
	}
	else{
		fprintf(storeHere,"%6u cp", cp);
	}
}

////////////////////
// Put these into a seperate file
// Also the reason these are formated like this is that i have a function i wrote that turns excel tables into c code
// In other words, father forgive me for i have sinned.

//////////
// NPC Name Generator
// Takes in the location to print the name to
// Also takes in flags for culture,
// TODO
// Define flag cultures 
// Create list of firstnames and lastnames for each culture
// Be able to combine the lists based on what flags are set
// Choose a random firstname and last name
void nameGen(FILE* storeHere, uint16_t flags){
	
}

//////////
// Generate the name of a shop
// Create list of adjectives and nouns.
// Choose a random entry on the list

void shopnameGen(FILE* storeHere){
	int numElements = 143;
	char adjectives[numElements][NAME_LENGTH];
	char nouns[numElements][NAME_LENGTH];
	/////
	// Have a program that formats this, this stuff is pasted in
	strcpy(adjectives[0], "Red");
	strcpy(adjectives[1], "Blue");
	strcpy(adjectives[2], "Green");
	strcpy(adjectives[3], "Yellow");
	strcpy(adjectives[4], "Purple");
	strcpy(adjectives[5], "Orange");
	strcpy(adjectives[6], "Chartreuse");
	strcpy(adjectives[7], "Periwinkle");
	strcpy(adjectives[8], "Brown");
	strcpy(adjectives[9], "Gold");
	strcpy(adjectives[10], "Silver");
	strcpy(adjectives[11], "Bronze");
	strcpy(adjectives[12], "Brave");
	strcpy(adjectives[13], "Calm");
	strcpy(adjectives[14], "Gentle");
	strcpy(adjectives[15], "Happy");
	strcpy(adjectives[16], "Drunk");
	strcpy(adjectives[17], "Eagar");
	strcpy(adjectives[18], "Able");
	strcpy(adjectives[19], "Bad");
	strcpy(adjectives[20], "Best");
	strcpy(adjectives[21], "Black");
	strcpy(adjectives[22], "White");
	strcpy(adjectives[23], "Clear");
	strcpy(adjectives[24], "King's");
	strcpy(adjectives[25], "Queen's");
	strcpy(adjectives[26], "High");
	strcpy(adjectives[27], "Big");
	strcpy(adjectives[28], "Little");
	strcpy(adjectives[29], "Long");
	strcpy(adjectives[30], "Short");
	strcpy(adjectives[31], "Only");
	strcpy(adjectives[32], "Other");
	strcpy(adjectives[33], "Real");
	strcpy(adjectives[34], "Special");
	strcpy(adjectives[35], "Young");
	strcpy(adjectives[36], "Old");
	strcpy(adjectives[37], "Erudite");
	strcpy(adjectives[38], "Euphoric");
	strcpy(adjectives[39], "Exquisite");
	strcpy(adjectives[40], "Adamant");
	strcpy(adjectives[41], "Arcadian");
	strcpy(adjectives[42], "Cerulean");
	strcpy(adjectives[43], "Comely");
	strcpy(adjectives[44], "Brittle");
	strcpy(adjectives[45], "Exotic");
	strcpy(adjectives[46], "Wordly");
	strcpy(adjectives[47], "Naive");
	strcpy(adjectives[48], "Effluent");
	strcpy(adjectives[49], "Shabby");
	strcpy(adjectives[50], "Shinning");
	strcpy(adjectives[51], "Jocular");
	strcpy(adjectives[52], "Luminous");
	strcpy(adjectives[53], "Bubbling");
	strcpy(adjectives[54], "Noxious");
	strcpy(adjectives[55], "Cranky");
	strcpy(adjectives[56], "Wicked");
	strcpy(adjectives[57], "Menacing");
	strcpy(adjectives[58], "Verdant");
	strcpy(adjectives[59], "Zealous");
	strcpy(adjectives[60], "Oily");
	strcpy(adjectives[61], "Slimy");
	strcpy(adjectives[62], "Knight's");
	strcpy(adjectives[63], "Dame's");
	strcpy(adjectives[64], "Lord's");
	strcpy(adjectives[65], "Lady's");
	strcpy(adjectives[66], "Two-Headed");
	strcpy(adjectives[67], "Petrified");
	strcpy(adjectives[68], "Winking");
	strcpy(adjectives[69], "Singing");
	strcpy(adjectives[70], "Thunderous");
	strcpy(adjectives[71], "Resplendant");
	strcpy(adjectives[72], "Gilded");
	strcpy(adjectives[73], "Restless");
	strcpy(adjectives[74], "Good");
	strcpy(adjectives[75], "Cold");
	strcpy(adjectives[76], "Hot");
	strcpy(adjectives[77], "Lukewarm");
	strcpy(adjectives[78], "Freezing");
	strcpy(adjectives[79], "Boiling");
	strcpy(adjectives[80], "Bitter");
	strcpy(adjectives[81], "Sweet");
	strcpy(adjectives[82], "Plane");
	strcpy(adjectives[83], "Midnight");
	strcpy(adjectives[84], "Noon");
	strcpy(adjectives[85], "Mountain");
	strcpy(adjectives[86], "Swamp");
	strcpy(adjectives[87], "Island");
	strcpy(adjectives[88], "Forest");
	strcpy(adjectives[89], "Frontier");
	strcpy(adjectives[90], "Spring");
	strcpy(adjectives[91], "Summer");
	strcpy(adjectives[92], "Fall");
	strcpy(adjectives[93], "Winter");
	strcpy(adjectives[94], "Ideal");
	strcpy(adjectives[95], "Floating");
	strcpy(adjectives[96], "Royal");
	strcpy(adjectives[97], "Last");
	strcpy(adjectives[98], "First");
	strcpy(adjectives[99], "Useless");
	strcpy(adjectives[100], "Tricky");
	strcpy(adjectives[101], "Wispy");
	strcpy(adjectives[102], "Sour");
	strcpy(adjectives[103], "Poor");
	strcpy(adjectives[104], "Metal");
	strcpy(adjectives[105], "Wooden");
	strcpy(adjectives[106], "Magical");
	strcpy(adjectives[107], "Crimson");
	strcpy(adjectives[108], "Loud");
	strcpy(adjectives[109], "Soft");
	strcpy(adjectives[110], "Boisterous");
	strcpy(adjectives[111], "Laughing");
	strcpy(adjectives[112], "Drinking");
	strcpy(adjectives[113], "Swimming");
	strcpy(adjectives[114], "Running");
	strcpy(adjectives[115], "Walking");
	strcpy(adjectives[116], "Blind");
	strcpy(adjectives[117], "Deaf");
	strcpy(adjectives[118], "Lame");
	strcpy(adjectives[119], "Mute");
	strcpy(adjectives[120], "Fine");
	strcpy(adjectives[121], "Mythic");
	strcpy(adjectives[122], "Rare");
	strcpy(adjectives[123], "Common");
	strcpy(adjectives[124], "Duke's");
	strcpy(adjectives[125], "Earl's");
	strcpy(adjectives[126], "Marquis'");
	strcpy(adjectives[127], "Baron's");
	strcpy(adjectives[128], "Baroness'");
	strcpy(adjectives[129], "Countess'");
	strcpy(adjectives[130], "Marchioness'");
	strcpy(adjectives[131], "Duchess''");
	strcpy(adjectives[132], "Wounded");
	strcpy(adjectives[133], "Dead");
	strcpy(adjectives[134], "Bent");
	strcpy(adjectives[135], "Enraged");
	strcpy(adjectives[136], "One-Eyed");
	strcpy(adjectives[137], "Bloated");
	strcpy(adjectives[138], "Grapling");
	strcpy(adjectives[139], "Mysterious");
	strcpy(adjectives[140], "Flaming");
	strcpy(adjectives[141], "Flaming");
	strcpy(adjectives[142], "Thirsty");
	
	strcpy(nouns[0], "Trebuechet");
	strcpy(nouns[1], "Sheep");
	strcpy(nouns[2], "Ewe");
	strcpy(nouns[3], "Cow");
	strcpy(nouns[4], "Puppy");
	strcpy(nouns[5], "Dog");
	strcpy(nouns[6], "Kitten");
	strcpy(nouns[7], "Cat");
	strcpy(nouns[8], "Phoenix");
	strcpy(nouns[9], "Dragon");
	strcpy(nouns[10], "Wyrm");
	strcpy(nouns[11], "Griffin");
	strcpy(nouns[12], "Manticore");
	strcpy(nouns[13], "Sphinx");
	strcpy(nouns[14], "Roc");
	strcpy(nouns[15], "Gorgon");
	strcpy(nouns[16], "Golem");
	strcpy(nouns[17], "Spirit");
	strcpy(nouns[18], "Spectere");
	strcpy(nouns[19], "Fish");
	strcpy(nouns[20], "Shrimp");
	strcpy(nouns[21], "Crab");
	strcpy(nouns[22], "Maiden");
	strcpy(nouns[23], "Ox");
	strcpy(nouns[24], "Rooster");
	strcpy(nouns[25], "Chicken");
	strcpy(nouns[26], "Pig");
	strcpy(nouns[27], "Horse");
	strcpy(nouns[28], "Pony");
	strcpy(nouns[29], "Chick");
	strcpy(nouns[30], "Rabbit");
	strcpy(nouns[31], "Goat");
	strcpy(nouns[32], "Elephant");
	strcpy(nouns[33], "Donkey");
	strcpy(nouns[34], "Mule");
	strcpy(nouns[35], "Camel");
	strcpy(nouns[36], "Knight");
	strcpy(nouns[37], "Dame");
	strcpy(nouns[38], "Lord");
	strcpy(nouns[39], "Lady");
	strcpy(nouns[40], "Queen");
	strcpy(nouns[41], "King");
	strcpy(nouns[42], "Folly");
	strcpy(nouns[43], "Bear");
	strcpy(nouns[44], "Man");
	strcpy(nouns[45], "Woman");
	strcpy(nouns[46], "Melon");
	strcpy(nouns[47], "Carrot");
	strcpy(nouns[48], "Tree");
	strcpy(nouns[49], "Door");
	strcpy(nouns[40], "Soldier");
	strcpy(nouns[41], "Messenger");
	strcpy(nouns[42], "Cannon");
	strcpy(nouns[43], "Sword");
	strcpy(nouns[44], "Spear");
	strcpy(nouns[45], "Plow");
	strcpy(nouns[46], "Sickle");
	strcpy(nouns[47], "Priest");
	strcpy(nouns[48], "Friar");
	strcpy(nouns[49], "Bow");
	strcpy(nouns[50], "Hammer");
	strcpy(nouns[51], "Pot");
	strcpy(nouns[52], "Barrel");
	strcpy(nouns[53], "Loom");
	strcpy(nouns[54], "Mirror");
	strcpy(nouns[55], "Easel");
	strcpy(nouns[56], "Brush");
	strcpy(nouns[57], "Wagon");
	strcpy(nouns[58], "Boat");
	strcpy(nouns[59], "Rose");
	strcpy(nouns[60], "Daisy");
	strcpy(nouns[61], "Daffodil");
	strcpy(nouns[62], "Dandelion");
	strcpy(nouns[63], "Clover");
	strcpy(nouns[64], "Beast");
	strcpy(nouns[65], "Deer");
	strcpy(nouns[66], "Pig");
	strcpy(nouns[67], "Sow");
	strcpy(nouns[68], "Sea");
	strcpy(nouns[69], "Ocean");
	strcpy(nouns[70], "River");
	strcpy(nouns[71], "Squirel");
	strcpy(nouns[72], "Tower");
	strcpy(nouns[73], "House");
	strcpy(nouns[74], "Cabin");
	strcpy(nouns[75], "Place");
	strcpy(nouns[76], "Box");
	strcpy(nouns[77], "Gem");
	strcpy(nouns[78], "Ring");
	strcpy(nouns[79], "Ram");
	strcpy(nouns[80], "Drum");
	strcpy(nouns[81], "Flute");
	strcpy(nouns[82], "Lute");
	strcpy(nouns[83], "Basilisk");
	strcpy(nouns[84], "Fairy");
	strcpy(nouns[85], "Mermaid");
	strcpy(nouns[86], "Statue");
	strcpy(nouns[87], "Mushroom");
	strcpy(nouns[88], "Hero");
	strcpy(nouns[89], "Spider");
	strcpy(nouns[90], "Mouse");
	strcpy(nouns[91], "Star");
	strcpy(nouns[92], "Light");
	strcpy(nouns[93], "Lion");
	strcpy(nouns[94], "Gorilla");
	strcpy(nouns[95], "Ranger");
	strcpy(nouns[96], "Sage");
	strcpy(nouns[97], "Wizard");
	strcpy(nouns[98], "Hermit");
	strcpy(nouns[99], "Shop");
	strcpy(nouns[100], "Store");
	strcpy(nouns[101], "Shoppe");
	strcpy(nouns[102], "Sailor");
	strcpy(nouns[103], "Mercantile");
	strcpy(nouns[104], "Mart");
	strcpy(nouns[105], "Post");
	strcpy(nouns[106], "Fence");
	strcpy(nouns[107], "Shelf");
	strcpy(nouns[108], "Thing");
	strcpy(nouns[109], "Cricket");
	strcpy(nouns[110], "Labyrinth");
	strcpy(nouns[111], "Snake");
	strcpy(nouns[112], "Pirate");
	strcpy(nouns[113], "Outlaw");
	strcpy(nouns[114], "Mother");
	strcpy(nouns[115], "Father");
	strcpy(nouns[116], "Son");
	strcpy(nouns[117], "Daughter");
	strcpy(nouns[118], "Cousin");
	strcpy(nouns[119], "Aunt");
	strcpy(nouns[120], "Uncle");
	strcpy(nouns[121], "Snipe");
	strcpy(nouns[122], "Jackrabbit");
	strcpy(nouns[123], "R.O.U.S.");
	strcpy(nouns[124], "Stuff");
	strcpy(nouns[125], "Bistro");
	strcpy(nouns[126], "Gazebo");
	strcpy(nouns[127], "Thing-A-Mo-Jigger");
	strcpy(nouns[128], "Badger");
	strcpy(nouns[129], "Baby");
	strcpy(nouns[130], "Ship");
	strcpy(nouns[131], "Chest");
	strcpy(nouns[132], "Egg");
	strcpy(nouns[133], "Whale");
	strcpy(nouns[134], "Duck");
	strcpy(nouns[135], "Goose");
	strcpy(nouns[136], "Bucket");
	strcpy(nouns[137], "Fox");
	strcpy(nouns[138], "Bull");
	strcpy(nouns[139], "Badger");
	strcpy(nouns[140], "Traveller");
	strcpy(nouns[141], "Pixie");
	strcpy(nouns[142], "Sprite");
	
	fprintf(storeHere,"%s %s\n", adjectives[rand()%numElements],nouns[rand()%numElements]);
}

//////////
// Adventurer's Emporium
// TODO
// Finish adding items
void makeAdventurerEmprium(FILE* storeHere, uint16_t flags){
	uint8_t inventorySize = 255;
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
	inventory[12].biasFlags = 0x20;
	// Light Hammer
	strcpy(inventory[13].name,"Light Hammer");
	inventory[13].lowPrice = 100;
	inventory[13].midPrice = 200;
	inventory[13].highPrice = 300;
	inventory[13].stock = 5;
	inventory[13].biasFlags = 0x80;
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
	inventory[15].biasFlags = 0x400;
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
	inventory[18].biasFlags = 0x400;
	// Sling
	strcpy(inventory[19].name,"Sling");
	inventory[19].lowPrice = 7;
	inventory[19].midPrice = 10;
	inventory[19].highPrice = 20;
	inventory[19].stock = 3;
	inventory[19].biasFlags = 0x400;
	// Whip
	strcpy(inventory[20].name,"Whip");
	inventory[20].lowPrice = 10;
	inventory[20].midPrice = 20;
	inventory[20].highPrice = 30;
	inventory[20].stock = 5;
	inventory[20].biasFlags = 0x0;
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
	inventory[22].biasFlags = 0x800;
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
	inventory[24].biasFlags = 0x400;
	
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
	inventory[39].biasFlags = 0x0;
	// Chest
	strcpy(inventory[40].name,"Chest");
	inventory[40].lowPrice = 300;
	inventory[40].midPrice = 500;
	inventory[40].highPrice = 800;
	inventory[40].stock = 5;
	inventory[40].biasFlags = 0x0;
	// Climber's Kit
	strcpy(inventory[41].name,"Climber's Kit");
	inventory[41].lowPrice = 1800;
	inventory[41].midPrice = 2500;
	inventory[41].highPrice = 3800;
	inventory[41].stock = 5;
	inventory[41].biasFlags = 0x0;
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
	inventory[46].biasFlags = 0x0;
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
	inventory[48].biasFlags = 0x801;
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
	inventory[54].biasFlags = 0x800;
	// Mess Kit
	strcpy(inventory[55].name,"Mess Kit");
	inventory[55].lowPrice = 10;
	inventory[55].midPrice = 20;
	inventory[55].highPrice = 30;
	inventory[55].stock = 5;
	inventory[55].biasFlags = 0x0;
	// Paper
	strcpy(inventory[56].name,"Paper");
	inventory[56].lowPrice = 10;
	inventory[56].midPrice = 20;
	inventory[56].highPrice = 30;
	inventory[56].stock = 18;
	inventory[56].biasFlags = 0x841;
	// Parchment
	strcpy(inventory[57].name,"Parchment");
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
	inventory[67].biasFlags = 0xC0;
	// Silk Rope
	strcpy(inventory[68].name,"Silk Rope (50 ft.)");
	inventory[68].lowPrice = 700;
	inventory[68].midPrice = 1000;
	inventory[68].highPrice = 2000;
	inventory[68].stock = 15;
	inventory[68].biasFlags = 0x0;
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
	inventory[70].biasFlags = 0x80;
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
	inventory[72].biasFlags = 0x0;
	// Spyglass
	strcpy(inventory[73].name,"Spyglass");
	inventory[73].lowPrice = 75000;
	inventory[73].midPrice = 100000;
	inventory[73].highPrice = 150000;
	inventory[73].stock = 18;
	inventory[73].biasFlags = 0x12;
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
	inventory[88].biasFlags = 0x10;
	// Herbalism Kit
	strcpy(inventory[89].name,"Herbalism Kit");
	inventory[89].lowPrice = 300;
	inventory[89].midPrice = 500;
	inventory[89].highPrice = 800;
	inventory[89].stock = 10;
	inventory[89].biasFlags = 0x10;
	// Jeweler's Tools
	strcpy(inventory[90].name,"Jeweler's Tools");
	inventory[90].lowPrice = 1800;
	inventory[90].midPrice = 2500;
	inventory[90].highPrice = 3800;
	inventory[90].stock = 18;
	inventory[90].biasFlags = 0x800;
	// Navigator's Tools
	strcpy(inventory[91].name,"Navigator's Tools");
	inventory[91].lowPrice = 1800;
	inventory[91].midPrice = 2500;
	inventory[91].highPrice = 3800;
	inventory[91].stock = 3;
	inventory[91].biasFlags = 0x12;
	
	char dividerChar = ' ';
	fprintf(storeHere, "            %s           ", "Item Name"); // Item name colum
	fprintf(storeHere, "%c", dividerChar); 
	fprintf(storeHere, "     %s  ", "Low"); // low price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "    %s   ", "Mid"); // mid price colum
	fprintf(storeHere, "%c",dividerChar);
	fprintf(storeHere, "   %s   ", "High"); // high price colum
	fprintf(storeHere, "\n");
	time_t t;
	srand(time(NULL));
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
				convertFromCp(inventory[i].lowPrice, storeHere);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCp(inventory[i].midPrice, storeHere);
				fprintf(storeHere, "%c", dividerChar);
				convertFromCp(inventory[i].highPrice, storeHere);
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
}

void commandReminder(){
	printf(".\\programName <storageLoc.txt> <shopType> <flags>\n");
	printf("Supported shopTypes are:\n");
	printf("00 - Adventurer's Emporium\n");
	printf("01 - Alchemist's Shop\n");
	printf("02 - Arcana Shop\n");
	printf("03 - Baker's Shop\n");
	printf("04 - Blacksmith\n");
	printf("05 - Bookstore\n");
	printf("06 - Butcher's Shop\n");
	printf("07 - Cobbler's Shop\n");
	printf("08 - Fletcher\n");
	printf("09 - Leatherworker's Shop\n");
	printf("10 - Music Store\n");
	printf("11 - Tailor\n");
	printf("12 - Shady Shop\n");
	printf("13 - Shrine\n");
	printf("14 - Jeweler\n");
	printf("15 - Wizard's Tower\n");
	printf("Supported Flags are:\n");
	printf("Bit 00 - Magical\n");
	printf("Bit 01 - Costal\n");
	printf("Bit 02 - Hills\n");
	printf("Bit 03 - Exotic\n");
	printf("Bit 04 - Frontier\n");
	printf("Bit 05 - Forest\n");
	printf("Bit 06 - Industrial\n");
	printf("Bit 07 - Mining\n");
	printf("Bit 08 - Pious\n");
    printf("Bit 09 - Orchard\n");
	printf("Bit 10 - Rural\n");
	printf("Bit 11 - Urban\n");
}

enum shopType{Adventurer, Alchemist, Arcana, Baker, Barber, Blacksmith, Book, Butcher, Cobbler, Fletcher,
              General, Leather, Music, Tailor, Tavern, Shady, Shrine, Jeweler, Wizard };
			  
int main(int argc, char* argv[]){
	uint16_t flags = atoi(argv[3]);
	srand(time(NULL));
	if (argc != 4){
		commandReminder();
		return -1;
	}
	else{
		FILE * shopFile = fopen(argv[1], "w+");
		uint8_t shopNum = atoi(argv[2]);
		switch(shopNum){
			case 0:
				fprintf(shopFile, "Adventurer's Emporium\n");
				fprintf(shopFile, "The ");
				shopnameGen(shopFile);// Store Owners Name
				//nameGen(shopFile, 0xFF);
				makeAdventurerEmprium(shopFile, flags);
				break;
			default:
				printf("ERROR, INVALID COMMAND\n");
				commandReminder();
		}
		fclose(shopFile);
	}
	return 0;
}