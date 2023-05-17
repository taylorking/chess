#include <board.h>
#include <game.h>
#include <iostream>

int main(int argc, char** argv) {
  chess::Game g;
  std::cout << chess::Board::PrintBoard(*g.GetCurrentState()->GetBoard());
}
