#include "cppincludes.h"

class Solution {
  public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int emptyBottles = numBottles;
        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            result += newBottles;
            emptyBottles %= numExchange;
            emptyBottles += newBottles;
        }

        return result;
    }
};