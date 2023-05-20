#ifndef CHESS_LIB_PIECES_QUEEN
#define CHESS_LIB_PIECES_QUEEN
#include <piece.h>
namespace chess {
class Queen : public ClonablePiece<Queen> {
 protected:
  std::unordered_set<Position> GetRawMoves(
      ChessBoard const& board) const override;

 public:
  using ClonablePiece::ClonablePiece;
  std::string GetName() const override;
};

}  // namespace chess
#endif
