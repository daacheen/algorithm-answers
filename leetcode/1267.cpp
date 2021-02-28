#include "cppincludes.h"

/*

0 0 1 0 1
0 1 0 1 0
0 1 1 1 0
1 0 0 1 1
0 0 1 1 0

*/

class Solution {
  public:
    int flood(vector<vector<int>> &grid, int x, int y, bool start) {
        if (grid[x][y] == 0) {
            return 0;
        }

        int result = 1;

        // change the grid to -1
        grid[x][y] = -1;

        // on the same row
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][y] == 1) {
                result += flood(grid, i, y, false);
            }
        }

        // on the same column
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[x][i] == 1) {
                result += flood(grid, x, i, false);
            }
        }

        return (start && result == 1) ? 0 : result;
    }

    int countServers(vector<vector<int>> &grid) {
        // find the first server
        int result = 0;

        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    result += flood(grid, i, j, true);
                }
            }
        }

        return result;
    }
};
