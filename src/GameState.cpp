#include "GameState.h"
#include "Type.h"

bool GameState::makeMove(const Move& m){
        //initialize stack with brackets so all numeric vals are 0
        StateDelta s_delta{};
        s_delta.move = m;
        

        s_delta.castling_before = 
        s_delta.ep_before       =    
        s_delta.halfmove_before = 
        s_delta.fullmove_before = 
        s_delta.stm_before      = 


        std::uint8_t castling_before{};
        //bitmask castling rights (WK1,WQ2,BK4,BQ8)
        Square ep_before{64}; 
        //en passant checker on partic square 

        std::uint16_t halfmove_before{};
        //keeps track of fifty move rule, aka no pawns moved no pieces taken
        std::uint16_t fullmove_before{};
        //keeps track of t
        Color stm_before{Color::WHITE};
        PieceType captured_type{PieceType::NONE};
        
        Square captured_on{64};
        
    };

    Board board_{};
    Color stm_{Color::WHITE};
    std::vector<StateDelta> history_; 




