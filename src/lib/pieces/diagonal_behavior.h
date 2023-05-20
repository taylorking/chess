#ifndef CHESS_LIB_PIECES_DIAGONAL_BEHAVIOR
#define CHESS_LIB_PIECES_DIAGONAL_BEHAVIOR

#include <board.h>
#include <move.h>
#include <piece.h>
#include <vector>
namespace chess {
class DiagonalBehavior {
 public:
  static void AddDiagonalMoves(Piece const* piece, ChessBoard const& board,
                               bool max_dist, std::vector<Move>& move);
};
}  // namespace chess
#endif
