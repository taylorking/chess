#include <gmock/gmock.h>
namespace chess {
class MockPiece : public Piece {
  public:
    MockPiece(Color color): Piece(color, -1, -1) {}
    std::string GetName() const {
      return "dummy";
    }
    std::vector<Move> GetRawMoves(const ChessBoard& board) const override {
      return {}; 
    }
};

}
