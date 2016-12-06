OBJS = cat minustwo plustwo factorial myshell
CC = gcc

all: cat minustwo plustwo factorial myshell

cat:
	$(CC) cat.c -o cat
minustwo:
	$(CC) minustwo.c -o minustwo
plustwo:
	$(CC) plustwo.c -o plustwo
factorial:
	$(CC) factorial.c -o factorial
myshell:
	$(CC) myshell.c -o myshell
clean:
	rm -rf $(OBJS)
