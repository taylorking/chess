#ifndef CHESS_LIB_MOVE
#define CHESS_LIB_MOVE

#include <stdint.h>

namespace chess {

using Position = uint8_t;
inline Position PositionFromPair(int8_t x, int8_t y) { return x << 4 | y; }
inline std::pair<int8_t, int8_t> PositionToPair(int8_t move) {
  std::pair<int8_t, int8_t> result;
  result.first = move >> 4;
  // TODO Fix this - this only works on le.
  result.second = move & 0x0f;
  return result;
}
}  // namespace chess
#endif
