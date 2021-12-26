#include "cppincludes.h"

int to_int(string &s) {
    int r = 0;
    int base = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        r += (s[i] - '0') * base;
        base *= 2;
    }
    return r;
}

string to_bin_str(int i, int size) {
    string r;
    while (size > 0) {
        int remainder = i % 2;
        r += remainder + '0';
        i /= 2;
        size--;
    }

    reverse(r.begin(), r.end());
    return r;
}

class Solution {
  public:
    string findDifferentBinaryString(vector<string> &nums) {

        int n = nums.size();

        int max_possible = 1 << n;

        unordered_set<int> all_possibilities;
        int min_val = INT_MAX;
        for (string &num : nums) {
            int val = to_int(num);
            min_val = min(min_val, val);
            all_possibilities.insert(val);
            cout << val << endl;
        }

        for (int r = min_val; r <= max_possible; r++) {
            if (all_possibilities.find(r) == all_possibilities.end()) {
                return to_bin_str(r, n);
            }
        }

        return "";
    }
};