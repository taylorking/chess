#ifndef CHESS_LIB_PIECES_KING
#define CHESS_LIB_PIECES_KING
#include <piece.h>
namespace chess {
class King : public Piece {
  private:  
    std::vector<Move> GetRawMoves(const ChessBoard& board) const override;
  public:
    using Piece::Piece;
    std::string GetName() const  override;
};
}
#endif
