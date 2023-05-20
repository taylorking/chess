#ifndef CHESS_LIB_PIECES_PAWN
#define CHESS_LIB_PIECES_PAWN
#include <piece.h>
namespace chess {
class Pawn : public Piece {
 protected:
  std::vector<Move> GetRawMoves(ChessBoard const& board) const override;

 public:
  using Piece::Piece;
  std::string GetName() const override;
};
}  // namespace chess
#endif
