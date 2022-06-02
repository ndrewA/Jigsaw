#include "PieceSet.h"

PieceSet::PieceSet(EdgeTypes edgesIn, std::unordered_set<Piece, Piece::PieceHash> piecesIn) : edgeCollection(edgesIn), pieces(piecesIn) {
    std::unordered_map<int, std::unordered_multimap<int, Piece>>  pieceEdges;
    for(int i = 0; i < 4; i++)
        for(auto piece : pieces)
            pieceEdges[i].insert({piece.getAt(i), piece});

    for(auto piece : pieces) {
        pieceNeighbours pn(piece);
        for(int side = 0; side < 4; side++) {
            std::unordered_set<Piece, Piece::PieceHash> s(findEdgeNeighbours(piece.getAt(side), pieceEdges[(side+2)%4]));
            pn.neighbours[side] = s;
        }
        neighbours[piece] = pn;
    }
}

std::unordered_set<Piece, Piece::PieceHash> PieceSet::findEdgeNeighbours(int s, std::unordered_multimap<int, Piece> PieceBySide) {
    std::unordered_set<Piece, Piece::PieceHash> n;
    std::unordered_set<int> foundByEdge(edgeCollection.getType(s)->neighbours);
    for(auto j : foundByEdge)
        if(PieceBySide.find(j) != PieceBySide.end())
            for(auto iter = PieceBySide.equal_range(j).first; iter != PieceBySide.equal_range(j).second; iter++)
                n.insert(iter->second);
    return n;
}
