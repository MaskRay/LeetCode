// Strange Printer
impl Solution {
    pub fn strange_printer(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut dp = vec![vec![0; n]; n];
        for i in (0..n).rev() {
            dp[i][i] = 1;
            for j in (i+1)..n {
                dp[i][j] = dp[i][j-1]+1;
                for k in i..j {
                    if s[k] == s[j] {
                        dp[i][j] = dp[i][j].min(dp[i][k] + if k+1 <= j-1 {dp[k+1][j-1]} else {0});
                    }}}}
        dp[0][n-1]
    }
}
