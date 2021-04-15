CC=g++
CFLAGS= -pthread -std=c++11
DEPS = 
DIR = -Iinclude
OBJ = list_creator.o main.o 

%.o: %.cpp $(DEPS)
	$(CC) $(DIR) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) $(DIR) -o $@ $^ $(CFLAGS)

exe:
	./main

clean: 
	rm $(OBJ) main