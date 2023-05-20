#ifndef CHESS_LIB_PIECES_LINE_BEHAVIOR
#define CHESS_LIB_PIECES_LINE_BEHAVIOR

#include <board.h>
#include <piece.h>
#include <position.h>

namespace chess {
class LineBehavior {
 public:
  static void AddLinePositions(Piece const* piece, ChessBoard const& board,
                               bool max_dist,
                               std::unordered_set<Position>& move);
};
}  // namespace chess
#endif
