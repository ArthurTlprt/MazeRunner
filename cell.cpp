#include "cell.h"
#include <iostream>

cell::cell()
{
}

cell::cell(int id){
    idCell = id;
    std::clog << "LOG : cell number : " << idCell << " created." << std::endl;
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
    return idCell;
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

cell::~cell(){
    
}