#ifndef CHESS_LIB_PIECES_PAWN
#define CHESS_LIB_PIECES_PAWN
#include <piece.h>
namespace chess {
class Pawn: public Piece {
  protected:
    std::vector<Move> GetRawMoves(const ChessBoard& board) const override;
  public:
    using Piece::Piece;
    std::string GetName() const  override;
};
}
#endif

