#ifndef CHESS_LIB_PIECES_BISHOP
#define CHESS_LIB_PIECES_BISHOP
#include <piece.h>
namespace chess {
class Bishop : public Piece {
  private:
    std::vector<Move> GetRawMoves(const ChessBoard& board) const override;
  public:
    using Piece::Piece;
    std::string GetName() const  override;
};
}
#endif
