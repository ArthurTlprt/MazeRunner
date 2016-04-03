#include "cell.h"

cell::cell()
{
}
/**
 * @brief constructeur par copie
 * @param a celulle source
 */
cell::~cell(cell a){
    if(a==NULL){
        std::cerr << "WARNING : Initiated cell number : " << this.idCell << " with NULL value." << endl;
    }
    setLeftCell(a.getLeftCell());
    setUpCell(a.getUpCell());
    setRightCell(a.getRightCell());
    setDownCell(a.getDownCell());
    setId(a.getId());
}

/**
 * @brief getteur celulle de gauche
 * @return cell
 */
cell cell::getLeftCell(){
    return this.leftCell;
}

/**
 * @brief getteur celulle du haut 
 * @return cell
 */
cell cell::getUpCell(){
    return this.upCell;
}

/**
 * @brief getteur celulle de droite
 * @return cell
 */
cell cell::getRightCell(){
    return this.rightCell;
}

/**
 * @brief getteur de celulle du bas
 * @return cell
 */
cell cell::getDownCell(){
    return this.downCell;
}

/**
 * @brief Retourne la cellule suivant de l'actuelle
 * @return cell ou NULL Cellule Suivante
 */
cell cell::getNextCell(){
    if(this.rightCell != NULL){
        return this.rightCell;
    }else if(this.downCell != NULL){
        return this.downCell;
    }else{
        return NULL;
    }
}

/**
 * @brief retourne l'id de la cellule
 * @return int id
 */
int cell::getId(){
    return this.idCell;
}

/**
 * @brief Attribut une celulle à sa gauche
 * @param left cellule de gauche
 */
void cell::setLeftCell(cell left){
    leftCell = left;
}

/**
 * @brief Attribut une celulle au dessus
 * @param up celulle du dessus
 */
void cell::setUpCell(cell up){
    upCell = up;
}

/**
 * @brief Attribut une celulle à sa droite
 * @param right celulle de droite
 */
void cell::setRightCell(cell right){
    rightCell = right;
}

/**
 * @brief Attribut une cellule au dessous
 * @param down celulle du dessous
 */
void cell::setDownCell(cell down){
    downCell = down;
}
