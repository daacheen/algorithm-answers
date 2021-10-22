#include "cppincludes.h"

class Solution {
  public:
    string frequencySort(string s) {
        unordered_map<char, int> occurrence;

        for (char c : s) {
            if (occurrence.find(c) == occurrence.end()) {
                occurrence[c] = 1;
            } else {
                occurrence[c] += 1;
            }
        }

        // get all occurrences into a vector
        vector<pair<char, int>> vec(occurrence.begin(), occurrence.end());

        // sort according to value
        sort(vec.begin(), vec.end(), [](auto &&left, auto &&right) {
            return left.second > right.second;
        });

        // build the result
        string r;

        for (auto &&item : vec) {
            for (int i = 0; i < item.second; i++) {
                r += item.first;
            }
        }

        return r;
    }
};