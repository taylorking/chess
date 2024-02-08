#include "game_runner.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <random_player.h>
#include <vector>

namespace chess {
std::variant<Move, Rewind, Resign> RandomPlayer::RequestCommand(
    GameState const& game, std::string const& message) const {
  std::srand(std::time(0));
  std::vector<Piece const*> all_pieces;
  for (auto [piece, _] : game.board_.piece_map_.at(this->color_)) {
    all_pieces.push_back(piece);
  }
  random_shuffle(all_pieces.begin(), all_pieces.end());
  for (auto selected_piece : all_pieces) {
    std::vector<Move> moves = selected_piece->GetMoves(game.board_);
    random_shuffle(moves.begin(), moves.end());
    for (auto const& move : moves) {
      if (ApplyMoveForInvalidOrNewState(game, move, opposing_player_)
              .has_value()) {
        return move;
      }
    }
  }
  return Rewind{};
}

}  // namespace chess
