# edification des liens
Programme : main.o cell.o maze.o node.o pathFinding.o
	g++ -std=c++14 main.o cell.o maze.o node.o pathFinding.o -o Programme
	rm -rf *.o

# compilation en fichier objet
main.o : main.cpp cell.cpp maze.cpp
	g++ -std=c++14 -c main.cpp -o main.o

cell.o : cell.cpp
	g++ -std=c++14 -c cell.cpp -o cell.o

maze.o : maze.cpp
	g++ -std=c++14 -c maze.cpp -o maze.o

node.o : node.cpp
	g++ -std=c++14 -c node.cpp -o node.o

pathFinding.o : pathFinding.cpp
	g++ -std=c++14 -c pathFinding.cpp -o pathFinding.o

# suppression des fichiers temporaires
clean:
	 rm -rf *.o

# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf Programme
