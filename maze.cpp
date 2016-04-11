
/*
 * File:   maze.cpp
 * Author: isen
 *
 * Created on 7 avril 2016, 11:07
 */

#include "maze.h"

void printNtimes(std::string str, int n){
    for(int i = 0; i < n; ++i){
        std::cout << str;
    }
}

maze::maze() {
}

maze::maze(int width, int height){
    this->width = width;
    this->height = height;
    this->initCells();
}

/**
 *  @brief affiche le labyrinthe avec ses murs
 *  @return void
 */
void maze::print(){
    int cnt;
    for(std::vector<cell>&i:this->cells){
        cnt=0;
        for(cell&j:i){
            if(cnt == 0){
                printNtimes("+--", width);
                std::cout << "+" << std::endl;
            }
            //std::cout << "|  ";
            std::cout << "| " << j.getId();
            cnt++;
        }
        std::cout << "|  " << std::endl;
    }
    printNtimes("+--", width);
    std::cout << "+" << std::endl;
}

/**
 *  @brief affiche les ids de chaque cellule du labyrinthe
 *  @return void
 */
void maze::printIds(){
    for(std::vector<cell>&i:this->cells){
        for(cell&j:i){
            std::cout << j.getId() << std::endl;
        }
    }
}

/**
 *  @brief crée chaque cellule du labyrinthe et initialise ses voisins et ses cloisons
 *  @return void
 */
void maze::initCells(){
    //  crée les cellules et les sauvegarde dans un vector
    for(int i = 0; i < height; ++i){
        std::vector<cell> line;
        for(int j = 0; j < width; ++j){
            cell newCell = cell(i, j);
            newCell.setId((i)*width + j);

            line.push_back(newCell);
        }
        this->cells.push_back(line);
    }

    // initialise les cellules voisines
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            cell *up = NULL, *down = NULL, *left = NULL, *right = NULL;
            if(i !=0){
                up = &(cells[i-1][j]);
            }
            if(i != height-1){
                down = &(cells[i+1][j]);
            }
            if(j != 0){
                left = &(cells[i][j-1]);
            }
            if(j != width-1){
                right = &(cells[i][j+1]);
            }
            this->cells[i][j].setNeighborhood(left, up, right, down);
        }
    }

    int len = (width+1)*height + (height+1)*width;      // nombre de separateurs

    /*std::fill(this->dividers.begin(), this->dividers.begin() + len, 1);
    for(int i = 0; i < dividers.size(); ++i){
        std::cout << dividers[i] << std::endl;
    }*/
    for(int i = 0; i < len; ++i){
        this->dividers.push_back(true);
        std::cout << this->dividers[i] << std::endl;
    }



    std::vector<bool>::iterator it = this->dividers.begin();
    for(int i = 0; i < len; ++i, it++){
        std::cout << *it << std::endl;
    }

    //  initialise les cloisons
    this->cells[0][0].setDividerLeft(it);
    /*for(int i = 0; i < height; ++i){
        for(int j = 0; j <width; ++j){
            if( i == 0){
                if(j == 0){
                    this->cells[i][j].setDividers(&*it++, &(*(it++)), &(*(it++)), &(*(it++)));
                }else{
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerLeft(), &(it++), &(it++), &(it++));
                }
            }else{
                if(j == 0){
                    this->cells[i][j].setDividers(&(it++), this->cells[i-1][j].getDividerUp(), &(it++), &(it++));
                }else{
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerLeft(), this->cells[i-1][j].getDividerUp(), &(it++), &(it++));
                }
            }
        }
    }*/

}

/**
 * [maze::getCell description]
 * @param  x [description]
 * @param  y [description]
 * @return   [description]
 */
cell maze::getCell(int x, int y){
    return cells[y][x];
}

maze::maze(const maze& orig) {
}

maze::~maze() {
}
