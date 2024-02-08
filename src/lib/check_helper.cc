#include <check_helper.h>
#include <models.h>
#include <player.h>
namespace chess {
bool IsPlayerInCheck(GameState const& state, Player const* player) {
  // TODO: Check for a move to put you in check that puts the other player in
  // check.
  Color opposing_color = player->color_ == WHITE ? BLACK : WHITE;
  for (auto [piece, _] : state.board_.piece_map_.at(opposing_color)) {
    for (Move move : piece->GetMoves(state.board_)) {
      std::tuple<int, int> coords = {move.x_, move.y_};
      if (state.king_positions_.at(player->color_) == coords) {
        return true;
      }
    }
  }
  return false;
}
}  // namespace chess
