#include "cppincludes.h"

class Solution {
  public:
    int findGCD(vector<int> &nums) {
        // find the min and max
        int min_val = INT_MAX, max_val = INT_MIN;

        for (int num : nums) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }

        // find the common divisor
        return __gcd(min_val, max_val);
    }
};