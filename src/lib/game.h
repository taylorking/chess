#ifndef CHESS_LIB_GAME
#define CHESS_LIB_GAME

#include <game_state.h>
#include <vector>

namespace chess {
class Game {
 private:
  std::vector<std::unique_ptr<GameState>> previous_states_;
  std::unique_ptr<Player> white_;
  std::unique_ptr<Player> black_;
  std::unique_ptr<GameState> current_state_;

 public:
  Game();
  GameState const* GetCurrentState();
  void Run();
};
}  // namespace chess
#endif
