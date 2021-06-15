
// NOT COMPLETED
#include "cppincludes.h"

class Solution {

    unordered_set<string> visited;
    int result = 0;

  public:
    int numTilePossibilities(string tiles) {
        // sort the tiles
        sort(tiles.begin(), tiles.end());

        string base = "";

        calc(base, tiles);

        return result;
    }

    void calc(string &base, string &rest) {
        if (rest.length() == 0) {
            return;
        }

        // select each difference chars in the rest
        int i = 0;
        while (i < rest.length()) {
            char c = rest[i];
            string newRest = rest;
            newRest.erase(rest.begin() + i);
            // insert the char into each position in the base
            for (int j = 0; j < base.size(); i++) {
                string newString = base;
                newString.insert(newString.begin() + j, c);
                if (visited.find(newString) == visited.end()) {
                    // if not visited, rec
                    visited.insert(newString);
                    result++;
                    calc(newString, newRest);
                }
            }

            // iterate i to the next unique char
            while (i < rest.length() && rest[++i] == c) {
            }
        }
    }
};