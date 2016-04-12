
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

void maze::printHori(int d){
    switch (d) {
       case 1:
           std::cout << "+--";
           break;
       case -1:
           std::cout << "+--";
           break;
       case 0:
           std::cout << "+ #";
           break;
    }
}

void maze::printVert(int d){
    switch (d) {
         case 1:
            std::cout << "|";
            break;
        case -1:
           std::cout << "|";
           break;
         case 0:
            std::cout << " ";
            break;
    }
}

void maze::print(){
    /**
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
     */

    for(int line = 0; line < this->height; ++line){

        for(int col = 0; col < this->width; ++col){
            this->printHori(*(this->cells[line][col].getDividerUp()));
            if(col == this->width-1){
                std::cout << "+";
            }
        }
        std::cout << std::endl;

        for(int col = 0; col < this->width; ++col){
            this->printVert(*(this->cells[line][col].getDividerRight()));
            if(this->cells[line][col].isMarked()){
                std::cout << "##";
            }else{
                std::cout << "  ";
            }
            if(col == this->width-1){
                this->printVert(*(this->cells[line][col].getDividerLeft()));
            }
        }
        std::cout << std::endl;
        if(line == this->height-1){
            for(int col = 0; col < this->width; ++col){
                this->printHori(*(this->cells[line][col].getDividerDown()));
                if(col == this->width-1){
                    std::cout << "+";
                }
            }
        }
    }
    std::cout << std::endl << std::endl;

}

void maze::printIds(){
    for(std::vector<cell>&i:this->cells){
        for(cell&j:i){
            std::cout << j.getId() << std::endl;
        }
    }
}

void maze::initCells(){
    //  Crée toutes les cellules et les sauvegarde dans un vector
    for(int i = 0; i < height; ++i){
        std::vector<cell> line;
        for(int j = 0; j < width; ++j){
            cell newCell = cell(i, j);
            newCell.setId((i)*width + j);

            line.push_back(newCell);
        }
        this->cells.push_back(line);
    }
    // Lie la cellule à ses celulles voisines
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

    // obliger sinon bug lors de l'initialisation de la premiere cellule
    for(int i = 0; i < 4; ++i){
        this->dividers.push_back(1);
    }
    // create all dividers and store them in a vector
    std::vector<int>::iterator it = this->dividers.begin();
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if( i == 0){
                if(j == 0){
                    int left = -1, up = -1, right = 1, down = 1;
                    this->dividers.push_back(left);
                    this->dividers.push_back(up);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers( &(*(this->dividers.end()-4)), &(*(this->dividers.end()-3)), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)) );
                }else if(j == width -1){
                    int up = -1, right = -1, down = 1;
                    this->dividers.push_back(up);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers( this->cells[i][j-1].getDividerRight(), &(*(this->dividers.end()-3)), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)) );
                }else{
                    int up = -1, right = 1, down = 1;
                    this->dividers.push_back(up);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), &(*(this->dividers.end()-3)), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)));
                }
            }else if(i == height-1){
                if(j == 0){
                    int left = -1, right = 1, down = -1;
                    this->dividers.push_back(left);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(&(*(this->dividers.end()-3)), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)));
                }else if(j == width -1){
                    int right = -1, down = -1;
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-3)));
                }else{
                    int right = 1, down = -1;
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-1)), &(*(this->dividers.end()-2)));
                }
            }else{
                if(j == 0){
                    int left = -1, right = 1, down = 1;
                    this->dividers.push_back(left);
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(&(*(this->dividers.end()-3)), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)) );
                }else if(j == width -1){
                    int right = -1, down = 1;
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)) );
                }else{
                    int right = 1, down = 1;
                    this->dividers.push_back(right);
                    this->dividers.push_back(down);
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), &(*(this->dividers.end()-2)), &(*(this->dividers.end()-1)) );
                }
            }
        }
    }
}

cell maze::getCell(int x, int y){
    return cells[y][x];
}

maze::maze(const maze& orig) {
}

maze::~maze() {
}
