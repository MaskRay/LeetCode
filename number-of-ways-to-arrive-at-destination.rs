// Number of Ways to Arrive at Destination
impl Solution {
    pub fn count_paths(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut d = vec![vec![std::i64::MAX/2; n]; n];
        let mut c = vec![vec![1i64; n]; n];
        for road in roads.into_iter() {
            let u = road[0] as usize;
            let v = road[1] as usize;
            d[u][v] = road[2] as i64;
            d[v][u] = road[2] as i64;
            c[u][v] = 1;
            c[v][u] = 1;
        }
        for k in 0..n {
            for i in 0..n {
                for j in 0..n {
                    let d1 = d[i][k]+d[k][j];
                    if d1 < d[i][j] { d[i][j] = d1; c[i][j] = 0; }
                    if d1 == d[i][j] { c[i][j] = (c[i][j]+c[i][k]*c[k][j]) % 1000000007; }
                }
            }
        }
        c[0][n-1] as i32
    }
}
