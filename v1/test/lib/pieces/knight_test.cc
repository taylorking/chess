#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <knight.h>
#include <mock_piece.h>

namespace chess {
using ::testing::UnorderedElementsAre;
TEST(KnightTest, WhiteOpeningTest) {
  Piece* n = nullptr;
  auto black_piece = MockPiece(Color::BLACK);
  auto white_piece = MockPiece(Color::WHITE);

  Piece* w = &white_piece;
  Piece* b = &black_piece;
  auto knight = std::make_unique<TestPiece<Knight>>(Color::WHITE, 7, 6);

  ChessBoard board({
    b, b, b, b, b, b, b, b,
    b, b, b, b, b, b, b, b,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    w, w, w, w, w, w, w, w,
    w, w, w, w, w, w, knight.get(), w
  });
  EXPECT_THAT(knight->GetMoves(board),
    UnorderedElementsAre(
      PositionFromPair(5, 7), PositionFromPair(5, 5)
    ));
}
TEST(KnightTest, GetAllPositions) {
  Piece* n = nullptr;
  auto knight = std::make_unique<TestPiece<Knight>>(Color::WHITE, 3, 3); 
  ChessBoard board({
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, knight.get(), n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n
  });
  EXPECT_THAT(knight->GetMoves(board),
    UnorderedElementsAre(
      PositionFromPair(2, 1), PositionFromPair(2, 5),
      PositionFromPair(1, 2), PositionFromPair(1, 4),
      PositionFromPair(4, 1), PositionFromPair(4, 5),
      PositionFromPair(5, 2), PositionFromPair(5, 4)
  ));
}
}
