#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Board.h"

class King: public Piece{
    public:
        King(bool isWhite); // color determines everything else

        bool isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const override;
        //check if logical move, will implement blocking logic and such later

};

#endif //KING_H
