#include "cppincludes.h"

const int MODULO = 1000000007;

class Solution {
  public:
    int f;
    unordered_map<int, unordered_map<int, int>> dp;

    int rec(int d, int t) {
        if (dp.find(d) != dp.end() && dp[d].find(t) != dp[d].end()) {
            return dp[d][t];
        }

        if (t == 0) {
            return dp[d][t] = d == 0 ? 1 : 0;
        }

        if (f * d < t) {
            return dp[d][t] = 0;
        }

        long long r = 0;
        for (int i = 1; i <= f && i <= t; i++) {
            r += rec(d - 1, t - i);
            r %= MODULO;
        }
        return dp[d][t] = r;
    }

    int numRollsToTarget(int d, int f, int target) {
        this->f = f;

        return rec(d, target);
    }
};