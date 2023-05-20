#ifndef CHESS_LIB_PIECES_BISHOP
#define CHESS_LIB_PIECES_BISHOP
#include <piece.h>
namespace chess {
class Bishop : public ClonablePiece<Bishop> {
 protected:
  std::unordered_set<Position> GetRawMoves(
      ChessBoard const& board) const override;

 public:
  using ClonablePiece::ClonablePiece;
  std::string GetName() const override;
};
}  // namespace chess
#endif
