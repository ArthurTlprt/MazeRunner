
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
    // create all dividers and store them in a vector

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if( i == 0){
                if(j == 0){
                    int left = -1, up = -1, right = 1, down = 1;
                    this->dividers.push_back(left);
                    this->dividers.push_back(up);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers( &(*(this->dividers.end()-3)), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)), &(*(this->dividers.end())) );
                }else if(j == width -1){
                    int up = -1, right = -1, down = 1;
                    this->dividers.push_back(up);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers( this->cells[i][j-1].getDividerRight(), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)), &(*(this->dividers.end())) );
                }else{
                    int up = -1, right = 1, down = 1;
                    this->dividers.push_back(up);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)), &(*(this->dividers.end())));
                }
            }else if(i == height-1){
                if(j == 0){
                    int left = -1, right = 1, down = -1;
                    this->dividers.push_back(left);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(&(*(this->dividers.end()-2)), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-1)), &(*(this->dividers.end())));
                }else if(j == width -1){
                    int right = -1, down = -1;
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-1)), &(*(this->dividers.end()-2)));
                }else{
                    int right = 1, down = -1;
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end())), &(*(this->dividers.end()-1)));
                }
            }else{
                if(j == 0){
                    int left = -1, right = 1, down = 1;
                    this->dividers.push_back(left);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(&(*(this->dividers.end()-2)), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-1)), &(*(this->dividers.end())) );
                }else if(j == width -1){
                    int right = -1, down = 1;
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-1)), &(*(this->dividers.end())) );
                }else{
                    int right = 1, down = 1;
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerUp(), &(*(this->dividers.end()-1)), &(*(this->dividers.end())) );
                }
            }
        }
    }
    std::vector<int>::iterator it = this->dividers.begin();
    for(it = this->dividers.begin(); it != this->dividers.end(); it++){
        //std::cout << *it << std::endl;
    }
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
