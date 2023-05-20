#include <game.h>
#include <game_state.h>

namespace chess {
Game::Game() : current_state_(std::make_unique<GameState>()) {}

GameState const* Game::GetCurrentState() { return current_state_.get(); }

}  // namespace chess
