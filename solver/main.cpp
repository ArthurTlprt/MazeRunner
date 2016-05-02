
//#include "cell.h"
//#include "maze.h"
#include <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include "json.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "pathFinding.h"
#include "json.hpp"

using json = nlohmann::json;




int main(int argc, char **argv)
{
    json maze;
    std::ifstream readfile("../generator/maze.json");
    if(readfile.is_open()){
        readfile >> maze;
    }
    int size=maze["dim"]["height"];
    std::cout<<size;
    std::map<std::string,std::string> mamap;
    mamap=recup(maze);
    findPath(mamap,size);
    return 0;
}
