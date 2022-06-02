#include "EdgeTypes.h"

#include <iostream>

void EdgeTypes::addNeighbour(const int type1, const int type2) {
    try {
        getType(type1)->neighbours.insert(type2);
        if(type1 != type2) getType(type2)->neighbours.insert(type1);
    }
    catch(int t) {std::cout << "type " << t << " has NOT been FOUND\n";}
}

Edge* EdgeTypes::getType(const int type) {
    if(getByType.find(type) == getByType.end()) throw type;
    return getByType[type];
}
