#include <bishop.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <board.h>
#include <mock_piece.h>

namespace chess {

using ::testing::UnorderedElementsAre;

TEST(BishopTests, TestMovesAndNoCollisions) {
  Piece* n = nullptr;
  auto black_piece = MockPiece(Color::BLACK);
  auto white_piece = MockPiece(Color::WHITE);
  
  Piece* w = &white_piece;
  Piece* b = &black_piece;

  ChessBoard board{
    b, b, b, b, b, b, b, b,
    b, b, b, b, b, b, b, b,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, w, n, n, n, n,
    w, w, w, n, w, w, w, w,
    w, w, w, w, w, w, w, w
  };

  auto bishop = std::make_unique<Bishop>(Color::WHITE, 7, 2);
  EXPECT_THAT(bishop->GetMoves(board), 
      UnorderedElementsAre(Move(6,3), Move(5,4), Move(4,5), Move(3, 6), Move(2,7)));
}

TEST(BishopTests, TestMovesNoPieces) {
  Piece* n = nullptr;
  
  auto bishop = std::make_unique<Bishop>(Color::WHITE, 3, 3);
 
  ChessBoard board{
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, bishop.get(), n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n,
    n, n, n, n, n, n, n, n
  };

  EXPECT_THAT(bishop->GetMoves(board), 
    UnorderedElementsAre(
      // Up-Left
      Move(0,0), Move(1, 1), Move(2,2), 
      // Up-Right
      Move(2,4), Move(1,5), Move(0,6),
      // Down-Left
      Move(4,2), Move(5,1), Move(6,0),
      // Down-Right
      Move(4,4), Move(5,5), Move(6,6), Move(7,7)));
}

}
