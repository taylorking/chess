#ifndef CHESS_LIB_GAME_RUNNER_H_
#define CHESS_LIB_GAME_RUNNER_H_
#include <memory>
#include <models.h>
#include <optional>

namespace chess {
Game* SetupNewGame(Player* white_player_, Player* black_player_);
void RunGame(Game*);
std::optional<std::unique_ptr<GameState>> ApplyMoveForInvalidOrNewState(
    GameState const& state, Move const& move, Player const* opposing_player);
}  // namespace chess
#endif
