#include "cppincludes.h"

class Solution {
  public:
    vector<int> processQueries(vector<int> &queries, int m) {
        vector<int> result(queries.size());

        vector<int> p(m);
        for (int i = 1; i <= m; i++) {
            p[i - 1] = i;
        }

        for (int j = 0; j < queries.size(); j++) {
            int q = queries[j];
            // find the index of q in p
            int i;
            for (i = 0; i < m; i++) {
                if (p[i] == q) {
                    break;
                }
            }

            // move p[i] to the beginning
            rotate(p.begin(), p.begin() + i, p.begin() + i + 1);
            result[j] = i;
        }

        return result;
    }
};