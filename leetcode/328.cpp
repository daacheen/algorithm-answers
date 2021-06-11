#include "cppincludes.h"

class Solution {
  public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->next == nullptr) {
            return head;
        }

        ListNode *oddHead = head, *evenHead = head->next;
        ListNode *firstEven = head->next;

        while (true) {
            bool evenMore = evenHead->next != nullptr;
            if (evenMore) {
                oddHead->next = evenHead->next;
                oddHead = oddHead->next;
            } else {
                oddHead->next = nullptr;
            }
            if (oddHead->next != nullptr) {
                evenHead->next = oddHead->next;
                evenHead = evenHead->next;
            } else {
                evenHead->next = nullptr;
                // no more next node for odd and even indices
                if (!evenMore) {
                    break;
                }
            }
        }

        oddHead->next = firstEven;

        return head;
    }
};