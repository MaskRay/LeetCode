// Find the Kth Smallest Sum of a Matrix With Sorted Rows
impl Solution {
    pub fn kth_smallest(mat: Vec<Vec<i32>>, k: i32) -> i32 {
        use std::collections::BinaryHeap;
        let mut h = BinaryHeap::new();
        h.push(0);
        for a in mat.into_iter() {
            let mut h1 = BinaryHeap::new();
            for x in h.iter() {
                for y in a.iter() {
                    h1.push(x+y);
                    if h1.len() > k as usize { h1.pop(); }
                }
            }
            h = h1;
        }
        *h.peek().unwrap()
    }
}
