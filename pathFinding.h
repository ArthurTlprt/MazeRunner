#include "node.h"
#include <vector>
#include <string>
#include <list>
#include <map>

node getLowestFOfList(std::list<node> list);
std::vector<node> createSuccessor(std::string);
float distance(node goal, node current);
std::multimap<int,int> parseSuccessor(std::string successor);
void displayList(std::list<node> list, std::string name);