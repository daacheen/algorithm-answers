use crate::utils::Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        
        if s.len() < 1 {
            return "".to_string();
        }

        let vec: Vec<char> = s.chars().collect();

        let (mut ans_l, mut ans_r) = (0, 0);

        for p in 0..vec.len() {
            // s[p] as pivot
            let len1 = Solution::extend(&vec, p as i32, p);
            let len2 = Solution::extend(&vec, p as i32, p + 1);
            let len = std::cmp::max(len1, len2);
            if len > ans_r - ans_l {
                ans_l = p - (len - 1) / 2;
                ans_r = p + len / 2;
            }
        }

        s[ans_l..ans_r + 1].to_string()
    }

    fn extend(s: &Vec<char>, mut left: i32, mut right: usize) -> usize {
        while left >= 0 && right < s.len() && s[left as usize] == s[right] {
            left -= 1;
            right += 1;
        }
        right - left as usize - 1
    }
}
