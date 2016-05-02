
/*
 * File:   maze.cpp
 * Author: isen
 *
 * Created on 7 avril 2016, 11:07
 */

#include "maze.h"

//utils
json maze::save(){
  json g;
  for (int i=0;i<this->height;i++){
    for(int j=0;j<this->width;j++){
      json m;
      if(this->cells[i][j].getDividerUp()==0){
        std::string b;
        int a=i-1;
        b=std::to_string(a) + ','+ std::to_string(j);
        m.push_back(b);
      }
      if(this->cells[i][j].getDividerRight()==0){
        std::string b;
        int a=j+1;
        b=std::to_string(i)+','+std::to_string(a);
        m.push_back(b);
      }
      if(this->cells[i][j].getDividerDown()==0){
        std::string b;
        int a=i+1;
        b=std::to_string(a)+','+std::to_string(j);
        m.push_back(b);
      }
      if(this->cells[i][j].getDividerLeft()==0){
        std::string b;
        int a=j-1;
        b=std::to_string(i)+','+std::to_string(a);
        m.push_back(b);
      }
      g[i][j]=m;
    }
  }
  return g;
}

std::vector<int> indexes(cell* tab[], int len){
    std::vector<int> v;
    for(int i = 0; i < len; ++i){
        if(tab[i] != NULL)
            v.push_back(i);
    }
    return v;
}

void maze::clear(){
    for(int i=0; i < 100; ++i){
        std::cout << std::endl << std::endl;
    }
}


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
    srand(time(NULL));
    this->generate(this->cells[0][0]);
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
           //std::cout << "+##";
           std::cout << "+  ";
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
         case 2:
         case 0:
            std::cout << " ";
            break;
    }
}

void maze::print(){
    this->clear();
    std::cout << std::endl << std::endl;
    for(int line = 0; line < this->height; ++line){

        for(int col = 0; col < this->width; ++col){
            this->printHori((this->cells[line][col].getDividerUp()));
            if(col == this->width-1){
                std::cout << "+";
            }
        }
        std::cout << std::endl;

        for(int col = 0; col < this->width; ++col){
            this->printVert((this->cells[line][col].getDividerLeft()));
            if(this->cells[line][col].isMarked()){
                //std::cout << "##";
                std::cout << "  ";
            }else{
                std::cout << "  ";
            }
            if(col == this->width-1){
                this->printVert((this->cells[line][col].getDividerRight()));
            }
        }
        std::cout << std::endl;
        if(line == this->height-1){
            for(int col = 0; col < this->width; ++col){
                this->printHori((this->cells[line][col].getDividerDown()));
                if(col == this->width-1){
                    std::cout << "+";
                }
            }
        }
    }
    std::cout << std::endl << std::endl;

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
    // Lie la cellule à ses cellules voisines
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

    // create all dividers and store them in a vector
    // initialise tous les murs des cellules
    // toutes les cellules sont fermées au début
    // -1 donne sur un mur incassable
    // 1 donne sur un mur cassable
    // 0 indique qu'il n'y a pas de mur
    // et 2 indique une entrée ou une sortie
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if( i == 0){
                if(j == 0){
                    int left = 2, up = -1, right = 1, down = 1;
                    this->cells[i][j].setDividers( left, up, right, down );
                }else if(j == width -1){
                    int up = -1, right = -1, down = 1;
                    this->cells[i][j].setDividers( this->cells[i][j-1].getDividerRight(), up, right, down );
                }else{
                    int up = -1, right = 1, down = 1;
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), up, right, down);
                }
            }else if(i == height-1){
                if(j == 0){
                    int left = -1, right = 1, down = -1;
                    this->cells[i][j].setDividers(left, this->cells[i-1][j].getDividerDown(), right, down);
                }else if(j == width -1){
                    int right = 2, down = -1;
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), right, down);
                }else{
                    int right = 1, down = -1;
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), right, down);
                }
            }else{
                if(j == 0){
                    int left = -1, right = 1, down = 1;
                    this->cells[i][j].setDividers(left, this->cells[i-1][j].getDividerDown(), right, down );
                }else if(j == width -1){
                    int right = -1, down = 1;
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), right, down );
                }else{
                    int right = 1, down = 1;
                    this->cells[i][j].setDividers(this->cells[i][j-1].getDividerRight(), this->cells[i-1][j].getDividerDown(), right, down );
                }
            }
        }
    }
}

cell maze::getCell(int x, int y){
    return cells[y][x];
}

std::vector<int> maze::getNexts(cell& c){
    cell* tab[4] = {NULL, NULL, NULL, NULL};  // ptrs vers cellules voisines
    // sélectionne les cellules voisines non explorées
    //
    //  si cellule existe non explorée on peut la tirer au sort
    //
    if(c.getDividerLeft() == 1){
        if(c.getLeftCell()->isMarked() == false){
            tab[0] = c.getLeftCell();
        }
    }
    if(c.getDividerUp() == 1){
        if(c.getUpCell()->isMarked() == false){
            tab[1] = c.getUpCell();
        }
    }
    if(c.getDividerRight() == 1){
        if(c.getRightCell()->isMarked() == false){
            tab[2] = c.getRightCell();
        }
    }
    if(c.getDividerDown() == 1){
        if(c.getDownCell()->isMarked() == false){
            tab[3] = c.getDownCell();
        }
    }
    std::vector<int> v = indexes(tab, 4); // copie les ptr pour tirer au sort
    return v;
}

void maze::generate(cell& c){
    // On attend avant d'aficher
    //
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    // si pas toutes les cellules explorées, continue
    //
    if(this->visited.size() != this->width * this->height){
        c.setMark(true);  // marque la cellule visitée
        this->visited.insert(c.getId());  // fait un historique des cellules précédentes

        std::vector<int> v = getNexts(c);

        this->print(); // affiche le lab

        // si il y a au moins un cellule voisine disponible...
         if(v.size() > 0){
            int way = 4;
            way = rand() % v.size(); // on tire au sort parmis les cellules inexplorées voisines
            // on casse la cloison séparant les deux cellules
            //  et on rappelle la fonction avec en parametre la cellule voisine choisie
            //
            this->antecedent.push(&c);
            // On explore la cellule qui vient d'etre tirée au sort
            switch (v[way]) {
                case 0:
                    c.getLeftCell()->setDividerRight(0);
                    c.setDividerLeft(0);
                    this->generate(*(c.getLeftCell()));
                    break;
                case 1:
                    c.getUpCell()->setDividerDown(0);
                    c.setDividerUp(0);
                    this->generate(*(c.getUpCell()));
                    break;
                case 2:
                    c.getRightCell()->setDividerLeft(0);
                    c.setDividerRight(0);
                    this->generate(*(c.getRightCell()));
                    break;
                case 3:
                    c.getDownCell()->setDividerUp(0);
                    c.setDividerDown(0);
                    this->generate(*(c.getDownCell()));
                    break;
            }

        }else{
            // si pas de cellule voisine inexplorée on recule
            if(this->antecedent.size() > 0){
                cell n = *(this->antecedent.top());
                this->antecedent.pop();
                int id = n.getId();
                // cherche la cellule qui sera revisitée
                for(std::vector<cell>&line: this->cells){
                    for(cell&item: line){
                        if(item.getId() == id)
                            this->generate(item);
                    }
                }
            }
        }
    }else{
        std::cout << "fin" << std::endl;
    }
}

void maze::debug(){
    for(std::vector<cell>&line: this->cells){
        for(cell&item: line){
            item.debug();
        }
    }
}

maze::maze(const maze& orig) {
}

maze::~maze() {
}
