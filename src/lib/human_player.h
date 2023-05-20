#ifndef CHESS_LIB_HUMAN_PLAYER
#define CHESS_LIB_HUMAN_PLAYER

#include <game.h>
#include <player.h>

namespace chess {
class HumanPlayer : public Player {
 private:
  Game* game_;

 public:
  HumanPlayer(Color color, Game* game) : Player(color), game_(game) {}
  std::pair<Piece const*, Position> GetMove() const override;
};
}  // namespace chess
#endif
