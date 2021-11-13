#include "cppincludes.h"

string to_key(vector<int> *num1, vector<int> *num2) {
    string s;
    for (int i : *num1) {
        s += i + '0';
        s += ",";
    }

    for (int i : *num2) {
        s += i + '0';
        s += ",";
    }

    return s;
}

int sum(vector<int> &nums) {
    int r = 0;
    for (int i : nums) {
        r += i;
    }
    return r;
}

class Solution {

    unordered_map<string, int> dp;

  public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int sum1 = sum(nums1), sum2 = sum(nums2);
        cout << sum1 << " " << sum2 << endl;

        // ensure nums1 < nums2
        vector<int> *smaller, *bigger;
        if (sum1 > sum2) {
            smaller = &nums2;
            bigger = &nums1;
        } else {
            smaller = &nums1;
            bigger = &nums2;
        }

        string &&key = to_key(smaller, bigger);

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        if (nums1.size() * 6 < nums2.size() ||
            nums2.size() * 6 < nums1.size()) {
            return dp[key] = -1;
        }

        if (sum1 == sum2) {
            return dp[key] = 0;
        }

        int ans = INT_MAX;

        int diff = sum2 - sum1;

        // decrease
        int max_in_nums = bigger[bigger.size() - 1];

        if (max_in_nums - 1 >= diff) {
            cout << "bigger[" << bigger.size() - 1 << "] = " << max_in_nums - diff
                 << endl;
            ans = 1;
        } else {
            cout << "bigger[" << bigger.size() - 1 << "] = " << 1 << endl;
            bigger[bigger.size() - 1] = 1;
            int ret = minOperations(nums1, bigger);
            if (ret != -1) {
                ans = min(ans, 1 + ret);
            }
            bigger[bigger.size() - 1] = max_in_nums;
        }

        if (ans != 1) {
            int min_in_nums = nums1[nums1.size() - 1];

            if (6 - min_in_nums >= diff) {
                cout << "nums1[" << nums1.size() - 1 << "] = " << 6 - diff
                     << endl;
                ans = 1;
            } else {
                cout << "nums1[" << bigger.size() - 1 << "] = " << 6 << endl;
                nums1[nums1.size() - 1] = 6;
                int ret = minOperations(nums1, bigger);
                if (ret != -1) {
                    ans = min(ans, 1 + ret);
                }
                nums1[nums1.size() - 1] = min_in_nums;
            }
        }
        cout << endl;

        return ans == INT_MAX ? -1 : (dp[key] = ans);
    }
};

int main() {
    vector<int> nums1{6, 6};
    vector<int> bigger{1};

    cout << endl;
    cout << Solution().minOperations(nums1, nums2) << endl;
}