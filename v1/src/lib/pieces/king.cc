#include <diagonal_behavior.h>
#include <king.h>
#include <line_behavior.h>

namespace chess {

std::unordered_set<Position> King::GetRawMoves(ChessBoard const& board) const {
  std::unordered_set<Position> results;
  LineBehavior::AddLinePositions(this, board, true, results);
  DiagonalBehavior::AddDiagonalPositions(this, board, true, results);
  return results;
}
std::string King::GetName() const { return "Ki"; }
}  // namespace chess
