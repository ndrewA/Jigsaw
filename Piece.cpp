#include "Piece.h"

Piece::Piece(int edgeIn[], const int idIn) : id(idIn) {
    for(unsigned short i = 0; i < 4; i++)
        pieceEdges[i] = edgeIn[i];
}


bool Piece::operator == (const Piece& otherPiece) const {
    if (this->pieceEdges[0] == otherPiece.pieceEdges[0] &&
        this->pieceEdges[1] == otherPiece.pieceEdges[1] &&
        this->pieceEdges[2] == otherPiece.pieceEdges[2] &&
        this->pieceEdges[3] == otherPiece.pieceEdges[3] &&
        this->id == otherPiece.id) return true;
    return false;
}

size_t Piece::PieceHash::operator()(const Piece& piece) const {
    size_t hash0 = std::hash<int>()(piece.pieceEdges[0]);
    size_t hash1 = std::hash<int>()(piece.pieceEdges[1]) << 1;
    size_t hash2 = std::hash<int>()(piece.pieceEdges[2]) << 2;
    size_t hash3 = std::hash<int>()(piece.pieceEdges[3]) << 3;
    return hash0 ^ hash1 ^ hash2 ^ hash3;
}
