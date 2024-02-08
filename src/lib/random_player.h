#ifndef CHESS_LIB_RANDOM_PLAYER_H_
#define CHESS_LIB_RANDOM_PLAYER_H_
#include <models.h>
#include <player.h>
namespace chess {

class RandomPlayer : public Player {
 public:
  RandomPlayer(Color color, Player const* opposing_player)
      : opposing_player_(opposing_player), Player(color) {}
  std::variant<Move, Rewind, Resign> RequestCommand(
      GameState const& game, std::string const& message) const override;

 private:
  Player const* opposing_player_;
};

}  // namespace chess
#endif
