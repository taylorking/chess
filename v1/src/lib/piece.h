#ifndef CHESS_LIB_PIECE
#define CHESS_LIB_PIECE

#include <board.h>
#include <color.h>
#include <memory>
#include <position.h>
#include <string>
#include <unordered_set>

namespace chess {

class GameState;
class ChessBoard;
class Piece;

class Piece {
 private:
  static Piece const* CheckForCheck(GameState const&);
 protected:
  Color color_;
  int x_;
  int y_;
  virtual std::string GetName() const = 0;
  virtual std::unordered_set<Position> GetRawMoves(ChessBoard const&) const = 0;
 public:
  std::string ToString() const;
  std::unordered_set<Position> GetMoves(GameState const&) const;
  Color GetColor() const;
  std::pair<int, int> GetCoordinates() const;

  virtual std::unique_ptr<Piece> clone() const = 0;
  explicit Piece(Color color, int x, int y);
  explicit Piece(Piece const& p) = default;
  void ApplyMove(Position);
};

template <class T>
class ClonablePiece : public Piece {
 public:
  using Piece::Piece;
  virtual std::unique_ptr<Piece> clone() const {
    return std::make_unique<T>(static_cast<T const&>(*this));
  }
};

}  // namespace chess
#endif
