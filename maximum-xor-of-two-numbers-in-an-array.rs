impl Solution {
    pub fn find_maximum_xor(nums: Vec<i32>) -> i32 {
        use std::collections::HashSet;
        use std::iter::FromIterator;
        (0..32).rev().fold(0, |acc,i| {
            let m = acc | 1<<i;
            let s: HashSet<i32> = HashSet::from_iter(nums.iter().map(|x| x&m));
            if s.iter().any(|&x| s.contains(&(x^m))) {m} else {acc}
        })
    }
}
