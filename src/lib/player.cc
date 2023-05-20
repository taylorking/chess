#include <algorithm>
#include <player.h>
namespace chess {

Player::Player(Color color) : color_(color) {}

std::vector<Piece const*> Player::GetPieces() const {
  std::vector<Piece const*> result;
  std::transform(player_pieces_->begin(), player_pieces_->end(),
                 std::back_inserter(result),
                 [](std::unique_ptr<Piece> const& piece) -> Piece const* {
                   return piece.get();
                 });
  return result;
}

Color Player::GetColor() const { return color_; }

void Player::SetPlayerPieces(PlayerPieces* pieces) { player_pieces_ = pieces; }
std::unique_ptr<Piece> Player::TakePieceFromPlayer(Piece const* piece) {
  return nullptr;
}
}  // namespace chess
