#include "cppincludes.h"

class CombinationIterator {

    string characters;
    int minMask = 0;
    int combinationLength;
    bool nextPrepared = false;
    int mask;

  public:
    CombinationIterator(string characters, int combinationLength)
        : characters(characters), combinationLength(combinationLength) {

        minMask = (int)(pow(2, combinationLength)) - 1;
        mask = (int)(pow(2, characters.size())) - 1;

        hasNext();
    }

    string next() {
        if (!nextPrepared) {
            hasNext();
        }

        nextPrepared = false;

        string r;
        for (int i = 0; i < characters.size(); i++) {
            if (((int)(mask & (1 << (characters.size() - 1 - i)))) != 0) {
                r += characters[i];
            }
        }

        mask--;

        return r;
    }

    int count1(int n) {
        int r = 0;
        while (n > 0) {
            r += n % 2;
            n /= 2;
        }
        return r;
    }

    bool hasNext() {
        // mask-- until the number of 1 matches requirement
        while (mask >= minMask && count1(mask) != combinationLength) {
            mask--;
        }

        if (mask >= minMask) {
            nextPrepared = true;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */