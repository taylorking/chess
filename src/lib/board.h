#ifndef CHESS_LIB_BOARD
#define CHESS_LIB_BOARD

#include <array>

#include <piece.h>
#include <player.h>

namespace chess {
class Piece;
class Player;
using ChessBoard = std::array<std::array<Piece*, 8>, 8>;


class Board {
  public:
    static ChessBoard CreateBoard(Player* white, Player* black);
    static std::string PrintBoard(const ChessBoard& board);
};

}
#endif
