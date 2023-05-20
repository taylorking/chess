#include <queen.h>

#include <line_behavior.h>
#include <diagonal_behavior.h>

namespace chess {

std::vector<Move> Queen::GetRawMoves(ChessBoard const& board) const {
  std::vector<Move> results;
  LineBehavior::AddLineMoves(this, board, false, results);
  DiagonalBehavior::AddDiagonalMoves(this, board, false, results);
  return results;
}
std::string Queen::GetName() const { return "Q"; }
}  // namespace chess
