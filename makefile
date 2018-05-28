all: shopGen settlementGen

shopGen: shopGen.c
	gcc shopGen shopGen.c

settlementGen: settlementGen.c
	gcc -o settlementGen settlementGen.c

clean:
	rm settlementGen
	rm shopGen
