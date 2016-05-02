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
#include <stack>
#include <ctime>
#include <unordered_set>
#include <chrono>
#include <thread>
#include "json.hpp"
using json = nlohmann::json;



class maze {
public:
    maze();
    maze(int width, int height);
    maze(const maze& orig);
    virtual ~maze();
    void print();
    void debug();
    json save();
    cell getCell(int x, int y);
    std::vector<std::vector<cell> > cells;
    std::stack<cell*> antecedent;
    std::unordered_set<int> visited;
    void generate(cell&);
private:
    void initCells();
    void printHori(int d);
    void printVert(int d);
    std::vector<int> getNexts(cell&);
    int width;
    int height;
};

#endif	/* MAZE_H */
