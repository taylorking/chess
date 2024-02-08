#ifndef CHESS_HUMAN_PLAYER_H_
#define CHESS_HUMAN_PLAYER_H_
#include <models.h>
#include <player.h>

namespace chess {
class HumanPlayer : public Player {
 public:
  HumanPlayer(Color color, std::string const& name)
      : name_(name), Player(color) {}
  std::variant<Move, Rewind, Resign> RequestCommand(
      GameState const& game, std::string const& message) const override;

 private:
  std::string name_;
};
}  // namespace chess

#endif
