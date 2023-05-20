#ifndef CHESS_LIB_PLAYER
#define CHESS_LIB_PLAYER

#include <board.h>
#include <color.h>
#include <memory>
#include <piece.h>
#include <position.h>
#include <string>
#include <vector>

namespace chess {

class Piece;

using PlayerPieces = std::vector<std::unique_ptr<Piece>>;

class Player {
 protected:
  const Color color_;
  PlayerPieces* player_pieces_;

 public:
  Player(Color);
  Player(Player const&) = delete;
  std::vector<Piece const*> GetPieces() const;
  Color GetColor() const;
  void SetPlayerPieces(PlayerPieces*);
  std::unique_ptr<Piece> TakePieceFromPlayer(Piece const*);
  virtual std::pair<Piece const*, Position> GetMove() const = 0;
};
}  // namespace chess
#endif
