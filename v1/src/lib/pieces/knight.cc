#include <algorithm>
#include <knight.h>
namespace chess {

std::unordered_set<Position> Knight::GetRawMoves(
    ChessBoard const& board) const {
  auto [x, y] = GetCoordinates();
  auto moves = {PositionFromPair(x - 2, y - 1), PositionFromPair(x - 2, y + 1),
                PositionFromPair(x - 1, y - 2), PositionFromPair(x - 1, y + 2),
                PositionFromPair(x + 1, y - 2), PositionFromPair(x + 1, y + 2),
                PositionFromPair(x + 2, y - 1), PositionFromPair(x + 2, y + 1)};

  std::unordered_set<Position> filtered_for_bounds;
  std::copy_if(moves.begin(), moves.end(),
               std::inserter(filtered_for_bounds, filtered_for_bounds.begin()),
               [&](Position const& move) {
                 auto [x, y] = PositionToPair(move);
                 return x >= 0 && x <= 7 && y >= 0 && y <= 7;
               });

  std::unordered_set<Position> results;
  std::copy_if(
      filtered_for_bounds.begin(), filtered_for_bounds.end(),
      std::inserter(results, results.begin()), [&](Position const& move) {
        auto [x, y] = PositionToPair(move);
        return board[x][y] == nullptr || board[x][y]->GetColor() != GetColor();
      });
  return results;
}
std::string Knight::GetName() const { return "K"; }
}  // namespace chess
