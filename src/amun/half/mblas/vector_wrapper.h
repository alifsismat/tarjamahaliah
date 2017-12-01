#pragma once
#include "matrix.h"
#include "vector.h"

namespace amunmt {
namespace GPUHalf {
namespace mblas {


template <typename T>
class VectorWrapper
{
public:
  VectorWrapper(const Vector<T> &vec)
  {
    size_ = vec.size();
    data_ = nullptr;
    dataConst_ = vec.data();
  }

  VectorWrapper(Vector<T> &vec)
  {
    size_ = vec.size();
    data_ = vec.data();
    dataConst_ = vec.data();
  }

  __device__ __host__
  VectorWrapper(const T *ptr, uint size)
  {
    size_ = size;
    data_ = nullptr;
    dataConst_ = ptr;
  }

  __device__ __host__
  VectorWrapper(T *ptr, uint size)
  {
    size_ = size;
    data_ = ptr;
    dataConst_ = ptr;
  }

  __device__ __host__
  uint size() const
  {
    return size_;
  }

  __device__
  T* data()
  {
    assert(data_);
    return data_;
  }

  __device__
  const T* data() const
  {
    assert(dataConst_);
    return dataConst_;
  }

  __device__
  const T &operator[](uint i) const
  {
    assert(i < size());
    return data()[i];
  }

  __device__
  T &operator[](uint i)
  {
    assert(i < size());
    return data()[i];
  }

protected:
  uint size_;

  T *data_;
  const T *dataConst_;

};


}
}
}

