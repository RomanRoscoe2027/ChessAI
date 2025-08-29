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
    void setBoard(auto&& grid);
    void initializeStandardBoard();
    //beginning of games, set up pieces restarting game etc
    //auto only works in c++20 for func params, careful boy
    //double apersand for r and l values, not really needed but useful to know

    //internet suggests seperate initialize board and setboard functions... mmmffff
    //EDIT an hour later - makes sense, dont want to set board manually everytime
    void printBoard() const;
    //after every move/turn board must be updated
   
    const Piece* getPiece(int startX, int startY) const;
    //access piece at grid square
    bool movePiece(int startX, int endX, int startY, int endY, Piece* piece);
    bool isEmpty(int xcord, int ycord);
};
#endif //BOARD_H