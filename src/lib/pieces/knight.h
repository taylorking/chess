#ifndef CHESS_LIB_PIECES_KNIGHT
#define CHESS_LIB_PIECES_KNIGHT
#include <piece.h>
namespace chess {
class Knight : public Piece {
 private:
  std::vector<Move> GetRawMoves(ChessBoard const& board) const override;

 public:
  using Piece::Piece;
  std::string GetName() const override;
};
}  // namespace chess
#endif
