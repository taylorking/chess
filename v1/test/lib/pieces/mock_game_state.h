#ifndef CHESS_TEST_LIB_PIECES_MOCK_GAME_STATE
#define CHESS_TEST_LIB_PIECES_MOCK_GAME_STATE
class MockGameState : public GameState {
  public:
    MockGameState(const ChessBoard& board) : 
      GameState(board) {}
}

#endif
