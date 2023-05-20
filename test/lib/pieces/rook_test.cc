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
  auto rook = std::make_unique<Rook>(Color::WHITE, 7, 7);
  ChessBoard board{b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b,
                   n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n,
                   n, n, n, n, n, n, n, n, n, n, n, w, n, n, n, n,
                   w, w, w, n, w, w, w, n, w, w, w, w, w, w, w, rook.get()};
  EXPECT_THAT(rook->GetMoves(board),
              UnorderedElementsAre(Move(7, 6), Move(7, 5), Move(7, 4),
                                   Move(7, 3), Move(7, 2), Move(7, 1)));
}

TEST(RookTests, TestAllMoveDirections) {
  Piece* n = nullptr;

  auto rook = std::make_unique<Rook>(Color::WHITE, 3, 4);
  ChessBoard board{
      n, n, n, n, n, n, n,          n, n, n, n, n, n, n, n, n, n, n, n, n, n, n,
      n, n, n, n, n, n, rook.get(), n, n, n, n, n, n, n, n, n, n, n, n, n, n, n,
      n, n, n, n, n, n, n,          n, n, n, n, n, n, n, n, n, n, n, n, n,
  };
  EXPECT_THAT(rook->GetMoves(board),
              UnorderedElementsAre(
                  // Left
                  Move(3, 0), Move(3, 1), Move(3, 2), Move(3, 3),
                  // Right
                  Move(3, 5), Move(3, 6), Move(3, 7),
                  // Up
                  Move(2, 4), Move(1, 4), Move(0, 4),
                  // Down
                  Move(4, 4), Move(5, 4), Move(6, 4), Move(7, 4)));
}

}  // namespace chess
