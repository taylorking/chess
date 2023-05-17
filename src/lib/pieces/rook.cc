#include <rook.h>

#include <line_behavior.h>

namespace chess {
    
std::vector<Move> Rook::GetRawMoves(const ChessBoard& board) const {
  std::vector<Move> result;
  LineBehavior::AddLineMoves(this, board, false, result);
  return result;
}
std::string Rook::GetName() const  {
  return "R";
}
}
