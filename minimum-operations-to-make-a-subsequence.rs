// Minimum Operations to Make a Subsequence
impl Solution {
    pub fn min_operations(target: Vec<i32>, arr: Vec<i32>) -> i32 {
        use std::collections::BTreeMap;
        use std::cmp::Ordering::{Less,Greater};
        let mut mp = BTreeMap::new();
        let n = target.len();
        for (i,x) in target.into_iter().enumerate() {
            mp.insert(x, i);
        }
        let mut a = vec![];
        for v in arr.into_iter() {
            if let Some(x) = mp.get(&v) {
                let i = a.binary_search_by(|&y| if y < x { Less } else { Greater }).unwrap_or_else(|i| i);
                if i < a.len() {
                    a[i] = x;
                } else {
                    a.push(x);
                }
            }
        }
        (n-a.len()) as i32
    }
}
