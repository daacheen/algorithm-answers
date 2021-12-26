
#include "cppincludes.h"

class Solution {
  public:
    int minimumDifference(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        // find the window
        int result = INT_MAX;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            result = min(result, nums[i + k - 1] - nums[i]);
        }
        return result;
    }
};