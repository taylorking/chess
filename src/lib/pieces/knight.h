#ifndef CHESS_LIB_PIECES_KNIGHT_H_
#define CHESS_LIB_PIECES_KNIGHT_H_
#include <models.h>
#include <vector>

namespace chess {
class Knight : public Piece {
 public:
  using Piece::Piece;
  std::vector<Move> GetMoves(Board const& board) const override;
  std::string GetName() const override;
};
}  // namespace chess
#endif
