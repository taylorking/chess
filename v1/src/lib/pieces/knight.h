#ifndef CHESS_LIB_PIECES_KNIGHT
#define CHESS_LIB_PIECES_KNIGHT
#include <piece.h>
namespace chess {
class Knight : public ClonablePiece<Knight> {
 protected:
  std::unordered_set<Position> GetRawMoves(
      ChessBoard const& board) const override;

 public:
  using ClonablePiece::ClonablePiece;
  std::string GetName() const override;
};
}  // namespace chess
#endif
