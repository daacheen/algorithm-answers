#include "cppincludes.h"

/**

l, r
dp[i][i][any] = 0
dp[i][j][any] = INT_MAX
dp[l][r][cost] = max(
        cost > (abs(s[r]-t[r]) as a) ? dp[l][r-1][cost-a] + 1 : INT_MIN,
        cost > (abs(s[l]-t[l]) as a) ? dp[l-1][r][cost-a] + 1 : INT_MIN
)


*/

class Solution {
  public:
    int equalSubstring(string s, string t, int maxCost) {
        // sliding window
        int len = s.length();

        if (len == 0) {
            return 0;
        }

        int l = 0, r = 0;
        int result = 0;
        int cost = maxCost;
        while (l <= r && r < len) {
            // try s[r]
            int costToExpandToR = abs(s[r] - t[r]);
            if (costToExpandToR <= cost) {
                // can continue
                cost -= costToExpandToR;
                result = max(result, r - l + 1);
                r++;
                continue;
            }
            // cannot continue, try removing the left
            while (l <= r) {
                // remove l
                cost += abs(s[l] - t[l]);
                l++;
                if (l <= r) {
                    if (costToExpandToR <= cost) {
                        break;
                    }
                } else {
                    // l > r, the windows is closed
                    // reset l, r, cost to start from the next window
                    cost = maxCost;
                    r = l;
                    break;
                }
            }
        }

        return result;
    }
};