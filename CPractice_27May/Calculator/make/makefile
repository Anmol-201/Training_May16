CC = gcc
SRC = ./src
OBJ = ./obj
INC = ./include
BIN = ./bin

CFLAGS = -Wall -g -o
IFLAGS = -I $(INC)
LDFLAGS =  -c

calc: $(OBJ)/calc.o $(OBJ)/calc_functions.o
	$(CC) $(CFLAGS) $(BIN)/calc $(OBJ)/calc.o $(OBJ)/calc_functions.o
	
$(OBJ)/calc.o: $(SRC)/calc.c
	$(CC) $(LDFLAGS) $(IFLAGS) $(SRC)/calc.c
	mv *.o $(OBJ)/
	
$(OBJ)/calc_functions.o: $(SRC)/calc_functions.c
	$(CC) $(LDFLAGS) $(IFLAGS) $(SRC)/calc_functions.c
	mv *.o $(OBJ)

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/calc

