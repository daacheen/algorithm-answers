#include "cppincludes.h"

class Solution {
  public:
    // 判断x有没有可能是第k小的元素
    // 也就是看有多少比x小的元素
    // 这个算法是一行一行地看，
    // 如果当前行(i)的最后一个元素（i*n）都比x小，那么整行的元素都比x小，结果+=n（一行有n个元素）
    // 如果当前行的(i)的最后一个元素比x大或者等于，因为第i行两个元素之间的距离是i，第一个元素是i，那么整行会有x/i个元素比x小。
    bool enough(int x, int m, int n, int k) {
        int c = 0;
        for (int i = 1; i <= m; i++) {
            if (i * n < x) {
                c += n;
            } else {
                c += x / i;
            }
        }

        return c >= k;
    }

    int findKthNumber(int m, int n, int k) {
        // 直接背binary search的界了
        // low<high， 下限超过，搜索时下限=mid+1，上限不超过，搜索时上限=mid
        int low = 0, high = m * n;

        while (low < high) {
            // mid就是结果
            int mid = low + (high - low) / 2;

            if (enough(mid, m, n, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};