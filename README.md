# RPG Repository
This repository contains a bunch of stuff that i am working on for RPG's. I'll add things as i remember. Not all of it will be code
Some of this code is autogenerated by another function not in this repository. It should be obvious what it is when you see it, it is the stuff that i would be crazy to type.
# Contents
  1. Demagus True Reference - A general reference for medieval RPG's and the like
  2. test.c - A rough framework for the functions that i am currently working on.
  3. shopGen.c - A rough piece of code that randomly generates the a certain type of shop
  4. settlementGen.c - A rough piece of code that randomly generates a full settlement, with shops. The user can specify the size of the settlement.
  5. nameGen.c - A rough piece of code with a couple random name generators.
  6. convertFromCP.c - A piece of code that converts copper pieces into other currencies.
# Simple Compile and Run
## Compile
On systems without make

`gcc -o test .\nameGen.c .\convertFromCp.c .\onesCount.c .\itoa.c .\shopGen.c .\settlementGen.c .\test.c`

On systems with make

`make all`

## Run
`.\test <command name> <command arguments>`

# Notes
I'm trying to make this work on windows an linux. If you run into an issue on either O.S. let me know.

I'd love to eventaully put this all on a website. I just need to learn how to do web stuff first.

This code is something i'm working on in my free time, for fun.

Comments or Suggestions? Contact me at:

worthlesstrifle@gmail.com
