#include "Puzzle.h"

Puzzle::Puzzle(const int len1, const int len2, PieceSet ps) : puzzle(len1*len2), pieceSet(ps), m(len1), n(len2) {
    std::fill(puzzle.begin(), puzzle.end(), Cell(pieceSet));
}

bool Puzzle::solveMaze(int index, int solvedNum) {
    if(puzzle[index].possibilities.empty()) return false;
    puzzle[index].isSolved = true;

    if(solvedNum == n*m) {
        puzzle[index].curPiece = *puzzle[index].possibilities.begin();
        return true;
    }
    Cell left, right, up, down, curCell;
    if(index % n > 0) left = puzzle[index-1];
    if(index / n > 0) up = puzzle[index-n];
    if(index % n < n-1) {
        right = puzzle[index+1];
    }
    if(index / n < m-1) down = puzzle[index+n];
    curCell = puzzle[index];
    for(auto piece : puzzle[index].possibilities) {
        puzzle[index].curPiece = piece;

        bool isValid = true;

        if((index % n > 0) && (!puzzle[index-1].isSolved)) {
            puzzle[index-1].possibilities = intersect(pieceSet.getNeighbours(piece, 0), left.possibilities);
            if(puzzle[index-1].possibilities.empty()) isValid = false;
        }
        if((index / n > 0) && (!puzzle[index-n].isSolved)) {
            puzzle[index-n].possibilities = intersect(pieceSet.getNeighbours(piece, 1), up.possibilities);
            if(puzzle[index-n].possibilities.empty()) isValid = false;
        }
        if((index % n < n-1) && (!puzzle[index+1].isSolved)) {
            puzzle[index+1].possibilities = intersect(pieceSet.getNeighbours(piece, 2), right.possibilities);
            if(puzzle[index+1].possibilities.empty()) isValid = false;
        }
        if((index / n < m-1) && (!puzzle[index+n].isSolved)) {
            puzzle[index+n].possibilities = intersect(pieceSet.getNeighbours(piece, 3), down.possibilities);
            if(puzzle[index+n].possibilities.empty()) isValid = false;
        }
        if(isValid) {
            if((index % n > 0) && (!puzzle[index-1].isSolved)) {
                if(solveMaze(index-1, solvedNum+1)) return true;
            } else if((index / n > 0) && (!puzzle[index-n].isSolved)) {
                if(solveMaze(index-n, solvedNum+1)) return true;
            } else if((index % n < n-1) && (!puzzle[index+1].isSolved)) {
                if(solveMaze(index+1, solvedNum+1)) return true;
            } else if((index / n < m-1) && (!puzzle[index+n].isSolved)) {
                if(solveMaze(index+n, solvedNum+1)) return true;
            }
        }
        if(index % n > 0) puzzle[index-1] = left;
        if(index / n > 0) puzzle[index-n] = up;
        if(index % n < n-1) puzzle[index+1] = right;
        if(index / n < m-1) puzzle[index+n] = down;
        puzzle[index]= curCell;
    }
    puzzle[index].isSolved = false;

    return false;
}

void Puzzle::printMaze() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(puzzle[i*n+j].isSolved) {
                for(int k = 0; k < 4; k++)
                    std::cout << puzzle[i*n+j].curPiece.getAt(k);
            } else std::cout << "  - ";//std::cout << "- " << puzzle[i*n+j].possibilities.size() << "-";
            std::cout << " ";
        }
        std::cout << '\n';
    }
}

std::unordered_set<Piece, Piece::PieceHash> Puzzle::intersect(std::unordered_set<Piece, Piece::PieceHash> s1,
                                                              std::unordered_set<Piece, Piece::PieceHash> s2) {
    if(s1.empty() || s2.empty()) return std::unordered_set<Piece, Piece::PieceHash>();
    std::unordered_set<Piece, Piece::PieceHash> s;
    int mask = 0;
    for(auto p : s1) {
        mask |= (1 << p.getId());
    }
    for(auto p : s2)
        if((1 << p.getId()) & mask ) s.insert(p);

    return s;
}
