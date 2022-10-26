all: Chiffrement.o
	gcc -o all Chiffrement.o

Chiffrement: Chiffrement.c 
	gcc Chiffrement.c -o Chiffrement
	
clean:
	rm -rf *.o

mrproper: clean
	rm -rf hello