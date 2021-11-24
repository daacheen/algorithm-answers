#include "cppincludes.h"

#define MY

#ifdef MY
class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                             vector<vector<int>> &secondList) {
        vector<vector<int>> result;

        int fi = 0, si = 0;
        while (fi < firstList.size() && si < secondList.size()) {
            // skip no intersection zone
            while (fi < firstList.size() && si < secondList.size() &&
                   (firstList[fi][1] < secondList[si][0] ||
                    secondList[si][1] < firstList[fi][0])) {
                if (firstList[fi][1] < secondList[si][0]) {
                    fi++;
                } else {
                    si++;
                }
            }

            if (fi == firstList.size() || si == secondList.size()) {
                break;
            }

            if (firstList[fi][0] == secondList[si][0]) {
                if (firstList[fi][1] == secondList[si][1]) {
                    result.push_back({firstList[fi][0], firstList[fi][1]});
                    fi++;
                    si++;
                } else if (firstList[fi][1] < secondList[si][1]) {
                    result.push_back({firstList[fi][0], firstList[fi][1]});
                    secondList[si][0] = firstList[fi][1];
                    fi++;
                } else {
                    result.push_back({firstList[fi][0], secondList[si][1]});
                    firstList[fi][0] = secondList[si][1];
                    si++;
                }
            } else if (firstList[fi][0] < secondList[si][0]) {
                if (firstList[fi][1] == secondList[si][1]) {
                    result.push_back({secondList[si][0], firstList[fi][1]});
                    fi++;
                    si++;
                } else if (firstList[fi][1] < secondList[si][1]) {
                    result.push_back({secondList[si][0], firstList[fi][1]});
                    secondList[si][0] = firstList[fi][1];
                    fi++;
                } else {
                    result.push_back({secondList[si][0], secondList[si][1]});
                    firstList[fi][0] = secondList[si][1];
                    si++;
                }
            } else {
                if (firstList[fi][1] == secondList[si][1]) {
                    result.push_back({firstList[fi][0], firstList[fi][1]});
                    fi++;
                    si++;
                } else if (firstList[fi][1] < secondList[si][1]) {
                    result.push_back({firstList[fi][0], firstList[fi][1]});
                    secondList[si][0] = firstList[fi][1];
                    fi++;
                } else {
                    result.push_back({firstList[fi][0], secondList[si][1]});
                    firstList[fi][0] = secondList[si][1];
                    si++;
                }
            }
        }
        return result;
    }
};
#else
class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                             vector<vector<int>> &secondList) {
        vector<vector<int>> result;

        int fi = 0, si = 0;
        while (fi < firstList.size() && si < secondList.size()) {
            int lo = max(firstList[fi][0], secondList[si][0]);
            int hi = min(firstList[fi][1], secondList[si][1]);

            if (lo <= hi) {
                result.push_back({lo, hi});
            }

            if (firstList[fi][1] <= secondList[si][1]) {
                fi++;
            } else {
                si++;
            }
        }

        return result;
    }
};
#endif