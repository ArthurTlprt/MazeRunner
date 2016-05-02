
#include "cell.h"
#include "maze.h"
#include "json.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using json = nlohmann::json;

int main(int argc, char **argv)
{
    // crée un objet json
    json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    std::cout << j["happy"] << std::endl;


    // écrit un objet json dans un fichier
    std::ofstream writefile;
    writefile.open ("maze.json");
    //writefile << j;
    //writefile.close();
    // crée un objet json à partir d'un fichier
    json jsonRead;
    std::string line;
    std::ifstream readfile("maze.json");
    if (readfile.is_open()){
      getline (readfile,line);
	std::cout << j["happy"] << std::endl;
      // json::parse permet de transformer un string en objet json
      //jsonRead =  json::parse(line);
      //readfile.close();
    }
    std::cout << jsonRead << std::endl;
    // input maze sizes

    int width, height;
    std::cout << "Setting the width" << std::endl;
    std::cin >> width;
    std::cout << "Setting the height" << std::endl;
    std::cin >> height;
    std::cout << std::endl << std::endl;

    // setting up a maze

    maze lab = maze(width, height);

    //display maze
    json g;
    //display maze
    g=lab.save();
    writefile << g ;
    writefile.close();

    lab.print();

    return 0;
}
