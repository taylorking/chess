#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <bishop.h>
#include <board.h>
#include <mock_piece.h>

namespace chess {

using ::testing::UnorderedElementsAre;

TEST(BishopTests, TestPositionsAndNoCollisions) {
  Piece* n = nullptr;
  auto black_piece = MockPiece(Color::BLACK);
  auto white_piece = MockPiece(Color::WHITE);

  Piece* w = &white_piece;
  Piece* b = &black_piece;

  ChessBoard board({b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b,
                   n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n,
                   n, n, n, n, n, n, n, n, n, n, n, w, n, n, n, n,
                   w, w, w, n, w, w, w, w, w, w, w, w, w, w, w, w});

  auto bishop = std::make_unique<TestPiece<Bishop>>(Color::WHITE, 7, 2);
  EXPECT_THAT(bishop->GetMoves(board),
              UnorderedElementsAre(PositionFromPair(6, 3), PositionFromPair(5, 4), PositionFromPair(4, 5),
                                   PositionFromPair(3, 6), PositionFromPair(2, 7)));
}

TEST(BishopTests, TestPositionsNoPieces) {
  Piece* n = nullptr;

  auto bishop = std::make_unique<TestPiece<Bishop>>(Color::WHITE, 3, 3);

  ChessBoard board({n, n, n, n, n, n, n, n, n, n, n, n, n, n,
                   n, n, n, n, n, n, n, n, n, n, n, n, n, bishop.get(),
                   n, n, n, n, n, n, n, n, n, n, n, n, n, n,
                   n, n, n, n, n, n, n, n, n, n, n, n, n, n,
                   n, n, n, n, n, n, n, n});

  EXPECT_THAT(bishop->GetMoves(board),
              UnorderedElementsAre(
                  // Up-Left
                  PositionFromPair(0, 0), PositionFromPair(1, 1), PositionFromPair(2, 2),
                  // Up-Right
                  PositionFromPair(2, 4), PositionFromPair(1, 5), PositionFromPair(0, 6),
                  // Down-Left
                  PositionFromPair(4, 2), PositionFromPair(5, 1), PositionFromPair(6, 0),
                  // Down-Right
                  PositionFromPair(4, 4), PositionFromPair(5, 5), PositionFromPair(6, 6), PositionFromPair(7, 7)));
}

}  // namespace chess
