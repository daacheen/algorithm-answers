#include "cppincludes.h"

class Solution {
  public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *lead = list1;
        for (int i = 0; i < a - 1; i++) {
            lead = lead->next;
        }
        ListNode *orig = lead->next;
        lead->next = list2;
        for (int i = 0; i < b - a + 1; i++) {
            orig = orig->next;
        }

        // get tail of list2
        ListNode *tail = list2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = orig;

        return list1;
    }
};
