#include "cppincludes.h"

class Solution {
  public:
    string multiplyDigit(string &num1, char digit, int bit) {
        string result;
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {
            char d = num1[i];
            int r = (d - '0') * (digit - '0') + carry;
            carry = r / 10;
            result += ((int)r % 10) + '0';
        }

        if (carry > 0) {
            result += carry + '0';
        }

        reverse(result.begin(), result.end());
        for (int i = 0; i < bit; i++) {
            result += '0';
        }
        return result;
    }

    string stringAdd(string &str1, string &str2) {
        string result;
        int carry = 0;

        int len = max(str1.size(), str2.size());
        for (int i = 0; i < len; i++) {
            int d1 = (int)str1.size() - 1 - i >= 0
                         ? (str1[str1.size() - 1 - i] - '0')
                         : 0;

            int d2 = (int)str2.size() - 1 - i >= 0
                         ? (str2[str2.size() - 1 - i] - '0')
                         : 0;

            int r = d1 + d2 + carry;

            carry = r / 10;
            result += (r % 10) + '0';
        }

        if (carry > 0) {
            result += carry + '0';
        }

        reverse(result.begin(), result.end());

        return result;
    }

    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int bit = 0;
        string r("0");
        for (int i = num2.size() - 1; i >= 0; i--) {
            string &&mr = multiplyDigit(num1, num2[i], bit);
            r = stringAdd(r, mr);

            bit++;
        }

        return r;
    }
};
