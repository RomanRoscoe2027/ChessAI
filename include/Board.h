#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>
#include <memory> //unique ptrs
//choosing vector for board, despite fixed size, for bound checking
class Board{
private:
    std::vector<std::vector<std::unique_ptr<Piece>>> grid;
//std::vector<std::vector<Piece*>> grid; - was first idea until discovered unique ptrs
//set up board as 2d array with pieces as main focus
public:
    Board();
    void setBoard(auto &grid);
    //beginning of games, set up pieces restarting game etc
    void printboard() const;
    //after every move/turn board must be updated
   
    Piece* getPiece(int startX, int startY);
    //access piece at grid square
    bool movePiece(int startX, int endX, int startY, int endY, Piece* piece);
};
#endif //BOARD_H