#include "cppincludes.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == key) {
                return nullptr;
            } else {
                return root;
            }
        }

        if (root->val != key) {
            bool left = root->val > key;
            TreeNode *ret = deleteNode(left ? root->left : root->right, key);
            if (ret == nullptr) {
                if (left) {
                    root->left = nullptr;
                } else {
                    root->right = nullptr;
                }
            }
            return root;
        }

        if (root->left != nullptr) {
            // move the rightmost val in the left tree to the value
            // and delete the rightmost val

            // find the rightmost element
            TreeNode *elem = root->left, *ans = nullptr;
            while (elem->right != nullptr) {
                ans = elem;
                elem = elem->right;
            }

            // swap the value and delete the val
            root->val = elem->val;
            if (ans != nullptr) {
                ans->right = elem->left;
            } else {
                root->left = elem->left;
            }

        } else {
            // move the leftmost val in the right tree to the root
            // and delete the leftmost val
            TreeNode *elem = root->right, *ans = nullptr;
            while (elem->left != nullptr) {
                ans = elem;
                elem = elem->left;
            }

            // swap the value and delete the val
            root->val = elem->val;
            if (ans != nullptr) {
                ans->left = elem->right;
            } else {
                root->right = elem->right;
            }
        }
        return root;
    }
};