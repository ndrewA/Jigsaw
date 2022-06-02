#ifndef EDGETYPES_H
#define EDGETYPES_H

#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <iostream>

struct Edge
{
    std::unordered_set<int> neighbours;
    int type;
    Edge() {}
    Edge(const int t) : type(t) {}
};

class EdgeTypes
{
    private:
        std::unordered_map<int, Edge*> getByType;
    public:
        EdgeTypes() {}
        ~EdgeTypes() {getByType.clear();}
        void addEdge(const int type) {getByType[type] = new Edge(type);}
        void addNeighbour(const int neighbour1, const int neighbour2);
        Edge* getType(const int type);
        std::unordered_set<int> getNeighbours(const int type) {return getByType[type]->neighbours;}
};

#endif // EDGETYPES_H
