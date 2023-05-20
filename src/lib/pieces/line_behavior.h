#ifndef CHESS_LIB_PIECES_LINE_BEHAVIOR
#define CHESS_LIB_PIECES_LINE_BEHAVIOR

#include <board.h>
#include <move.h>
#include <piece.h>

namespace chess {
class LineBehavior {
 public:
  static void AddLineMoves(Piece const* piece, ChessBoard const& board,
                           bool max_dist, std::vector<Move>& move);
};
}  // namespace chess
#endif
