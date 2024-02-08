#include <board_helper.h>
#include <check_helper.h>
#include <game_runner.h>
#include <player.h>
#include <iostream>
#include <memory>
#include <models.h>
#include <optional>
#include <type_traits>

template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};
// explicit deduction guide (not needed as of C++20)
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

namespace chess {

namespace {
Player const* GetOpposingPlayer(Game const& game, Player const* player) {
  if (game.white_player_ == player) return game.black_player_;
  return game.white_player_;
}
bool ValidateMove(Board const& board, Move const& move) {
  // TODO: optimize this code.
  Piece const* piece = move.piece_;
  std::vector<Move> moves = piece->GetMoves(board);
  for (Move const& valid_move : moves) {
    if (move == valid_move) return true;
  }
  return false;
}
void ApplyMove(GameState& state, Move const& move) {
  Piece const* piece = move.piece_;
  auto [x, y] = state.board_.piece_map_[move.piece_->color_][move.piece_];
  if (state.king_positions_[piece->color_] == std::tuple<int, int>{x, y}) {
    state.king_positions_[piece->color_] = {move.x_, move.y_};
  }
  state.board_.chess_board_[x][y] = nullptr;
  x = move.x_;
  y = move.y_;
  Piece const* existing_piece = state.board_.chess_board_[x][y];
  if (existing_piece != nullptr) {
    state.board_.piece_map_[existing_piece->color_].erase(existing_piece);
  }
  state.board_.chess_board_[x][y] = piece;
  state.board_.piece_map_[move.piece_->color_][move.piece_] = {move.x_,
                                                               move.y_};
}
}  // namespace

Game* SetupNewGame(Player* white_player, Player* black_player) {
  Game* new_game =
      new Game{.white_player_ = white_player, .black_player_ = black_player};
  new_game->current_state_ = std::make_unique<GameState>();
  new_game->current_state_->turn_ = white_player;
  InitializeBoard(*new_game);
  return new_game;
}
void RunGame(Game* game) {
  std::optional<std::unique_ptr<GameState>> new_state = std::nullopt;
  std::string status;
  while (!new_state.has_value()) {
    Player const* current_player = game->current_state_->turn_;
    Player const* opposing_player = GetOpposingPlayer(*game, current_player);
    if (current_player -> CheckForCheckmate(*game->current_state_, opposing_player)) {
      std::cout << "Game over. " << std::endl << opposing_player->color_ << " wins.";
      std::exit(0);
    }
    std::variant<Move, Rewind, Resign> command =
        current_player->RequestCommand(*game->current_state_, status);
    std::visit(overloaded{[&](Move const& move) {
                            new_state = ApplyMoveForInvalidOrNewState(
                                *game->current_state_, move,
                                opposing_player);
                          },
                          [&](Rewind const& rewind) {
                            if (game->past_states_.size() < 2) return;
                            game->past_states_.pop_back();
                            game->current_state_ =
                                std::move(game->past_states_.back());
                            game->past_states_.pop_back();
                          },
                          [&](Resign const& resign) {
                          }},
               command);
  }
  game->past_states_.push_back(std::move(game->current_state_));
  game->current_state_ = std::move(*new_state);
}

std::optional<std::unique_ptr<GameState>> ApplyMoveForInvalidOrNewState(
    GameState const& game_state, Move const& move,
    Player const* opposing_player) {
  Player const* active_player = game_state.turn_;
  if (active_player->color_ != move.piece_->color_) {
    // You're moving a piece that doesn't belong to you.
    return std::nullopt;
  }

  if (!ValidateMove(game_state.board_, move)) {
    // The move is not valid
    return std::nullopt;
  }
  auto new_state = std::make_unique<GameState>(game_state);
  new_state->turn_ = opposing_player;
  ApplyMove(*new_state, move);
  if (IsPlayerInCheck(*new_state, active_player)) {
    return std::nullopt;
  }
  return std::move(new_state);
}

}  // namespace chess
