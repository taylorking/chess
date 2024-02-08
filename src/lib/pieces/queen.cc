#include <models.h>
#include <piece_helpers.h>
#include <queen.h>
#include <vector>

namespace chess {

std::vector<Move> Queen::GetMoves(Board const& b) const {
  std::vector<Move> moves;
  HorizontalBehavior(moves, this, b);
  DiagonalBehavior(moves, this, b);
  return moves;
}
std::string Queen::GetName() const { return "Q "; }
}  // namespace chess
