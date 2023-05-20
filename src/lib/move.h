#ifndef CHESS_LIB_MOVE
#define CHESS_LIB_MOVE
namespace chess {

class Move {
 public:
  int x_;
  int y_;
  Move(int x, int y) : x_(x), y_(y) {}
  bool operator==(Move const& other) const = default;
};
}  // namespace chess
#endif
