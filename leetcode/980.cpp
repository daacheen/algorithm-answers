#include "cppincludes.h"

const int TAKEN = 3;

class Solution {

    int stepsRequired = 1;

    int xLength, yLength;

    bool stepable(int i) { return i == 0 || i == 2; }

  public:
    void search(vector<vector<int>> &grid, int x, int y, int steps,
                int &result) {
        if (grid[x][y] == 2 + TAKEN) {
            if (steps == stepsRequired) {
                result++;
            }
            return;
        }

        // find the next step
        int ways = 0;
        if (x < xLength - 1 && stepable(grid[x + 1][y])) {
            grid[x + 1][y] += TAKEN;
            search(grid, x + 1, y, steps + 1, result);
            grid[x + 1][y] -= TAKEN;
        }

        if (x > 0 && stepable(grid[x - 1][y])) {
            grid[x - 1][y] += TAKEN;
            search(grid, x - 1, y, steps + 1, result);
            grid[x - 1][y] -= TAKEN;
        }

        if (y < yLength - 1 && stepable(grid[x][y + 1])) {
            grid[x][y + 1] += TAKEN;
            search(grid, x, y + 1, steps + 1, result);
            grid[x][y + 1] -= TAKEN;
        }

        if (y > 0 && stepable(grid[x][y - 1])) {
            grid[x][y - 1] += TAKEN;
            search(grid, x, y - 1, steps + 1, result);
            grid[x][y - 1] -= TAKEN;
        }
    }

    int uniquePathsIII(vector<vector<int>> &grid) {

        xLength = grid.size();
        yLength = grid[0].size();

        pair<int, int> start;

        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == 1) {
                    start.first = x;
                    start.second = y;
                } else if (grid[x][y] == 0) {
                    stepsRequired++;
                }
            }
        }
        int result = 0;
        search(grid, start.first, start.second, 0, result);
        return result;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};

    cout << Solution().uniquePathsIII(grid) << endl;
}