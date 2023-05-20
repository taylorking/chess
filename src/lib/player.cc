#include <algorithm>
#include <player.h>
namespace chess {

Player::Player(Color color) : color_(color) {}

std::vector<Piece const*> Player::GetPieces() const {
  std::vector<Piece const*> result;
  std::transform(player_pieces_.begin(), player_pieces_.end(),
                 std::back_inserter(result),
                 [](std::unique_ptr<Piece> const& piece) -> Piece const* {
                   return piece.get();
                 });
  return result;
}

Color Player::GetColor() { return color_; }

void Player::GivePieceToPlayer(std::unique_ptr<Piece> piece) {
  player_pieces_.push_back(std::move(piece));
}

}  // namespace chess
