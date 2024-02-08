#include <game_runner.h>
#include <human_player.h>
#include <models.h>
#include <random_player.h>

using ::chess::Game;
using ::chess::HumanPlayer;
using ::chess::Player;
using ::chess::RandomPlayer;
using ::chess::RunGame;

int main() {
  std::unique_ptr<Player> white_player =
      std::make_unique<HumanPlayer>(chess::WHITE, "White player");
  // std::unique_ptr<Player> black_player =
  // std::make_unique<HumanPlayer>(chess::BLACK, "Black player");
  std::unique_ptr<Player> black_player =
      std::make_unique<RandomPlayer>(chess::BLACK, white_player.get());
  Game* game = SetupNewGame(white_player.get(), black_player.get());

  while (true) {
    RunGame(game);
  }
}
