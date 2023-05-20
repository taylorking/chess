#ifndef CHESS_LIB_PIECES_PAWN
#define CHESS_LIB_PIECES_PAWN
#include <piece.h>
namespace chess {
class Pawn : public ClonablePiece<Pawn> {
 protected:
  std::unordered_set<Position> GetRawMoves(
      ChessBoard const& board) const override;

 public:
  using ClonablePiece::ClonablePiece;
  std::string GetName() const override;
};
}  // namespace chess
#endif
