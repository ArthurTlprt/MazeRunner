#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "pathFinding.h"
#include <math.h>
#define lentgthMaze 10

int findPath(std::string maze_Map[][],int size)
{
    std::string maze_map[3][3];
    int i = 0;
    maze_map[0][0]="0,1/1,0";
    maze_map[0][1]="0,2/0,0/1,1";
    maze_map[0][2]="1,2/0,1";
    maze_map[1][0]="0,0/2,0/1,1";
    maze_map[1][1]="0,1/2,1/1,0/1,2";
    maze_map[1][2]="2,2/0,2/1,1";
    maze_map[2][2]="2,1/1,2";
    maze_map[2][1]="2,0/2,2/1,1";
    maze_map[2][0]="2,1/1,0";
    
    // OPEN/CLOSED list et leurs iterator
    std::list<node> openList;
    std::list<node>::iterator itListOpen;
    std::list<node> closeList;
    std::list<node>::iterator itListClose;
    std::vector<node> successors;
    std::vector<node>::iterator it_node_successor;
    
    // Creation de la premiere et derniere case (depart,arrivé)
    node cell_goal(2,2);
    node cell_start(0,0);
    cell_start.setCost(0);
    cell_start.setHeurist(0);
    node cell_current;
    node node_stock;
    // Ajout du depart a l'open
    openList.push_back(cell_start);
    // Tant qu'on break pas ou que la list n'est pas plein
    while(!openList.empty()){
        // On recupere le noeud avec le poid le plus faible
        cell_current = openList.back();
        std::cout << "node_current : " << cell_current << std::endl;
        // Si c'est le noeud d'arrivé on stop
        if(cell_current == cell_goal){
            std::cout << "Reach" << std::endl;
            std::cout << "Voici le chemin a prendre : ";
            displayList(closeList,"");
            std::cout << std::endl;
            return 0;
        }else{
            // Sinon on recupére ses successeur
            successors = createSuccessor(maze_map[cell_current.getX()][cell_current.getY()]);
            // Pour chaque successeur on defini sont g
            for(it_node_successor=successors.begin();it_node_successor!=successors.end();it_node_successor++){
                node_stock = *(it_node_successor);
                std::cout << "node_successor(" << i << " ): " << node_stock << std::endl;
                // trouvé si le noeud est deja dans OPEN ou CLOSE, si oui on le jette de la liste
                itListOpen = find(openList.begin(),openList.end(),node_stock);
                itListClose = find(closeList.begin(),closeList.end(),node_stock);
                displayList(openList,"open");
                if( (itListOpen!=openList.end() && node_stock.getHeurist() <= (*(itListOpen)).getHeurist()) || (itListClose!=closeList.end() && node_stock.getHeurist() <= (*(itListClose)).getHeurist())){
                }else{
                node_stock.setCost(cell_current.getCost()+1);
                node_stock.setDistance(distance(cell_goal,node_stock));
                node_stock.setHeurist(node_stock.getHeurist());
                openList.push_back(node_stock);
                openList.sort();
                }
            }
        }
        closeList.push_back(cell_current);
        displayList(closeList,"close");
    }
    return -1;
}

std::vector<node> createSuccessor(std::string successorsString){
    std::multimap<int,int>::iterator itChild;
    
    std::vector<node> successors;
    
    std::multimap<int,int> coordChild = parseSuccessor(successorsString);
    for(itChild = coordChild.begin();itChild!=coordChild.end();itChild+){
        successors.push_back(node((*itChild).first,(*itChild).second));
    }
    return successors;
};

float distance(node goal, node current){
    float h =  sqrt((goal.getX()-current.getX())*(goal.getX()-current.getX())(goal.getY()-current.getY())*(goal.getY()-current.getY()));
    return h;
};

std::multimap<int,int> parseSuccessor(std::string successor){
    std::multimap<int,int> coordChild;
    std::string coordChain;
    for(int i =0; i<(int)successor.size();i=i+4){
        coordChain = successor.substr(i,3);
        coordChild.insert(std::make_pair(coordChain[0]-'0',coordChain[2]-'0'));
    }
    return coordChild;
};

void displayList(std::list<node> list,std::string name){
    std::cout <<"liste : " << name;
    std::list<node>::iterator p = list.begin();
    while(p != list.end()) {
        std::cout << *p << " / ";
        p++;
    }
    std::cout << std::endl;
}



