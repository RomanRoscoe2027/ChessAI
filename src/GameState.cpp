#include "GameState.h"
#include "Type.h"




void nextTurn();
bool getTurn(const Color side_to_move);

int getTurnNumber(MoveList move_data) {return move_data.count;}

void make_move (const Move &move);
void undo_move (const Move &move);
     
bool playIfLegal(const Move& m);
bool isSquareAttacked(const Move& m);


