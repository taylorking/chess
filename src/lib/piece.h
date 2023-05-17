#ifndef CHESS_LIB_PIECE
#define CHESS_LIB_PIECE

#include <string>
#include <vector>

#include <board.h>
#include <color.h>
#include <move.h>

namespace chess {
class Piece;
using ChessBoard = std::array<std::array<Piece*, 8>, 8>;

class Piece {
  protected:
    Color color_;
    int x_;
    int y_;
    virtual std::string GetName() const = 0;
    virtual std::vector<Move> GetRawMoves(const ChessBoard& board) const = 0;
  public:
    std::string ToString() const;
    std::vector<Move> GetMoves(const ChessBoard& board) const;
    Color GetColor() const;
    explicit Piece(Color color, int x, int y);
    std::pair<int, int> GetCoordinates() const;
};
}
#endif