#include "GameState.h"
#include "Type.h"
#include <iostream>
#include <string>

// parse algebraic like e2 -> x=4,y=1
static bool parseSquare(const std::string &s, Square &out){
    if (s.size() != 2) return false;
    char file = s[0];
    char rank = s[1];
    if (file < 'a' || file > 'h') return false;
    if (rank < '1' || rank > '8') return false;
    int x = file - 'a';
    int y = rank - '1';
    out = encode_square(x,y);
    return true;
}

int main(){
    GameState gs{};
    gs.makeMove(Move{}); // no-op to ensure board exists (silently ignored in makeMove if invalid)
    std::cout << "Simple Chess CLI - enter moves like e2e4 or 'q' to quit\n";

    // print initial board
    gs.printBoard();

    while (true){
        std::cout << (gs.sideToMove() == Color::WHITE ? "White> " : "Black> ");
        std::string line;
        if(!std::getline(std::cin, line)) break;
        if(line == "q" || line == "quit") break;
        if(line.size() < 4){
            std::cout << "Enter moves like e2e4\n";
            continue;
        }
        std::string froms = line.substr(0,2);
        std::string tos = line.substr(2,2);
        Square from,to;
        if(!parseSquare(froms, from) || !parseSquare(tos, to)){
            std::cout << "Invalid move format. Use e2e4\n";
            continue;
        }
        Move m;
        m.from = from;
        m.to = to;
        std::string reason;
        if(!gs.canMove(m, reason)){
            std::cout << "Move failed: " << reason << "\n";
            continue;
        }

        if(gs.makeMove(m)){
            gs.printBoard();
        } else {
            std::cout << "Move failed during execution\n";
        }
    }

    return 0;
}
