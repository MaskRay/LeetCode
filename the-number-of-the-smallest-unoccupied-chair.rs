// The Number of the Smallest Unoccupied Chair
impl Solution {
    pub fn smallest_chair(mut times: Vec<Vec<i32>>, target_friend: i32) -> i32 {
        use std::cmp::Reverse;
        use std::collections::{BinaryHeap,BTreeSet};
        let start = times[target_friend as usize][0];
        times.sort_unstable_by_key(|t| t[0]);
        let mut used: BinaryHeap<Reverse<(i32, i32)>> = BinaryHeap::new();
        let mut free: BinaryHeap<Reverse<i32>> = BinaryHeap::new();
        let mut allo = 0;
        let mut sit = 0;
        for t in times.into_iter() {
            if start < t[0] { break; }
            while let Some(Reverse(x)) = used.peek() {
                if t[0] < x.0 { break; }
                free.push(Reverse(x.1));
                used.pop();
            }
            if let Some(Reverse(x)) = free.pop() {
                sit = x;
            } else {
                sit = allo;
                allo += 1;
            }
            used.push(Reverse((t[1], sit)));
        }
        sit
    }
}
