#include "cppincludes.h"

// t for taken, n for not taken
const char TAKEN = 't';
const char NOT_TAKEN = 'n';

class Solution {

    // char_taken + arr_taken
    unordered_set<string> dp;
    unordered_set<int> ignored;

  public:
    int maxLength(vector<string> &arr) {
        int result = 0;

        string char_taken(26, NOT_TAKEN);
        string arr_taken(arr.size(), NOT_TAKEN);

        // cout << char_taken << " " << arr_taken << endl;

        // filter strs with repeated char already
        for (int i = 0; i < arr.size(); i++) {
            string &str = arr[i];
            string present(26, NOT_TAKEN);
            for (char c : str) {
                if (present[c - 'a'] == TAKEN) {
                    ignored.insert(i);
                    break;
                }
                present[c - 'a'] = TAKEN;
            }
        }

        for (int i : ignored) {
            cout << i << " ";
        }
        cout << endl;

        search(arr, 0, char_taken, arr_taken, result);

        return result;
    }

    void search(vector<string> &arr, int start, string &char_taken,
                string &arr_taken, int &result) {
        string key = char_taken + arr_taken;
        if (dp.find(key) != dp.end()) {
            return;
        }

        dp.insert(key);

        // search
        for (int i = start; i < arr.size(); i++) {
            // ignore if necessary
            if (ignored.find(i) != ignored.end()) {
                continue;
            }

            // try take i
            bool can = true;
            for (char c : arr[i]) {
                if (char_taken[c - 'a'] == TAKEN) {
                    can = false;
                    break;
                }
            }

            if (!can) {
                continue;
            }

            // take the i
            arr_taken[i] = TAKEN;
            for (char c : arr[i]) {
                char_taken[c - 'a'] = TAKEN;
            }

            // calculate result
            int ans = 0;
            for (char c : char_taken) {
                if (c == TAKEN) {
                    ans++;
                }
            }
            result = max(result, ans);

            // cout << result << " ";
            // print_str(arr, arr_taken);
            // cout << endl;

            // search from next
            search(arr, i + 1, char_taken, arr_taken, result);

            // reset the i
            arr_taken[i] = NOT_TAKEN;
            for (char c : arr[i]) {
                char_taken[c - 'a'] = NOT_TAKEN;
            }
        }
    };
};

int main() {
    // vector<string> input = {"ab", "ba", "cd", "dc", "ef", "fe", "gh", "hg",
    //                         "ij", "ji", "kl", "lk", "mn", "nm", "op", "po"};

    vector<string> input = {"cha", "r", "act", "ers"};
    // vector<string> input = {"yy", "bkhwmpbiisbldzknpm"};
    cout << Solution().maxLength(input);
}