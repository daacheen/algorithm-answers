#include "cppincludes.h"

const int EMPTY = 0;
const int FRESH = 1;
const int ROTTEN = 2;
const int JUST_ROTTEN = 3;

class Solution {

    int fresh_count = 0;

    int elapse(vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();

        int rot_count = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != FRESH) {
                    continue;
                }
                if ((i > 0 && grid[i - 1][j] == ROTTEN) ||
                    (i < row - 1 && grid[i + 1][j] == ROTTEN) ||
                    (j > 0 && grid[i][j - 1] == ROTTEN) ||
                    (j < col - 1 && grid[i][j + 1] == ROTTEN)) {
                    grid[i][j] = JUST_ROTTEN;
                    rot_count++;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == JUST_ROTTEN) {
                    grid[i][j] = ROTTEN;
                }
            }
        }

        return rot_count;
    }

  public:
    int orangesRotting(vector<vector<int>> &grid) {
        for (auto &&row : grid) {
            for (auto &&cell : row) {
                if (cell == FRESH) {
                    fresh_count++;
                }
            }
        }

        if (fresh_count == 0) {
            return 0;
        }

        int day = 0;
        while (true) {
            int rot_count = elapse(grid);
            fresh_count -= rot_count;
            if (rot_count == 0) {
                if (fresh_count == 0) {
                    return day;
                } else {
                    return -1;
                }
            }
            day++;
        }
    }
};