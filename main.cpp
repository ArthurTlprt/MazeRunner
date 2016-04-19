
#include "cell.h"
#include "maze.h"
#include "json.hpp"
#include <iostream>
#include <vector>
#include <string>

using json = nlohmann::json;

int main(int argc, char **argv)
{

    json j;

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

    //lab.print();

    //lab.printIds();


    //lab.generate(lab.cells[0][0]);

    lab.print();

    std::unordered_set<int>::iterator it;
    for(it = lab.visited.begin(); it != lab.visited.end(); ++it){
        std::cout << *it << std::endl;
    }

    //lab.debug();


    return 0;
}
