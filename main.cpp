
#include "cell.h"
#include <iostream>
int main(int argc, char **argv)
{
    cell firstCell(1);
    cell secondCell(2);
    
    firstCell.setRightCell(&secondCell);
    cell* ptr = firstCell.getNextCell();
    
    std::cout << firstCell.getId() << std::endl;
    std::cout << ptr->getId() << std::endl;
}
