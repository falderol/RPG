all: shopGen test

shopGen: shopGen.c
	gcc -o shopGen shopGen.c

test: test.c
	gcc -o test test.c

clean:
	rm test
	rm shopGen