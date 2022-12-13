SRC = src
OBJ = obj
BIN = bin
CC = gcc
INCLUDEFLAGS = -I ./include

main: $(SRC)/main.c $(OBJ)/functions.o 
	$(CC) -o $(BIN)/main $(INCLUDEFLAGS) $(SRC)/main.c $(OBJ)/functions.o

$(OBJ)/functions.o: $(SRC)/functions.c 
	$(CC) -o $(OBJ)/function.o $(INCLUDEFLAGS) -c $(SRC)/functions.c

clean: 
	echo "Cleaning files ..."
	rm $(BIN)/main $(OBJ)/*.o 
