#insert your own filename here

CC = gcc
SRC = {wildcard cnpython/*.c}


#Uncomment and add your own file here if you need it

#BUILD = ./build/something

#all src/main.c:
#	${CC} src/main.c ${SRC} -o ${BUILD}

#test: ./template.c
#	gcc ./template.c cnpython.c -o ./template.o -lm


clear: *.o
	rm *.o

