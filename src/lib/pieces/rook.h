#ifndef CHESS_LIB_PIECES_ROOK
#define CHESS_LIB_PIECES_ROOK
#include <piece.h>
namespace chess {
class Rook: public Piece {
  private:
    std::vector<Move> GetRawMoves(const ChessBoard& board) const override;
  public:
    using Piece::Piece;
    std::string GetName() const override;
};
}
#endif
