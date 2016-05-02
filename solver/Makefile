# edification des liens
Programme : main.o node.o pathFinding.o
	g++ -std=c++14 main.o node.o pathFinding.o -o Programme
	rm -rf *.o

# compilation en fichier objet
main.o : main.cpp node.cpp pathFinding.cpp
	g++ -std=c++14 -c main.cpp -o main.o

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
