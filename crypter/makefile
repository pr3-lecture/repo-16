
clean:
	del crypto.o main.o encrypt.exe decrypt.exe

crypto.o: crypto.c
	gcc -Wall -c crypto.c

main.o: main.c
	gcc -Wall -c main.c
	
crypto: crypto.o main.o
	gcc -o encrypt crypto.o main.o
	gcc -o decrypt crypto.o main.o