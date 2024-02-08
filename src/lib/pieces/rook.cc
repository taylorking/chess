#include <models.h>
#include <piece_helpers.h>
#include <rook.h>
#include <vector>

namespace chess {
std::vector<Move> Rook::GetMoves(Board const& b) const {
  std::vector<Move> moves;
  HorizontalBehavior(moves, this, b);
  return moves;
}
std::string Rook::GetName() const { return "R "; }
}  // namespace chess
