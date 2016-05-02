#include "node.h"
#include <vector>
#include <string>
#include <list>
#include <map>
#include "../generator/json.hpp"
using json = nlohmann::json;

std::vector<node> createSuccessor(std::string successorsString);
float distance(node goal, node current);
std::multimap<int,int> parseSuccessor(std::string successor);
void displayList(std::list<node> list, std::string name);
int findPath(std::map<std::string,std::string> maze_map,int size);