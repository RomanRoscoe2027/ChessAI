#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "Board.h" 
class Rook : public Piece {
public:

    Rook(bool isWhite);  
    // need to know if white or black to determine symbol as well
    bool isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const override; 
    //declare move logic
    bool rookHasMoved(bool first_move) const;

};

#endif //ROOK_H
