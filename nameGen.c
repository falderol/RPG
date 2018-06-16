#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#define NAME_LENGTH 32

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
	srand(time(0));
}

//////////
// Generate the name of a shop
// Create list of adjectives and nouns.
// Choose a random entry on the list

void shopnameGen(FILE* storeHere){
	srand(time(0));
	int16_t numElements = 154;
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
	strcpy(adjectives[17], "Eager");
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
	strcpy(adjectives[131], "Duchess'");
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
	strcpy(adjectives[143], "Olde");
	strcpy(adjectives[144], "Beautiful");
	strcpy(adjectives[145], "Rusty");
	strcpy(adjectives[146], "New");
	strcpy(adjectives[147], "Spotted");
	strcpy(adjectives[148], "Prancing");
	strcpy(adjectives[149], "Dancing");
	strcpy(adjectives[150], "Broken");
	strcpy(adjectives[151], "Lovely");
	strcpy(adjectives[152], "Violent");
	strcpy(adjectives[153], "Bloody");
	
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
	strcpy(nouns[50], "Soldier");
	strcpy(nouns[51], "Messenger");
	strcpy(nouns[52], "Cannon");
	strcpy(nouns[53], "Sword");
	strcpy(nouns[54], "Spear");
	strcpy(nouns[55], "Plow");
	strcpy(nouns[56], "Sickle");
	strcpy(nouns[57], "Priest");
	strcpy(nouns[58], "Friar");
	strcpy(nouns[59], "Bow");
	strcpy(nouns[60], "Hammer");
	strcpy(nouns[61], "Pot");
	strcpy(nouns[62], "Barrel");
	strcpy(nouns[63], "Loom");
	strcpy(nouns[64], "Mirror");
	strcpy(nouns[65], "Easel");
	strcpy(nouns[66], "Brush");
	strcpy(nouns[67], "Wagon");
	strcpy(nouns[68], "Boat");
	strcpy(nouns[69], "Rose");
	strcpy(nouns[70], "Daisy");
	strcpy(nouns[71], "Daffodil");
	strcpy(nouns[72], "Dandelion");
	strcpy(nouns[73], "Clover");
	strcpy(nouns[74], "Beast");
	strcpy(nouns[75], "Deer");
	strcpy(nouns[76], "Pig");
	strcpy(nouns[77], "Sow");
	strcpy(nouns[78], "Sea");
	strcpy(nouns[79], "Ocean");
	strcpy(nouns[80], "River");
	strcpy(nouns[81], "Squirel");
	strcpy(nouns[82], "Tower");
	strcpy(nouns[83], "House");
	strcpy(nouns[84], "Cabin");
	strcpy(nouns[85], "Place");
	strcpy(nouns[86], "Box");
	strcpy(nouns[87], "Gem");
	strcpy(nouns[88], "Ring");
	strcpy(nouns[89], "Ram");
	strcpy(nouns[90], "Drum");
	strcpy(nouns[91], "Flute");
	strcpy(nouns[92], "Lute");
	strcpy(nouns[93], "Basilisk");
	strcpy(nouns[94], "Fairy");
	strcpy(nouns[95], "Mermaid");
	strcpy(nouns[96], "Statue");
	strcpy(nouns[97], "Mushroom");
	strcpy(nouns[98], "Hero");
	strcpy(nouns[99], "Spider");
	strcpy(nouns[100], "Mouse");
	strcpy(nouns[101], "Star");
	strcpy(nouns[102], "Light");
	strcpy(nouns[103], "Lion");
	strcpy(nouns[104], "Gorilla");
	strcpy(nouns[105], "Ranger");
	strcpy(nouns[106], "Sage");
	strcpy(nouns[107], "Wizard");
	strcpy(nouns[108], "Hermit");
	strcpy(nouns[109], "Shop");
	strcpy(nouns[110], "Store");
	strcpy(nouns[111], "Shoppe");
	strcpy(nouns[112], "Sailor");
	strcpy(nouns[113], "Mercantile");
	strcpy(nouns[114], "Mart");
	strcpy(nouns[115], "Post");
	strcpy(nouns[116], "Fence");
	strcpy(nouns[117], "Shelf");
	strcpy(nouns[118], "Thing");
	strcpy(nouns[119], "Cricket");
	strcpy(nouns[120], "Labyrinth");
	strcpy(nouns[121], "Snake");
	strcpy(nouns[122], "Pirate");
	strcpy(nouns[123], "Outlaw");
	strcpy(nouns[124], "Mother");
	strcpy(nouns[125], "Father");
	strcpy(nouns[126], "Son");
	strcpy(nouns[127], "Daughter");
	strcpy(nouns[128], "Cousin");
	strcpy(nouns[129], "Aunt");
	strcpy(nouns[130], "Uncle");
	strcpy(nouns[131], "Snipe");
	strcpy(nouns[132], "Jackrabbit");
	strcpy(nouns[133], "Rodent of Unusual Size");
	strcpy(nouns[134], "Stuff");
	strcpy(nouns[135], "Bistro");
	strcpy(nouns[136], "Gazebo");
	strcpy(nouns[137], "Thing-A-Mo-Jigger");
	strcpy(nouns[138], "Badger");
	strcpy(nouns[139], "Baby");
	strcpy(nouns[140], "Ship");
	strcpy(nouns[141], "Chest");
	strcpy(nouns[142], "Egg");
	strcpy(nouns[143], "Whale");
	strcpy(nouns[144], "Duck");
	strcpy(nouns[145], "Goose");
	strcpy(nouns[146], "Bucket");
	strcpy(nouns[147], "Fox");
	strcpy(nouns[148], "Bull");
	strcpy(nouns[149], "Badger");
	strcpy(nouns[150], "Traveller");
	strcpy(nouns[151], "Pixie");
	strcpy(nouns[152], "Sprite");
	strcpy(nouns[153], "Pit");
	
	fprintf(storeHere,"%s %s\n", adjectives[rand()%numElements],nouns[rand()%numElements]);
}

