PROG = corrida
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=gnu++11
OBJS = main.o sapo.o cabecalho.o corrida.o lerArquivos.o
SRC = src/
BUILD = build/
BIN = bin/

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o $(BUILD)
	mv $(PROG) $(BIN)

main.o :
	$(CC) $(CPPFLAGS) -c $(SRC)main.cpp
sapo.o :
	$(CC) $(CPPFLAGS) -c $(SRC)sapo.cpp
cabecalho.o :
	$(CC) $(CPPFLAGS) -c $(SRC)cabecalho.cpp
corrida.o :
	$(CC) $(CPPFLAGS) -c $(SRC)corrida.cpp
lerArquivos.o :
	$(CC) $(CPPFLAGS) -c $(SRC)lerArquivos.cpp
clean:
	rm -f *.o 
