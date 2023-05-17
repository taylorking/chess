#include <board.h>

#include <iostream>
#include <sstream>

#include <bishop.h>
#include <knight.h>
#include <king.h>
#include <pawn.h>
#include <rook.h>
#include <queen.h>


namespace chess {

template<typename T>
void MakePieceAndGiveToPlayer(Player* player, ChessBoard& board, int x, int y) {
  auto ptr = std::make_unique<T>(player->GetColor(), x, y);
  T* raw_ptr = ptr.get();
  player->GivePieceToPlayer(std::move(ptr));
  board[y][x] = raw_ptr;
}

ChessBoard Board::CreateBoard(Player* white, Player* black) {
  ChessBoard board;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      board[i][j] = nullptr;
    } 
  }

  for (int i = 0; i < 8; i++) {
    MakePieceAndGiveToPlayer<Pawn>(white, board, i, 6);
    MakePieceAndGiveToPlayer<Pawn>(black, board, i, 1);
  }
  MakePieceAndGiveToPlayer<Rook>(white, board, 0, 7);
  MakePieceAndGiveToPlayer<Rook>(white, board, 7, 7);
  MakePieceAndGiveToPlayer<Rook>(black, board, 0, 0);
  MakePieceAndGiveToPlayer<Rook>(black, board, 7, 0);

  MakePieceAndGiveToPlayer<Knight>(white, board, 1, 7);
  MakePieceAndGiveToPlayer<Knight>(white, board, 6, 7);
  MakePieceAndGiveToPlayer<Knight>(black, board, 1, 0);
  MakePieceAndGiveToPlayer<Knight>(black, board, 6, 0);

  MakePieceAndGiveToPlayer<Bishop>(white, board, 2, 7);
  MakePieceAndGiveToPlayer<Bishop>(white, board, 5, 7);
  MakePieceAndGiveToPlayer<Bishop>(black, board, 2, 0);
  MakePieceAndGiveToPlayer<Bishop>(black, board, 5, 0);

  MakePieceAndGiveToPlayer<Queen>(white, board, 3, 7);
  MakePieceAndGiveToPlayer<Queen>(black, board, 3, 0);

  MakePieceAndGiveToPlayer<King>(white, board, 4, 7);
  MakePieceAndGiveToPlayer<King>(black, board, 4, 0);

  return board;
}

/**
Board::Board(Player* white, Player* black) {
  board_ = MakeNewChessBoard(white, black);
}
**/

std::string Board::PrintBoard(const ChessBoard& board) {
  char header_char = 'A';
  int header_int = 1;
  std::stringstream boardstr;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      boardstr << ' ';
      if (i == 0 || i == 9) {
        boardstr << header_char << ' ';
        header_char++;
        continue;
      } else if (j == 0) {
        boardstr << header_int;
        continue;
      } else if (j == 9) {
        boardstr << header_int;
        header_int++;
        continue;
      } else {
        header_char = 'A';
        if (board[i-1][j-1] == nullptr) {
          boardstr << ' ';
        } else {
          boardstr << board[i-1][j-1]->ToString();
        }
      }
      boardstr << ' ';
    }
    boardstr << std::endl;
  }
  return boardstr.str();
}
}
