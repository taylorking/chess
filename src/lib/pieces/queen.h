#ifndef CHESS_LIB_PIECES_QUEEN
#define CHESS_LIB_PIECES_QUEEN
#include <piece.h>
namespace chess {
class Queen : public Piece {
 private:
  std::vector<Move> GetRawMoves(ChessBoard const& board) const override;

 public:
  using Piece::Piece;
  std::string GetName() const override;
};

}  // namespace chess
#endif
