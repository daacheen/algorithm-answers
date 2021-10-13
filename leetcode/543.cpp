#include "cppincludes.h"

int dfs(TreeNode *root, int &ans) {
    if (root == nullptr) {
        return 0;
    }
    int left = dfs(root->left, ans);
    int right = dfs(root->right, ans);

    ans = max(ans, left + right);
    return 1 + max(left, right);
}

class Solution {
  public:
    int diameterOfBinaryTree(TreeNode *root) {
        int ans = INT_MIN;

        dfs(root, ans);
        return ans;
    }
};