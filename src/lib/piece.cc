#include <piece.h>

namespace chess {
Piece::Piece(Color color, int x, int y) : color_(color), x_(x), y_(y) {}

std::string Piece::ToString() const {
  std::string result;
  switch (color_) {
    case WHITE:
      result.append("\e[97m");
      break;
    case BLACK:
      result.append("\e[90m");
      break;
  }
  result.append(GetName());
  result.append("\e[0m");
  return result;
}

Color Piece::GetColor() const { return color_; }

std::pair<int, int> Piece::GetCoordinates() const { return {x_, y_}; }

std::vector<Move> Piece::GetMoves(ChessBoard const& board) const {
  auto moves = this->GetRawMoves(board);

  return moves;
}

}  // namespace chess
