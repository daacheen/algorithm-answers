use crate::utils::Solution;
use std::cmp::max;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        if s.len() <= 1 {
            return s.len() as i32;
        }

        let s: Vec<char> = s.chars().collect();

        let mut map: [i32; 128] = [-1; 128];
        map[s[0] as usize] = 0;
        let mut begin: usize = 0;
        let mut end = 0;
        let mut ans: usize = 0;

        loop {
            end += 1;
            if end == s.len() {
                break;
            }
            if map[s[end] as usize] != -1 {
                for i in begin..map[s[end] as usize] as usize {
                    map[s[i] as usize] = -1;
                }
                begin = map[s[end] as usize] as usize + 1;
            }
            map[s[end] as usize] = end as i32;
            ans = max(ans, end - begin + 1);
        }

        ans as i32
    }
}
