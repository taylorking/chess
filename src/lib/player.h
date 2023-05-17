#ifndef CHESS_LIB_PLAYER
#define CHESS_LIB_PLAYER

#include<memory>
#include<string>
#include<vector>

#include <color.h>
#include <piece.h>

namespace chess {

class Piece;

class Player {

  private:
    const Color color_;
    std::vector<std::unique_ptr<Piece>> player_pieces_;
  public:
    Player(Color color);
    std::vector<Piece const*> GetPieces() const;
    Color GetColor();
    void GivePieceToPlayer(std::unique_ptr<Piece>);
    void TakePieceFromPlayer(Piece*); 
};
}
#endif
