// Minimum Cost to Reach Destination in Time
impl Solution {
    pub fn min_cost(max_time: i32, edges: Vec<Vec<i32>>, passing_fees: Vec<i32>) -> i32 {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;
        let n = passing_fees.len();
        let mut g = vec![vec![]; n];
        for e in edges.into_iter() {
            g[e[0] as usize].push((e[1], e[2]));
            g[e[1] as usize].push((e[0], e[2]));
        }
        let mut dist = vec![max_time+1; n];
        let mut h: BinaryHeap<Reverse<(i32, i32, i32)>> = BinaryHeap::from(vec![Reverse((passing_fees[0], 0, 0))]);
        while let Some(Reverse((fee, c, t))) = h.pop() {
            let c = c as usize;
            if dist[c] <= t { continue; }
            dist[c] = t;
            if c == n-1 { return fee; }
            for &e in g[c].iter() {
                if t+e.1 < dist[e.0 as usize] {
                    h.push(Reverse((fee+passing_fees[e.0 as usize], e.0, t+e.1)));
                }
            }
        }
        -1
    }
}
