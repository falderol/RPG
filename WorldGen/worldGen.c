#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "settlementGen.h"
#include "flagDefines.h"
#include "mapKey.h"
#include "worldGen.h"
#include "../Utilities/utilities.h"

#define WORLD_WIDTH 512
#define WORLD_HEIGHT 512

void worldCommandReminder(){
    printf("worldGen <filename.txt>\n");
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
/* ----|-------------|----------------------------------------------- */
/*  00 | Costal      | When a water tile meets a land tile            */
/*  01 | Mountain    | Initial plate collisions and surrounding tiles */
/*  02 | Agriculture | Settlement in Farming Biome                    */
/*  03 | Forest      | TBD - Something to do with weather             */
/* ----|-------------|----------------------------------------------- */
/*  04 | Commerce    | TBD                                            */
/*  05 | Frontier    | TBD - Something to do with nearby settlements? */
/*  06 | Industrial  | Resources and Town Level Pop                   */
/*  07 | Rural       | Settlement with village level pop in 4 tile    */
/*     |             | radius                                         */
/* ----|-------------|----------------------------------------------- */
/*  08 | Urban       | Settlement with city level pop in 4 tile radius*/
/*  09 | Exotic      | Randomly blobbed on the map                    */
/*  10 | Pious       | Randomly blobbed                               */
/*  11 | Magical     | rand is called for 0.01*mapHeigh*mapWidth times*/
/* ----|-------------|----------------------------------------------- */
/*  12 | TBD         | unassigned                                     */
/*  13 | TBD         | unassigned                                     */
/*  14 | Firearms    | Optional flag if using firearms                */
/*  15 | Invalid     | Marks the tile as invalid                      */
/* ----|-------------|----------------------------------------------- */
/*  16 | West        | Randomly placed initial plate, then blobbed    */
/*  17 | South       | Randomly placed initial plate, then blobbed    */
/*  18 | East        | Randomly placed initial plate, then blobbed    */
/*  19 | North       | Randomly placed initial plate, then blobbed    */
/* ----|-------------|----------------------------------------------- */
/*  20 | Moisture    | Dry, Mid, Wet, invalid                         */
/*  21 | Moisture    |                                                */
/*  22 | Temperature | Tropical, temperate, subartic, artic           */
/*  23 | Temperature |                                                */
/* ----|-------------|----------------------------------------------- */
/*  24 | Height      | Below, at, above, invalid                      */
/*  25 | Height      |                                                */
/*  26 | TBD         | unassigned                                     */
/*  27 | TBD         | unassigned                                     */
/* ----|-------------|----------------------------------------------- */
/*  29 | TBD         | unassigned                                     */
/*  28 | TBD         | unassigned                                     */
/*  30 | TBD         | unassigned                                     */
/*  31 | Land        | Initialy from plate collisions, then blobbed   */
/* ----|-------------|----------------------------------------------- */
/*                                                                    */
/**********************************************************************/
void worldGen(char * filename){
    printf ("Storing Region in %s\n", filename);
    FILE * worldFile;
    worldFile = fopen(filename, "w+");
    uint32_t rawMap[WORLD_HEIGHT][WORLD_WIDTH];
    memset(rawMap, '\0', sizeof(uint32_t)*WORLD_WIDTH*WORLD_HEIGHT);
    uint32_t rawMapMask[WORLD_HEIGHT][WORLD_WIDTH];
    memset(rawMapMask, '\0', sizeof(uint32_t)*WORLD_WIDTH*WORLD_HEIGHT);
    uint8_t plateAmount = 20+rand()%10;
    uint16_t randY;
    uint16_t randX;
    uint16_t randXgroup;
    uint16_t randYgroup;
    uint32_t loopAmount;
    printf("Randomly Seeding Plates\n");
    for (int i = 0; i < plateAmount; ++i){
        randX = rand()%WORLD_WIDTH;
        randY = rand()%WORLD_HEIGHT;
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
    printf("Blobbing Plates\n");
    uint32_t tileAmount = 0;
    uint16_t overBorderLoc = 0;
    while (tileAmount < (WORLD_HEIGHT * WORLD_WIDTH)-plateAmount){
        memset(rawMapMask, '\0', sizeof(uint32_t)*WORLD_WIDTH*WORLD_HEIGHT);
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                if (!(rand()%4) && (rawMap[i][j] == 0)){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
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
                            if (i==WORLD_HEIGHT-1){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
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
                            if (j==WORLD_WIDTH-1){
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
                                rawMapMask[i][j] = rawMap[i][WORLD_WIDTH-1];
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
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
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
/*  Cold | Tagia     | Tagia     | Forest     | Bog                   */
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
    
    printf("Placing Initial Mountains\n");
    for(int i = 0; i < WORLD_HEIGHT; ++i){
        for(int j = 0; j < WORLD_WIDTH; ++j){
            switch(rawMap[i][j]>>16){
                case 1 : /* tile is west */
                    if (i == 0){ /* look north */
                        if ((rawMap[i][(j-WORLD_HEIGHT/2 > 0) ? j-WORLD_HEIGHT/2 : j+WORLD_HEIGHT/2]>>19)&1){ /* if north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look north */
                        if ((rawMap[i-1][j]>>17)&1){ /* if south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    if (i == WORLD_HEIGHT-1){ /* look south */
                        if ((rawMap[i][(j-WORLD_HEIGHT/2 > 0) ? j-WORLD_HEIGHT/2 : j+WORLD_HEIGHT/2]>>17)&1){ /* if south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look south */
                        if ((rawMap[i+1][j]>>19)&1){ /* if north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    if (j == 0){ /* look west */
                        if (!((rawMap[i][WORLD_WIDTH-1]>>16)&1)){ /* if not west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look west */
                        if (!((rawMap[i][j-1]>>16)&1)){ /* if not west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    break;
                case 2: /* tile is south */
                    if (j == WORLD_WIDTH-1){ /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    if (i == WORLD_HEIGHT-1){ /* look south */
                        if (!((rawMap[i][(j-WORLD_HEIGHT/2 > 0) ? j-WORLD_HEIGHT/2 : j+WORLD_HEIGHT/2]>>19)&1)){ /* if not north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look south */
                        if (!((rawMap[i+1][j]>>17)&1)){ /* if not south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    if (j == 0){ /* look west */
                        if ((rawMap[i][WORLD_WIDTH-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look west */
                        if ((rawMap[i][j-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    break;

                case 4: /* tile is east */
                    if (i == 0){ /* look north */
                        if ((rawMap[i][(j-WORLD_HEIGHT/2 > 0) ? j-WORLD_HEIGHT/2 : j+WORLD_HEIGHT/2]>>19)&1){ /* if north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look north */
                        if ((rawMap[i-1][j]>>17)&1){ /* if south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    if (i == WORLD_HEIGHT-1){ /* look south */
                        if ((rawMap[i][(j-WORLD_HEIGHT/2 > 0) ? j-WORLD_HEIGHT/2 : j+WORLD_HEIGHT/2]>>17)&1){ /* if south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look south */
                        if ((rawMap[i+1][j]>>19)&1){ /* if north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    if (j == WORLD_WIDTH-1){ /* look east */
                        if (!((rawMap[i][0]>>18)&1)){ /* if not east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look east */
                        if (!((rawMap[i][j+1]>>18)&1)){ /* if not east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    break;
                case 8: /* tile is north */
                    if (j == WORLD_WIDTH-1){ /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look east */
                        if ((rawMap[i][j+1]>>16)&1){ /* if west land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    if (i == 0){ /* look north */
                        if (!((rawMap[i][(j-WORLD_HEIGHT/2 > 0) ? j-WORLD_HEIGHT/2 : j+WORLD_HEIGHT/2]>>17)&1)){ /* if not south land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look north */
                        if (!((rawMap[i-1][j]>>19)&1)){ /* if not north land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    if (j == 0){ /* look west */
                        if ((rawMap[i][WORLD_WIDTH-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    else { /* look west */
                        if ((rawMap[i][j-1]>>18)&1){ /* if east land */
                            rawMap[i][j] |= FLAG_MOUNTAIN + FLAG_MOIST_MID;
                        }
                    }
                    break;
            }
        }
    }
    
    printf("Placing Land Seed\n");
    uint8_t landSeedAmount = 12 + rand()%8;
    uint16_t dispersalRange = 64;
    uint16_t numMisses;
    uint16_t toManyFails = dispersalRange*dispersalRange*2; /* Good change to try every tile in the 64 before it fails*/
    for (int i = 0; i < landSeedAmount; ++i){
        randXgroup = (rand()%(WORLD_WIDTH-dispersalRange*2))+dispersalRange;
        randYgroup = (rand()%(WORLD_HEIGHT-dispersalRange*2))+dispersalRange;
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
    
    printf ("Blobbing Land\n");
    uint16_t landLoopAmount = 640 + rand()%64;
    for (int h = 0; h < landLoopAmount; ++h){
        memset(rawMapMask, '\0', sizeof(uint32_t)*WORLD_WIDTH*WORLD_HEIGHT);
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                if (!(rand()%10) && (rawMap[i][j] & FLAG_LAND)){
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
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
                                rawMapMask[i][overBorderLoc] |= FLAG_LAND;
                            }
                            else {
                                rawMapMask[i-1][j] |= FLAG_LAND;
                            }
                            break;
                        case 1: /* South */
                            if (i==WORLD_HEIGHT-1){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
                                rawMapMask[i][overBorderLoc] = FLAG_LAND;
                            }
                            else {
                                rawMapMask[i+1][j] |= FLAG_LAND;
                            }
                            break;
                        case 2: /* East */
                            if (j==WORLD_WIDTH-1){
                                rawMapMask[i][0] |= FLAG_LAND;
                            }
                            else {
                                rawMapMask[i][j+1] |= FLAG_LAND;
                            }
                            break;
                        case 3: /* West */
                            if (j==0){
                                rawMapMask[i][WORLD_WIDTH-1] |= FLAG_LAND;
                            }
                            else {
                                rawMapMask[i][j-1] |= FLAG_LAND;
                            }
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                rawMap[i][j] |= rawMapMask[i][j];
            }
        }
    }
    
    printf("Fuzifying Coastal Areas\n");
    /**********************************************************************/
    /* Fuzzy Coast                                                        */
    /**********************************************************************/
    loopAmount = (WORLD_WIDTH+WORLD_HEIGHT)/24 + rand()%((WORLD_WIDTH+WORLD_HEIGHT)/128);
    for (int loop = 0; loop < loopAmount; ++loop){
        memset(rawMapMask, '\0', sizeof(uint32_t)*WORLD_WIDTH*WORLD_HEIGHT);
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                if (!(rand()%8) && !(rawMap[i][j]&FLAG_LAND)){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
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
                            if (i==WORLD_HEIGHT-1){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
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
                            if (j==WORLD_WIDTH-1){
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
                                if ((rawMap[i][WORLD_WIDTH-1] & FLAG_WEST) != 0){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][WORLD_WIDTH-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_LAND & rawMap[i][WORLD_WIDTH-1];
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
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                rawMap[i][j] |= rawMapMask[i][j];
            }
        }
        /**********************************************************************/
        /* Add some islands                                                   */
        /**********************************************************************/
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                if((rawMap[i][j]&FLAG_MOUNTAIN)&&!(rand()%2048)){
                    rawMap[i][j] |= (FLAG_LAND + FLAG_COASTAL);
                }
                if (!(rand()%((WORLD_WIDTH*WORLD_HEIGHT)/2))){
                    rawMap[i][j] |= (FLAG_LAND + FLAG_COASTAL);
                }
            }
        }
    }
    
    /**********************************************************************/
    /* Increase Mountains                                                 */
    /**********************************************************************/
    printf("Enlarging Mountains\n");
    loopAmount = 16 + rand()%4;
    for (int loop = 0; loop < loopAmount; ++loop){
        memset(rawMapMask, '\0', sizeof(uint32_t)*WORLD_WIDTH*WORLD_HEIGHT);
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                if (!(rand()%4) && !(rawMap[i][j]&(FLAG_LAND+FLAG_MOUNTAIN))){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
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
                            if (i==WORLD_HEIGHT-1){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
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
                            if (j==WORLD_WIDTH-1){
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
                                if ((rawMap[i][WORLD_WIDTH-1] & FLAG_WEST) != 0){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][WORLD_WIDTH-1];
                                }
                                else if (rand()%2){
                                    rawMapMask[i][j] |= FLAG_MOUNTAIN & rawMap[i][WORLD_WIDTH-1];
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
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                rawMap[i][j] |= rawMapMask[i][j];
            }
        }
    }
    /* Set Sea Moisture */
    printf("Setting Initial Sea Moisture\n");
    for (int i = 0; i < WORLD_HEIGHT; ++i){
        for (int j = 0; j < WORLD_WIDTH; ++j){
            rawMap[i][j] = (rawMap[i][j]&(FLAG_LAND)) ? rawMap[i][j] : (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) | FLAG_MOIST_VERYWET;
        }
    }
    /*General wind pattern*/
    /* 1/6 | South West   */
    /* 2/6 | North East   */
    /* 3/6 | South West   */
    /* 4/6 | North West   */
    /* 5/6 | South East   */
    /* 6/6 | North West   */
    printf("Setting Wind Moistness\n");
    /* FIXME Add Border handling */
    loopAmount = 256;
    for (int h = 0; h < loopAmount; ++h){
        for (int i = 1; i < WORLD_HEIGHT-1; ++i){
            printf("%d\n",i/(WORLD_HEIGHT/6));
            for (int j = 1; j < WORLD_WIDTH-1; ++j){
                if (rand()%3){
                    switch((i-1)/(WORLD_HEIGHT/6)){
                        case 0: /* Southwest */
                        case 2: /* Southwest */
                            if ((!(rawMap[i+1][j-1]&FLAG_MOIST_VERYWET)) && (!(rawMap[i+1][j-1]&FLAG_MOUNTAIN))){
                                if (rawMap[i][j]&FLAG_MOIST_VERYWET){
                                    if(rand()%((4-((rawMap[i][j]&FLAG_MOIST_VERYWET)>>20))*4)){
                                        rawMapMask[i+1][j-1] = rawMap[i][j]&FLAG_MOIST_VERYWET;
                                    }
                                    else{
                                        if (((rawMap[i][j]&FLAG_MOIST_VERYWET)>>20)>1){
                                            rawMapMask[i+1][j-1] = rawMap[i][j]-FLAG_MOIST_MID;
                                        }
                                    }
                                }
                            }
                            break;
                        case 1: /* Northeast */
                            if ((!(rawMap[i-1][j+1]&FLAG_MOIST_VERYWET)) && (!(rawMap[i-1][j+1]&FLAG_MOUNTAIN))){
                                if (rawMap[i][j]&FLAG_MOIST_VERYWET){
                                    if(rand()%((4-((rawMap[i][j]&FLAG_MOIST_VERYWET)>>20))*4)){
                                        rawMapMask[i-1][j+1] = rawMap[i][j]&FLAG_MOIST_VERYWET;
                                    }
                                    else{
                                        if (((rawMap[i][j]&FLAG_MOIST_VERYWET)>>20)>1){
                                            rawMapMask[i-1][j+1] = rawMap[i][j]-FLAG_MOIST_MID;
                                        }
                                    }
                                }
                            }
                             break;
                        case 4: /* Southeast */
                            if ((!(rawMap[i+1][j+1]&FLAG_MOIST_VERYWET)) && (!(rawMap[i+1][j+1]&FLAG_MOUNTAIN))){
                                if (rawMap[i][j]&FLAG_MOIST_VERYWET){
                                    if(rand()%((4-((rawMap[i][j]&FLAG_MOIST_VERYWET)>>20))*4)){
                                        rawMapMask[i+1][j+1] = rawMap[i][j]&FLAG_MOIST_VERYWET;
                                    }
                                    else{
                                        if (((rawMap[i][j]&FLAG_MOIST_VERYWET)>>20)>1){
                                            rawMapMask[i+1][j+1] = rawMap[i][j]-FLAG_MOIST_MID;
                                        }
                                    }
                                }
                            }
                            break;
                        case 3: /* Northwest */
                        case 5: /* Northwest */
                            if ((!(rawMap[i-1][j-1]&FLAG_MOIST_VERYWET)) && (!(rawMap[i-1][j-1]&FLAG_MOUNTAIN))){
                                if (rawMap[i][j]&FLAG_MOIST_VERYWET){
                                    if(rand()%((4-((rawMap[i][j]&FLAG_MOIST_VERYWET)>>20))*4)){
                                        rawMapMask[i-1][j-1] = rawMap[i][j]&FLAG_MOIST_VERYWET;
                                    }
                                    else{
                                        if (((rawMap[i][j]&FLAG_MOIST_VERYWET)>>20)>1){
                                            rawMapMask[i-1][j-1] = rawMap[i][j]-FLAG_MOIST_MID;
                                        }
                                    }
                                }
                            }
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < WORLD_HEIGHT; ++i){
                for (int j = 0; j < WORLD_WIDTH; ++j){
                    rawMap[i][j] |= rawMapMask[i][j];
                }
            }
    }
    /**********************************************************************/
    /* Set random lakes                                                   */
    /**********************************************************************/
    printf("Adding Random Lakes\n");
    for (int i = 0; i < (WORLD_HEIGHT*WORLD_WIDTH)/1024; ++i){
        randX = rand()%WORLD_HEIGHT;
        randY = rand()%WORLD_WIDTH;
        rawMap[randX][randY] = (rawMap[randX][randY]&(~(FLAG_LAND+FLAG_MOIST_VERYWET))) | FLAG_MOIST_VERYWET;
    }
    printf("Further Fuzifying Coast\n");
    loopAmount = 1 + rand()%2;
    for (int h; h < loopAmount; ++h){
        for (int i = 0; i < WORLD_HEIGHT; ++i){
                for (int j = 0; j < WORLD_WIDTH; ++j){
                    rawMapMask[i][j] = rawMap[i][j];
                }
            }
        for (int i = 0; i < WORLD_HEIGHT; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                if ((!(rawMap[i][j]&FLAG_LAND)) && (!(rand()%4))){
                    switch(rand()%4){
                        case 0: /* North */
                            if (i==0){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
                                rawMapMask[i][overBorderLoc] &= (~FLAG_LAND);
                            }
                            else {
                                rawMapMask[i-1][j] &= (~FLAG_LAND);
                            }
                            break;

                        case 1: /* South  */
                            if (i==WORLD_HEIGHT-1){
                                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
                                rawMapMask[i][overBorderLoc] &= (~FLAG_LAND);
                            }
                            else {
                                rawMapMask[i+1][j] &= (~FLAG_LAND);
                            }
                            break;

                        case 2: /* East */
                            if (j==WORLD_WIDTH-1){
                                rawMapMask[i][0] &= (~FLAG_LAND);
                            }
                            else {
                                rawMapMask[i][j+1] &= (~FLAG_LAND);
                            }
                            break;

                        case 3: /* West */
                            if (j==0){
                                rawMapMask[i][WORLD_WIDTH-1] &= (~FLAG_LAND);
                            }
                            else {
                                rawMapMask[i][j-1] &= (~FLAG_LAND);
                            }
                            break;
                    }
                }
            }
            for (int i = 0; i < WORLD_HEIGHT; ++i){
                for (int j = 0; j < WORLD_WIDTH; ++j){
                    rawMap[i][j] = rawMapMask[i][j];
                }
            }
        }
    }
    
    /**********************************************************************/
    /* Set coast tiles                                                    */
    /**********************************************************************/
    printf("Marking Coastal Tiles\n");
    for (int i = 0; i < WORLD_HEIGHT; ++i){
        for (int j = 0; j < WORLD_WIDTH; ++j){
            if (i == 0){
                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
                if((!(rawMap[i][overBorderLoc] & FLAG_LAND) || !(rawMap[i+1][j] & FLAG_LAND) || !(rawMap[i][j+1] & FLAG_LAND) || !(rawMap[i][j-1] & FLAG_LAND) || !(rawMap[i+1][j+1] & FLAG_LAND) || !(rawMap[i][overBorderLoc + 1] & FLAG_LAND) || !(rawMap[i+1][j-1] & FLAG_LAND) || !(rawMap[i][overBorderLoc - 1] & FLAG_LAND)) 
                   && (rawMap[i][j] & FLAG_LAND)){
                    rawMap[i][j] |= 1;
                }
            }
            if (i == WORLD_HEIGHT-1){
                overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
                if((!(rawMap[i][overBorderLoc] & FLAG_LAND) || !(rawMap[i-1][j] & FLAG_LAND) || !(rawMap[i][j+1] & FLAG_LAND) || !(rawMap[i][j-1] & FLAG_LAND) || !(rawMap[i-1][j+1] & FLAG_LAND) || !(rawMap[i][overBorderLoc + 1] & FLAG_LAND) || !(rawMap[i-1][j-1] & FLAG_LAND) || !(rawMap[i][overBorderLoc - 1] & FLAG_LAND)) 
                   && (rawMap[i][j] & FLAG_LAND)){
                    rawMap[i][j] |= 1;
                }
            }
            else if (j == 0){
                if((!(rawMap[i+1][j] & FLAG_LAND) || !(rawMap[i-1][j] & FLAG_LAND) || !(rawMap[i][j+1] & FLAG_LAND) || !(rawMap[i][WORLD_WIDTH-1] & FLAG_LAND) || !(rawMap[i+1][j+1] & FLAG_LAND) || !(rawMap[i-1][j+1] & FLAG_LAND) || !(rawMap[i+1][WORLD_WIDTH-1] & FLAG_LAND) || !(rawMap[i-1][WORLD_WIDTH-1] & FLAG_LAND)) 
                   && (rawMap[i][j] & FLAG_LAND)){
                    rawMap[i][j] |= 1;
                }
            }
            else if (j == WORLD_WIDTH-1){
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
    printf("Determining Temperatures\n");
    for (int i = 0; i < WORLD_HEIGHT; ++i){
        for (int j = 0; j < WORLD_HEIGHT; ++j){
            if ((i <= WORLD_HEIGHT/8)|| (i > (WORLD_HEIGHT/8) * 7)){
                rawMap[i][j] |= FLAG_TEMP_ARTIC;
                if(!(rawMap[i][j]&FLAG_LAND) && ((i > (WORLD_HEIGHT/16+WORLD_HEIGHT/32))&&(i < (((WORLD_HEIGHT/8) * 7)+(WORLD_HEIGHT/32))))){/* If water warmer */
                    rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                    rawMap[i][j] |= FLAG_TEMP_SUBARTIC;
                }
            }
            else if ((i <= (WORLD_HEIGHT/8)*2) || (i > (WORLD_HEIGHT/8) *6)){
                if(rawMap[i][j]&FLAG_MOUNTAIN){/* If mountain colder */
                    rawMap[i][j] |= FLAG_TEMP_ARTIC;
                }
                else {
                    rawMap[i][j] |= FLAG_TEMP_SUBARTIC;
                }
                if((!(rawMap[i][j]&FLAG_LAND)) && ((i >=((WORLD_HEIGHT/8) + WORLD_HEIGHT/16 + WORLD_HEIGHT/32)) && (i < (((WORLD_HEIGHT/8) * 6) + WORLD_HEIGHT/32)))){/* If water warmer */
                    rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                    rawMap[i][j] |= FLAG_TEMP_TEMPERATE;
                }
            }
            else if ((i <= (WORLD_HEIGHT/8)*3 + WORLD_HEIGHT/32) || (i > (WORLD_HEIGHT/8) * 5 - WORLD_HEIGHT/32)){
                if(rawMap[i][j]&FLAG_MOUNTAIN){/* If mountain colder */
                    rawMap[i][j] |= FLAG_TEMP_SUBARTIC;
                }
                else{
                    rawMap[i][j] |= FLAG_TEMP_TEMPERATE;
                }
            }
            else if (i <= (WORLD_HEIGHT/8)*5-WORLD_HEIGHT/32){/* If mountain colder */
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
    loopAmount = 16;
    for (int h = 0; h < loopAmount; ++h){
        for (int i = 1; i < WORLD_HEIGHT-1; ++i){
            for (int j = 0; j < WORLD_WIDTH; ++j){
                switch(rand()%16){
                    case 0: /* North */
                        if (i==0){
                            overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
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
                        if (i==WORLD_HEIGHT-1){
                            overBorderLoc = (j-WORLD_WIDTH/2 > 0) ? j-WORLD_WIDTH/2 : j+WORLD_WIDTH/2;
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
                        if (j==WORLD_WIDTH-1){
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
                            if (((rawMap[i][j]&FLAG_TEMP_TROPICAL) < (rawMap[i][WORLD_WIDTH-1]&FLAG_TEMP_TROPICAL)) && !(rawMap[i][j]&FLAG_MOUNTAIN)){
                                rawMap[i][j] &= (0xFFFFFFFF^FLAG_TEMP_TROPICAL);
                                rawMap[i][j] |= ((rawMap[i][WORLD_WIDTH-1]&FLAG_TEMP_TROPICAL) );
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
    /* Set moisture                                                       */
    /**********************************************************************/
    /* FIXME Add Border Handling                                          */
    loopAmount = 2 + rand()%4;
    for (int h = 0; h < loopAmount; ++h){
        for (int i = 1; i < WORLD_HEIGHT-1; ++i){
            for (int j = 1; j < WORLD_WIDTH-1; ++j){
                if (!(rawMap[i][j]&FLAG_MOIST_VERYWET)){
                    switch(rand()%10){
                        case 0:
                            rawMap[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i+1][j]&(FLAG_MOIST_VERYWET)); 
                            break;
                        case 1:
                            rawMap[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i+1][j+1]&(FLAG_MOIST_VERYWET)); 
                            break;
                        case 2:
                            rawMap[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i+1][j-1]&(FLAG_MOIST_VERYWET)); 
                            break;
                        case 3:
                            rawMap[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i-1][j]&(FLAG_MOIST_VERYWET));
                            break;
                        case 4:
                            rawMap[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i-1][j+1]&(FLAG_MOIST_VERYWET));
                            break;
                        case 5:
                            rawMap[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i-1][j-1]&(FLAG_MOIST_VERYWET));
                            break;
                        case 6:
                            rawMap[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i][j+1]&(FLAG_MOIST_VERYWET));
                            break;
                        case 7:
                            rawMap[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i][j-1]&(FLAG_MOIST_VERYWET));
                            break;
                        default:
                            break; 
                   }
                }
            }
        }
    }
    printf("Smoothing Moistness\n");
    loopAmount = 8+rand()%8;
    for (int h = 0; h < loopAmount; ++h){
        for (int i = 1; i < WORLD_HEIGHT-1; ++i){
            for (int j = 1; j < WORLD_WIDTH-1; ++j){
                switch(rand()%16){
                    case 0:
                        rawMapMask[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i+1][j]&(FLAG_MOIST_VERYWET)); 
                        break;
                    case 1:
                        rawMapMask[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i+1][j+1]&(FLAG_MOIST_VERYWET)); 
                        break;
                    case 2:
                        rawMapMask[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i+1][j-1]&(FLAG_MOIST_VERYWET)); 
                        break;
                    case 3:
                        rawMapMask[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i-1][j]&(FLAG_MOIST_VERYWET));
                        break;
                    case 4:
                        rawMapMask[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i-1][j+1]&(FLAG_MOIST_VERYWET));
                        break;
                    case 5:
                        rawMapMask[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i-1][j-1]&(FLAG_MOIST_VERYWET));
                        break;
                    case 6:
                        rawMapMask[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i][j+1]&(FLAG_MOIST_VERYWET));
                        break;
                    case 7:
                        rawMapMask[i][j] = (rawMap[i][j]&(~FLAG_MOIST_VERYWET)) + (rawMap[i][j-1]&(FLAG_MOIST_VERYWET));
                        break;
                    default:
                        rawMapMask[i][j] = rawMap[i][j];
                        break;
                }
            }
        }
        for (int i = 1; i < WORLD_HEIGHT-1; ++i){
            for (int j = 1; j < WORLD_WIDTH-1; ++j){
                rawMap[i][j] = rawMapMask[i][j];
            }
        }
    }
    /*****************************/
    /* Add flags                 */
    printf("Seeding Flags\n");
    for (int i = 1; i < WORLD_HEIGHT-1; ++i){
        for (int j = 1; j < WORLD_WIDTH-1; ++j){
            /* Set Forested Flag */
            rawMap[i][j] |= (((rawMap[i][j] & FLAG_MOIST_VERYWET) == FLAG_MOIST_WET) && (!(rawMap[i][j] & FLAG_TEMP_TROPICAL))) ? FLAG_FOREST : 0;
            rawMap[i][j] |= (((rawMap[i][j] & FLAG_MOIST_VERYWET) == FLAG_MOIST_VERYWET) && ((rawMap[i][j] & FLAG_TEMP_TROPICAL) == FLAG_TEMP_TROPICAL)) ? FLAG_FOREST : 0;
            /* Set Agriculture Flag */
            rawMap[i][j] |= (((rawMap[i][j] & FLAG_MOIST_VERYWET) == FLAG_MOIST_DRY) && ((rawMap[i][j] & FLAG_TEMP_TROPICAL) == FLAG_TEMP_TEMPERATE)) ? FLAG_AGRICULTURE : 0;
            rawMap[i][j] |= (((rawMap[i][j] & FLAG_MOIST_VERYWET) == FLAG_MOIST_MID) && ((rawMap[i][j] & FLAG_TEMP_TROPICAL) == FLAG_TEMP_TEMPERATE)) ? FLAG_AGRICULTURE : 0;
            rawMap[i][j] |= (((rawMap[i][j] & FLAG_MOIST_VERYWET) == FLAG_MOIST_MID) && ((rawMap[i][j] & FLAG_TEMP_TROPICAL) == FLAG_TEMP_TROPICAL)) ? FLAG_AGRICULTURE : 0;
            rawMap[i][j] |= (!(rand()%4) && ((rawMap[i][j] & FLAG_MOIST_VERYWET) == FLAG_MOIST_VERYWET) && ((rawMap[i][j] & FLAG_TEMP_TROPICAL) == FLAG_TEMP_TEMPERATE)) ? FLAG_AGRICULTURE : 0;
            /* Set Frontier Flag */
            rawMap[i][j] |= ((rawMap[i][j] & FLAG_TEMP_TROPICAL) == FLAG_TEMP_SUBARTIC) ? FLAG_FRONTIER : 0;
            rawMap[i][j] |= ((rawMap[i][j] & FLAG_TEMP_TROPICAL) == FLAG_TEMP_ARTIC) ? FLAG_FRONTIER : 0;
            /* Set Commerce Flag */
            rawMap[i][j] |= (((rawMap[i][j] & FLAG_COASTAL) && !(rand()%8)) || !(rand()%128)) ? FLAG_COMMERCE: 0;
            /* Seed Magical Flag */
            rawMap[i][j] |= (!(rand()%128)) ? FLAG_MAGICAL : 0;
            rawMap[i][j] |= (!(rand()%128) && (rawMap[i][j]&FLAG_LAND)) ? FLAG_MAGICAL : 0;
            /* Seed Pious Flag */
            rawMap[i][j] |= (!(rand()%128) && (rawMap[i][j]&FLAG_LAND)) ? FLAG_PIOUS : 0;
        }
    }
    
    /************/
    /* Make Map */
    printf("Making Map\n");
    uint16_t settlementNumber = 0;
    uint8_t hasSettlement = 0; /* CLEAN THIS UP YOU LAZY PERSON */
    uint8_t digitPlaced = 0;
    uint16_t cityDetails[2048];
    int8_t citySizes[2048];
    for (int i = 0; i < WORLD_HEIGHT; ++i){
        for (int j = 0; j < WORLD_WIDTH*2; ++j){
            /* Possibly replace with three digits of Hex, sould lost one less tile */
            if (digitPlaced >= 4){
                digitPlaced = 0;
            }
            if (!(i%8 || (((j+1)/2)+4)%16) || !((i+5)%8 || (((j+1)/2)+12)%16) ){ /* Simple City Placement DIGIT 0, DIGIT 1 UPDATE ME */
                if(rawMap[i][((j+1)/2)]&FLAG_LAND){/* If land */
                    hasSettlement = 1;
                    cityDetails[settlementNumber] = rawMap[i][(j+1)/2] & 0xFFFF | rawMap[i][(j+3)/2] & 0xFFFF | rawMap[i][(j-1)/2] & 0xFFFF | rawMap[i+1][(j+1)/2] & 0xFFFF | rawMap[i+1][(j+3)/2] & 0xFFFF | rawMap[i+1][(j-1)/2] & 0xFFFF | rawMap[i-1][(j+1)/2] & 0xFFFF | rawMap[i-1][(j+3)/2] & 0xFFFF | rawMap[i-1][(j-1)/2] & 0xFFFF; /* Flags of all areas withing 1 tile of settlement */
                    /* City Size Calculation */
                    citySizes[settlementNumber] = (rawMap[i][(j+1)/2] & FLAG_TEMP_TROPICAL)>>22;
                    if (citySizes[settlementNumber] == 3){
                        citySizes[settlementNumber] = onesCount16(cityDetails[settlementNumber] & FLAG_SETTLEMENT_SIZE)*3 + rand()%105 - 10;
                    }
                    else if (citySizes[settlementNumber] == 2){
                        citySizes[settlementNumber] = onesCount16(cityDetails[settlementNumber] & FLAG_SETTLEMENT_SIZE)*3 + rand()%105 - 2;
                    }
                    else if (citySizes[settlementNumber] == 1){
                        citySizes[settlementNumber] = onesCount16(cityDetails[settlementNumber] & FLAG_SETTLEMENT_SIZE)*3 + rand()%100 - 15;
                    }
                    else if (citySizes[settlementNumber] == 0){
                        citySizes[settlementNumber] = onesCount16(cityDetails[settlementNumber] & FLAG_SETTLEMENT_SIZE) + rand()%100 - 30;
                    }
                    else {
                        citySizes[settlementNumber] = onesCount16(cityDetails[settlementNumber] & FLAG_SETTLEMENT_SIZE) + rand()%100;
                    }
                }
                if ((j%2) && hasSettlement){
                    fprintf(worldFile, "%d", (settlementNumber/1000)%10);
                    digitPlaced += 1;
                }
            }
            else if (hasSettlement){/* Simple City Placement DIGIT 3 */
                if(digitPlaced == 1){
                    fprintf(worldFile, "%d", (settlementNumber/100)%10);
                    digitPlaced += 1;
                }
                else if(digitPlaced == 2){
                    fprintf(worldFile, "%d", (settlementNumber/10)%10);
                    digitPlaced += 1;
                }
                else{
                    fprintf(worldFile, "%d", (settlementNumber%10));
                    digitPlaced = 0;
                    settlementNumber +=1;
                    hasSettlement = 0;
                }
            }

            if ((j%2)&&(digitPlaced<=0)){
                if ((rawMap[i][j/2]&FLAG_LAND)&&(rawMap[i][j/2]&FLAG_MOUNTAIN)){/* Mountain */
                    fprintf(worldFile, "%s",MOUNTAIN);
                }
                else if (rawMap[i][j/2]&FLAG_LAND){ /* Default Land */
                    if ((rawMap[i][j/2]&FLAG_TEMP_TROPICAL) == FLAG_TEMP_TROPICAL){ /* Tropical Temperatures */
                        if((rawMap[i][j/2]&FLAG_MOIST_VERYWET) == FLAG_MOIST_VERYWET){ /* Mangrove */
                            fprintf(worldFile, "%s",MANGROVE);
                        }
                        else if (rawMap[i][j/2]&FLAG_MOIST_WET){ /* Rainforest */
                            fprintf(worldFile, "%s",RAINFOREST);
                        }
                        else if (rawMap[i][j/2]&FLAG_MOIST_MID){ /* SAVANNA */
                            fprintf(worldFile, "%s",SAVANNA);
                        }
                        else { /* Desert */
                            fprintf(worldFile, "%s",DESERT);
                        }
                    }
                    else if (rawMap[i][j/2]&FLAG_TEMP_TEMPERATE){ /* Temperate Temperatures */
                        if((rawMap[i][j/2]&FLAG_MOIST_VERYWET) == FLAG_MOIST_VERYWET){ /* Swamp */
                            fprintf(worldFile, "%s",SWAMP);
                        }
                        else if (rawMap[i][j/2]&FLAG_MOIST_WET){ /* Forest */
                            fprintf(worldFile, "%s",FOREST);
                        }
                        else if (rawMap[i][j/2]&FLAG_MOIST_MID){ /* Prairie */
                            fprintf(worldFile, "%s",PRAIRIE);
                        }
                        else { /* Shrubland */
                            fprintf(worldFile, "%s",SHRUBLAND);
                        }
                    }
                    else if (rawMap[i][j/2]&FLAG_TEMP_SUBARTIC){ /* Subartic Temperatures */
                        if((rawMap[i][j/2]&FLAG_MOIST_VERYWET) == FLAG_MOIST_VERYWET){/* Bog */
                            fprintf(worldFile, "%s",BOG);
                        }
                        else if (rawMap[i][j/2]&FLAG_MOIST_WET){ /* Forest */
                            fprintf(worldFile, "%s",FOREST);
                        }
                        else {
                            fprintf(worldFile, "%s",TAGIA); /* Tagia */
                        }
                    }
                    else { /* Artic Temperatures */
                        fprintf(worldFile, "%s",TUNDRA); /* Tundra */
                    }
                }
                else{ /* Water */
                    fprintf(worldFile, "%s",WATER);
                }
            }
            else if (digitPlaced<=0){
                fprintf(worldFile, "%s"," ");
            }
        }
        fprintf(worldFile, "\n");
    }
    fprintf(worldFile, "\nKEY\n");
    fprintf(worldFile, "    BIOME    | SYMBOL\n");
    fprintf(worldFile, "-------------|-------\n");
    fprintf(worldFile, "       WATER |    %s\n", WATER);
    fprintf(worldFile, "    MOUNTAIN |    %s\n", MOUNTAIN);
    fprintf(worldFile, "      TUNDRA |    %s\n", TUNDRA);
    fprintf(worldFile, "       TAGIA |    %s\n", TAGIA);
    fprintf(worldFile, "         BOG |    %s\n", BOG);
    fprintf(worldFile, "   SHRUBLAND |    %s\n", SHRUBLAND);
    fprintf(worldFile, "     PRAIRIE |    %s\n", PRAIRIE);
    fprintf(worldFile, "      FOREST |    %s\n", FOREST);
    fprintf(worldFile, "       SWAMP |    %s\n", SWAMP);
    fprintf(worldFile, "      DESERT |    %s\n", DESERT);
    fprintf(worldFile, "     SAVANNA |    %s\n", SAVANNA);
    fprintf(worldFile, "  RAINFOREST |    %s\n", RAINFOREST);
    fprintf(worldFile, "    MANGROVE |    %s\n", MANGROVE);

    fprintf(worldFile, "\nSUGGESTED SETTLEMENT FLAGS AND SIZES\n");
    fprintf(worldFile, "\n");

    

    for (int i = 0; i < settlementNumber; ++i){
        fprintf(worldFile, "Settlement %d:\n", i); /* Settement Number */
        fprintf(worldFile, "    Size: %d\n", citySizes[i]);
        if (citySizes[i] >70){
            cityDetails[i] |= FLAG_URBAN;
        }
        else if (citySizes[i] > 0){
            cityDetails[i] |= FLAG_RURAL;
        }
        fprintf(worldFile, "    Flag Num: %d\n", cityDetails[i]);
        fprintf(worldFile, "    Flags:");
        if(cityDetails[i] & FLAG_COASTAL){
            fprintf(worldFile, " Coastal");
        }
        if(cityDetails[i] & FLAG_MOUNTAIN){
            fprintf(worldFile, " Mountain");
        }
        if(cityDetails[i] & FLAG_AGRICULTURE){
            fprintf(worldFile, " Agricultural");
        }
        if(cityDetails[i] & FLAG_FOREST){
            fprintf(worldFile, " Forest");
        }
        if(cityDetails[i] & FLAG_COMMERCE){
            fprintf(worldFile, " Trading");
        }
        if(cityDetails[i] & FLAG_FRONTIER){
            fprintf(worldFile, " Frontier");
        }
        if(cityDetails[i] & FLAG_INDUSTRIAL){
            fprintf(worldFile, " Industrial");
        }
        if(cityDetails[i] & FLAG_RURAL){
            fprintf(worldFile, " Rural");
        }
        if(cityDetails[i] & FLAG_URBAN){
            fprintf(worldFile, " Urban");
        }
        if(cityDetails[i] & FLAG_EXOTIC){
            fprintf(worldFile, " Exotic");
        }
        if(cityDetails[i] & FLAG_PIOUS){
            fprintf(worldFile, " Pious");
        }
        if(cityDetails[i] & FLAG_MAGICAL){
            fprintf(worldFile, " Magical");
        }
        fprintf(worldFile, "\n");
    }

    printf("Finishing Map\n");
#if 0
    /* Alternitively make a list of seeds for the srand(). If we call the same */
    /* seed we always get the same result with all our rands. This can be used */
    /* to generate a queried settlement on demand, and have it always be the   */
    /* same. We would also need to include pop and flags                       */
    /* 8 bit for pop, 16 for flags, 32 for random seed                         */ 
    fclose(worldFile);
    printf("Generating Settlements...");
    for (int i = 0; i < settlementNumber; ++i){
        worldFile = fopen(filename, "a+");
        fprintf(worldFile, "SETTLEMENT %04d\n",i);
        fclose(worldFile);
        printf("SETTLEMENT %04d\n", i);
        settlementGen(filename, rand()%100, cityDetails[i]);
    }
#endif
    printf("Finished Generating World\n");
}