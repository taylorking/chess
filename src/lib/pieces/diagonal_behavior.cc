#include <diagonal_behavior.h>

namespace chess {
namespace {

void AddUpLeftMoves(Piece const* piece, const ChessBoard& board, bool max_dist, std::vector<Move>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x--;
  y--;
  while (x >= 0 && y >= 0) {
    if (board[x][y] == nullptr) {
      moves.push_back(Move(x, y));
      x--;
      y--;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.push_back(Move(x, y)); break;
  }
}
void AddUpRightMoves(Piece const* piece, const ChessBoard& board, bool max_dist, std::vector<Move>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x--;
  y++;
  while (x >= 0 && y <= 7) {
    if (board[x][y] == nullptr) {
      moves.push_back(Move(x, y));
      x--;
      y++;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.push_back(Move(x, y)); break;
  }
}
void AddDownLeftMoves(Piece const* piece, const ChessBoard& board, bool max_dist, std::vector<Move>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x++;
  y--;
  while (x <= 7 && y >= 0) {
    if (board[x][y] == nullptr) {
      moves.push_back(Move(x, y));
      x++;
      y--;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.push_back(Move(x, y)); break;
  }

}
void AddDownRightMoves(Piece const* piece, const ChessBoard& board, bool max_dist, std::vector<Move>& moves) {
  auto [x, y] = piece->GetCoordinates();
  x++;
  y++;
  while (x <= 7 && y <= 7) {
    if (board[x][y] == nullptr) {
      moves.push_back(Move(x, y));
      x++;
      y++;
      if (max_dist) break;
      continue;
    }
    if (board[x][y]->GetColor() == piece->GetColor()) break;
    moves.push_back(Move(x, y)); break;
  }
}
}
void DiagonalBehavior::AddDiagonalMoves(Piece const* piece, const ChessBoard& board, bool max_dist, std::vector<Move>& moves) {
  AddUpLeftMoves(piece, board, max_dist, moves); 
  AddUpRightMoves(piece, board, max_dist, moves); 
  AddDownLeftMoves(piece, board, max_dist, moves); 
  AddDownRightMoves(piece, board, max_dist, moves); 
}
}
