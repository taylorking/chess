#ifndef CHESS_LIB_PIECES_KING
#define CHESS_LIB_PIECES_KING
#include <piece.h>
namespace chess {
class King : public ClonablePiece<King> {
 protected:
  std::unordered_set<Position> GetRawMoves(
      ChessBoard const& board) const override;

 public:
  using ClonablePiece::ClonablePiece;
  std::string GetName() const override;
};
}  // namespace chess
#endif
