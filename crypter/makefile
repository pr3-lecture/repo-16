
clean:
	del crypto.o encrypt.exe decrypt.exe

crypto.o: crypto.c
	gcc -Wall -c crypto.c

crypto: crypto.o
	gcc -o encrypt crypto.o
	gcc -o decrypt crypto.o