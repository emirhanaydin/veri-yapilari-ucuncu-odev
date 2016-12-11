CC=g++
BIN=bin
INCL=include
LIB=lib
SRC=src
EXE=main

all: make_dirs gen_libs compile run

make_dirs:
	IF NOT EXIST $(BIN) (MD "$(BIN)")
	IF NOT EXIST $(INCL) (MD "$(INCL)")
	IF NOT EXIST $(LIB) (MD "$(LIB)")
	IF NOT EXIST $(SRC) (MD "$(SRC)")
	
gen_libs: main.o dosya.o dugum.o ikiliAramaAgaci.o kuyruk.o

compile:
	$(CC) $(LIB)/main.o $(LIB)/dosya.o $(LIB)/dugum.o $(LIB)/ikiliAramaAgaci.o $(LIB)/kuyruk.o -o $(BIN)/$(EXE)

run:
	$(BIN)/$(EXE).exe
	
main.o:
	$(CC) -I $(INCL) -c $(SRC)/main.cpp -o $(LIB)/main.o
	
dosya.o:
	$(CC) -I $(INCL) -c $(SRC)/dosya.cpp -o $(LIB)/dosya.o
	
dugum.o:
	$(CC) -I $(INCL) -c $(SRC)/dugum.cpp -o $(LIB)/dugum.o
	
ikiliAramaAgaci.o:
	$(CC) -I $(INCL) -c $(SRC)/ikiliAramaAgaci.cpp -o $(LIB)/ikiliAramaAgaci.o
	
kuyruk.o:
	$(CC) -I $(INCL) -c $(SRC)/kuyruk.cpp -o $(LIB)/kuyruk.o
	
clear:
	DEL "$(BIN)\$(EXE).exe"
	DEL "$(LIB)\*.o"