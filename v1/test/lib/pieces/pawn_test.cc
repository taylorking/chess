#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <board.h>
#include <mock_piece.h>
#include <pawn.h>

using ::testing::UnorderedElementsAre;

namespace chess {
TEST(PawnTests, OpeningPositionWhite) {
  Piece* n = nullptr;
  auto black_piece = MockPiece(Color::BLACK);
  auto white_piece = MockPiece(Color::WHITE);

  Piece* w = &white_piece;
  Piece* b = &black_piece;
  
  auto pawn = std::make_shared<TestPiece<Pawn>>(Color::WHITE, 6, 7);
  ChessBoard board({
    b, b, b, b, b, b, b, b,
    b, b, b, b, b, b, b, b,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    w, w, w, w, w, w, w, pawn.get(),
    w, w, w, w, w, w, w, w
  });
  EXPECT_THAT(pawn->GetMoves(board),
      UnorderedElementsAre(
        PositionFromPair(5, 7), PositionFromPair(4, 7)
      ));
}

TEST(PawnTests, OpeningPositionBlack) {
  Piece* n = nullptr;
  auto black_piece = MockPiece(Color::BLACK);
  auto white_piece = MockPiece(Color::WHITE);

  Piece* w = &white_piece;
  Piece* b = &black_piece;
  
  auto pawn = std::make_shared<TestPiece<Pawn>>(Color::BLACK, 1, 7);
  ChessBoard board({
    b, b, b, b, b, b, b, b,
    b, b, b, b, b, b, b, pawn.get(),
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    w, w, w, w, w, w, w, w,
    w, w, w, w, w, w, w, w
  });
  EXPECT_THAT(pawn->GetMoves(board),
      UnorderedElementsAre(
        PositionFromPair(2, 7), PositionFromPair(3, 7)
      ));
}
TEST(PawnTests, WhiteTakesPiece) {
  Piece* n = nullptr;
  auto black_piece = MockPiece(Color::BLACK);
  auto white_piece = MockPiece(Color::WHITE);

  Piece* w = &white_piece;
  Piece* b = &black_piece;
  
  auto pawn = std::make_shared<TestPiece<Pawn>>(Color::WHITE, 6, 7);
  ChessBoard board({
    b, b, b, b, b, b, b, b,
    b, b, b, b, b, b, b, b,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, b, w,
    w, w, w, w, w, w, w, pawn.get(),
    w, w, w, w, w, w, w, w
  });
  EXPECT_THAT(pawn->GetMoves(board),
      UnorderedElementsAre(
        PositionFromPair(5, 6)
      ));
}
TEST(PawnTests, BlackTakesPiece) {
  Piece* n = nullptr;
  auto black_piece = MockPiece(Color::BLACK);
  auto white_piece = MockPiece(Color::WHITE);

  Piece* w = &white_piece;
  Piece* b = &black_piece;
  
  auto pawn = std::make_shared<TestPiece<Pawn>>(Color::BLACK, 1, 7);
  ChessBoard board({
    b, b, b, b, b, b, b, b,
    b, b, b, b, b, b, b, b,
    n, n, n, n, n, n, w, b,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    w, w, w, w, w, w, w, w,
    w, w, w, w, w, w, w, w
  });
  EXPECT_THAT(pawn->GetMoves(board),
      UnorderedElementsAre(
        PositionFromPair(2, 6)
      ));
}

}
