#include <algorithm>
#include <game_state.h>
#include <human_player.h>

namespace chess {

// New Constructor
GameState::GameState(Player* white, Player* black)
    : white_(white),
      black_(black),
      board_(white_pieces_, black_pieces_),
      turn_(white_) {
  white_->SetPlayerPieces(&white_pieces_);
  black_->SetPlayerPieces(&black_pieces_);
}

// Copy Constructor
GameState::GameState(GameState const& state)
    : white_(state.white_),
      black_(state.black_),
      board_(white_pieces_, black_pieces_, state.board_),
      turn_(nullptr) {
  white_->SetPlayerPieces(&white_pieces_);
  black_->SetPlayerPieces(&black_pieces_);
}

GameState::GameState(GameState&& state)
    : white_(state.white_),
      black_(state.black_),
      white_pieces_(std::move(state.white_pieces_)),
      black_pieces_(std::move(state.black_pieces_)),
      board_(std::move(state.board_)),
      turn_(state.turn_) {}

GameState::GameState(Player* white, Player* black, ChessBoard& board,
                     PlayerPieces& white_pieces, PlayerPieces& black_pieces,
                     Player const* turn)
    : white_(white),
      black_(black),
      board_(board),
      white_pieces_(std::move(white_pieces)),
      black_pieces_(std::move(black_pieces)),
      turn_(turn) {
  white_->SetPlayerPieces(&white_pieces_);
  black_->SetPlayerPieces(&black_pieces_);
}

ChessBoard const* GameState::GetBoard() const { return &board_; }

std::pair<Player const*, Player const*> GameState::GetPlayers() const {
  return {white_, black_};
}

Player const* GameState::GetCurrentTurn() const { return turn_; }

std::unique_ptr<GameState> GameState::ValidateAndApplyMove(Piece const* p, Position move) const {
  if (!p->GetMoves(*this).contains(move)) return nullptr;
  return ApplyMove(p, move);
}

std::unique_ptr<GameState> GameState::ApplyMove(Piece const* p,
                                                Position move) const {
  auto new_state = std::make_unique<GameState>(*this);
  new_state->turn_ = turn_ == black_ ? white_ : black_;
  auto [old_x, old_y] = p->GetCoordinates();
  auto [new_x, new_y] = PositionToPair(move);
  ChessBoard const& new_board = new_state->board_;
  if (new_board[new_x][new_y] != nullptr) {
    Player* player = new_board[new_x][new_y]->GetColor() == Color::WHITE
                         ? new_state->white_
                         : new_state->black_;
    new_state->graveyard_.push_back(
        player->TakePieceFromPlayer(new_board[new_x][new_y]));
  }
  Position old_position = PositionFromPair(old_x, old_y);
  new_state->board_.ApplyMove(old_position, move);
  return new_state;
}

}  // namespace chess
