#include "Board.h"
#include "Piece.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include <iostream>



Board::Board(){
    /**grid.resize(8,std::vector<std::unique_ptr<Piece>>(8));
    the above code causes absolute pandemonium, copies unique ptrs*/
    grid.resize(8);
    for (auto& row : grid) {
    row.resize(8);  //each element will be nullptr by default, avoids copying
    }
    
    initializeStandardBoard();

}
Board::~Board() = default; // sigh. forward declaration needs this so piece can fully be defined.

void Board::initializeStandardBoard() {
    //white pieces (bottom)
    
    grid[0][0] = std::make_unique<Rook>(true);
    grid[0][1] = std::make_unique<Knight>(true);
    grid[0][2] = std::make_unique<Bishop>(true);
    grid[0][3] = std::make_unique<Queen>(true);
    grid[0][5] = std::make_unique<Bishop>(true);
    grid[0][6] = std::make_unique<Knight>(true);
    grid[0][7] = std::make_unique<Rook>(true);

    //black pieces (top)
    grid[7][0] = std::make_unique<Rook>(false);
    grid[7][1] = std::make_unique<Knight>(false);
    grid[7][2] = std::make_unique<Bishop>(false);
    grid[7][3] = std::make_unique<Queen>(false);
    grid[7][5] = std::make_unique<Bishop>(false);
    grid[7][6] = std::make_unique<Knight>(false);
    grid[7][7] = std::make_unique<Rook>(false);

    //add pawns and other pieces later
}

void Board::printBoard() const{
    for (int y = 7; y >= 0; y--){
        std::cout << y + 1 << " ";
        for( int x = 0; x < 8; ++x){
            if(grid[y][x]){
                std::cout << grid[y][x]->getSymbol() << " ";
            }
            else{
                std::cout << "." << " ";
            }
        }
    std::cout << "\n";
    }
    std::cout << "  a b c d e f g h\n\n";
}

const Piece* Board::getPiece(int startX, int startY) const{
    return (grid[startX][startY].get());
}
bool Board::isEmpty(int xcord, int ycord){
    return (getPiece(xcord,ycord) == nullptr);
}
