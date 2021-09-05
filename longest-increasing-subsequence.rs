impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        use std::cmp::Ordering::{Less,Greater};
        let mut a = vec![];
        for x in nums.into_iter() {
            let i = a.binary_search_by(|&y| if y < x { Less } else { Greater }).unwrap_or_else(|i| i);
            if i < a.len() {
                a[i] = x;
            } else {
                a.push(x);
            }
        }
        a.len() as i32
    }
}
