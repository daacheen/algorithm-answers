#![allow(dead_code)]
mod q1;
mod q2;
mod q3;
mod q5;
mod utils;

use utils::Solution;

fn main() {
    // Solution::length_of_longest_substring(String::from("abcabcbb"));
    Solution::longest_palindrome("babad".to_string());
}
