all: hw1_myprintf.o hw1_str.o
	ar rcs libhw1.a hw1_myprintf.o hw1_str.o

hw1_myprintf.o: hw1_myprintf.c
	gcc -c -o hw1_myprintf.o hw1_myprintf.c

hw1_str.o: hw1_str.c
	gcc -c -o hw1_str.o hw1_str.c
