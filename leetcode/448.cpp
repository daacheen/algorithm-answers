#include "cppincludes.h"

class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> m(nums.size(), 0);

        for (int num : nums) {
            m[num - 1]++;
        }

        vector<int> r;
        for (int i = 1; i < m.size(); i++) {
            if (m[i] == 0) {
                r.push_back(i + 1);
            }
        }

        return r;
    }
};