CC = gcc
SRC = ${wildcard ../../cnpython/*.c}
#Necessary -lm flag for the library to work
CLAGS = -lm
BUILD = ./helloWorld.o

all ./helloWorld.c:
	${CC} ./helloWorld.c ${SRC} ${CLAGS} -o ${BUILD} 