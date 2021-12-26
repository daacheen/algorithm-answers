#include "cppincludes.h"

//  1 1 0

//

bool compare(const string &a, const string &b) {
    if (a.size() > b.size()) {
        return true;
    }
    if (a.size() < b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) {
            return true;
        } else if (a[i] < b[i]) {
            return false;
        }
    }
    return true;
}

class Solution {
  public:
    string kthLargestNumber(vector<string> &nums, int k) {
        // make min heap in the first k elements
        make_heap(nums.begin(), nums.begin() + k, compare);

        // for the rest elements, if element > min element in the heap, pop and
        // push
        for (int i = k; i < nums.size(); i++) {
            if (compare(nums[i], nums[0])) {
                pop_heap(nums.begin(), nums.begin() + k, compare);
                iter_swap(nums.begin() + k - 1, nums.begin() + i);
                push_heap(nums.begin(), nums.begin() + k, compare);
            }
        }

        // get the top value
        return nums[0];
    }
};

int main() {
    vector<string> s = {"378", "9011", "90"};
    Solution().kthLargestNumber(s, 2);
}