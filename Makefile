all: clean create

create: main.o cell.o maze.o
        g++ -o create main.o cell.o maze.o
        
main.o : main.cpp cell.h maze.h json.hpp
        g++ -o main.o -W -Wall
        
cell.o : cell.cpp cell.h
        g++ -o cell.o -W -Wall
        
maze.o : maze.cpp maze.h
        g++ -o maze.o -W -Wall
        
clean:
    rm --rf *.o
