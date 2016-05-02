
#include "cell.h"
#include "maze.h"
#include "json.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "pathFinding.h"
#include "../generator/json.hpp"

using json = nlohmann::json;

int main(int argc, char **argv)
{
    json maze;
    std::string line;
    std::ifstream readfile("../generator/maze.json");
    if(readfile.is_open()){
        readfile >> maze;
    }
    std::map<std::string,std::string> coordMaze = recup(maze);
    findPath(coordMaze,maze["dim"]["height"]);
    return 0;
}
