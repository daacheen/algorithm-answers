#include "cppincludes.h"

class Solution {
  public:
    vector<int> numberOfLines(vector<int> &widths, string s) {
        int line = 1, curr = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (100 - curr >= w) {
                curr += w;
            } else {
                line += 1;
                curr = w;
            }
        }
        return {line, curr};
    }
};