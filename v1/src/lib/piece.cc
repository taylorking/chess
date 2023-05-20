#include <game_state.h>
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

std::unordered_set<Position> Piece::GetMoves(GameState const& state) const {
  auto moves = this->GetRawMoves(*state.GetBoard());
  std::unordered_set<Position> allowed_moves;
  std::copy_if(moves.begin(), moves.end(), 
      std::inserter(allowed_moves, allowed_moves.begin()),
    [&](const Position move) {
      return CheckForCheck(*state.ApplyMove(this, move)) == nullptr;
  });
  return allowed_moves;
}

void Piece::ApplyMove(Position move) {
  auto [x, y] = PositionToPair(move);
  x_ = x;
  y_ = y;
}

}  // namespace chess
