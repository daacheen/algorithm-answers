#include "cppincludes.h"

class Solution {
  public:
    // 单调栈
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> greaters;
        stack<int> s;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            int v = nums2[i];
            while (!s.empty() && s.top() <= v) {
                s.pop();
            }
            if (!s.empty()) {
                greaters[nums2[i]] = s.top();
            }
            s.push(v);
        }

        vector<int> ans(nums1.size(), -1);
        for (int j = 0; j < nums1.size(); j++) {
            if (greaters.find(nums1[j]) != greaters.end()) {
                ans[j] = greaters[nums1[j]];
            }
        }

        return ans;
    }
};