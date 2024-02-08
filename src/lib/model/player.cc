#include <models.h>
#include <game_runner.h>
#include <player.h>
namespace chess {
bool Player::CheckForCheckmate(GameState const& game, const Player* opposing_player) const {
  for (const auto [piece, _] : game.board_.piece_map_.at(this->color_)) {
    for (const auto move : piece->GetMoves(game.board_)) {
      if (ApplyMoveForInvalidOrNewState(game, move, opposing_player).has_value()) {
        return false;    
      }
    }
  }
  return true;
}

}
