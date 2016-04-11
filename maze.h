/* 
 * File:   maze.h
 * Author: isen
 *
 * Created on 7 avril 2016, 11:07
 */

#ifndef MAZE_H
#define	MAZE_H

#include "cell.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class maze {
public:
    maze();
    maze(int width, int height);
    maze(const maze& orig);
    virtual ~maze();
    void print();
    void printIds();
    cell getCell(int x, int y);
private:
    void initCells();
    std::vector<std::vector<cell> > cells;
    std::vector<bool >dividers;
    int width;
    int height;
};

#endif	/* MAZE_H */

