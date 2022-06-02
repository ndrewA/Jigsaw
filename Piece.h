#ifndef PIECE_H
#define PIECE_H

#include "EdgeTypes.h"

class Piece
{
    private:
        int pieceEdges[4];
        int id;

    public:
        struct PieceHash {
            size_t operator()(const Piece& piece) const;
        };

    public:
        Piece() {}
        Piece(int edgeIn[], const int idIn);
        ~Piece() {}
        int getAt(const int index) {return pieceEdges[index];}
        int getId() {return id;}
        bool operator == (const Piece& otherPiece) const;
};

#endif // PIECE_H
