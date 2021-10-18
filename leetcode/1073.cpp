#include "cppincludes.h"

class Solution {
  public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {

        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());

        vector<int> result;

        int len = max(arr1.size(), arr2.size());

        int step = 0;

        for (int i = 0; i < len || step != 0; i++) {

            int v1 = i < arr1.size() ? arr1[i] : 0;
            int v2 = i < arr2.size() ? arr2[i] : 0;

            int r = v1 + v2 - step;
            if (r >= 2) {
                step = 1;
                r -= 2;
            } else if (r == -1) {
                step = -1;
                r = 1;
            } else {
                step = 0;
            }

            cout << "v1 " << v1 << " v2 " << v2 << " r " << r << " step "
                 << step << endl;

            result.push_back(r);
        }

        // remove leading zero
        while (result.back() == 0 && result.size() > 1) {
            result.pop_back();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};