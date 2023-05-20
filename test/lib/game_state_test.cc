#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <game_state.h>

using ::testing::Eq;

namespace chess {
namespace {
class MockPlayer : public Player {
  public:
    MockPlayer(): Player(Color::WHITE) {}
    virtual std::pair<Piece const*, Position> GetMove() const {
      return {nullptr, 0};
    }
    
};
}
TEST(GameState, GameIsStarted) {
  MockPlayer white_, black_;
  auto state = GameState(&white_, &black_);
  auto [player1, player2] = state.GetPlayers();
  EXPECT_EQ(player1->GetPieces().size(), 16);
  EXPECT_EQ(player2->GetPieces().size(), 16);
}

TEST(GameState, CloneGameState) {
  MockPlayer white_, black_;
  auto state = GameState(&white_, &black_);
  auto [white, black] = state.GetPlayers();
  
  auto new_state = GameState(state);
  auto [new_white, new_black] = new_state.GetPlayers();
  EXPECT_EQ(new_white->GetPieces().size(), 16);
  EXPECT_EQ(new_black->GetPieces().size(), 16);
}

TEST(GameState, TestMakeAPosition) {
  MockPlayer white_;
  MockPlayer black_;
  auto initial_state = GameState(&white_, &black_);
  {
    auto [white, black] = initial_state.GetPlayers();
    EXPECT_THAT(initial_state.GetCurrentTurn(), Eq(white));
  }
  Piece const* p = (*initial_state.GetBoard())[6][7];
  auto new_state = initial_state.ApplyMove(p, PositionFromPair(4, 7));
  {
    auto [white, black] = new_state->GetPlayers();
    EXPECT_THAT(new_state->GetCurrentTurn(), Eq(black));
  }
  
  EXPECT_THAT((*new_state->GetBoard())[6][7], Eq(nullptr));
  auto const* new_piece = (*new_state->GetBoard())[4][7];
  auto [x, y] = new_piece->GetCoordinates();
  EXPECT_THAT(x, Eq(4));
  EXPECT_THAT(y, Eq(7));
  EXPECT_THAT(new_piece->GetColor(), Eq(Color::WHITE));
}

}  // namespace chess
