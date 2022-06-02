#ifndef PUZZLE_H
#define PUZZLE_H

#include "PieceSet.h"

struct Cell {
    bool isSolved;
    Piece curPiece;
    std::unordered_set<Piece, Piece::PieceHash> possibilities;
    Cell() {}
    Cell(PieceSet ps) : isSolved(false), possibilities(ps.getPieces()) {}
};

class Puzzle
{
    private:
        std::vector<Cell> puzzle;
        PieceSet pieceSet;
        int m, n;

    public:
        Puzzle(const int len1, const int len2, PieceSet ps);
        ~Puzzle() {}
        bool solveMaze() {return solveMaze(0, 1);}
        void printMaze();

    private:
        bool solveMaze(int index, int solvedNum);
        std::unordered_set<Piece, Piece::PieceHash> intersect(std::unordered_set<Piece, Piece::PieceHash> s1,
                                                              std::unordered_set<Piece, Piece::PieceHash> s2);

};

#endif // PUZZLE_H
