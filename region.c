#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "settlementGen.h"
#include "flagDefines.h"

#define REGION_WIDTH 512
#define REGION_HEIGHT 512

void regionCommandReminder(){
    printf("regionGen <filename.txt>\n");
}
/**********************************************************************/
/* GENERAL                                                            */
/* One tile will be 1 sq mile                                         */
/* This whole thing is lazily written and needs to be fixed           */
/**********************************************************************/
/* CITIES                                                             */
/* Go through the array of the map, in hex pattern place cities every */
/* 6 miles if there is land                                           */
/*     0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F  */
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/* 0 |   |   |   |   |   |   |   |   |   |   |   |   |   |   | C |   |*/
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/* 1 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |*/
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/* 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |*/
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/* 3 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |*/
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/* 4 |   |   |   |   |   |   | C |   |   |   |   |   |   |   |   |   |*/
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/* 5 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |*/
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/* 6 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |*/
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/* 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |*/
/*   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|*/
/*                                                                    */
/* ascii will look like                                               */  
/*   0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N O P Q R S T U V W*/
/* 0 . . . . . . . . . . . . . .0000 . . . . . . . . . . . . . .0001 .*/
/* 1 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* 2 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* 3 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* 4 . . . . . .0002 . . . . . . . . . . . . . .0003 . . . . . . . . .*/
/* 5 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* 6 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* 7 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* 8 . . . . . . . . . . . . . .0004 . . . . . . . . . . . . . .0005 .*/
/* 9 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* A . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* B . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* C . . . . . .0006 . . . . . . . . . . . . . .0007 . . . . . . . . .*/
/* D . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* E . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/* F . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .*/
/*                                                                    */
/* This gives us a maximum of 1024 settlements on our 512x512 map     */
/* On a map with ~ earth water coverage of about 70% this means we    */
/* Will have an average of 308 settlements                            */
/* If we roll for random settlements from 1 to 105 this means we will */
/* have on average 15 cities, 86 towns, 203 villages, and 6 abandoned */
/* settlements                                                        */
/**********************************************************************/
/* FLAGS                                                              */
/* a 32 bit int will be used to represent each spot in the map.       */
/* 16 bits are reserved for settlement information                    */
/* 16 bits are reseved for world information                          */
/* Bit 0 is the LSB, bit 31 is the MSB                                */
/*                                                                    */
/* Bit | Description | Caused By                                      */
/* ----|-------------|------------------------------------------------*/
/*  00 | Coastal     | When a water tile meets a land tile            */
/*  01 | Mountain    | Initial plate collisions and surrounding tiles */
/*  02 | Agriculture | Settlement in Farming Biome                    */
/*  03 | Forest      | TBD - Something to do with weather             */
/*  04 | Commerce    | TBD                                            */
/*  05 | Frontier    | TBD - Something to do with nearby settlements? */
/*  06 | Industrial  | Resources and Town Level Pop                   */
/*  07 | Rural       | Settlement with village level pop in 4 tile    */
/*     |             | radius                                         */
/*  08 | Urban       | Settlement with city level pop in 4 tile radius*/
/*  09 | Exotic      | Randomly blobbed on the map                    */
/*  10 | Pious       | Randomly blobbed                               */
/*  11 | Magical     | rand is called for 0.01*mapHeigh*mapWidth times*/
/*  12 | TBD         | unassigned                                     */
/*  13 | TBD         | unassigned                                     */
/*  14 | Firearms    | Optional flag if using firearms                */
/*  15 | Invalid     | Marks the tile as invalid                      */
/*  16 | West        | Randomly placed initial plate, then blobbed    */
/*  17 | South       | Randomly placed initial plate, then blobbed    */
/*  18 | East        | Randomly placed initial plate, then blobbed    */
/*  19 | North       | Randomly placed initial plate, then blobbed    */
/*  20 | Moisture    | Dry, Mid, Wet, invalid                         */
/*  21 | Moisture    |                                                */
/*  22 | Temperature | Tropical, temperate, subartic, artic           */
/*  24 | Temperature |                                                */
/*  25 | Height      | Below, at, above, invalid                      */
/*  26 | Height      |                                                */
/*  27 | TBD         | unassigned                                     */
/*  28 | TBD         | unassigned                                     */
/*  28 | TBD         | unassigned                                     */
/*  30 | TBD         | unassigned                                     */
/*  31 | Land        | Initialy from plate collisions, then blobbed   */
/*                                                                    */
/**********************************************************************/
int regionGen(char * filename){
    printf ("Storing region in %s\n", filename);
    FILE * regionFile;
    regionFile = fopen(filename, "w+");
    uint32_t rawMap[REGION_HEIGHT][REGION_WIDTH];
    memset(rawMap, '\0', sizeof(uint32_t)*REGION_WIDTH*REGION_HEIGHT);
    uint32_t rawMapMask[REGION_HEIGHT][REGION_WIDTH];
    memset(rawMapMask, '\0', sizeof(uint32_t)*REGION_WIDTH*REGION_HEIGHT);
    uint8_t plateAmount = 16+rand()%16;
    uint16_t randY;
    uint16_t randX;
    uint16_t randXgroup;
    uint16_t randYgroup;
    uint32_t loopAmount;
    printf("Randomly placing plates...\n");
    for (int i = 0; i < plateAmount; ++i){
        randX = rand()%REGION_WIDTH;
        randY = rand()%REGION_HEIGHT;
        if (rawMap[randY][randX] == 0){
            rawMap[randY][randX] = (1<<rand()%4)<<16;
        }
        else{
            --i;
        }
    }

    /**************************************/
    /* Initial Plate Construction         */
    /* Make plates moving in one of the   */
    /* four cardinal directions.          */
    /**************************************/
    printf("Blobbing Plates...\n");
    uint32_t tileAmount = 0;
    uint16_t overBorderLoc = 0;
    while (tileAmount < (REGION_HEIGHT * REGION_WIDTH)-plateAmount){
        memset(rawMapMask, '\0', sizeof(uint32_t)*REGION_WIDTH*REGION_HEIGHT);
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                if (!(rand()%4) && (rawMap[i][j] == 0)){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                rawMapMask[i][j] = (rawMap[i][overBorderLoc] & (FLAG_NORTH + FLAG_SOUTH)) ? rawMap[i][overBorderLoc]  ^ (FLAG_NORTH + FLAG_SOUTH) : rawMap[i][overBorderLoc];
                            }
                            else {
                                rawMapMask[i][j] = rawMap[i-1][j];
                            }
                            if (rawMapMask[i][j] != 0){
                                ++tileAmount;
                            }
                            break;
                        case 1: /* South */
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                rawMapMask[i][j] = (rawMap[i][overBorderLoc] & (FLAG_NORTH + FLAG_SOUTH)) ? rawMap[i][overBorderLoc]  ^ (FLAG_NORTH + FLAG_SOUTH) : rawMap[i][overBorderLoc];
                            }
                            else {
                                rawMapMask[i][j] = rawMap[i+1][j];
                            }
                            if (rawMapMask[i][j] != 0){
                                ++tileAmount;
                            }
                            break;
                        case 2: /* East */
                            if (j==REGION_WIDTH-1){
                                rawMapMask[i][j] = rawMap[i][0];
                            }
                            else {
                                rawMapMask[i][j] = rawMap[i][j+1];
                            }
                            if (rawMapMask[i][j] != 0){
                                ++tileAmount;
                            }
                            break;
                        case 3: /* West */
                            if (j==0){
                                rawMapMask[i][j] = rawMap[i][REGION_WIDTH-1];
                            }
                            else {
                                rawMapMask[i][j] = rawMap[i][j-1];
                            }
                            if (rawMapMask[i][j] != 0){
                                ++tileAmount;
                            }
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                rawMap[i][j] |= rawMapMask[i][j];
            }
        }
    }
