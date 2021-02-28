#include "cppincludes.h"

class Solution {
  public:
    // TLE
    int minSubarray_TLE(vector<int> &nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % p == 0) {
            return 0;
        }

        vector<vector<long long>> sums(n, vector<long long>(n, 0));

        sums[0][0] = sum - nums[0];

        int minVal = INT_MAX;
        for (int i = 1; i < n; i++) {
            sums[0][i] = sums[0][i - 1] - nums[i];
            if (i != n - 1 && sums[0][i] % p == 0) {
                minVal = min(minVal, i);
            }
        }

        // dp
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                sums[i][j] = sums[i - 1][j] + nums[i - 1];
                if (sums[i][j] % p == 0) {
                    minVal = min(minVal, j - i);
                }
            }
        }

        return minVal == INT_MAX ? -1 : (minVal + 1);
    }

    // https://leetcode.com/problems/make-sum-divisible-by-p/discuss/1046556/C%2B%2B-with-simple-explanation

    int minSubarray(vector<int> &nums, int p) {

        int n = nums.size();
        int sum = 0;

        for (int num : nums) {
            sum = (sum + num) % p;
        }

        if (sum == 0) {
            return 0;
        }

        unordered_map<int, int> m;
        m[0] = -1;
        int s = 0;
        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            s = (nums[i] + s) % p;
            auto iter = m.find((s - sum + p) % p);
            // cannot remove all items
            if (iter != m.end() && (i - iter->second != n)) {
                // i is the number of the larger array
                // iter->second is the number of small array
                // the subarray has the length of  iter->second -i
                minVal = min(minVal, i - iter->second);
            }
            m[s] = i;
        }

        return minVal == INT_MAX ? -1 : minVal;
    }
};