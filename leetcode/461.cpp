#include "cppincludes.h"

class Solution {
  public:
    int hammingDistance(int x, int y) {
        x = x ^ y;

        y = 0;
        while (x > 0) {
            y += (int)(x & 1);
            x >>= 1;
        }
        return y;
    }
};