#include <board.h>
#include <board_printer.h>
#include <sstream>

namespace chess {
std::string PrintBoard(ChessBoard const& board) {
  char header_char = 'A';
  int header_int = 1;
  std::stringstream boardstr;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      boardstr << ' ';
      if (i == 0 || i == 9) {
        boardstr << header_char << ' ';
        header_char++;
        continue;
      } else if (j == 0) {
        boardstr << header_int;
        continue;
      } else if (j == 9) {
        boardstr << header_int;
        header_int++;
        continue;
      } else {
        header_char = 'A';
        if (board[i - 1][j - 1] == nullptr) {
          boardstr << ' ';
        } else {
          boardstr << board[i - 1][j - 1]->ToString();
        }
      }
      boardstr << ' ';
    }
    boardstr << std::endl;
  }
  return boardstr.str();
}
}  // namespace chess
