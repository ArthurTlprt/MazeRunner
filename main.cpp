
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
    
    // setting up a maze
    
    maze lab = maze(width, height);
    
    //display maze
    
    lab.print();
    
    //  display all ids
    
    //lab.printIds();
    
    cell potiron = lab.getCell(0, 0);
    std::cout << *(potiron.getDividerLeft()) << std::endl;
    if(*(potiron.getDividerLeft()) == 1){
        std::cout << "nous on veut des nichons" << std::endl;
    }
   
    return 0;
}
