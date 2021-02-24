#include "cppincludes.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    void swapValues(ListNode *node1, ListNode *node2) {
        int val1 = node1->val;
        node1->val = node2->val;
        node2->val = val1;
    }

    void deleteNode(ListNode *node) {
        // swap the values of neighboring nodes consecutively
        ListNode *nextNode = node->next;

        while (nextNode->next != nullptr) {
            swapValues(node, nextNode);
            node = nextNode;
            nextNode = node->next;
        }

        // swap one more time
        swapValues(node, nextNode);

        // destroy the link to the last node
        node->next = nullptr;
    }
};