#include "cppincludes.h"

/*

4x + 2y = a
x + y = b

x = (a-2b)/2
y = 2b-a/2

*/

class Solution {
  public:
    vector<int> numOfBurgers(int a, int b) {
        if (a - 2 * b < 0 || (a - 2 * b) % 2 == 1) {
            return {};
        }
        int x = (a - 2 * b) / 2;

        if (a % 2 == 1) {
            return {};
        }
        int y = 2 * b - a / 2;
        if (y < 0) {
            return {};
        }

        return {x, y};
    }
};