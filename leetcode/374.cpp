#include "cppincludes.h"

int guess(int num);

int avg(int a, int b) { return (a / 2) + (b / 2) + ((a % 2 + b % 2) / 2); }

class Solution {
  public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        int ans;
        while (true) {
            int num = avg(low, high);
            ans = guess(num);
            if (ans == 0) {
                return num;
            }

            if (ans == 1) {
                low = num + 1;
            }

            if (ans == -1) {
                high = num - 1;
            }
        }
    }
};
