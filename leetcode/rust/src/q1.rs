use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut cache: HashMap<i32, usize> = HashMap::new();

        for i in 0..nums.len() {
            let complement = target - nums[i];
            if let Some(pos) = cache.get(&complement) {
                return vec![i as i32, *pos as i32];
            }
            cache.insert(nums[i], i);
        }
        panic!("Sould not be here!");

    }
}
