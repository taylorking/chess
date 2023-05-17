#ifndef CHESS_LIB_MOVE
#define CHESS_LIB_MOVE
namespace chess {

class Move {
  public:
    int x_;
    int y_;
    Move(int x, int y): x_(x), y_(y) {}
    bool operator==(const Move& other) const = default;
};
}
#endif
