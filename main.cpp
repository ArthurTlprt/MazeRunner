
#include "cell.h"
#include "maze.h"
#include <iostream>
#include <vector>
#include <string>


int main(int argc, char **argv)
{

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


    lab.generate(lab.cells[0][0]);

    lab.print();

    lab.debug();



    return 0;
}
