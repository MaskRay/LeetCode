// Graph Connectivity With Threshold
impl Solution {
    pub fn are_connected(n: i32, threshold: i32, queries: Vec<Vec<i32>>) -> Vec<bool> {
        fn find(uf: &mut Vec<i32>, mut x: i32) -> i32 {
            let mut r = x;
            while uf[r as usize] != r { r = uf[r as usize]; }
            while x != r {
                let y = uf[x as usize];
                uf[x as usize] = r;
                x = y;
            }
            r
        }
        let mut uf = (0..=n).collect::<Vec<i32>>();
        for d in threshold+1..=n/2 {
            for i in (d*2..=n).step_by(d as usize) {
                let x = find(&mut uf, d);
                let y = find(&mut uf, i);
                if x != y { uf[y as usize] = x; }
            }
        }
        queries.into_iter().map(|q| {find(&mut uf, q[0]) == find(&mut uf, q[1])}).collect::<Vec<_>>()
    }
}
