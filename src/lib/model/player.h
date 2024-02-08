#ifndef CHESS_LIB_MODEL_PLAYER_H_
#define CHESS_LIB_MODEL_PLAYER_H_
#include <models.h>
namespace chess {
class Player {
 public:
  Player(Color color) : color_(color) {}
  virtual std::variant<Move, Rewind, Resign> RequestCommand(
      GameState const& game, std::string const& message) const = 0;
  bool CheckForCheckmate(GameState const& game, const Player* opposing_player) const;
  Color color_;
};
}
#endif
