// Maximum Product of the Length of Two Palindromic Subsequences
impl Solution {
    pub fn max_product(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let m = 1 << n;
        let mut dp = vec![0; m];
        for i in 1..m {
            let mut a = vec![];
            for j in 0..n { if (i>>j & 1) != 0 { a.push(s[j]); }}
            if a.iter().eq(a.iter().rev()) { dp[i] = a.len(); }
        }
        let mut ans = 0;
        for i in 1..m {
            let mut j = i;
            while j > 0 {
                ans = ans.max(dp[m-1-i] * dp[j]);
                j = j-1 & i;
            }
        }
        ans as i32
    }
}
