#include <king.h>
#include <models.h>
#include <piece_helpers.h>
#include <vector>

namespace chess {
std::vector<Move> King::GetMoves(Board const& b) const {
  std::vector<Move> moves;
  DiagonalBehavior(moves, this, b, true);
  HorizontalBehavior(moves, this, b, true);
  return moves;
}
std::string King::GetName() const { return "Ki"; }
}  // namespace chess
