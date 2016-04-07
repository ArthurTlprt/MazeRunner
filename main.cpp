
#include "cell.h"
#include <iostream>
#include <vector>
#include <string>

void printNtimes(std::string str, int n){
    for(int i = 0; i < n; ++i){
        std::cout << str;
    }
}

int main(int argc, char **argv)
{
    std::vector<std::vector<cell> > maze;
    
    /*
    cell firstCell(1);
    cell secondCell(2);
    
    firstCell.setRightCell(&secondCell);
    cell* ptr = firstCell.getNextCell();
    
    
    
    std::cout << firstCell.getId() << std::endl;
    std::cout << ptr->getId() << std::endl;
    */
    
    int width, height;
    std::cout << "Setting the width" << std::endl;
    std::cin >> width;
    std::cout << "Setting the height" << std::endl;
    std::cin >> height;
    
    for(int i = 0; i < height; ++i){
        std::vector<cell> line;
        for(int j = 0; j < width; ++j){
            if(j == 0){
                printNtimes("+--", width);
                std::cout << "+" << std::endl;
            }
            cell newCell = cell(i, j);
            newCell.setId((i)*width + j);
            
            line.push_back(newCell);
            
            std::cout << "|  " ;
        }
        std::cout << "|  " << std::endl;
        maze.push_back(line);
    }
    printNtimes("+--", width);
    std::cout << "+" << std::endl;
    
    
    int tab[] = {0, 1, 2, 3, 4, 5};
    for(int&i:tab){
        std::cout << i << std::endl;
    }
    
    return 0;
}
