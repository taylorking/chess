#include <pawn.h>
namespace chess {

std::vector<Move> Pawn::GetRawMoves(ChessBoard const& board) const {
  return {};
}
std::string Pawn::GetName() const { return "P"; }
}  // namespace chess
