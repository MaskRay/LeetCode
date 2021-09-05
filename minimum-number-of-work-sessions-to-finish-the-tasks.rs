// Minimum Number of Work Sessions to Finish the Tasks
impl Solution {
    pub fn min_sessions(tasks: Vec<i32>, session_time: i32) -> i32 {
        let n = tasks.len();
        let m = 1 << n;
        let mut dp = vec![n as i32; m];
        for i in 1..m {
            let mut s = 0;
            for j in 0..n { if (i >> j & 1) != 0 { s += tasks[j]; }}
            if s <= session_time {
                dp[i] = 1;
            } else {
                let mut j = i-1;
                while j > 0 {
                    dp[i] = dp[i].min(dp[i-j]+dp[j]);
                    j = j-1 & i;
                }
            }
        }
        dp[m-1]
    }
}
