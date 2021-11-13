#include "cppincludes.h"

class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        int r = 0;
        for (int num : nums) {
            r ^= num;
        }

        // find the rightmost different bit of the two number
        int rdb = 0;
        for (; rdb < 32; rdb++) {
            if (((int)(r & (1 << rdb))) != 0) {
                break;
            }
        }

        rdb = 1 << rdb;

        // xor rdb with every number with that bit set
        // to get one result
        int r1 = 0;
        for (int num : nums) {
            if (((int)(num & rdb)) != 0) {
                r1 ^= num;
            }
        }

        return {r1, r ^ r1};
    }
};