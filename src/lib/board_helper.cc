#include <bishop.h>
#include <board_helper.h>
#include <king.h>
#include <knight.h>
#include <models.h>
#include <pawn.h>
#include <queen.h>
#include <rook.h>

namespace chess {
namespace {
void UpdateGameState(Game& game, std::unique_ptr<Piece> piece, int x, int y) {
  auto& board = game.current_state_->board_;
  board.chess_board_[x][y] = piece.get();
  board.piece_map_[piece->color_][piece.get()] = {x, y};
  game.pieces_.push_back(std::move(piece));
}
}  // namespace
void InitializeBoard(Game& game) {
  for (int i = 0; i < 8; i++) {
    UpdateGameState(game, std::make_unique<Pawn>(WHITE), 6, i);
    UpdateGameState(game, std::make_unique<Pawn>(BLACK), 1, i);
  }
  UpdateGameState(game, std::make_unique<Rook>(BLACK), 0, 0);
  UpdateGameState(game, std::make_unique<Rook>(BLACK), 0, 7);
  UpdateGameState(game, std::make_unique<Rook>(WHITE), 7, 0);
  UpdateGameState(game, std::make_unique<Rook>(WHITE), 7, 7);
  UpdateGameState(game, std::make_unique<Knight>(BLACK), 0, 1);
  UpdateGameState(game, std::make_unique<Knight>(BLACK), 0, 6);
  UpdateGameState(game, std::make_unique<Knight>(WHITE), 7, 1);
  UpdateGameState(game, std::make_unique<Knight>(WHITE), 7, 6);
  UpdateGameState(game, std::make_unique<Bishop>(BLACK), 0, 2);
  UpdateGameState(game, std::make_unique<Bishop>(BLACK), 0, 5);
  UpdateGameState(game, std::make_unique<Bishop>(WHITE), 7, 2);
  UpdateGameState(game, std::make_unique<Bishop>(WHITE), 7, 5);
  UpdateGameState(game, std::make_unique<King>(BLACK), 0, 4);
  UpdateGameState(game, std::make_unique<King>(WHITE), 7, 4);
  UpdateGameState(game, std::make_unique<Queen>(BLACK), 0, 3);
  UpdateGameState(game, std::make_unique<Queen>(WHITE), 7, 3);
  game.current_state_->king_positions_[WHITE] = {7, 4};
  game.current_state_->king_positions_[BLACK] = {0, 4};
}

}  // namespace chess
