#include "cppincludes.h"

class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        // binary search
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid - 1] == nums[mid]) {
                if ((mid - left) % 2 == 1) {
                    left = mid + 1;
                } else {
                    right = mid - 2;
                }
            } else if (nums[mid + 1] == nums[mid]) {
                if ((mid - left) % 2 == 1) {
                    right = mid - 1;
                } else {
                    left = mid + 2;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[left];
    }
};