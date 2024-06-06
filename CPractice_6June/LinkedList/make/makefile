CC = gcc
SRC = ./src
OBJ = ./obj
INC = ./include
BIN = ./bin

CFLAGS = -Wall -g -o
IFLAGS = -I $(INC)
LDFLAGS =  -c

llist: $(OBJ)/main.o $(OBJ)/function.o
	$(CC) $(CFLAGS) $(BIN)/llist $(OBJ)/main.o $(OBJ)/function.o
	
$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(LDFLAGS) $(IFLAGS) $(SRC)/main.c
	mv *.o $(OBJ)/
	
$(OBJ)/function.o: $(SRC)/function.c
	$(CC) $(LDFLAGS) $(IFLAGS) $(SRC)/function.c
	mv *.o $(OBJ)

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/llist

val:
	valgrind  --tool=memcheck $(BIN)/llist 

