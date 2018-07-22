#ifndef FLAG_DEFINES_HEADER_FILE
#define FLAG_DEFINES_HEADER_FILE

#define NAME_LENGTH 32
#define INVALID_FLAG 32768
#define FIREARMS_FLAG 16384

#define FLAG_COASTAL 1
#define FLAG_MOUNTAIN 2
#define FLAG_AGRICULTURE 4
#define FLAG_FOREST 8
#define FLAG_COMMERCE 16
#define FLAG_FRONTIER 32
#define FLAG_INDUSTRIAL 64
#define FLAG_RURAL 128
#define FLAG_URBAN 256
#define FLAG_EXOTIC 512
#define FLAG_PIOUS 1024
#define FLAG_MAGICAL 2048

#endif

/* Bit | Description | Caused By                                      */
/* ----|-------------|------------------------------------------------*/
/*  00 | Costal      | When a water tile meets a land tile            */
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