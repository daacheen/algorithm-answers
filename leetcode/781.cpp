#include "cppincludes.h"

class Solution {
  public:
    int numRabbits(vector<int> &answers) {
        // count the number of each occurrence
        unordered_map<int, int> m;
        for (int i : answers) {
            if (m.find(i) != m.end()) {
                m[i]++;
            } else {
                m[i] = 1;
            }
        }

        int count = 0;
        for (auto &&entry : m) {
            // count the possible colors
            // if a color has n rabbits, at most (n-1) rabbits answers n-1
            // so, for each occurrence n, 
            // each (n+1) occurrence refers to a color

            // the followiing line counts the min number of colors that has been referred to 
            int colors = ceil((double)entry.second / (entry.first + 1));
            // and each color refers to (n+1) rabbits
            count += (entry.first + 1) * colors;
        }

        return count;
    }
};