#ifndef CHESS_LIB_PIECES_DIAGONAL_BEHAVIOR
#define CHESS_LIB_PIECES_DIAGONAL_BEHAVIOR

#include <vector>

#include <piece.h>
#include <board.h>
#include <move.h>
namespace chess {
class DiagonalBehavior {
  public:
    static void AddDiagonalMoves(Piece const* piece, const ChessBoard& board, bool max_dist, std::vector<Move>& move);

};
}
#endif
