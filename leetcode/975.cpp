#include "cppincludes.h"

/*
[2,3,1,1,4]

[1,1,2,3,4]
[2,3,0,1,4]

jump_target_odd = [1, 4, 3, 4,-1]
jump_target_even = [2,2,3,-1,-1]

dp_odd = [0,0,0,0,1]
dp_even = [0,0,0,0,1]

dp_odd[i] = dp_even[jump_target_odd[i]]
dp_even[i] = dp_odd[jump_target_even[i]]

[0, 1, 0, 1, 1]
[0, 0, 1, 0, 1]

dp_even[1] = true
*/

class Solution {
  public:
    int oddEvenJumps(vector<int> &arr) {
        // calculate all jump targets
        int n = arr.size();
        vector<int> jump_odd(n, -1), jump_even(n, -1);

        // find jump targets for i
        // the following is O(n^2) TLE
        // for (int i = 0; i < n; i++) {
        //     int min_value = INT_MAX, min_index = -1;
        //     int max_value = INT_MIN, max_index = -1;
        //     for (int j = i + 1; j < n; j++) {
        //         if (arr[i] <= arr[j] && arr[j] < min_value) {
        //             min_value = arr[j];
        //             min_index = j;
        //         }
        //         if (arr[i] >= arr[j] && arr[j] > max_value) {
        //             max_value = arr[j];
        //             max_index = j;
        //         }
        //     }
        //     jump_odd[i] = min_index;
        //     jump_even[i] = max_index;
        // }

        // use stacks to find jump_targets
        // the following is incorrect
        stack<int> gs, ls;
        for (int i = n - 1; i >= 0; i--) {
            while (!gs.empty() && arr[gs.top()] < arr[i]) {
                gs.pop();
            }
            if (!gs.empty()) {
                jump_odd[i] = gs.top();
            }
            gs.push(i);

            while (!ls.empty() && arr[ls.top()] > arr[i]) {
                ls.pop();
            }
            if (!ls.empty()) {
                jump_even[i] = ls.top();
            }
            ls.push(i);
        }

        // dp
        int result = 1;
        vector<bool> dp_odd(n, false), dp_even(n, false);
        dp_odd[n - 1] = dp_even[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            if (jump_odd[i] != -1) {
                dp_odd[i] = dp_even[jump_odd[i]];
                if (dp_odd[i]) {
                    result++;
                }
            }
            if (jump_even[i] != -1) {
                dp_even[i] = dp_odd[jump_even[i]];
            }
        }

        return result;
    }
};
