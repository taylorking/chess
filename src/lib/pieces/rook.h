#ifndef CHESS_LIB_PIECES_ROOK_H_
#define CHESS_LIB_PIECES_ROOK_H_
#include <models.h>
#include <vector>

namespace chess {
class Rook : public Piece {
 public:
  using Piece::Piece;
  std::vector<Move> GetMoves(Board const& board) const override;
  std::string GetName() const override;
};
}  // namespace chess
#endif
