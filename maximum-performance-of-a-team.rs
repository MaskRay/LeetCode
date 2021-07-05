// Maximum Performance of a Team
impl Solution {
    pub fn max_performance(n: i32, speed: Vec<i32>, efficiency: Vec<i32>, k: i32) -> i32 {
        use std::{cmp::Reverse,collections::BinaryHeap};
        let mut h: BinaryHeap<Reverse<i32>> = BinaryHeap::new();
        let mut a = efficiency.into_iter().zip(speed).collect::<Vec<(i32,i32)>>();
        a.sort_unstable_by_key(|x| Reverse(x.0));
        let mut sum = 0;
        let mut ans = 0;
        for (e, s) in a.into_iter() {
            if h.len() == k as usize { sum -= h.pop().unwrap().0 as i64; }
            sum += s as i64;
            h.push(Reverse(s));
            ans = ans.max(e as i64 * sum)
        }
        (ans % 1000000007) as i32
    }
}
