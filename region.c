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
                        case 0: //North
                            if (i==0){
                                overBorderLoc = (j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2;
                                rawMapMask[i][j] = (rawMap[i][overBorderLoc] & (0xA<<16)) ? rawMap[i][overBorderLoc]  ^ (0xA<<16) : rawMap[i][overBorderLoc];
                            }
                            else {
                                rawMapMask[i][j] = rawMap[i-1][j];
                            }
                            if (rawMapMask[i][j] != 0){
                                ++tileAmount;
                            }
                            break;
                        case 1: //South
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2;
                                rawMapMask[i][j] = (rawMap[i][overBorderLoc] & (0xA<<16)) ? rawMap[i][overBorderLoc]  ^ (0xA<<16) : rawMap[i][overBorderLoc];
                            }
                            else {
                                rawMapMask[i][j] = rawMap[i+1][j];
                            }
                            if (rawMapMask[i][j] != 0){
                                ++tileAmount;
                            }
                            break;
                        case 2: //East
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
                        case 3: //West
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
/*      Water |       .       |       .       |   .                   */
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
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look north */
                        if ((rawMap[i-1][j]>>17)&1){ /* if south land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    if (i == REGION_HEIGHT-1){ /* look south */
                        if ((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>17)&1){ /* if south land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look south */
                        if ((rawMap[i+1][j]>>19)&1){ /* if north land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    if (j == 0){ /* look west */
                        if (!((rawMap[i][REGION_WIDTH-1]>>16)&1)){ /* if not west land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look west */
                        if (!((rawMap[i][j-1]>>16)&1)){ /* if not west land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    break;
                case 2: /* tile is south */
                    if (j == REGION_WIDTH-1){ /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    if (i == REGION_HEIGHT-1){ /* look south */
                        if (!((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>19)&1)){ /* if not north land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look south */
                        if (!((rawMap[i+1][j]>>17)&1)){ /* if not south land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    if (j == 0){ /* look west */
                        if ((rawMap[i][REGION_WIDTH-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look west */
                        if ((rawMap[i][j-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    break;

                case 4: /* tile is east */
                    if (i == 0){ /* look north */
                        if ((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>19)&1){ /* if north land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look north */
                        if ((rawMap[i-1][j]>>17)&1){ /* if south land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    if (i == REGION_HEIGHT-1){ /* look south */
                        if ((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>17)&1){ /* if south land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look south */
                        if ((rawMap[i+1][j]>>19)&1){ /* if north land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    if (j == REGION_WIDTH-1){ /* look east */
                        if (!((rawMap[i][0]>>18)&1)){ /* if not east land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look east */
                        if (!((rawMap[i][j+1]>>18)&1)){ /* if not east land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    break;
                case 8: /* tile is north */
                    if (j == REGION_WIDTH-1){ /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    if (i == 0){ /* look north */
                        if (!((rawMap[i][(j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2]>>17)&1)){ /* if not south land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look north */
                        if (!((rawMap[i-1][j]>>19)&1)){ /* if not north land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    if (j == 0){ /* look west */
                        if ((rawMap[i][REGION_WIDTH-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    else { /* look west */
                        if ((rawMap[i][j-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= 0x2;
                        }
                    }
                    break;
            }
        }
    }
    printf("Placing land seed...\n");
    uint8_t landSeedAmount = 8 + rand()%4;
    uint16_t dispersalRange = 64;
    for (int i = 0; i < landSeedAmount; ++i){
        randXgroup = (rand()%(REGION_WIDTH-dispersalRange*2))+dispersalRange;
        randYgroup = (rand()%(REGION_HEIGHT-dispersalRange*2))+dispersalRange;
        loopAmount = rand()%8 + 8;
        for (int j = 0; j < loopAmount; ++j){
            randX = randYgroup + rand()%dispersalRange - dispersalRange/2;
            randY = randXgroup + rand()%dispersalRange - dispersalRange/2;
            rawMap[randY][randX] |= 0x80000000;
        }


    }
    printf ("Blobbing land...\n");
    uint16_t landLoopAmount = 256 + rand()%64;
    for (int h = 0; h < landLoopAmount; ++h){
        memset(rawMapMask, '\0', sizeof(uint32_t)*REGION_WIDTH*REGION_HEIGHT);
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                if (!(rand()%4) && (rawMap[i][j] & 0x80000000)){
                    uint8_t landBias;
                    landBias = rand()%6;
                    if (landBias > 3){
                        landBias = ((rawMap[i][j] >> 16) & 0xF);
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
                        case 0: //North
                            if (i==0){
                                overBorderLoc = (j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2;
                                rawMapMask[i][overBorderLoc] |= 0x80000000;
                            }
                            else {
                                rawMapMask[i-1][j] |= 0x80000000;
                            }
                            break;
                        case 1: //South
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2;
                                rawMapMask[i][overBorderLoc] = 0x80000000;
                            }
                            else {
                                rawMapMask[i+1][j] |= 0x80000000;
                            }
                            break;
                        case 2: //East
                            if (j==REGION_WIDTH-1){
                                rawMapMask[i][0] |= 0x80000000;
                            }
                            else {
                                rawMapMask[i][j+1] |= 0x80000000;
                            }
                            break;
                        case 3: //West
                            if (j==0){
                                rawMapMask[i][REGION_WIDTH-1] |= 0x80000000;
                            }
                            else {
                                rawMapMask[i][j-1] |= 0x80000000;
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
    loopAmount = (REGION_WIDTH+REGION_HEIGHT)/32 + rand()%((REGION_WIDTH+REGION_HEIGHT)/128);
    for (int loop = 0; loop < loopAmount; ++loop){
        memset(rawMapMask, '\0', sizeof(uint32_t)*REGION_WIDTH*REGION_HEIGHT);
        for (int i = 0; i < REGION_HEIGHT; ++i){
            for (int j = 0; j < REGION_WIDTH; ++j){
                if (!(rand()%4) && !(rawMap[i][j]&0x80000000)){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2;
                                if((rawMap[i][overBorderLoc] & 0x2) != 0){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][overBorderLoc];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][overBorderLoc];
                                }
                            }
                            else {
                                if((rawMap[i-1][j] & 0x8) != 0){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i-1][j];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i-1][j];
                                }
                            }
                            break;

                        case 1: /* South  */
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2;
                                if((rawMap[i][overBorderLoc] & 0x8) != 0){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][overBorderLoc];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][overBorderLoc];
                                }
                            }
                            else {
                                if((rawMap[i+1][j] & 0x2) != 0){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i+1][j];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i+1][j];
                                }
                            }
                            break;

                        case 2: /* East */
                            if (j==REGION_WIDTH-1){
                                if ((rawMap[i][0] & 0x4) != 0){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][0];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][0];
                                }
                            }
                            else {
                                if ((rawMap[i][0] & 0x4) != 0){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][j+1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][j+1];
                                }
                            }
                            break;

                        case 3: /* West */
                            if (j==0){
                                if ((rawMap[i][REGION_WIDTH-1] & 0x1) != 0){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][REGION_WIDTH-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][REGION_WIDTH-1];
                                }
                            }
                            else {
                                if ((rawMap[i][0] & 0x1) != 0){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][j-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x80000000 & rawMap[i][j-1];
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
                if((rawMap[i][j]&0x2)&&!(rand()%1024)){
                    rawMap[i][j] |= 0x80000001;
                }
                if (!(rand()%((REGION_WIDTH*REGION_HEIGHT)))){
                    rawMap[i][j] |= 0x80000001;
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
                if (!(rand()%4) && !(rawMap[i][j]&0x8000002)){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2;
                                if((rawMap[i][overBorderLoc] & 0x2) != 0){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][overBorderLoc];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][overBorderLoc];
                                }
                            }
                            else {
                                if((rawMap[i-1][j] & 0x8) != 0){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i-1][j];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i-1][j];
                                }
                            }
                            break;

                        case 1: /* South  */
                            if (i==REGION_HEIGHT-1){
                                overBorderLoc = (j-REGION_HEIGHT/2 > 0) ? j-REGION_HEIGHT/2 : j+REGION_HEIGHT/2;
                                if((rawMap[i][overBorderLoc] & 0x8) != 0){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][overBorderLoc];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][overBorderLoc];
                                }
                            }
                            else {
                                if((rawMap[i+1][j] & 0x2) != 0){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i+1][j];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i+1][j];
                                }
                            }
                            break;

                        case 2: /* East */
                            if (j==REGION_WIDTH-1){
                                if ((rawMap[i][0] & 0x4) != 0){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][0];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][0];
                                }
                            }
                            else {
                                if ((rawMap[i][0] & 0x4) != 0){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][j+1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][j+1];
                                }
                            }
                            break;

                        case 3: /* West */
                            if (j==0){
                                if ((rawMap[i][REGION_WIDTH-1] & 0x1) != 0){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][REGION_WIDTH-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][REGION_WIDTH-1];
                                }
                            }
                            else {
                                if ((rawMap[i][0] & 0x1) != 0){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][j-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= 0x2 & rawMap[i][j-1];
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
    /********/
    /* Temp */
    for (int i = 0; i < REGION_HEIGHT; ++i){
        for (int j = 0; j < REGION_WIDTH; ++j){
            
            if ((rawMap[i][j]&0x80000000)&&(rawMap[i][j]&0x2)){
                fprintf(regionFile, "%2s","M");
            }
            else if (rawMap[i][j]&0x80000000){
                fprintf(regionFile, "%2s","*");
            }
            else{
                fprintf(regionFile, "%2s",".");
            }
        }
        fprintf(regionFile, "\n");
    }
    printf("Closing file...\n");
    fclose(regionFile);
    return 0;
}