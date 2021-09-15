#include "cppincludes.h"

class Solution {
  public:
    bool is_ascii(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    string reverseOnlyLetters(string s) {
        vector<int> positions;
        vector<char> chars;

        string asciiStr;

        for (int i = 0; i < s.size(); i++) {
            if (!is_ascii(s[i])) {
                positions.push_back(i);
                chars.push_back(s[i]);
            } else {
                asciiStr.push_back(s[i]);
            }
        }

        reverse(asciiStr.begin(), asciiStr.end());

        // insert the chars back
        for (int i = 0; i < positions.size(); i++) {
            int p = positions[i];
            char c = chars[i];
            asciiStr.insert(asciiStr.begin() + p, c);
        }

        return asciiStr;
    }
};
