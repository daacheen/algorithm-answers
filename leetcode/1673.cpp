#include "cppincludes.h"

// 其实不知道为什么能过……

class Solution {
  public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (!s.empty() && s.top() > num &&
            // 如果 现在stack里还有的 + 剩下的个数 <= k了，就不能再pop了
                   nums.size() - i + s.size() > k) {
                s.pop();
            }
            s.push(num);
        }

        // pop extra elements
        int popTimes = s.size() - k;
        for (int i = 0; i < popTimes; i++) {
            s.pop();
        }

        // the reverse order of the result
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }
        return result;
    }
};