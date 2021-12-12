#include "cppincludes.h"

class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        // sum
        int s = accumulate(nums.begin(), nums.end(), 0);

        if (s % 2 != 0) {
            return false;
        }

        int N = s;
        s /= 2;

        vector<bool> dp(N + 1, false);

        stack<int> marks;

        for (int num : nums) {
            marks.push(num);

            for (int i = 1; i <= N; i++) {
                if (dp[i] && !dp[i + num]) {
                    marks.push(i + num);
                }
            }

            while (!marks.empty()) {
                int val = marks.top();
                if (val == s) {
                    return true;
                }
                dp[val] = true;
                marks.pop();
            }
        }

        return false;
    }
};