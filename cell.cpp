
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

void cell::setDividerLeft(const bool& left) {
    this->dividerLeft = left;
}

void cell::setDividerUp(const bool& up) {
    this->dividerUp = up;
}

void cell::setDividerRight(const bool& right) {
    this->dividerRight = right;
}

void cell::setDividerDown(const bool& down) {
    this->dividerDown = down;
}

void cell::setDividers(const bool& left, const bool& up, const bool& right, const bool& down){
    cell::setDividerLeft(left);
    cell::setDividerRight(right);
    cell::setDividerUp(up);
    cell::setDividerDown(down);
}

const bool & cell::getDividerLeft(){
    return dividerLeft;
}

const bool & cell::getDividerUp(){
    return dividerUp;
}

const bool & cell::getDividerRight(){
    return dividerRight;
}

const bool & cell::getDividerDown(){
    return dividerDown;
}

cell::~cell(){

}
