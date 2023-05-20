#include <diagonal_behavior.h>
#include <line_behavior.h>
#include <queen.h>

namespace chess {

std::unordered_set<Position> Queen::GetRawMoves(ChessBoard const& board) const {
  std::unordered_set<Position> results;
  LineBehavior::AddLinePositions(this, board, false, results);
  DiagonalBehavior::AddDiagonalPositions(this, board, false, results);
  return results;
}
std::string Queen::GetName() const { return "Q"; }
}  // namespace chess
