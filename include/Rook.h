#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:

    Rook(bool isWhite);  
    // need to know if white or black to determine symbol as well
    bool isValidMove(int startX, int startY, int endX, int endY) const override; 
    //declare move logic
    

};

#endif
