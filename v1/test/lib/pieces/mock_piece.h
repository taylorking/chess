#include <gmock/gmock.h>
#include <position.h>
#include <piece.h>
namespace chess {

template<class T>
class TestPiece: public T {
  public:
    using T::T; 
    std::unordered_set<Position> GetMoves(const ChessBoard& board) const {
      return this->GetRawMoves(board);
    }
};

class MockPiece : public ClonablePiece<MockPiece>{
 public:
  MockPiece(Color color) : ClonablePiece(color, -1, -1) {}
  std::string GetName() const { return "dummy"; }
  std::unordered_set<Position> GetRawMoves(ChessBoard const& board) const override {
    return {};
  }
};

}  // namespace chess
