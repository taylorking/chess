#ifndef CHESS_LIB_GAME_STATE
#define CHESS_LIB_GAME_STATE

#include <board.h>
#include <memory>
#include <optional>
#include <player.h>
#include <position.h>

namespace chess {

class ChessBoard;
class Player;
class Piece;

using PlayerPieces = std::vector<std::unique_ptr<Piece>>;

class GameState {
 protected:
  Player* white_;
  Player* black_;
  PlayerPieces white_pieces_;
  PlayerPieces black_pieces_;
  std::vector<std::unique_ptr<Piece>> graveyard_;
  ChessBoard board_;
  Player const* turn_;

  void SetKingPosition(Color, Position);

 public:
  GameState(Player*, Player*);
  GameState(GameState&&);

  GameState(Player*, Player*, ChessBoard&, PlayerPieces&, PlayerPieces&,
            Player const*);

  explicit GameState(GameState const& state);

  ChessBoard const* GetBoard() const;
  std::pair<Player const*, Player const*> GetPlayers() const;

  Player const* GetCurrentTurn() const;
  std::unique_ptr<GameState> ApplyMove(Piece const* p, Position move) const;
  std::unique_ptr<GameState> ValidateAndApplyMove(Piece const* p, Position move) const;
};
}  // namespace chess
#endif
