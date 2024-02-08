#include <models.h>
#include <pawn.h>
#include <piece_helpers.h>
namespace chess {
std::vector<Move> Pawn::GetMoves(Board const& board) const {
  auto [x, y] = board.piece_map_.at(this->color_).at(this);
  std::vector<Move> moves;
  if (this->color_ == BLACK) {
    std::tuple<int, int> coords;
    coords = {x + 2, y};
    if (x == 1 && IsLocationOnBoard(coords)) {
      if (GetPieceAtLocation(board, coords) == nullptr) {
        ConstructMove(moves, this, coords);
      }
    }
    coords = {x + 1, y};
    if (IsLocationOnBoard(coords) &&
        GetPieceAtLocation(board, coords) == nullptr) {
      ConstructMove(moves, this, coords);
    }
    coords = {x + 1, y + 1};
    if (IsLocationOnBoard(coords) &&
        GetPieceAtLocation(board, coords) != nullptr &&
        GetPieceAtLocation(board, coords)->color_ == WHITE) {
      ConstructMove(moves, this, coords);
    }
    coords = {x + 1, y - 1};
    if (IsLocationOnBoard(coords) &&
        GetPieceAtLocation(board, coords) != nullptr &&
        GetPieceAtLocation(board, coords)->color_ == WHITE) {
      ConstructMove(moves, this, coords);
    }
  }
  if (this->color_ == WHITE) {
    std::tuple<int, int> coords;
    coords = {x - 2, y};
    if (x == 6 && IsLocationOnBoard(coords)) {
      if (GetPieceAtLocation(board, coords) == nullptr) {
        ConstructMove(moves, this, coords);
      }
    }
    coords = {x - 1, y};
    if (IsLocationOnBoard(coords) &&
        GetPieceAtLocation(board, coords) == nullptr) {
      ConstructMove(moves, this, coords);
    }
    coords = {x - 1, y - 1};
    if (IsLocationOnBoard(coords) &&
        GetPieceAtLocation(board, coords) != nullptr &&
        GetPieceAtLocation(board, coords)->color_ == BLACK) {
      ConstructMove(moves, this, coords);
    }
    coords = {x - 1, y + 1};
    if (IsLocationOnBoard(coords) &&
        GetPieceAtLocation(board, coords) != nullptr &&
        GetPieceAtLocation(board, coords)->color_ == BLACK) {
      ConstructMove(moves, this, coords);
    }
  }
  return moves;
}

std::string Pawn::GetName() const { return "P "; }

}  // namespace chess
