#include <line_behavior.h>
#include <rook.h>

namespace chess {

std::unordered_set<Position> Rook::GetRawMoves(ChessBoard const& board) const {
  std::unordered_set<Position> result;
  LineBehavior::AddLinePositions(this, board, false, result);
  return result;
}
std::string Rook::GetName() const { return "R"; }
}  // namespace chess
