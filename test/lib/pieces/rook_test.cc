#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <board.h>
#include <mock_piece.h>
#include <rook.h>

using ::testing::UnorderedElementsAre;
namespace chess {
TEST(RookTests, TestCapturePiece) {
  Piece* n = nullptr;
  auto black_piece = MockPiece(Color::BLACK);
  auto white_piece = MockPiece(Color::WHITE);

  Piece* w = &white_piece;
  Piece* b = &black_piece;
  auto rook = std::make_unique<TestPiece<Rook>>(Color::WHITE, 7, 7);
  ChessBoard board({b, b, b, b, b, b, b, b, 
                   b, b, b, b, b, b, b, b,
                   n, n, n, n, n, n, n, n, 
                   n, n, n, n, n, n, n, n,
                   n, n, n, n, n, n, n, n, 
                   n, n, n, w, n, n, n, n,
                   w, w, w, n, w, w, w, n, 
                   w, w, w, w, w, w, w, rook.get()});
  EXPECT_THAT(rook->GetMoves(board),
              UnorderedElementsAre(PositionFromPair(6,7), PositionFromPair(5,7), PositionFromPair(4,7),
                                   PositionFromPair(3,7), PositionFromPair(2,7), PositionFromPair(1,7)));
}

TEST(RookTests, TestAllPositionDirections) {
  Piece* n = nullptr;

  auto rook = std::make_unique<TestPiece<Rook>>(Color::WHITE, 3, 4);
  ChessBoard board({
      n, n, n, n, n, n, n,          n, n, n, n, n, n, n, n, n, n, n, n, n, n, n,
      n, n, n, n, n, n, rook.get(), n, n, n, n, n, n, n, n, n, n, n, n, n, n, n,
      n, n, n, n, n, n, n,          n, n, n, n, n, n, n, n, n, n, n, n, n,
  });
  EXPECT_THAT(rook->GetMoves(board),
              UnorderedElementsAre(
                  // Left
                  PositionFromPair(3, 0), PositionFromPair(3, 1), PositionFromPair(3, 2), PositionFromPair(3, 3),
                  // Right
                  PositionFromPair(3, 5), PositionFromPair(3, 6), PositionFromPair(3, 7),
                  // Up
                  PositionFromPair(2, 4), PositionFromPair(1, 4), PositionFromPair(0, 4),
                  // Down
                  PositionFromPair(4, 4), PositionFromPair(5, 4), PositionFromPair(6, 4), PositionFromPair(7, 4)));
}

}  // namespace chess
