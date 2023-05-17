#include <game_state.h>

#include <gtest/gtest.h>

using ::testing::Eq;

namespace chess {

TEST(SetupGameState, GameIsStarted) {
  auto state = GameState();
  auto [player1, player2]  = state.GetPlayers();
  EXPECT_EQ(player1->GetPieces().size(), 16);
  EXPECT_EQ(player2->GetPieces().size(), 16);
}


}
