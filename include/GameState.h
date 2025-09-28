// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <cstdint>
#include "Type.h"
#include "Board.h"

class GameState {
public:
    
    GameState(Color start = Color::WHITE) noexcept;

    bool makeMove(const Move& m) noexcept;
    void unmakeMove() noexcept;

    

private:

    struct StateDelta {
        //essentially a stack that recalls just enough info to go back
        Move move;

        std::uint8_t castling_before{0};
        //bitmask castling rights (WK1,WQ2,BK4,BQ8)
        Square ep_before{64}; 
        //en passant checker on partic square 

        std::uint16_t halfmove_before{0};
        //keeps track of fifty move rule, aka no pawns moved no pieces taken
        std::uint16_t fullmove_before{1};
        //keeps track of t
        Color stm_before{Color::WHITE};
        PieceType captured_type{PieceType::NONE};
        
        Square captured_on{64};
        
    };

    Board board_{};
    Color stm_{Color::WHITE};
    std::vector<StateDelta> history_; 
};

#endif // GAMESTATE_H
