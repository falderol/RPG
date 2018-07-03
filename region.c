#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "settlementGen.h"

void regionCommandReminder(){

}
/**********************************************************************/
/* GENERAL                                                            */
/* One tile will be 1 sq mile                                         */
/**********************************************************************/
/* PLATES                                                             */
/* Standard Construction                                              */
/* Bit 03 | Bit 02 | Bit 01 | Bit 00                                  */
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
/*  00 | Magical     | rand is called for 0.01*mapHeigh*mapWidth times*/
/*  01 | Costal      | When a water tile meets a land tile            */
/*  02 | Wealthy     | TBD                                            */
/*  03 | Exotic      | Randomly blobbed on the map                    */
/*  04 | Frontier    | TBD - Something to do with nearby settlements? */
/*  05 | Forest      | TBD - Something to do with weather             */
/*  06 | Industrial  | Resources and Town Level Pop                   */
/*  07 | Mining      | Settlement near Mountain                       */
/*  08 | Agriculture | Settlement in Farming Biome                    */
/*  09 | Rural       | Settlement with village level pop in 4 tile    */
/*     |             | radius                                         */
/*  10 | Urban       | Settlement with city level pop in 4 tile radius*/
/*  11 | TBD         | unassigned                                     */
/*  12 | TBD         | unassigned                                     */
/*  13 | TBD         | unassigned                                     */
/*  14 | Firearms    | Optional flag if using firearms                */
/*  15 | Invalid     | Marks the tile as invalid                      */
/*  16 | West        | Randomly placed initial plate, then blobbed    */
/*  17 | South       | Randomly placed initial plate, then blobbed    */
/*  18 | East        | Randomly placed initial plate, then blobbed    */
/*  19 | North       | Randomly placed initial plate, then blobbed    */
/*  10 | Moisture    | Dry, Mid, Wet, invalid                         */
/*  21 | Moisture    |                                                */
/*  22 | Temperature | Tropical, temperate, subartic, artic           */
/*  23 | Temperature |                                                */
/*  24 | Height      | Below, at, above, invalid                      */
/*  25 | Height      |                                                */
/*  26 | TBD         | unassigned                                     */
/*  27 | TBD         | unassigned                                     */
/*  28 | TBD         | unassigned                                     */
/*  29 | TBD         | unassigned                                     */
/*  30 | TBD         | unassigned                                     */
/*  31 | Land        | Initialy from plate collisions, then blobbed   */
/*                                                                    */
/*                                                                    */
/**********************************************************************/
int regionGen(char * filename){
    FILE * regionFile = fopen(filename, "w+");
    fclose(regionFile);
    return 0;
}