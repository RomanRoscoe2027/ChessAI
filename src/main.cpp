#include "Board.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    Board board;           // This calls the constructor, which sets up the board
    board.printBoard();    // This prints the current state to the terminal
    return 0;
}
