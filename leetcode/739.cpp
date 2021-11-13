#include "cppincludes.h"

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<vector<int>> memo(100 - 30 + 1);
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            memo[temp - 30].push_back(i);
            // find cooler temperatures
            for (int j = 0; j < temp - 30; j++) {
                for (int index : memo[j]) {
                    result[index] = i - index;
                }
                memo[j].clear();
            }
        }

        return result;
    }
};