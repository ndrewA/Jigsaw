#include "Puzzle.h"

#include <unordered_set>
#include <iostream>

void printNeighbours(PieceSet ps, std::unordered_set<Piece, Piece::PieceHash> ph) {
    for(auto piece : ph) {
        for(int side = 0; side < 4; side++)
            std::cout << piece.getAt(side) << ' ';
        std::cout << '\n';
        for(int side = 0; side < 4; side++) {
            std::cout << "side = " << side << '\n';
            for(auto n : ps.getNeighbours(piece, side)) {
                for(int j = 0; j < 4; j++)
                    std::cout << n.getAt(j) << ' ';
                std::cout << '\n';
            }
        }
        std::cout << "=======\n";
    }
}

int main()
{
    EdgeTypes et;
    et.addEdge(3);
    et.addEdge(4);
    et.addEdge(5);
    et.addNeighbour(3, 4);
    //et.addNeighbour(4, 5);

    int arr1[4] = {3, 3, 3, 3};
    Piece p1(arr1, 0);
    int arr2[4] = {4, 4, 4, 4};
    Piece p2(arr2, 1);
    int arr3[4] = {5, 3, 3, 3};
    Piece p3(arr3, 2);
    std::unordered_set<Piece, Piece::PieceHash> ph;
    ph.insert(p1);
    ph.insert(p2);
    ph.insert(p3);
    //ph.insert(p4);
    PieceSet ps(et, ph);
    //printNeighbours(ps, ph);
    Puzzle puzzle(5, 4, ps);
    puzzle.solveMaze() ? std::cout << "SOLVED\n" : std::cout << "NOT SOLVED\n";
    puzzle.printMaze();
    return 0;
}
