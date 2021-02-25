#include "cppincludes.h"

class Solution {
  public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int result = 0;

        // calculate the diffs
        int lastDiff = nums[1] - nums[0], count = 1;
        for (int i = 1; i < nums.size() - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            if (diff == lastDiff) {
                count++;
            } else {
                if (count >= 2) {
                    // sum 1+2+...+(count + 1-3+1)
                    result += (count + 1 - 3 + 1) * (1 + count + 1 - 3 + 1) / 2;
                }
                lastDiff = diff;
                count = 1;
            }
        }
        if (count >= 2) {
            // sum 1+2+...+(count + 1-3+1)
            result += (count + 1 - 3 + 1) * (1 + count + 1 - 3 + 1) / 2;
        }
        return result;
    }
};