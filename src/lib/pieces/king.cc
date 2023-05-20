#include <king.h>

#include <diagonal_behavior.h>
#include <line_behavior.h>

namespace chess {

std::vector<Move> King::GetRawMoves(ChessBoard const& board) const {
  std::vector<Move> results;
  LineBehavior::AddLineMoves(this, board, true, results);
  DiagonalBehavior::AddDiagonalMoves(this, board, true, results);
  return results;
}
std::string King::GetName() const { return "Ki"; }
}  // namespace chess
