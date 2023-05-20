#include <line_behavior.h>

namespace chess {
namespace {
void AddUpMoves(Piece const* piece, ChessBoard const& board,
    bool max_dist, std::vector<Move>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x--;
  while (x >= 0) {
    if (board[x][y] == nullptr) {
      moves.push_back(Move(x, y));
      x--;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.push_back(Move(x, y));
    break;
  }
}

void AddDownMoves(Piece const* piece, ChessBoard const& board,
    bool max_dist, std::vector<Move>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x++;
  while (x <= 7) {
    if (board[x][y] == nullptr) {
      moves.push_back(Move(x, y));
      x++;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.push_back(Move(x, y));
    break;
  }
}

void AddLeftMoves(Piece const* piece, ChessBoard const& board,
    bool max_dist, std::vector<Move>& moves) {
  auto [x, y] = piece->GetCoordinates();
  y--;
  while (y >= 0) {
    if (board[x][y] == nullptr) {
      moves.push_back(Move(x, y));
      y--;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.push_back(Move(x, y));
    break;
  }
}

void AddRightMoves(Piece const* piece, ChessBoard const& board,
    bool max_dist, std::vector<Move>& moves) {
  auto [x, y] = piece->GetCoordinates();
  y++;
  while (y <= 7) {
    if (board[x][y] == nullptr) {
      moves.push_back(Move(x, y));
      y++;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.push_back(Move(x, y));
    break;
  }

}
}
void LineBehavior::AddLineMoves(Piece const* piece, ChessBoard const& board,
                                bool max_dist, std::vector<Move>& moves) {
  AddUpMoves(piece,  board,
       max_dist,  moves);
  AddDownMoves(piece,  board,
       max_dist,  moves);
  AddLeftMoves(piece,  board,
       max_dist,  moves);
  AddRightMoves(piece,  board,
       max_dist,  moves);
}
}  // namespace chess
