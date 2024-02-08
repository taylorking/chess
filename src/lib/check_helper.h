#ifndef CHESS_LIB_CHECK_HELPER_H_
#define CHESS_LIB_CHECK_HELPER_H_
#include <models.h>

namespace chess {
bool IsPlayerInCheck(GameState const& state, Player const* player);
}

#endif
