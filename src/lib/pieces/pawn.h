#ifndef CHESS_LIB_PIECES_PAWN_H_
#define CHESS_LIB_PIECES_PAWN_H_
#include <models.h>
#include <vector>

namespace chess {
class Pawn : public Piece {
  using Piece::Piece;
  std::vector<Move> GetMoves(Board const& board) const override;
  std::string GetName() const override;
};
}  // namespace chess
#endif