/**********************************************************************/
/* PLATES                                                             */
/* Standard Construction                                              */
/* Bit 19 | Bit 18 | Bit 17 | Bit 16                                  */
/* -------|--------|--------|-------                                  */
/*  North |   East |  South |   West                                  */
/*                                                                    */
/* Tile                Look    Look    Look    Look                   */
/* Type  | Collision | North | South | East  | West                   */
/* ------|-----------|-------|-------|-------|-------                 */
/* North |   Diverge |   0   |  !N   |   E   |   W                    */
/*       |  Converge |  !N   |   0   |   W   |   E                    */
/*       | Transform |   0   |   0   |   S   |   S                    */
/* South |   Diverge |   0   |  !S   |   E   |   W                    */
/*       |  Converge |  !S   |   0   |   W   |   E                    */
/*       | Transform |   0   |   0   |   N   |   N                    */
/*  East |   Diverge |   N   |   S   |   0   |  !E                    */
/*       |  Converge |   S   |   N   |  !E   |   0                    */
/*       | Transform |   W   |   W   |   0   |   0                    */
/*  West |   Diverge |   N   |   S   |   0   |  !W                    */
/*       |  Converge |   S   |   N   |  !W   |   0                    */
/*       | Transform |   E   |   E   |   0   |   0                    */
/**********************************************************************/
/* LAND                                                               */
/* I know the following isnt accurate, it's good enough for this      */
/*       |    Dry    |    Mid    |     Wet    | Very Wet              */
/* ------|-----------|-----------|------------|----------             */
/* Artic | Tundra    | Tundra    | Tundra     | Tundra                */
/*  Cold | Tagia     | Tagia     | Tagia      | Bog                   */
/*   Mid | Shrubland | Prairie   | Forest     | Swamp                 */
/*   Hot | Desert    | Savanna   | Rainforest | Mangrove              */
/*                                                                    */
/*  Land Type | Unique Symbol | Simple Symbol | UTF-8                 */
/* -----------|---------------|---------------|-------                */
/*     Tundra |       A       |       A       |   ʭ                   */
/*      Tagia |       T       |       T       |   †                   */
/*        Bog |       B       |       ^       |   φ                   */
/*  Shrubland |       ~       |       ~       |   ɷ                   */
/*    Prairie |       P       |       ~       |   ~                   */
/*     Forest |       F       |       T       |   Ŧ                   */
/*      Swamp |       S       |       ^       |   Ψ                   */
/*     Desert |       D       |               |                       */
/*    Savanna |       V       |       +       |   ±                   */
/* Rainforest |       R       |       T       |   ‡                   */
/*   Mangrove |       ^       |       ^       |   ʎ                   */
/*      Water |       .       |       .       |   ▓                   */
/*   Mountain |       M       |       M       |   Δ                   */
/*                                                                    */
/* If Height is above everything gets made one column drier           */
/* If Height is below everything gets on column wetter                */ 
/* Temperature is influenced by y cord                                */
/* Moisture is influenced by proximity to water, and height           */
/* work from the coastal tiles in, filling in tiles adjacent to those */
/* already filled in each pass, a decrease in height from above sea   */
/* level is a decrease in moisture. Start at mid or wet               */
/* Height is determined by plate collision, random placement, then    */
/* blobbing to fill in the rest of it                                 */
/**********************************************************************/
/* I hate to do this but it looks better                              */
/**********************************************************************/
    
    printf("Placing Initial Mountains...\n");
    for(int i = 0; i < REGION_HEIGHT; ++i){
        for(int j = 0; j < REGION_WIDTH; ++j){
            switch(rawMap[i][j]>>16){
                case 1 : /* tile is west */
                    if (i == 0){ /* look north */
                        if ((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>19)&1){ /* if north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look north */
                        if ((rawMap[i-1][j]>>17)&1){ /* if south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    if (i == REGION_HEIGHT-1){ /* look south */
                        if ((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>17)&1){ /* if south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look south */
                        if ((rawMap[i+1][j]>>19)&1){ /* if north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    if (j == 0){ /* look west */
                        if (!((rawMap[i][REGION_WIDTH-1]>>16)&1)){ /* if not west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look west */
                        if (!((rawMap[i][j-1]>>16)&1)){ /* if not west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    break;
                case 2: /* tile is south */
                    if (j == REGION_WIDTH-1){ /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    if (i == REGION_HEIGHT-1){ /* look south */
                        if (!((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>19)&1)){ /* if not north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look south */
                        if (!((rawMap[i+1][j]>>17)&1)){ /* if not south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    if (j == 0){ /* look west */
                        if ((rawMap[i][REGION_WIDTH-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look west */
                        if ((rawMap[i][j-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    break;

                case 4: /* tile is east */
                    if (i == 0){ /* look north */
                        if ((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>19)&1){ /* if north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look north */
                        if ((rawMap[i-1][j]>>17)&1){ /* if south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    if (i == REGION_HEIGHT-1){ /* look south */
                        if ((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>17)&1){ /* if south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look south */
                        if ((rawMap[i+1][j]>>19)&1){ /* if north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    if (j == REGION_WIDTH-1){ /* look east */
                        if (!((rawMap[i][0]>>18)&1)){ /* if not east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look east */
                        if (!((rawMap[i][j+1]>>18)&1)){ /* if not east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    break;
                case 8: /* tile is north */
                    if (j == REGION_WIDTH-1){ /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    if (i == 0){ /* look north */
                        if (!((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>17)&1)){ /* if not south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look north */
                        if (!((rawMap[i-1][j]>>19)&1)){ /* if not north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    if (j == 0){ /* look west */
                        if ((rawMap[i][REGION_WIDTH-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    else { /* look west */
                        if ((rawMap[i][j-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN;
                        }
                    }
                    break;
            }
        }
    }
    //#if 0
    printf("Placing land seed...\n");
    uint8_t landSeedAmount = 8 + rand()%4;
    uint16_t dispersalRange = 64;
    uint16_t numMisses;
    uint16_t toManyFails = dispersalRange*dispersalRange*2; /* Good change to try every tile in the 64 before it fails*/
    for (int i = 0; i < landSeedAmount; ++i){
        randXgroup = (rand()%(REGION_WIDTH-dispersalRange*2))+dispersalRange;
        randYgroup = (rand()%(REGION_HEIGHT-dispersalRange*2))+dispersalRange;
        loopAmount = rand()%8 + 8;
        numMisses = 0;
        for (int j = 0; j < loopAmount; ++j){
            randX = randYgroup + rand()%dispersalRange - dispersalRange/2;
            randY = randXgroup + rand()%dispersalRange - dispersalRange/2;
            if (rawMap[randX][randY] & FLAG_MOUNTAIN){
                rawMap[randY][randX] |= FLAG_LAND;
            }
            else if (numMisses == toManyFails){
                --i;
                break;
            }
            else {
                ++numMisses;
                --j;
            }
        }


    }
    printf ("Blobbing land...\n");
    uint16_t landLoopAmount = 256 + rand()%64;
    for (int h = 0; h < landLoopAmount; ++h){
        memset(rawMapMask, '\0', sizeof(uint32_t)*REGION_WIDTH*REGION_HEIGHT);
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                if (!(rand()%4) && (rawMap[i][j] & FLAG_LAND)){
                    uint8_t landBias;
                    landBias = rand()%6;
                    if (landBias > 3){
                        landBias = ((rawMap[i][j] >> 16) & 0xF); /* Get plate movement */
                        if (landBias == 2){
                            landBias = 1;
                        }
                        else if (landBias == 4){
                            landBias = 2;
                        }
                        else if (landBias == 8){
                            landBias = 3;
                        }
                    }
                    switch(landBias){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                rawMapMask[i][overBorderLoc] |= FLAG_LAND;
                            }
                            else {
                                rawMapMask[i-1][j] |= FLAG_LAND;
                            }
                            break;
                        case 1: /* South */
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                rawMapMask[i][overBorderLoc] = FLAG_LAND;
                            }
                            else {
                                rawMapMask[i+1][j] |= FLAG_LAND;
                            }
                            break;
                        case 2: /* East */
                            if (j==REGION_WIDTH-1){
                                rawMapMask[i][0] |= FLAG_LAND;
                            }
                            else {
                                rawMapMask[i][j+1] |= FLAG_LAND;
                            }
                            break;
                        case 3: /* West */
                            if (j==0){
                                rawMapMask[i][REGION_WIDTH-1] |= FLAG_LAND;
                            }
                            else {
                                rawMapMask[i][j-1] |= FLAG_LAND;
                            }
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                rawMap[i][j] |= rawMapMask[i][j];
            }
        }
    }
    printf("Fuzifying Coastal Areas...\n");
    /**********************************************************************/
    /* Fuzzy Coast                                                        */
    /**********************************************************************/
    loopAmount = (REGION_WIDTH+REGION_HEIGHT)/24 + rand()%((REGION_WIDTH+REGION_HEIGHT)/128);
    for (int loop = 0; loop < loopAmount; ++loop){
        memset(rawMapMask, '\0', sizeof(uint32_t)*REGION_WIDTH*REGION_HEIGHT);
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                if (!(rand()%4) && !(rawMap[i][j]&FLAG_LAND)){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                if((rawMap[i][overBorderLoc] & FLAG_SOUTH) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][overBorderLoc];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][overBorderLoc];
                                }
                            }
                            else {
                                if((rawMap[i-1][j] & FLAG_NORTH) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i-1][j];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i-1][j];
                                }
                            }
                            break;

                        case 1: /* South  */
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                if((rawMap[i][overBorderLoc] & FLAG_NORTH) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][overBorderLoc];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][overBorderLoc];
                                }
                            }
                            else {
                                if((rawMap[i+1][j] & FLAG_SOUTH) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i+1][j];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i+1][j];
                                }
                            }
                            break;

                        case 2: /* East */
                            if (j==REGION_WIDTH-1){
                                if ((rawMap[i][0] & FLAG_EAST) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][0];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][0];
                                }
                            }
                            else {
                                if ((rawMap[i][0] & FLAG_EAST) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][j+1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][j+1];
                                }
                            }
                            break;

                        case 3: /* West */
                            if (j==0){
                                if ((rawMap[i][REGION_WIDTH-1] & FLAG_WEST) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][REGION_WIDTH-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][REGION_WIDTH-1];
                                }
                            }
                            else {
                                if ((rawMap[i][0] & FLAG_WEST) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][j-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][j-1];
                                }
                            }
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                rawMap[i][j] |= rawMapMask[i][j];
            }
        }
        /**********************************************************************/
        /* Add some islands                                                   */
        /**********************************************************************/
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                if((rawMap[i][j]&FLAG_MOUNTAIN)&&!(rand()%1024)){
                    rawMap[i][j] |= (FLAG_LAND + FLAG_COASTAL);
                }
                if (!(rand()%((REGION_WIDTH*REGION_HEIGHT)/2))){
                    rawMap[i][j] |= (FLAG_LAND + FLAG_COASTAL);
                }
            }
        }
    }

    /**********************************************************************/
    /* Increase Mountains                                                 */
    /**********************************************************************/
    printf("Enlarging Mountains...\n");
    loopAmount = 16 + rand()%4;
    for (int loop = 0; loop < loopAmount; ++loop){
        memset(rawMapMask, '\0', sizeof(uint32_t)*REGION_WIDTH*REGION_HEIGHT);
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                if (!(rand()%4) && !(rawMap[i][j]&(FLAG_LAND+FLAG_MOUNTAIN))){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                if((rawMap[i][overBorderLoc] & FLAG_SOUTH) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][overBorderLoc];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][overBorderLoc];
                                }
                            }
                            else {
                                if((rawMap[i-1][j] & FLAG_NORTH) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i-1][j];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i-1][j];
                                }
                            }
                            break;

                        case 1: /* South  */
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                if((rawMap[i][overBorderLoc] & FLAG_NORTH) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][overBorderLoc];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][overBorderLoc];
                                }
                            }
                            else {
                                if((rawMap[i+1][j] & FLAG_SOUTH) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i+1][j];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i+1][j];
                                }
                            }
                            break;

                        case 2: /* East */
                            if (j==REGION_WIDTH-1){
                                if ((rawMap[i][0] & FLAG_EAST) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][0];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][0];
                                }
                            }
                            else {
                                if ((rawMap[i][0] & FLAG_EAST) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][j+1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][j+1];
                                }
                            }
                            break;

                        case 3: /* West */
                            if (j==0){
                                if ((rawMap[i][REGION_WIDTH-1] & FLAG_WEST) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][REGION_WIDTH-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][REGION_WIDTH-1];
                                }
                            }
                            else {
                                if ((rawMap[i][0] & FLAG_WEST) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][j-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][j-1];
                                }
                            }
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                rawMap[i][j] |= rawMapMask[i][j];
            }
        }
    }
    /**********************************************************************/
    /* Set random lakes                                                   */
    /**********************************************************************/
    printf("Adding some random lakes...\n");
    for (int i = 0; i < (REGION_HEIGHT*REGION_WIDTH)/1024; ++i){
        rawMap[rand()%REGION_HEIGHT][rand()%REGION_WIDTH] &= 0x7FFFFFFF;
    }
    loopAmount = 1;//4 + rand()%4;
    for (int h; h < loopAmount; ++h){
        for (int i = 0; i < REGION_HEIGHT; ++i){
                for (int j = 0; j < REGION_WIDTH; ++j){
                    rawMapMask[i][j] = rawMap[i][j];
                }
            }
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                if ((!(rawMap[i][j]&FLAG_LAND)) && (!(rand()%4))){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                rawMapMask[i][overBorderLoc] &= 0x7FFFFFFF;

                            }
                            else {
                                rawMapMask[i-1][j] &= 0x7FFFFFFF;
                            }
                            break;

                        case 1: /* South  */
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                                rawMapMask[i][overBorderLoc] &= 0x7FFFFFFF;
                            }
                            else {
                                rawMapMask[i+1][j] &= 0x7FFFFFFF;
                            }
                            break;

                        case 2: /* East */
                            if (j==REGION_WIDTH-1){
                                rawMapMask[i][0] &= 0x7FFFFFFF;
                            }
                            else {
                                rawMapMask[i][j+1] &= 0x7FFFFFFF;
                            }
                            break;

                        case 3: /* West */
                            if (j==0){
                                rawMapMask[i][REGION_WIDTH-1] &= 0x7FFFFFFF;
                            }
                            else {
                                rawMapMask[i][j-1] &= 0x7FFFFFFF;
                            }
                            break;
                    }
                }
            }
            for (int i = 0; i < REGION_HEIGHT; ++i){
                for (int j = 0; j < REGION_WIDTH; ++j){
                    rawMap[i][j] = rawMapMask[i][j];
                }
            }
        }
    }
    /**********************************************************************/
    /* Set coast tiles                                                    */
    /**********************************************************************/
    printf("Marking costal files...\n");
    for (int i = 0; i < REGION_HEIGHT; ++i){
        for (int j = 0; j < REGION_WIDTH; ++j){
            if (i == 0){
                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                if((!(rawMap[i][overBorderLoc] & FLAG_LAND) || !(rawMap[i+1][j] & FLAG_LAND) || !(rawMap[i][j+1] & FLAG_LAND) || !(rawMap[i][j-1] & FLAG_LAND) || !(rawMap[i+1][j+1] & FLAG_LAND) || !(rawMap[i][overBorderLoc + 1] & FLAG_LAND) || !(rawMap[i+1][j-1] & FLAG_LAND) || !(rawMap[i][overBorderLoc - 1] & FLAG_LAND)) 
                   && (rawMap[i][j] & FLAG_LAND)){
                    rawMap[i][j] |= 1;
                }
            }
            if (i == REGION_HEIGHT-1){
                overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                if((!(rawMap[i][overBorderLoc] & FLAG_LAND) || !(rawMap[i-1][j] & FLAG_LAND) || !(rawMap[i][j+1] & FLAG_LAND) || !(rawMap[i][j-1] & FLAG_LAND) || !(rawMap[i-1][j+1] & FLAG_LAND) || !(rawMap[i][overBorderLoc + 1] & FLAG_LAND) || !(rawMap[i-1][j-1] & FLAG_LAND) || !(rawMap[i][overBorderLoc - 1] & FLAG_LAND)) 
                   && (rawMap[i][j] & FLAG_LAND)){
                    rawMap[i][j] |= 1;
                }
            }
            else if (j == 0){
                if((!(rawMap[i+1][j] & FLAG_LAND) || !(rawMap[i-1][j] & FLAG_LAND) || !(rawMap[i][j+1] & FLAG_LAND) || !(rawMap[i][REGION_WIDTH-1] & FLAG_LAND) || !(rawMap[i+1][j+1] & FLAG_LAND) || !(rawMap[i-1][j+1] & FLAG_LAND) || !(rawMap[i+1][REGION_WIDTH-1] & FLAG_LAND) || !(rawMap[i-1][REGION_WIDTH-1] & FLAG_LAND)) 
                   && (rawMap[i][j] & FLAG_LAND)){
                    rawMap[i][j] |= 1;
                }
            }
            else if (j == REGION_WIDTH-1){
                if((!(rawMap[i+1][j] & FLAG_LAND) || !(rawMap[i-1][j] & FLAG_LAND) || !(rawMap[i][0] & FLAG_LAND) || !(rawMap[i][j-1] & FLAG_LAND) || !(rawMap[i+1][0] & FLAG_LAND) || !(rawMap[i-1][0] & FLAG_LAND) || !(rawMap[i+1][j-1] & FLAG_LAND) || !(rawMap[i-1][j-1] & FLAG_LAND)) 
                   && (rawMap[i][j] & FLAG_LAND)){
                    rawMap[i][j] |= 1;
                }
            }
            else{
               if((!(rawMap[i+1][j] & FLAG_LAND) || !(rawMap[i-1][j] & FLAG_LAND) || !(rawMap[i+1][j+1] & FLAG_LAND) || !(rawMap[i-1][j+1] & FLAG_LAND) || !(rawMap[i+1][j-1] & FLAG_LAND) || !(rawMap[i-1][j-1] & FLAG_LAND) || !(rawMap[i][j+1] & FLAG_LAND) || !(rawMap[i][j-1] & FLAG_LAND)) 
               && (rawMap[i][j] & FLAG_LAND)){
                    rawMap[i][j] |= 1;
                } 
            }
        }
    }
    /**********************************************************************/
    /* Set initial temperature                                            */
    /**********************************************************************/
    /* Basic way to set temperatures                                      */
    /**********************************************************************/
    printf("Determining temperatures...\n");
    for (int i = 0; i < REGION_HEIGHT; ++i){
        for (int j = 0; j < REGION_HEIGHT; ++j){
            if ((i <= REGION_HEIGHT/8)|| (i > (REGION_HEIGHT/8) * 7)){
                rawMap[i][j] |= FLAG_TEMP_ARTIC;
                if(!(rawMap[i][j]&FLAG_LAND) && ((i > (REGION_HEIGHT/16+REGION_HEIGHT/32))&&(i < (((REGION_HEIGHT/8) * 7)+(REGION_HEIGHT/32))))){/* If water warmer */
                    rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                    rawMap[i][j] |= FLAG_TEMP_SUBARTIC;
                }
            }
            else if ((i <= (REGION_HEIGHT/8)*2) || (i > (REGION_HEIGHT/8) *6)){
                if(rawMap[i][j]&FLAG_MOUNTAIN){/* If mountain colder */
                    rawMap[i][j] |= FLAG_TEMP_ARTIC;
                }
                else {
                    rawMap[i][j] |= FLAG_TEMP_SUBARTIC;
                }
                if((!(rawMap[i][j]&FLAG_LAND)) && ((i >=((REGION_HEIGHT/8) + REGION_HEIGHT/16 + REGION_HEIGHT/32)) && (i < (((REGION_HEIGHT/8) * 6) + REGION_HEIGHT/32)))){/* If water warmer */
                    rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                    rawMap[i][j] |= FLAG_TEMP_TEMPERATE;
                }
            }
            else if ((i <= (REGION_HEIGHT/8)*3) || (i > (REGION_HEIGHT/8) * 5 - REGION_HEIGHT/64)){
                if(rawMap[i][j]&FLAG_MOUNTAIN){/* If mountain colder */
                    rawMap[i][j] |= FLAG_TEMP_SUBARTIC;
                }
                else{
                    rawMap[i][j] |= FLAG_TEMP_TEMPERATE;
                }
            }
            else if (i <= (REGION_HEIGHT/8)*5+REGION_HEIGHT/64){/* If mountain colder */
                if(rawMap[i][j]&FLAG_MOUNTAIN){
                    rawMap[i][j] |= FLAG_TEMP_TEMPERATE;
                }
                else {
                    rawMap[i][j] |= FLAG_TEMP_TROPICAL;
                }
                if(!(rawMap[i][j]&FLAG_LAND)){/* If water colder */
                    rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                    rawMap[i][j] |= FLAG_TEMP_TEMPERATE;
                }
            }
        }
    }
    loopAmount = 4;
    for (int h = 0; h < loopAmount; ++h){
        for (int i = 1; i < REGION_HEIGHT-1; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                switch(rand()%4){
                    case 0: /* North */
                        if (i==0){
                            overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) <  (rawMap[i][overBorderLoc]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i][overBorderLoc]&FLAG_TEMP_TROPICAL) );
                            }
                        }
                        else {
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) < (rawMap[i-1][j]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i-1][j]&FLAG_TEMP_TROPICAL) );
                            }
                        }
                        break;
                    case 1: /* South  */
                        if (i==REGION_HEIGHT-1){
                            overBorderLoc = (j-REGION_WIDTH/2 > 0) ? j-REGION_WIDTH/2 : j+REGION_WIDTH/2;
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) < (rawMap[i][overBorderLoc]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i][overBorderLoc]&FLAG_TEMP_TROPICAL) );
                            }
                        }
                        else {
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) < (rawMap[i+1][j]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i+1][j]&FLAG_TEMP_TROPICAL) );
                            }
                        }
                        break;
                    case 2: /* East */
                        if (j==REGION_WIDTH-1){
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) < (rawMap[i][0]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i][0]&FLAG_TEMP_TROPICAL) );
                            }
                        }
                        else {
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) < (rawMap[i][j+1]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i][j+1]&FLAG_TEMP_TROPICAL) );
                            }
                        }
                        break;
                    case 3: /* West */
                        if (j==0){
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) < (rawMap[i][REGION_WIDTH-1]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i][REGION_WIDTH-1]&FLAG_TEMP_TROPICAL) );
                            }
                        }
                        else {
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) < (rawMap[i][j-1]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i][j-1]&FLAG_TEMP_TROPICAL) );
                            }
                        }
                        break;
                }
            }
        }
    }
    /* Smooth out temperatures with a little bit of randomness */
    /**********************************************************************/
    /* Set initial moisture                                               */
    /**********************************************************************/
    printf("Setting initial moisture...\n");
    for (int i = 0; i < REGION_HEIGHT; ++i){
        for (int j = 0; j < REGION_WIDTH; ++j){
            if (!(rawMap[i][j] & FLAG_LAND)){
                rawMap[i][j] |= 0x300000; /* Set moisture to four */
            }
        }
    }
    //#endif
    /********/
    /* Temp */
    uint16_t settlementNumber = 0;
    uint8_t hasSettlement = 0; /* CLEAN THIS UP YOU LAZY PERSON */
    uint8_t digitPlaced = 0;
    uint16_t cityDetails[2048];
    for (int i = 0; i < REGION_HEIGHT; ++i){
        for (int j = 0; j < REGION_WIDTH*2; ++j){
            /* Possibly replace with three digits of Hex, sould lost one less tile */
            if (digitPlaced >= 4){
                digitPlaced = 0;
            }
            if (!(i%8 || (((j+1)/2)+4)%16) || !((i+5)%8 || (((j+1)/2)+12)%16) ){ /* Simple City Placement DIGIT 0, DIGIT 1 UPDATE ME */
                if(rawMap[i][((j+1)/2)]&FLAG_LAND){/* If land */
                    hasSettlement = 1;
                    cityDetails[settlementNumber] = rawMap[i][(j+1)/2] & 0xFFFF;
                }
                if ((j%2) && hasSettlement){
                    fprintf(regionFile, "%d", (settlementNumber/1000)%10);
                    digitPlaced += 1;
                }
            }
            else if (hasSettlement){/* Simple City Placement DIGIT 3 */
                if(digitPlaced == 1){
                    fprintf(regionFile, "%d", (settlementNumber/100)%10);
                    digitPlaced += 1;
                }
                else if(digitPlaced == 2){
                    fprintf(regionFile, "%d", (settlementNumber/10)%10);
                    digitPlaced += 1;
                }
                else{
                    fprintf(regionFile, "%d", (settlementNumber%10));
                    digitPlaced = 0;
                    settlementNumber +=1;
                    hasSettlement = 0;
                }
            }

            if ((j%2)&&(digitPlaced<=0)){
                if ((rawMap[i][j/2]&FLAG_LAND)&&(rawMap[i][j/2]&FLAG_MOUNTAIN)){/* Mountain */
                    fprintf(regionFile, "%s","Δ");
                }
                else if (rawMap[i][j/2]&FLAG_LAND){ /* Default Land */
                    if ((rawMap[i][j/2]&FLAG_TEMP_TROPICAL) == FLAG_TEMP_TROPICAL){ /* Tropical Temperatures */
                        fprintf(regionFile, "%s","±");
                    }
                    else if (rawMap[i][j/2]&FLAG_TEMP_TEMPERATE){ /* Temperate Temperatures */
                        fprintf(regionFile, "%s","~");
                    }
                    else if (rawMap[i][j/2]&FLAG_TEMP_SUBARTIC){ /* Subartic Temperatures */
                        fprintf(regionFile, "%s","†");
                    }
                    else { /* Artic Temperatures */
                        fprintf(regionFile, "%s","ʭ");
                    }
                }
                else{ /* Water */
                    fprintf(regionFile, "%s","▓");
                }
            }
            else if (digitPlaced<=0){
                fprintf(regionFile, "%s"," ");
            }
        }
        fprintf(regionFile, "\n");
    }
    printf("Finishing World Map...\n");
#if 0
    /* Alternitively make a list of seeds for the srand(). If we call the same */
    /* seed we always get the same result with all our rands. This can be used */
    /* to generate a queried settlement on demand, and have it always be the   */
    /* same. We would also need to include pop and flags                       */
    /* 8 bit for pop, 16 for flags, 32 for random seed                         */ 
    fclose(regionFile);
    printf("Generating Settlements...");
    for (int i = 0; i < settlementNumber; ++i){
        regionFile = fopen(filename, "a+");
        fprintf(regionFile, "SETTLEMENT %04d\n",i);
        fclose(regionFile);
        printf("SETTLEMENT %04d\n", i);
        settlementGen(filename, rand()%100, cityDetails[i]);
    }
#endif
    printf("Finished Generating World...\n");
    return 0;
}