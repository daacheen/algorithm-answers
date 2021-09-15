#include "cppincludes.h"

class Solution {
  public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        bool neg = false;

        if (x < 0) {
            x = -x;
            neg = true;
        }

        int ans = 0;
        while (x > 0) {
            if (ans > INT_MAX / 10) {
                return 0;
            }
            int remainder = x % 10;
            ans = ans * 10 + remainder;
            x /= 10;
        }

        return neg ? -ans : ans;
    }
};