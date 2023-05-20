#include <diagonal_behavior.h>
#include <position.h>

namespace chess {
namespace {

void AddUpLeftPositions(Piece const* piece, ChessBoard const& board,
                        bool max_dist, std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x--;
  y--;
  while (x >= 0 && y >= 0) {
    if (board[x][y] == nullptr) {
      moves.insert(PositionFromPair(x, y));
      x--;
      y--;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.insert(PositionFromPair(x, y));
    break;
  }
}
void AddUpRightPositions(Piece const* piece, ChessBoard const& board,
                         bool max_dist, std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x--;
  y++;
  while (x >= 0 && y <= 7) {
    if (board[x][y] == nullptr) {
      moves.insert(PositionFromPair(x, y));
      x--;
      y++;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.insert(PositionFromPair(x, y));
    break;
  }
}
void AddDownLeftPositions(Piece const* piece, ChessBoard const& board,
                          bool max_dist, std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x++;
  y--;
  while (x <= 7 && y >= 0) {
    if (board[x][y] == nullptr) {
      moves.insert(PositionFromPair(x, y));
      x++;
      y--;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.insert(PositionFromPair(x, y));
    break;
  }
}
void AddDownRightPositions(Piece const* piece, ChessBoard const& board,
                           bool max_dist, std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x++;
  y++;
  while (x <= 7 && y <= 7) {
    if (board[x][y] == nullptr) {
      moves.insert(PositionFromPair(x, y));
      x++;
      y++;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.insert(PositionFromPair(x, y));
    break;
  }
}
}  // namespace
void DiagonalBehavior::AddDiagonalPositions(
    Piece const* piece, ChessBoard const& board, bool max_dist,
    std::unordered_set<Position>& moves) {
  AddUpLeftPositions(piece, board, max_dist, moves);
  AddUpRightPositions(piece, board, max_dist, moves);
  AddDownLeftPositions(piece, board, max_dist, moves);
  AddDownRightPositions(piece, board, max_dist, moves);
}
}  // namespace chess
