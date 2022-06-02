#ifndef PIECESET_H
#define PIECESET_H

#include "Piece.h"
#include "EdgeTypes.h"

#include <unordered_set>
#include <map>
#include <unordered_map>

struct pieceNeighbours
{
    Piece piece;
    std::unordered_map<int, std::unordered_set<Piece, Piece::PieceHash>> neighbours;
    pieceNeighbours() {}
    pieceNeighbours(Piece p) : piece(p) {}
};

class PieceSet
{
    private:
        EdgeTypes edgeCollection;
        std::unordered_set<Piece, Piece::PieceHash> pieces;
        std::unordered_map<Piece, pieceNeighbours, Piece::PieceHash> neighbours;

    public:
        PieceSet(EdgeTypes edgesIn, std::unordered_set<Piece, Piece::PieceHash> piecesIn);
        ~PieceSet() {}
        std::unordered_set<Piece, Piece::PieceHash> getNeighbours(Piece piece, int side) {return neighbours[piece].neighbours[side];}
        std::unordered_set<Piece, Piece::PieceHash> getPieces() {return pieces;}

    private:
        std::unordered_set<Piece, Piece::PieceHash> findEdgeNeighbours(int s, std::unordered_multimap<int, Piece> PieceBySide);
};

#endif // PIECESET_H
