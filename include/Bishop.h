#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:

    Bishop(bool isWhite);  
    // need to know if white or black to determine symbol as well
    bool isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const override; 
    //declare move logic
    

};

#endif // BISHOP_H
