#ifndef CHESS_LIB_PIECES_KNIGHT
#define CHESS_LIB_PIECES_KNIGHT
#include <piece.h>
namespace chess {
class Knight : public Piece {
  private:
    std::vector<Move> GetRawMoves(const ChessBoard& board) const override;
  public:
    using Piece::Piece;
    std::string GetName() const override;
};
}
#endif
