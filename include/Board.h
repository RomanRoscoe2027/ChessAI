#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"   // <-- must include this for unique_ptr<Piece>

#include <vector>
#include <memory> 
//unique ptrs
//choosing vector for board, despite fixed size, for bound checking
class Board{
private:
    std::vector<std::vector<std::unique_ptr<Piece>>> grid;
//std::vector<std::vector<Piece*>> grid; - was first idea until discovered unique ptrs
//set up board as 2d array with pieces as main focus
public:
    Board();
    ~Board() = default;
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
    //move a piece from (startX,startY) to (endX,endY). Returns any captured piece.
    std::unique_ptr<Piece> movePiece(int startX, int startY, int endX, int endY);
    //place a piece (used for undo/restore). Takes ownership of the pointer.
    void placePiece(int x, int y, std::unique_ptr<Piece> piece);
    bool isEmpty(int xcord, int ycord)const;
};
#endif //BOARD_H