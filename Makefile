#insert your own filename here

CC = gcc
SRC = ${wildcard ./cnpython/*.c}
CFLAGS = -lm


#Uncomment and add your own file here if you need it

BUILD = ./build/something

all:
	${CC} ${SRC} -lm -o ${BUILD}

test: ./template.c
	gcc ./template.c cnpython.c -o ./template.o -lm


clear: *.o
	rm *.o

