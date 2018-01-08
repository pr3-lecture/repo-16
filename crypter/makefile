all: crypto

clean:
	del crypto.o main.o test.o encrypt.exe decrypt.exe test.exe

crypto.o: crypto.c
	gcc -Wall -c crypto.c
	
test.o: test.c
	gcc -Wall -c test.c

main.o: main.c
	gcc -Wall -c main.c
	
crypto: main.o
	gcc -o encrypt main.o
	gcc -o decrypt main.o
	
runtest: test.o
	gcc -o test test.o
	test.exe