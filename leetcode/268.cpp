#include "cppincludes.h"

class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int expectedSum = (n + 1) * n / 2;
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        return expectedSum - actualSum;
    }
};