void townnameGen(FILE * storeHere){
	srand(time(0));
	uint8_t numFirst = 57;
	char first[numFirst][NAME_LENGTH];
	strcpy(first[0],"Milwau");
	strcpy(first[1],"Madi");
	strcpy(first[2],"Keno");
	strcpy(first[3],"Green");
	strcpy(first[4],"Blue");
	strcpy(first[5],"Red");
	strcpy(first[6],"Yellow");
	strcpy(first[7],"Wauke");
	strcpy(first[8],"Osh");
	strcpy(first[9],"Winne");
	strcpy(first[10],"Champ");
	strcpy(first[11],"Chica");
	strcpy(first[12],"Urban");
	strcpy(first[13],"Winth");
	strcpy(first[14],"Winne");
	strcpy(first[15],"Lond");
	strcpy(first[16],"Up");
	strcpy(first[17],"Eden");
	strcpy(first[18],"Edin");
	strcpy(first[19],"Ham");
	strcpy(first[20],"Minne");
	strcpy(first[21],"Rock");
	strcpy(first[21],"River");
	strcpy(first[23],"Spring");
	strcpy(first[24],"Aur");
	strcpy(first[25],"Joil");
	strcpy(first[26],"Elg");
	strcpy(first[27],"Peor");
	strcpy(first[28],"Rac");
	strcpy(first[29],"Sup");
	strcpy(first[30],"Du");
	strcpy(first[31],"Roch");
	strcpy(first[32],"Dul");
	strcpy(first[33],"Mad");
	strcpy(first[34],"Dun");
	strcpy(first[35],"Kin");
	strcpy(first[36],"Ler");
	strcpy(first[37],"Orrin");
	strcpy(first[38],"Maccels");
	strcpy(first[39],"Skarg");
	strcpy(first[40],"Bull");
	strcpy(first[41],"Black");
	strcpy(first[42],"Jarl");
	strcpy(first[43],"Knight");
	strcpy(first[44],"Earth");
	strcpy(first[45],"Old");
	strcpy(first[46],"New");
	strcpy(first[47],"North");
	strcpy(first[48],"South");
	strcpy(first[49],"East");
	strcpy(first[50],"West");
	strcpy(first[51],"Dame");
	strcpy(first[52],"Storm");
	strcpy(first[53],"White");
	strcpy(first[54],"Mud");
	strcpy(first[55],"Burr");
	strcpy(first[56],"Mack");
	
	uint8_t numLast = 57;
	char last[numLast][NAME_LENGTH];
	strcpy(last[0],"ton");
	strcpy(last[1],"in");
	strcpy(last[2],"ville");
	strcpy(last[3],"shire");
	strcpy(last[4],"on");
	strcpy(last[5],"field");
	strcpy(last[6],"town");
	strcpy(last[7],"sha");
	strcpy(last[8],"ine");
	strcpy(last[9],"ton");
	strcpy(last[10],"kee");
	strcpy(last[11],"go");
	strcpy(last[12],"ion");
	strcpy(last[13],"an");
	strcpy(last[14],"son");
	strcpy(last[15],"gan");
	strcpy(last[16],"ing");
	strcpy(last[17],"ane");
	strcpy(last[18],"ay");
	strcpy(last[19],"sin");
	strcpy(last[20],"field");
	strcpy(last[21],"aire");
	strcpy(last[22],"osh");
	strcpy(last[23],"ago");
	strcpy(last[24],"land");
	strcpy(last[25],"mer");
	strcpy(last[26],"ange");
	strcpy(last[27],"ana");
	strcpy(last[28],"port");
	strcpy(last[29],"rop");
	strcpy(last[30],"borough");
	strcpy(last[31],"polis");
	strcpy(last[32],"ford");
	strcpy(last[33],"fort");
	strcpy(last[34],"dem");
	strcpy(last[35],"ora");
	strcpy(last[36],"et");
	strcpy(last[37],"aign");
	strcpy(last[38],"ia");
	strcpy(last[39],"ois");
	strcpy(last[40],"ota");
	strcpy(last[41],"uth");
	strcpy(last[42],"burg");
	strcpy(last[43],"castel");
	strcpy(last[44],"wich");
	strcpy(last[45],"caster");
	strcpy(last[46],"stey");
	strcpy(last[47],"ick");
	strcpy(last[48],"ness");
	strcpy(last[49],"run");
	strcpy(last[50],"scar");
	strcpy(last[51],"vein");
	strcpy(last[52],"garde");
	strcpy(last[53],"wind");
	strcpy(last[54],"cliffe");
	strcpy(last[55],"shade");
	strcpy(last[56],"holde");
	
	fprintf(storeHere,"%s%s\n", first[rand()%numFirst],last[rand()%numLast]);
}	