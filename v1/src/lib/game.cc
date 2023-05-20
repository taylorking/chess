#include <board_printer.h>
#include <game.h>
#include <game_state.h>
#include <human_player.h>
#include <iostream>
#include <memory>

namespace chess {
Game::Game()
    : white_(std::make_unique<HumanPlayer>(Color::WHITE, this)),
      black_(std::make_unique<HumanPlayer>(Color::BLACK, this)),
      current_state_(std::make_unique<GameState>(white_.get(), black_.get())) {}

GameState const* Game::GetCurrentState() { return current_state_.get(); }

void Game::Run() {
  while (true) {
    std::cout << PrintBoard(*current_state_->GetBoard());
    Player const* p = current_state_->GetCurrentTurn();
    auto [piece, move] = p->GetMove();
    {
      auto new_state = current_state_->ValidateAndApplyMove(piece, move);
      if (new_state != nullptr) {
        previous_states_.push_back(std::move(current_state_));
        current_state_ = std::move(new_state);
      }
    }
  }
}
}  // namespace chess
