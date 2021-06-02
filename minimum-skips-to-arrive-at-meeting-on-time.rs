// Minimum Skips to Arrive at Meeting On Time
impl Solution {
    pub fn min_skips(dist: Vec<i32>, speed: i32, hours_before: i32) -> i32 {
        let n = dist.len();
        let speed = speed as i64;
        let mx = hours_before as i64 * speed + 1;
        let mut dp = vec![vec![mx; n+1]; 2];
        dp[0][0] = 0;
        for i in 0..n {
            let d = dist[i] as i64;
            let i0 = i&1;
            for j in 0..=i+1 { dp[i0^1][j] = mx; }
            for j in 0..=i {
                dp[i0^1][j] = dp[i0^1][j].min((dp[i0][j]+speed-1)/speed*speed + d);
                dp[i0^1][j+1] = dp[i0^1][j+1].min(dp[i0][j] + d);
            }
        }
        if let Some(j) = dp[n&1].iter().position(|&v| v <= speed * hours_before as i64) {
            return j as i32;
        }
        -1
    }
}
