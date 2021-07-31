// Maximum Number of Points with Cost
impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i64 {
        let n = points[0].len();
        let mut f = vec![0i64; n];
        let mut g = vec![0i64; n];
        for a in points.iter() {
            let mut mx = std::i64::MIN;
            for i in 0..n {
                mx = mx.max(f[i]+i as i64);
                g[i] = mx+a[i] as i64-i as i64;
            }
            mx = std::i64::MIN;
            for i in (0..n).rev() {
                mx = mx.max(f[i]-i as i64);
                g[i] = g[i].max(mx+a[i] as i64+i as i64);
            }
            f.clone_from_slice(&g);
        }
        f.iter().fold(0, |acc,v| acc.max(*v))
    }
}
