#include <gmock/gmock.h>
namespace chess {
class MockPiece : public Piece {
 public:
  MockPiece(Color color) : Piece(color, -1, -1) {}
  std::string GetName() const { return "dummy"; }
  std::vector<Move> GetRawMoves(ChessBoard const& board) const override {
    return {};
  }
};

}  // namespace chess
