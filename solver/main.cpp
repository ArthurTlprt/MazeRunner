
#include "cell.h"
#include "maze.h"
#include "json.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../generator/json.hpp"

using json = nlohmann::json;

int main(int argc, char **argv)
{
    json maze;
    std::string line;
    std::ifstream readfile("../generator/maze.json");
    if(readfile.is_open()){
        getline(readfile,line);
        maze = json::parse(line);
        readfile.close();
    }
    std::map<std::string,std::string> coordMaze = recup(maze);
    int size;
    std::cout << "Size of the maze : ";
    std::cin >> size;
    std::cout << std::endl;
    findPath(coordMaze,size);
    return 0;
}
