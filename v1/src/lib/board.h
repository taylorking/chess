#ifndef CHESS_LIB_BOARD
#define CHESS_LIB_BOARD

#include <array>
#include <piece.h>
#include <player.h>
#include <vector>

namespace chess {
class Piece;
class Player;
using PlayerPieces = std::vector<std::unique_ptr<Piece>>;
using ChessBoardStore = std::array<std::array<Piece*, 8>, 8>;

class ChessBoard {
 private:
  ChessBoard() = default;
  ChessBoardStore board_;
  std::array<Piece*, 8> operator[](int i) { return board_[i]; }
  Position white_king_position_;
  Position black_king_position_;

 public:
  const std::array<Piece*, 8> operator[](int i) const { return board_[i]; }
  ChessBoard(PlayerPieces& white, PlayerPieces& black);
  ChessBoard(PlayerPieces& white, PlayerPieces& black, ChessBoard const& other);
  ChessBoard(ChessBoardStore&&, Position white = -1, Position black = -1);
  void ApplyMove(Position, Position);
  Position GetKingPosition(Color color) const;
};

}  // namespace chess
#endif
