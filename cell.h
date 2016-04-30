
#ifndef CELL_H
#define CELL_H

class cell
{
public:
    cell();
    //cell(const cell& c);
    cell(int id);
    cell(int x, int y);
    cell(cell* left,cell* up,cell* right,cell* down);
    ~cell();
    int getId();
    cell* getLeftCell();
    cell* getUpCell();
    cell* getRightCell();
    cell* getDownCell();
    cell* getNextCell();
    void setNeighborhood(cell* left, cell* up,cell* right,cell* down);
    void setLeftCell(cell* left);
    void setUpCell(cell* up);
    void setRightCell(cell* right);
    void setDownCell(cell* down);
    void setDividers(int divLeft, int divUp, int divRight, int divDown);
    void setDividerLeft(int divLeft);
    void setDividerUp(int divUp);
    void setDividerRight(int divRight);
    void setDividerDown(int divDown);
    int getDividerLeft();
    int getDividerUp();
    int getDividerRight();
    int getDividerDown();
    void setId(int id);
    void debug();
    void setMark(bool b);
    bool isMarked();
private:
    // ref vers cellule voisine, NULL si la cell donne sur un mur
    cell* leftCell;
    cell* upCell;
    cell* rightCell;
    cell* downCell;
    // coordonnées de la cellule
    int x;
    int y;
    int id;
    bool marked;
    /**
     *  si la cellule done sur:
     *  - un mur = -1
     *  - une cloison = 1
     *  - la cellule voisine = 0
     *  - entrée ou sortie = 2
     */
    int dividerLeft;
    int dividerUp;
    int dividerRight;
    int dividerDown;
    // int value;
    /* Pas sur que l'on ai besoin d'une valeur si on a l'id */
};

#endif // CELL_H
