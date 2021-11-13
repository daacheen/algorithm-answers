#include "cppincludes.h"

class Solution {
  public:
    int minStartValue(vector<int> &nums) {
        int minVal = INT_MAX;

        int result = 0;
        for (int num : nums) {
            result += num;
            minVal = min(minVal, result);
        }

        if (minVal >= 1) {
            return 1;
        }

        return 1 - minVal;
    }
};