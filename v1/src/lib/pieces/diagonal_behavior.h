#ifndef CHESS_LIB_PIECES_DIAGONAL_BEHAVIOR
#define CHESS_LIB_PIECES_DIAGONAL_BEHAVIOR

#include <board.h>
#include <piece.h>
#include <position.h>
#include <vector>
namespace chess {
class DiagonalBehavior {
 public:
  static void AddDiagonalPositions(Piece const* piece, ChessBoard const& board,
                                   bool max_dist,
                                   std::unordered_set<Position>& move);
};
}  // namespace chess
#endif
