#include <algorithm>

#include <game_state.h>
namespace chess {
 
GameState::GameState(): 
  white_(std::make_unique<Player>(WHITE)), 
  black_(std::make_unique<Player>(BLACK)),
  board_(Board::CreateBoard(white_.get(), black_.get())) {
}


ChessBoard const* GameState::GetBoard() const {
  return &board_;
}
std::pair<Player const*, Player const*> GameState::GetPlayers() const {
  return {white_.get(), black_.get()};
}

}
