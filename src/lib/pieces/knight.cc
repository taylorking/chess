#include <knight.h>
#include <models.h>
#include <piece_helpers.h>
#include <vector>

namespace chess {

std::vector<Move> Knight::GetMoves(Board const& b) const {
  auto [x, y] = b.piece_map_.at(this->color_).at(this);
  std::vector<std::tuple<int, int>> possible_moves{
      {x - 2, y - 1}, {x - 2, y + 1}, {x - 1, y + 2}, {x - 1, y - 2},
      {x + 1, y - 2}, {x + 1, y + 2}, {x + 2, y - 1}, {x + 2, y + 1}};
  std::vector<Move> moves;
  for (auto move : possible_moves) {
    if (!IsLocationOnBoard(move)) continue;
    auto [x, y] = move;
    if (b.chess_board_[x][y] != nullptr &&
        b.chess_board_[x][y]->color_ == this->color_) {
      continue;
    }
    ConstructMove(moves, this, move);
  }
  return moves;
}

std::string Knight::GetName() const { return "K "; }

}  // namespace chess
