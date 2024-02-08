#include <models.h>
#include <piece_helpers.h>

namespace chess {
Piece const* GetPieceAtLocation(Board const& board,
                                std::tuple<int, int> const& coords) {
  auto [x, y] = coords;
  return board.chess_board_[x][y];
}
void ConstructMove(std::vector<Move>& moves, Piece const* piece,
                   std::tuple<int, int> const& coords) {
  auto [x, y] = coords;
  moves.push_back(Move{.piece_ = piece, .x_ = x, .y_ = y});
}
void HorizontalBehavior(std::vector<Move>& moves, Piece const* piece,
                        Board const& board, bool is_king) {
  auto [x, y] = board.piece_map_.at(piece->color_).at(piece);
  // DOWN
  for (int i = x + 1; i < 8; i++) {
    if (board.chess_board_[i][y] == nullptr) {
      ConstructMove(moves, piece, {i, y});
      if (is_king) break;
      continue;
    }
    if (board.chess_board_[i][y]->color_ != piece->color_) {
      ConstructMove(moves, piece, {i, y});
      break;
    }
    break;
  }
  // UP
  for (int i = x - 1; i >= 0; i--) {
    if (board.chess_board_[i][y] == nullptr) {
      ConstructMove(moves, piece, {i, y});
      if (is_king) break;
      continue;
    }
    if (board.chess_board_[i][y]->color_ != piece->color_) {
      ConstructMove(moves, piece, {i, y});
      break;
    }
    break;
  }
  // LEFT
  for (int i = y - 1; i >= 0; i--) {
    if (board.chess_board_[x][i] == nullptr) {
      ConstructMove(moves, piece, {x, i});
      if (is_king) break;
      continue;
    }
    if (board.chess_board_[x][i]->color_ != piece->color_) {
      ConstructMove(moves, piece, {i, y});
      break;
    }
    break;
  }
  // RIGHT
  for (int i = y + 1; i < 8; i++) {
    if (board.chess_board_[x][i] == nullptr) {
      ConstructMove(moves, piece, {x, i});
      if (is_king) break;
      continue;
    }
    if (board.chess_board_[x][i]->color_ != piece->color_) {
      ConstructMove(moves, piece, {i, y});
      break;
    }
    break;
  }
}
void DiagonalBehavior(std::vector<Move>& moves, Piece const* piece,
                      Board const& board, bool is_king) {
  auto [x, y] = board.piece_map_.at(piece->color_).at(piece);
  // UP-LEFT;
  int i = x - 1;
  int j = y - 1;
  while (i >= 0 && j >= 0) {
    if (board.chess_board_[i][j] == nullptr) {
      ConstructMove(moves, piece, {i, j});
    } else if (board.chess_board_[i][j]->color_ != piece->color_) {
      ConstructMove(moves, piece, {i, j});
      break;
    } else {
      break;
    }
    if (is_king) break;
    i--;
    j--;
  }
  // UP-RIGHT;
  i = x - 1;
  j = y + 1;
  while (i >= 0 && j < 8) {
    if (board.chess_board_[i][j] == nullptr) {
      ConstructMove(moves, piece, {i, j});
    } else if (board.chess_board_[i][j]->color_ != piece->color_) {
      ConstructMove(moves, piece, {i, j});
      break;
    } else {
      break;
    }
    if (is_king) break;
    i--;
    j++;
  }
  // DOWN-LEFT;
  i = x + 1;
  j = y - 1;
  while (i < 8 && j >= 0) {
    if (board.chess_board_[i][j] == nullptr) {
      ConstructMove(moves, piece, {i, j});
    } else if (board.chess_board_[i][j]->color_ != piece->color_) {
      ConstructMove(moves, piece, {i, j});
      break;
    } else {
      break;
    }
    if (is_king) break;
    i++;
    j--;
  }
  // DOWN-RIGH;
  i = x + 1;
  j = y + 1;
  while (i < 8 && j < 8) {
    if (board.chess_board_[i][j] == nullptr) {
      ConstructMove(moves, piece, {i, j});
    } else if (board.chess_board_[i][j]->color_ != piece->color_) {
      ConstructMove(moves, piece, {i, j});
      break;
    } else {
      break;
    }
    if (is_king) break;
    i++;
    j++;
  }
}
}  // namespace chess
