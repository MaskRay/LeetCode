// IPO
impl Solution {
    pub fn find_maximized_capital(k: i32, mut w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
        use std::collections::BinaryHeap;
        let mut h = BinaryHeap::new();
        let mut a: Vec<(i32,i32)> = (0..profits.len()).map(|i| (capital[i], profits[i])).collect();
        a.sort_unstable();
        let mut i = 0;
        for _ in 0..k {
            while i < a.len() && a[i].0 <= w {
                h.push(a[i].1);
                i += 1;
            }
            if let Some(t) = h.pop() { w += t; }
            else { break; }
        }
        w
    }
}
