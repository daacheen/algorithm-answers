#include "cppincludes.h"

class Solution {
  public:
    // 0 1 2 5 6 6
    //
    // size = 6
    // index = 4
    int hIndex(vector<int> &citations) {

        if (citations.size() == 0) {
            return 0;
        }

        // sort
        sort(citations.begin(), citations.end());

        // try each one
        int h, index = citations.size() - 1;
        for (h = citations[index]; h >= 0; h--) {
            while (index >= 1 && h == citations[index - 1]) {
                index--;
            }
            if (h <= citations.size() - index) {
                break;
            }
        }
        return h;
    }
};