#ifndef CHESS_LIB_MODELS_H_
#define CHESS_LIB_MODELS_H_

#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

namespace chess {
enum Color {
  WHITE = 1,
  BLACK = 2,
};

struct Board;
class Piece;

struct Move {
  Piece const* piece_;
  int x_, y_;
  bool operator==(Move const& other) const = default;
};

class Piece {
 public:
  Piece(Color color) : color_(color) {}
  virtual std::vector<Move> GetMoves(Board const& board) const = 0;
  virtual std::string GetName() const = 0;
  Color color_;
};

using ChessBoard = Piece const* [8][8];
using PieceMap =
    std::unordered_map<Color,
                       std::unordered_map<Piece const*, std::tuple<int, int>>>;

struct Board {
  ChessBoard chess_board_;
  PieceMap piece_map_;
};

class Player;

struct GameState {
  Board board_;
  Player const* turn_;
  std::unordered_map<Color, std::tuple<int, int>> king_positions_;
  GameState() = default;
  GameState(GameState const& other) = default;
};

struct Rewind {};
struct Resign{};

struct Game {
  std::unique_ptr<GameState> current_state_ = nullptr;
  std::vector<std::unique_ptr<GameState>> past_states_;
  std::vector<std::unique_ptr<Piece>> pieces_;
  Player* white_player_;
  Player* black_player_;
};

}  // namespace chess
#endif
