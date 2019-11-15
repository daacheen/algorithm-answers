use crate::utils::ListNode;

struct Solution;

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut r = Box::new(ListNode::new(0));

        let re = r.clone();

        let mut carry = 0;

        let mut c1 = l1;
        let mut c2 = l2;

        loop {
            if c1.is_none() && c2.is_none() {
                break;
            }
            let mut result = carry;
            if let Some(n1) = c1.take() {
                result += n1.val;
                c1 = n1.next;
            }

            if let Some(n2) = c2.take() {
                result += n2.val;
                c2 = n2.next;
            }

            carry = result / 10;
            result %= 10;

            let next = Box::new(ListNode::new(result));
            r.next = Some(next.clone());
            r = next;
        }
        if carry == 1 {
            r.next = Some(Box::new(ListNode::new(1)));
        }

        return Some(re);
    }
}
