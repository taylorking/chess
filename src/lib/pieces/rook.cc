#include <line_behavior.h>
#include <rook.h>

namespace chess {

std::vector<Move> Rook::GetRawMoves(ChessBoard const& board) const {
  std::vector<Move> result;
  LineBehavior::AddLineMoves(this, board, false, result);
  return result;
}
std::string Rook::GetName() const { return "R"; }
}  // namespace chess
