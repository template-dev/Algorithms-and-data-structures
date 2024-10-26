#ifndef B320366D_CD81_46EE_92AC_FA62FCE3BE53
#define B320366D_CD81_46EE_92AC_FA62FCE3BE53

#include <cstdint>
#include <algorithm>

namespace Algorithms {
  class GCD {
  public:
    int64_t EuclidSubtractionRecursive(int64_t m, int64_t n);
    int64_t EuclidSubtractionIterative(int64_t m, int64_t n);
    int64_t EuclidRemainderOfTheDivisionRecursive(int64_t m, int64_t n);
    int64_t EuclidRemainderOfTheDivisionIterative(int64_t m, int64_t n);
    int64_t SteinzRecursive(int64_t m, int64_t n);
    int64_t SteinzIterative(int64_t m, int64_t n);
  };
}

#endif /* B320366D_CD81_46EE_92AC_FA62FCE3BE53 */
