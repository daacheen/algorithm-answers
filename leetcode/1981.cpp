#include "cppincludes.h"

class Solution {

    // returns min diff value
    // memo is rowline, sum to diff value
    int select(vector<vector<int>> &mat, int row, int target, int sum,
               vector<vector<int>> &memo) {

        if (row == mat.size()) {
            return abs(sum - target);
        }

        if (memo[row][sum] != 0) {
            return memo[row][sum];
        }

        int result = INT_MAX;
        bool is_last_bigger = false;
        for (int i = 0; i < mat[row].size(); i++) {
            int s = sum + mat[row][i];
            // if current sum > target, no need to proceed to next item
            // since all rows are ordered
            if (s > target) {
                if (is_last_bigger) {
                    break;
                } else {
                    is_last_bigger = true;
                }
            }
            int diff = select(mat, row + 1, target, s, memo);
            result = min(result, abs(diff));
        }

        return memo[row][sum] = result;
    }

  public:
    int minimizeTheDifference(vector<vector<int>> &mat, int target) {
        // sort every row
        for (int i = 0; i < mat.size(); i++) {
            sort(mat[i].begin(), mat[i].end());
        }

        // initialize the memo
        vector<vector<int>> memo(mat.size(), vector<int>(5000, -1));

        return select(mat, 0, target, 0, memo);
    }
};