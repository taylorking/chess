#include <bishop.h>
#include <models.h>
#include <piece_helpers.h>
#include <vector>

namespace chess {
std::vector<Move> Bishop::GetMoves(Board const& b) const {
  std::vector<Move> moves;
  DiagonalBehavior(moves, this, b);
  return moves;
}
std::string Bishop::GetName() const { return "B "; }
}  // namespace chess
