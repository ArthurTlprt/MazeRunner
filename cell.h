#ifndef CELL_H
#define CELL_H

class cell
{
public:
    cell();
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
    void setLeftCell(cell* left);
    void setUpCell(cell* up);
    void setRightCell(cell* right);
    void setDownCell(cell* down);
    void setId(int id);
private:
    // ref vers cellule voisine, NULL si la cell donne sur un mur
    cell* leftCell;
    cell* upCell;
    cell* rightCell;
    cell* downCell;
    // true si cellul donne sur une cloison
    bool dividerLeft;
    bool dividerUp;
    bool dividerRight;
    bool dividerDown;
    // coordonnées de la cellule
    int x;
    int y;
    /* J'hesite à faire un tableau de cell plutot que chaque cell */
    int id;
    bool marked;
    // int value;
    /* Pas sur que l'on ai besoin d'une valeur si on a l'id */
};

#endif // CELL_H
