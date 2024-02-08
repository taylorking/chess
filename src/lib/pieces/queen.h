#ifndef CHESS_LIB_PIECES_QUEEN_H_
#define CHESS_LIB_PIECES_QUEEN_H_
#include <models.h>
#include <vector>

namespace chess {
class Queen : public Piece {
 public:
  using Piece::Piece;
  std::vector<Move> GetMoves(Board const& board) const override;
  std::string GetName() const override;
};
}  // namespace chess
#endif
