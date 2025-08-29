#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Board.h"
class Pawn : public Piece {
public:

    Pawn(bool isWhite);  
    // need to know if white or black to determine symbol as well
    bool isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const override; 
    //declare move logic
};

#endif //PAWN_H
