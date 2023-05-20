#include <line_behavior.h>

namespace chess {
namespace {
void AddUpPositions(Piece const* piece, ChessBoard const& board, bool max_dist,
                    std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x--;
  while (x >= 0) {
    if (board[x][y] == nullptr) {
      moves.insert(PositionFromPair(x, y));
      x--;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.insert(PositionFromPair(x, y));
    break;
  }
}

void AddDownPositions(Piece const* piece, ChessBoard const& board,
                      bool max_dist, std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x++;
  while (x <= 7) {
    if (board[x][y] == nullptr) {
      moves.insert(PositionFromPair(x, y));
      x++;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.insert(PositionFromPair(x, y));
    break;
  }
}

void AddLeftPositions(Piece const* piece, ChessBoard const& board,
                      bool max_dist, std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  y--;
  while (y >= 0) {
    if (board[x][y] == nullptr) {
      moves.insert(PositionFromPair(x, y));
      y--;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.insert(PositionFromPair(x, y));
    break;
  }
}

void AddRightPositions(Piece const* piece, ChessBoard const& board,
                       bool max_dist, std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  y++;
  while (y <= 7) {
    if (board[x][y] == nullptr) {
      moves.insert(PositionFromPair(x, y));
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
void LineBehavior::AddLinePositions(Piece const* piece, ChessBoard const& board,
                                    bool max_dist,
                                    std::unordered_set<Position>& moves) {
  AddUpPositions(piece, board, max_dist, moves);
  AddDownPositions(piece, board, max_dist, moves);
  AddLeftPositions(piece, board, max_dist, moves);
  AddRightPositions(piece, board, max_dist, moves);
}
}  // namespace chess
