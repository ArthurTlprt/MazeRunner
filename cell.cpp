#include "cell.h"
#include <iostream>

cell::cell()
{
}

cell::cell(int x, int y) {
    
}

cell::cell(cell* left, cell* up, cell* right, cell* down) {

}


cell::cell(int id){
    this->id = id;
    std::clog << "LOG : cell number : " << this->id << " created." << std::endl;
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


cell::~cell(){
    
}