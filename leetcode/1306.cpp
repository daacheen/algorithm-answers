#include "cppincludes.h"

class Solution {
  public:
    bool dfs(vector<int> &arr, int i, vector<int> &dp) {
        if (dp[i] >= 0) {
            return dp[i] == 1;
        }

        if (arr[i] == 0) {
            dp[i] = 1;
            return true;
        }

        dp[i] = 0;

        if (i + arr[i] < arr.size()) {
            if (dfs(arr, i + arr[i], dp)) {
                dp[i] = 1;
                return true;
            }
        }

        if (i - arr[i] >= 0) {
            if (dfs(arr, i - arr[i], dp)) {
                dp[i] = 1;
                return true;
            }
        }

        return false;
    }

    bool canReach(vector<int> &arr, int start) {

        // 1 reach, 0 cannot reach, -1 not calculated
        vector<int> dp(arr.size(), -1);

        return dfs(arr, start, dp);
    }
};