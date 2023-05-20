#include <bishop.h>
#include <board.h>
#include <iostream>
#include <king.h>
#include <knight.h>
#include <pawn.h>
#include <queen.h>
#include <rook.h>
#include <sstream>

namespace chess {

template <typename T>
void MakePieceAndGiveToPlayer(PlayerPieces& player, Color color,
                              ChessBoardStore& board, int x, int y) {
  auto ptr = std::make_unique<T>(color, y, x);
  T* raw_ptr = ptr.get();
  player.push_back(std::move(ptr));
  board[y][x] = raw_ptr;
}

ChessBoard::ChessBoard(PlayerPieces& white, PlayerPieces& black)
    : white_king_position_(PositionFromPair(7, 4)),
      black_king_position_(PositionFromPair(0, 4)) {
  for (int i = 2; i <= 6; i++) {
    for (int j = 0; j < 8; j++) {
      board_[i][j] = nullptr;
    }
  }

  for (int i = 0; i < 8; i++) {
    MakePieceAndGiveToPlayer<Pawn>(white, Color::WHITE, board_, i, 6);
    MakePieceAndGiveToPlayer<Pawn>(black, Color::BLACK, board_, i, 1);
  }
  MakePieceAndGiveToPlayer<Rook>(white, Color::WHITE, board_, 0, 7);
  MakePieceAndGiveToPlayer<Rook>(white, Color::WHITE, board_, 7, 7);
  MakePieceAndGiveToPlayer<Rook>(black, Color::BLACK, board_, 0, 0);
  MakePieceAndGiveToPlayer<Rook>(black, Color::BLACK, board_, 7, 0);

  MakePieceAndGiveToPlayer<Knight>(white, Color::WHITE, board_, 1, 7);
  MakePieceAndGiveToPlayer<Knight>(white, Color::WHITE, board_, 6, 7);
  MakePieceAndGiveToPlayer<Knight>(black, Color::BLACK, board_, 1, 0);
  MakePieceAndGiveToPlayer<Knight>(black, Color::BLACK, board_, 6, 0);

  MakePieceAndGiveToPlayer<Bishop>(white, Color::WHITE, board_, 2, 7);
  MakePieceAndGiveToPlayer<Bishop>(white, Color::WHITE, board_, 5, 7);
  MakePieceAndGiveToPlayer<Bishop>(black, Color::BLACK, board_, 2, 0);
  MakePieceAndGiveToPlayer<Bishop>(black, Color::BLACK, board_, 5, 0);

  MakePieceAndGiveToPlayer<Queen>(white, Color::WHITE, board_, 3, 7);
  MakePieceAndGiveToPlayer<Queen>(black, Color::BLACK, board_, 3, 0);

  MakePieceAndGiveToPlayer<King>(white, Color::WHITE, board_, 4, 7);
  MakePieceAndGiveToPlayer<King>(black, Color::BLACK, board_, 4, 0);
}

ChessBoard::ChessBoard(PlayerPieces& white, PlayerPieces& black,
                       ChessBoard const& board) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == nullptr) {
        board_[i][j] = nullptr;
        continue;
      }
      auto piece = board[i][j]->clone();
      board_[i][j] = piece.get();
      auto& player = piece->GetColor() == Color::WHITE ? white : black;
      player.push_back(std::move(piece));
    }
  }
}
ChessBoard::ChessBoard(ChessBoardStore&& board, Position white, Position black)
    : board_(std::move(board)),
      white_king_position_(white),
      black_king_position_(black) {}

void ChessBoard::ApplyMove(Position old_position, Position move) {
  auto [old_x, old_y] = PositionToPair(old_position);
  auto [new_x, new_y] = PositionToPair(move);
  Piece* piece = board_[old_x][old_y];
  board_[new_x][new_y] = piece;
  board_[old_x][old_y] = nullptr;
  piece->ApplyMove(move);
}
Position ChessBoard::GetKingPosition(Color color) const {
  return color == Color::WHITE? white_king_position_ : black_king_position_;
}
}  // namespace chess
