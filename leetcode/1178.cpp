#include "cppincludes.h"

int string_to_int(string &s) {
    int i = 0;
    for (char c : s) {
        i |= 1 << (c - 'a');
    }
    return i;
}

// TLE
// 看了答案的，循环puzzle的所有可能解，在map里看有没有就行，不需要遍历word一个一个看
class Solution {
  public:
    vector<int> findNumOfValidWords(vector<string> &words,
                                    vector<string> &puzzles) {
        vector<int> result(puzzles.size(), 0);

        unordered_map<int, int> wordCount;

        for (int i = 0; i < words.size(); i++) {
            int bits = string_to_int(words[i]);
            if (wordCount.find(bits) == wordCount.end()) {
                wordCount[bits] = 1;
            } else {
                wordCount[bits]++;
            }
        }

        for (int i = 0; i < puzzles.size(); i++) {
            // convert puzzles to ints

            int first = 1 << (puzzles[i][0] - 'a');

            result[i] = wordCount[first];

            string rest = puzzles[i].substr(1);

            int puzzleInt = string_to_int(rest);

            for (int submask = puzzleInt; submask;
                 submask = (submask - 1) & puzzleInt) {
                result[i] += wordCount[submask | first]; // add first character
            }
        }

        return result;
    }
};
