#include <bishop.h>
#include <diagonal_behavior.h>
namespace chess {

std::vector<Move> Bishop::GetRawMoves(ChessBoard const& board) const {
  std::vector<Move> results;
  DiagonalBehavior::AddDiagonalMoves(this, board, false, results);
  return results;
}

std::string Bishop::GetName() const { return "\u265D"; }
}  // namespace chess
