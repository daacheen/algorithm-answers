#include "cppincludes.h"

// robbed[i] = max(robbed[i-1], robbed[i-1-j]+nums[i]),1<=j<=i-1
//

#define ON

#ifdef ON

class Solution {
  public:
    int rob(vector<int> &nums) {
        int size = nums.size();

        if (size == 0) {
            return 0;
        }

        vector<int> dp(size, 0);
        dp[0] = nums[0];

        if (size == 1) {
            return dp[0];
        }

        dp[1] = nums[1];

        int ans = max(dp[0], dp[1]);

        int prevMax = dp[0];
        for (int i = 2; i < size; i++) {
            prevMax = max(prevMax, dp[i - 2]);
            dp[i] = max(dp[i - 1], prevMax + nums[i]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
#else
class Solution {
  public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int ans = INT_MIN;
        int last_second = nums[0], last = max(nums[0], nums[1]), current;

        for (int i = 2; i < nums.size(); i++) {
            current = max(nums[i] + last_second, last);
            ans = max(ans, current);
            last_second = last;
            last = current;
        }

        return ans;
    }
};
#endif