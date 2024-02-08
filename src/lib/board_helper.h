#ifndef CHESS_LIB_BOARD_HELPER_H_
#define CHESS_LIB_BOARD_HELPER_H_
#include <models.h>
namespace chess {
bool ValidateAndApplyMove(Move const& move, Board& board);
void InitializeBoard(Game& game);
}  // namespace chess
#endif
