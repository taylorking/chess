#include <bishop.h>
#include <diagonal_behavior.h>
namespace chess {

std::unordered_set<Position> Bishop::GetRawMoves(
    ChessBoard const& board) const {
  std::unordered_set<Position> results;
  DiagonalBehavior::AddDiagonalPositions(this, board, false, results);
  return results;
}

std::string Bishop::GetName() const { return "\u265D"; }
}  // namespace chess
