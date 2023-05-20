#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <king.h>
#include <pawn.h>
#include <rook.h>
#include <board.h>
#include <player.h>
#include <game_state.h>

namespace chess {

using ::testing::UnorderedElementsAre;

class MockPlayer : public Player{
  public:
    using Player::Player;
    std::pair<Piece const*, Position> GetMove() const {
      return {nullptr, 0};
    }
};

TEST(TestCheck, ForbidMovesWhilePlayerInCheck) {

  PlayerPieces white_pieces;
  white_pieces.push_back(std::make_unique<Rook>(Color::WHITE, 0, 0));
  white_pieces.push_back(std::make_unique<King>(Color::WHITE, 3, 3));
  white_pieces.push_back(std::make_unique<Pawn>(Color::WHITE, 3, 5));

  PlayerPieces black_pieces;
  black_pieces.push_back(std::make_unique<Pawn>(Color::BLACK, 4, 4));

  Piece* n = nullptr;
  Piece* wr = white_pieces[0].get();
  Piece* wk = white_pieces[1].get();
  Piece* wp = white_pieces[2].get();

  Piece* bp = black_pieces[0].get();

  ChessBoard board({
    wr, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, wk,n, wp, n, n,
    n, n, n, n, bp, n, n, n,
    n, n, n, n, n,  n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
  }, PositionFromPair(2, 3), -1);
  
  MockPlayer white(Color::WHITE);
  MockPlayer black(Color::BLACK);
  white.SetPlayerPieces(&white_pieces);
  black.SetPlayerPieces(&black_pieces);

  auto state = GameState(&white, &black, board, 
    white_pieces, black_pieces, &white);

  EXPECT_THAT(wr->GetMoves(state), UnorderedElementsAre());
  EXPECT_THAT(wp->GetMoves(state), UnorderedElementsAre(
        PositionFromPair(4, 4)));
  EXPECT_THAT(wk->GetMoves(state), UnorderedElementsAre(
    PositionFromPair(2,2), PositionFromPair(2, 3), PositionFromPair(2, 4),
    PositionFromPair(3,2), PositionFromPair(3, 4), PositionFromPair(4, 3),
    PositionFromPair(4,2), PositionFromPair(4, 4)
  ));
}

TEST(TestCheck, AllowPlayerToMoveOutOfCheck) {

}
TEST(TestCheck, TestCheckMate) {

}
}
