# RPG Repository
This repository contains a bunch of stuff that i am working on for RPG's. I'll add things as i remember. Not all of it will be code.

Some of this code is autogenerated by another function not in this repository. It should be obvious what it is when you see it, it is the stuff that i would be crazy to type.

Alot of this stuff is poorly written. I'm sorry. Sometimes i will go back and make it better. Just call it agile, prioritizing working code early that is continuously improved.

# Contents
  1. Demagus True Reference - A general reference for medieval RPG's and the like
  2. test.c - A rough framework for the functions that i am currently working on.
  3. shopGen.c - A rough piece of code that randomly generates the a certain type of shop
  4. settlementGen.c - A rough piece of code that randomly generates a full settlement, with shops. The user can specify the size of the settlement.
  5. nameGen.c - A rough piece of code with a couple random name generators.
  6. convertFromCP.c - A piece of code that converts copper pieces into other currencies.
  7. region.c - A piece of code that generates a world.

## Demagus True Reference
This is the reference document that started it all. Honestly it is a whole lot more useful than this code. This stuff this code automates is just a section of it. But yeah, it is a logically orginized reference that contains a bunch of useful information. Everything from material properties and price to common hazards. Recommended amount of enemies in an encounter to food dishes and their prices. Check it out. Let me know if i got something wrong or there is something you belive i need to add.


## General
### Flags
Flags are used to be more specific about the area that something is in. I.E. if whatevers using the flags is in a magical frontier forest the flag value would be 49.

|**Bit 11**  |**Bit 10**  |**Bit 09**  |**Bit 08**  |**Bit 07**  |**Bit 06**  |
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|
|Magical     |Pious       |Exotic      |Urban       |Rural       |Industrial  |
|+2048       |+1024       |+512        |+256        |+128        |+64         |
|**Bit 05**  |**Bit 04**  |**Bit 03**  |**Bit 02**  |**Bit 01**  |**Bit 00**  |
|Frontier    |Commerce    |Forest      |Agriculture |Mountain    |Coastal     |
|+32         |+16         |+8          |+4          |+2          |+1          |

To generate a complete flagf add all the associated numbers to the flag together.


## Shop Generator
`.\test shopGen <filename.txt> <shop number> <flags>`

The shop generator generates the type of shop specified by the shop number, with a semi-random stock.

### Shop Number Key
| Shop # | Shop Type | Shop # | Shop Type |
|:-:|:-:|:-:|:-:|
00 | Adventurer's Emporium | 08 | Fletcher
01 | Alchemist's Shop | 09 | General Store
02 | Arcana Shop | 10 | Leatherworker's Shop
03 | Bakery | 11 | Music Store
04 | Barber | 12 | Tailor
05 | Blacksmith | 13 | Tavern
06 | Bookstore | 14 | Shrine
07 | Butcher's Shop | 15 | Jeweler

## Settlement Generator
`.\test settlementGen <filename.txt> <size> <flags>`

`.\test autoSettlementGen <filename.txt> <flags>`

Settlements are generated in ascii.

Settlement size can be set manually in a range from 1 to 100, or chosen automatically.

### Key

Each symbol on the map represents a 5 foot x 5 foot square, or one tile.

|Symbol| Meaning
|:-:|:-----------:|
| . | Empty Space |
| H | Road        |
| W | Water       |

## Region Gen

`.\test regionGen <filename.txt>`

THis piece of code automaticaly generates a world complete with several biomes. The numbers on the map represent settlement locations. You can generate the settlements using `.\test autoSettlementGen <filename.txt> <flags>` where the flags are described in the settlement section. Alternatively use `.\test settlementGen <filename.txt> <size> <flags>` if you want to determine the size of the settlement. 

I did write code that automaticaly generates all the settlements. The issue with this is twofold. Firstly it generates a little over 1,000 settlements per map. Average settlement size is just under 1 MiB, little over 1,000 of these is a GiB. Trust me, your players will not get to all of the 1000+ settlements that are normaly generated. The second issue is with general preference. More often than nought, GM's that i know, even if they choose a completely randomized map, want to make their own settlements. 

What i recomend is to make a fair amount of settlements with the settlementGen tool before, or on the fly during play and just name them the number on the map. It's fairly quick. Either ignore the flags completely, or set them if you city a small bit of bias in the shops. Set the size personally, either keeping in mind the 80 vilages to 19 towns to 1 city ratio, or making them based on what the story or players desire.

### Key

Each symbol on the map represents a 1 mile x 1 mile square.

|Symbol| Meaning
|:-:|:-----------:|
| ▓ | Water       |
| Δ | Mountain    |
| ʭ | Tundra      |
| † | Tagia       |
| φ | Bog         |
| ɷ | Shrubland   |
| ~ | Prairie     |
| Ŧ | Forest      |
| Ψ | Swamp       |
|   | Desert      |
| ± | Savanna     |
| ‡ | Rainforest  |
| ʎ | Mangrove    |


# Simple Compile and Run
## Compile

On systems with make

`make all`

## Run
`.\test <command name> <command arguments>`

## Convert Output to Image
The map is about 7168x6640 if you want to convert it from its .txt form to an image. I recomend you dont use the full file, as the length varies with the shop amount, and shop contents aren't very useful as an image. In other words, use the text files to find stuff, and the image if you need to import the map.

### Linux
You might have to change the imagemagik policy settings.

`sudo convert -size 6152x6664 xc:white -font "Unifont" -pointsize 12 -fill black -annotate +15+15 "@filename.txt" filename.png`

Don't have Unifont? Download it here http://www.unifoundry.com/unifont.html

Alternitively you can use another monospace font that supports the utf 8 charecter set.

# Notes
I'm trying to make this work on windows an linux. If you run into an issue on either O.S. let me know.

I'd love to eventaully put this all on a website. I just need to learn how to do web stuff first.

This code is something i'm working on in my free time, for fun.

Comments or Suggestions? Contact me at:

worthlesstrifle@gmail.com
