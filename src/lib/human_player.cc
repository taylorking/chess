#include <human_player.h>
#include <iostream>
#include <models.h>
#include <sstream>
namespace chess {
namespace {
void PrintBoard(Board const& board) {
  std::stringstream board_str;
  auto const black_background = "\033[48;5;240m";
  auto const white_background = "\033[48;5;249m";
  auto const white_fg = "\033[38;5;15m";
  auto const black_fg = "\033[38;5;0m";

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (i == 0 && j == 0) {
        board_str << "      ";
        continue;
      }
      if (i == 0) {
        board_str << "  " << j - 1 << "   ";
        continue;
      }
      if (i >= 1 && j == 0) {
        board_str << "  " << i - 1 << "   ";
        continue;
      }
      int x = i - 1;
      int y = j - 1;
      Piece const* piece = board.chess_board_[x][y];
      std::string bg_color =
          x % 2 == y % 2 ? white_background : black_background;
      std::string fg_color = piece == nullptr                ? ""
                             : piece->color_ == Color::WHITE ? white_fg
                                                             : black_fg;

      board_str << fg_color << bg_color << "  "
                << (piece == nullptr ? "  " : piece->GetName()) << "  \033[0m";
    }
    board_str << std::endl;
  }
  std::cout << board_str.str();
}
}  // namespace

std::variant<Move, Rewind, Resign> HumanPlayer::RequestCommand(
    GameState const& game, std::string const& status) const {
  int x = -1, y = -1;
  Piece const* piece = nullptr;
  while (true) {
    PrintBoard(game.board_);
    std::cout << "You are player: " << name_ << std::endl;
    std::cout << "Please pick a piece in the form x,y" << std::endl;
    std::string piece_string;
    std::cin >> piece_string;
    if (piece_string[0] == 'R') {
      return Rewind{};
    }
    x = (piece_string[0] - 0x30);
    y = (piece_string[2] - 0x30);
    piece = game.board_.chess_board_[x][y];
    if (piece == nullptr) {
      std::cout << "No piece at that location. " << std::endl;
      continue;
    }
    break;
  }
  std::cout << "You selected " << piece->GetName() << " at " << x << "," << y
            << std::endl;
  std::cout << "Make a move. Enter new coordinates in the form x,y"
            << std::endl;
  std::string move_string;
  std::cin >> move_string;
  x = (move_string[0] - 0x30);
  y = (move_string[2] - 0x30);
  return Move{.piece_ = piece, .x_ = x, .y_ = y};
}

}  // namespace chess
