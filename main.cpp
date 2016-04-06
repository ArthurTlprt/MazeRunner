
#include "cell.h"
#include <iostream>
#include <vector>

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
    
    std::cin >> width;
    std::cin >> height;
    
    for(int i = 0; i < height; ++i){
        std::vector<cell> line;
        for(int j = 0; j < width; ++j){
            if(j == 0){
                std::cout << std::string(width, '+--') << std::endl;
            }
            cell newCell = cell(i, j);
            newCell.setId((i)*width + j);
            
            line.push_back(newCell);
            
            std::cout << "|" << newCell.getId() ;
        }
        std::cout << "|" << std::endl;
        maze.push_back(line);
    }
    
    
    int tab[] = {0, 1, 2, 3, 4, 5};
    for(int&i:tab){
        std::cout << i << std::endl;
    }
    
    return 0;
}
