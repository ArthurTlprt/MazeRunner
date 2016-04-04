#ifndef CELL_H
#define CELL_H

class cell
{
public:
    cell();
    cell(cell a);
    cell(cell left, cell up, cell right, cell down);
    ~cell();
    int getId();
    cell getLeftCell();
    cell getUpCell();
    cell getRightCell();
    cell getDownCell();
    cell getNextCell();
    void setLeftCell(cell left);
    void setUpCell(cell up);
    void setRightCell(cell right);
    void setDownCell(cell down);
private:
    cell leftCell;
    cell upCell;
    cell rightCell;
    cell downCell;
    /* J'hesite à faire un tableau de cell plutot que chaque cell */
    int idCell;
    bool marked
    // int value;
    /* Pas sur que l'on ai besoin d'une valeur si on a l'id */
};

#endif // CELL_H
