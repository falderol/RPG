#Simple Makefile

all:
	cd RPGutilities; make all
	cd Utilities; make all
	cd WorldGen; make all
	gcc -Wall RPGutilities/convertFromCp.o Utilities/itoa.o Utilities/utilities.o WorldGen/nameGen.o WorldGen/shopGen.o WorldGen/settlementGen.o WorldGen/region.o test.c -o test

clean:
	cd RPGutilities; make clean
	cd Utilities; make clean
	cd WorldGen; make clean
	-rm -f *.o

