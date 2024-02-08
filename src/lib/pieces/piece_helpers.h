#ifndef CHESS_LIB_PIECE_HELPERS_H_
#define CHESS_LIB_PIECE_HELPERS_H_
#include <models.h>
#include <tuple>
namespace chess {
Piece const* GetPieceAtLocation(Board const& board,
                                std::tuple<int, int> const& coords);
void ConstructMove(std::vector<Move>& moves, Piece const* piece,
                   std::tuple<int, int> const& coords);
inline bool IsLocationOnBoard(std::tuple<int, int> const& coords) {
  auto [x, y] = coords;
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}
void HorizontalBehavior(std::vector<Move>& moves, Piece const* piece,
                        Board const& board, bool is_king = false);
void DiagonalBehavior(std::vector<Move>& moves, Piece const* piece,
                      Board const& board, bool is_king = false);
}  // namespace chess
#endif
