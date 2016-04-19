all: clean create

create: main.o cell.o maze.o
        g++ -o Run main.o cell.o maze.o
        
main.o : main.cpp cell.h maze.h json.hpp
        g++ -o main.o -W -Wall -ansi -pedantic
        
cell.o : cell.cpp cell.h
        g++ -o cell.o -W -Wall -ansi -pedantic
        
maze.o : maze.cpp maze.h
        g++ -o maze.o -W -Wall -ansi -pedantic
        
clean:
    rm --rf *.o
    
torebuild: clean
        rm -rf hello