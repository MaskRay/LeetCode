impl Solution {
    pub fn max_envelopes(mut envelopes: Vec<Vec<i32>>) -> i32 {
        use std::cmp::Ordering::{Less,Greater};
        envelopes.sort_unstable_by_key(|e| (e[0], -e[1]));
        let mut a = vec![];
        for x in envelopes.into_iter() {
            let i = a.binary_search_by(|&y| if y < x[1] { Less } else { Greater }).unwrap_or_else(|i| i);
            if i < a.len() {
                a[i] = x[1];
            } else {
                a.push(x[1]);
            }
        }
        a.len() as i32
    }
}
