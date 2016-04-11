
#include "cell.h"
#include <iostream>

cell::cell()
{
}

cell::cell(int x, int y) {

}


cell::cell(const cell& left, const cell& up, const cell& right,const cell& down){
  setUpCell(up);
  setDownCell(down);
  setLeftCell(left);
  setRightCell(right);
}

cell::cell(int id){
    this->id = id;
    std::clog << "LOG : cell number : " << this->id << " created." << std::endl;
}

/**
 * @brief getteur celulle de gauche
 * @return cell
 */
const cell & cell::getLeftCell(){
    return leftCell;
}

/**
 * @brief getteur celulle du haut
 * @return cell
 */
const cell & cell::getUpCell(){
    return upCell;
}

/**
 * @brief getteur celulle de droite
 * @return cell
 */
const cell & cell::getRightCell(){
    return rightCell;
}

/**
 * @brief getteur de celulle du bas
 * @return cell
 */
const cell & cell::getDownCell(){
    return downCell;
}

/**
 * @brief retourne l'id de la cellule
 * @return int id
 */
int cell::getId(){
    return id;
}

void cell::setNeighborhood(const cell& left, const cell& up, const cell& right,const cell& down) {
    setUpCell(up);
    setDownCell(down);
    setLeftCell(left);
    setRightCell(right);
}


/**
 * @brief Attribut une celulle à sa gauche
 * @param left cellule de gauche
 */
void cell::setLeftCell(const cell& left){
    leftCell = left;
}

/**
 * @brief Attribut une celulle au dessus
 * @param up celulle du dessus
 */
void cell::setUpCell(const cell& up){
    upCell = up;
}

/**
 * @brief Attribut une celulle à sa droite
 * @param right celulle de droite
 */
void cell::setRightCell(const cell& right){
    rightCell = right;
}

/**
 * @brief Attribut une cellule au dessous
 * @param down celulle du dessous
 */
void cell::setDownCell(const cell& down){
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

cell::~cell(){

}
