
#include "cell.h"
#include <iostream>

cell::cell()
{
}

cell::cell(int x, int y) {
    this->setMark(false);
}

cell::cell(cell* left, cell* up, cell* right, cell* down) {
    this->setLeftCell(left);
    this->setLeftCell(up);
    this->setLeftCell(right);
    this->setLeftCell(down);
    this->setMark(false);
}


cell::cell(int id){
    this->id = id;
    std::clog << "LOG : cell number : " << this->id << " created." << std::endl;
    this->setMark(false);
}
/**
 * @brief getteur celulle de gauche
 * @return cell
 */
cell* cell::getLeftCell(){
    return leftCell;
}

/**
 * @brief getteur celulle du haut
 * @return cell
 */
cell* cell::getUpCell(){
    return upCell;
}

/**
 * @brief getteur celulle de droite
 * @return cell
 */
cell* cell::getRightCell(){
    return rightCell;
}

/**
 * @brief getteur de celulle du bas
 * @return cell
 */
cell* cell::getDownCell(){
    return downCell;
}

/**
 * @brief Retourne la cellule suivant de l'actuelle
 * @return cell ou NULL Cellule Suivante
 */
cell* cell::getNextCell(){
    if(rightCell != NULL){
        return rightCell;
    }else if(downCell != NULL){
        return downCell;
    }else{
        return NULL;
    }
}

/**
 * @brief retourne l'id de la cellule
 * @return int id
 */
int cell::getId(){
    return id;
}

void cell::setNeighborhood(cell* left, cell* up, cell* right, cell* down) {
    setUpCell(up);
    setDownCell(down);
    setLeftCell(left);
    setRightCell(right);
}


/**
 * @brief Attribut une celulle à sa gauche
 * @param left cellule de gauche
 */
void cell::setLeftCell(cell* left){
    leftCell = left;
}

/**
 * @brief Attribut une celulle au dessus
 * @param up celulle du dessus
 */
void cell::setUpCell(cell* up){
    upCell = up;
}

/**
 * @brief Attribut une celulle à sa droite
 * @param right celulle de droite
 */
void cell::setRightCell(cell* right){
    rightCell = right;
}

/**
 * @brief Attribut une cellule au dessous
 * @param down celulle du dessous
 */
void cell::setDownCell(cell* down){
    downCell = down;
}

void cell::setId(int id) {
    this->id = id;
}

void cell::setDividerLeft(int* divLeft) {
    this->dividerLeft = divLeft;
}

void cell::setDividerUp(int* divUp) {
    this->dividerUp = divUp;
}

void cell::setDividerRight(int* divRight) {
    this->dividerRight = divRight;
}

void cell::setDividerDown(int* divDown) {
    this->dividerDown = divDown;
}

void cell::setDividers(int *divLeft, int *divUp, int *divRight, int *divDown){
    cell::setDividerLeft(divLeft);
    cell::setDividerRight(divRight);
    cell::setDividerUp(divUp);
    cell::setDividerDown(divDown);
}

int* cell::getDividerLeft(){
    return dividerLeft;
}

int* cell::getDividerUp(){
    return dividerUp;
}

int* cell::getDividerRight(){
    return dividerRight;
}

int* cell::getDividerDown(){
    return dividerDown;
}

void cell::debug(){
    std::cout << "id:           " << this->getId() << std::endl;
    std::cout << "div left      " << *(this->getDividerLeft()) << std::endl;
    std::cout << "div Up        " << *(this->getDividerUp()) << std::endl;
    std::cout << "div Right     " << *(this->getDividerRight()) << std::endl;
    std::cout << "div Down      " << *(this->getDividerDown()) << std::endl;
}

void cell::setMark(bool b){
    this->marked = b;
}

bool cell::isMarked(){
    return this->marked;
}

cell::~cell(){

}
