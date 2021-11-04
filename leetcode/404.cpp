#include "cppincludes.h"

class Solution {
  public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr) {
            return sumOfLeftLeaves(root->right);
        }
        int r = 0;
        if (root->left->left == nullptr && root->left->right == nullptr) {
            r = root->left->val;
        }
        return r + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};