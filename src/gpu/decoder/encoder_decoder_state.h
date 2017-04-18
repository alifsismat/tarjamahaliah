#pragma once

#include <string>
#include "common/scorer.h"

#include "gpu/mblas/matrix.h"

namespace amunmt {
namespace GPU {

class EncoderDecoderState : public State {
  public:
    EncoderDecoderState(const EncoderDecoderState&) = delete;
    EncoderDecoderState() {}

    virtual std::string Debug() const;

    mblas::Matrix& GetStates();
    mblas::Matrix& GetEmbeddings();
    const mblas::Matrix& GetStates() const;
    const mblas::Matrix& GetEmbeddings() const;

    virtual void JoinStates(const States& states);
    virtual void MakeState(State& state, size_t rowNo);

  protected:
    mblas::Matrix states_;
    mblas::Matrix embeddings_;
};

}  // namespace GPU
}  // namespace amunmt