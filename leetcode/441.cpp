#include "cppincludes.h"

class Solution {
  public:
    int arrangeCoins(int n) {
        int i = 0;
        while (n >= i + 1) {
            i++;
            n -= i;
        }

        return i;
    }
};