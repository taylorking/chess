#include <human_player.h>
#include <iostream>
#include <position.h>
#include <unistd.h>
namespace chess {
std::pair<Piece const*, Position> HumanPlayer::GetMove() const {
input:
  std::cout << "Make a move!" << std::endl;
  std::cout << " Enter Coordinates x,y" << std::endl;
  std::string selection_input;
  std::cin >> selection_input;
  int x = selection_input[0] - 0x30;
  int y = selection_input[2] - 0x30;
  auto const& board = *game_->GetCurrentState()->GetBoard();

  Piece const* p = board[x][y];
  if (p == nullptr || p->GetColor() != color_) {
    std::cout << "There is not a piece at the selected location." << std::endl
              << " Try again.";
    sleep(1);
    goto input;
  }
move:
  std::cout << "You selected piece: " << p->ToString() << " at location: " << x
            << "," << y << std::endl;
  std::cout << "Enter a destination x, y" << std::endl;
  std::cin >> selection_input;
  int new_x = selection_input[0] - 0x30;
  int new_y = selection_input[2] - 0x30;
  return {p, PositionFromPair(new_x, new_y)};
}
}  // namespace chess
