#include "cppincludes.h"
#include <algorithm>
#include <numeric>

/** 思想：union find
 * 把nums[i]和它的每个因数合并为一组，因数为parent
 * 在这个合并过程中，本来不相关的因数将会被合并到一起，成为一个根
 * 最后再对每个nums[i]看它们的根，计算这个根的频率
 */
class Solution {
  public:
    vector<int> breakdown(int N) {
        vector<int> result;
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) { // 如果 i 能够整除 N，说明 i 为 N 的一个质因子。
                while (N % i == 0)
                    N /= i;
                result.push_back(i);
            }
        }
        if (N != 1) { // 说明再经过操作之后 N 留下了一个素数
            result.push_back(N);
        }
        return result;
    }

    vector<int> parents;
    int find(int x) {
        if (x == parents[x]) {
            return x;
        } else {
            return parents[x] = find(parents[x]);
        }
    }

    void merge(int x, int p) { parents[find(x)] = find(p); }

    int largestComponentSize(vector<int> &nums) {

        if (nums.size() == 1) {
            return 1;
        }

        int max_val = *max_element(nums.begin(), nums.end());

        for (int i = 0; i <= max_val; i++) {
            parents.push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            auto factors = breakdown(nums[i]);
            for (int f : factors) {
                merge(nums[i], f);
            }
        }

        map<int, int> mp;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            int pc = find(nums[i]);
            mp[pc]++;
            ans = max(ans, mp[pc]);
        }
        return ans;
    }
};

int main() {
    vector<int> l{2, 3, 6, 7, 4, 12, 21, 39};
    Solution().largestComponentSize(l);
}
