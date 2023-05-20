#include <pawn.h>
namespace chess {
namespace {
void AddBlackPositions(Piece const* piece, ChessBoard const& board,
                       std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  if (x < 7 && board[x + 1][y] == nullptr) {
    moves.insert(PositionFromPair(x + 1, y));
    if (x == 1 && board[x + 2][y] == nullptr) {
      moves.insert(PositionFromPair(x + 2, y));
    }
  }
  if (x < 7 && y < 7 && board[x + 1][y + 1] != nullptr &&
      board[x + 1][y + 1]->GetColor() == Color::WHITE) {
    moves.insert(PositionFromPair(x + 1, y + 1));
  }
  if (x < 7 && y > 0 && board[x + 1][y - 1] != nullptr &&
      board[x + 1][y - 1]->GetColor() == Color::WHITE) {
    moves.insert(PositionFromPair(x + 1, y - 1));
  }
}
void AddWhitePositions(Piece const* piece, ChessBoard const& board,
                       std::unordered_set<Position>& moves) {
  auto [x, y] = piece->GetCoordinates();
  if (x > 0 && board[x - 1][y] == nullptr) {
    moves.insert(PositionFromPair(x - 1, y));
    if (x == 6 && board[x - 2][y] == nullptr) {
      moves.insert(PositionFromPair(x - 2, y));
    }
  }
  if (x > 0 && y < 7 && board[x - 1][y + 1] != nullptr &&
      board[x - 1][y + 1]->GetColor() == Color::BLACK) {
    moves.insert(PositionFromPair(x - 1, y + 1));
  }
  if (x > 0 && y > 0 && board[x - 1][y - 1] != nullptr &&
      board[x - 1][y - 1]->GetColor() == Color::BLACK) {
    moves.insert(PositionFromPair(x - 1, y - 1));
  }
}
}  // namespace

std::unordered_set<Position> Pawn::GetRawMoves(ChessBoard const& board) const {
  std::unordered_set<Position> results;
  switch (GetColor()) {
    case Color::WHITE:
      AddWhitePositions(this, board, results);
      break;
    case Color::BLACK:
      AddBlackPositions(this, board, results);
      break;
    default:
      break;
  }
  return results;
}
std::string Pawn::GetName() const { return "P"; }
}  // namespace chess
