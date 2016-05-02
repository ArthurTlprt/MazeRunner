#include <vector>
#include <stdio.h>
#include <iostream>
class node
{
public:
    node();
    node(int x, int y):px(x),py(y){dist=0;cost=0;};
    void setDistance(float distValue){dist = distValue;};
    void setCost(float costValue){cost = costValue;};
    void setHeurist(float heuristValue){heurist = heuristValue;};
    void setX(int x){px = x;};
    void setY(int y){py = y;};
    int getX() const{return px;};
    int getY() const{return py;};
    float getHeurist() const{return this->getCost()+this->getDist();};
    float getDist() const{return dist;};
    float getCost() const{return cost;};
    void setSuccessors(std::vector<node> successor){successors = successor;};
    node operator=(const node& a){
        cost = a.getCost();
        dist = a.getDist();
        heurist = a.getHeurist();
        px = a.getX();
        py = a.getY();
        return *this;
    }
    ~node();
private:
    int px,py;
    float dist,cost,heurist;
    std::vector<node> successors;
};

inline bool operator==(const node& c,const node& b){
    return (c.getX() == b.getX() && c.getY() == b.getY());
};

inline std::ostream& operator<<(std::ostream& out, const node& a){
    return out << "(" << a.getX() << "," << a.getY() << ")" << "[" << a.getDist() << "]" << "[" << a.getHeurist() << "]" << "[" << a.getCost() << "]";
};

inline bool operator<(const node& a, const node& b){
    if( a.getHeurist() < b.getHeurist() ){
        return true;
    }else{
        return false;
    }
}



