#ifndef CHESS_LIB_GAME_STATE
#define CHESS_LIB_GAME_STATE

#include <memory>

#include <board.h>
#include <player.h>
namespace chess {

class GameState {
  protected:
    std::unique_ptr<Player> white_;
    std::unique_ptr<Player> black_;
    const ChessBoard board_;
  public:
    GameState();
    ChessBoard const* GetBoard() const;
    std::pair<Player const*, Player const*>  GetPlayers() const;
    GameState ApplyStateChange(const Move& move) const;
};
}
#endif
