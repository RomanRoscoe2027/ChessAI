#include "Board.h"
#include "Piece.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
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

void Board::initializeStandardBoard() {
    //white pieces (bottom)
    grid[1][0] = std::make_unique<Pawn>(true);
    grid[1][1] = std::make_unique<Pawn>(true);
    grid[1][2] = std::make_unique<Pawn>(true);
    grid[1][3] = std::make_unique<Pawn>(true);
    grid[1][4] = std::make_unique<Pawn>(true);
    grid[1][5] = std::make_unique<Pawn>(true);
    grid[1][6] = std::make_unique<Pawn>(true);
    grid[1][7] = std::make_unique<Pawn>(true);

    grid[0][0] = std::make_unique<Rook>(true);
    grid[0][1] = std::make_unique<Knight>(true);
    grid[0][2] = std::make_unique<Bishop>(true);
    grid[0][3] = std::make_unique<Queen>(true);
    grid[0][4] = std::make_unique<King>(true);
    grid[0][5] = std::make_unique<Bishop>(true);
    grid[0][6] = std::make_unique<Knight>(true);
    grid[0][7] = std::make_unique<Rook>(true);

    //black pieces (top)
    grid[6][0] = std::make_unique<Pawn>(false);
    grid[6][1] = std::make_unique<Pawn>(false);
    grid[6][2] = std::make_unique<Pawn>(false);
    grid[6][3] = std::make_unique<Pawn>(false);
    grid[6][4] = std::make_unique<Pawn>(false);
    grid[6][5] = std::make_unique<Pawn>(false);
    grid[6][6] = std::make_unique<Pawn>(false);
    grid[6][7] = std::make_unique<Pawn>(false);

    grid[7][0] = std::make_unique<Rook>(false);
    grid[7][1] = std::make_unique<Knight>(false);
    grid[7][2] = std::make_unique<Bishop>(false);
    grid[7][3] = std::make_unique<Queen>(false);
    grid[7][4] = std::make_unique<King>(false);
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
    // grid is stored as grid[row][col] where row == y, col == x
    if (startY < 0 || startY >= 8 || startX < 0 || startX >= 8) return nullptr;
    return (grid[startY][startX].get());
}

std::unique_ptr<Piece> Board::movePiece(int startX, int startY, int endX, int endY){
    if (startY < 0 || startY >= 8 || startX < 0 || startX >= 8) return nullptr;
    if (endY < 0 || endY >= 8 || endX < 0 || endX >= 8) return nullptr;

    // take ownership of source
    std::unique_ptr<Piece> moving = std::move(grid[startY][startX]);
    // capture (take ownership) of destination
    std::unique_ptr<Piece> captured = std::move(grid[endY][endX]);
    // place moving piece into destination
    grid[endY][endX] = std::move(moving);
    // ensure source square is empty
    grid[startY][startX].reset();
    return captured;
}

void Board::placePiece(int x, int y, std::unique_ptr<Piece> piece){
    if (y < 0 || y >= 8 || x < 0 || x >= 8) return;
    grid[y][x] = std::move(piece);
}

bool Board::isEmpty(int xcord, int ycord) const{
    return (getPiece(xcord,ycord) == nullptr);
}
