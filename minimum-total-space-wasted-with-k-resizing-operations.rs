// Minimum Total Space Wasted With K Resizing Operations
impl Solution {
    pub fn min_space_wasted_k_resizing(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut dp = vec![vec![0; n+1]; 2];
        let mut mx = 0;
        let mut sum = 0;
        for i in 0..n {
            mx = mx.max(nums[i]);
            sum += nums[i];
            dp[0][i] = mx*(i as i32+1)-sum;
        }
        for kk in 0..k as usize {
            for i in 0..n {
                dp[kk+1&1][i] = dp[kk&1][i];
            }
            for i in 0..n {
                mx = 0;
                sum = 0;
                for j in i+1..n {
                    mx = mx.max(nums[j]);
                    sum += nums[j];
                    dp[kk+1&1][j] = dp[kk+1&1][j].min(dp[kk&1][i]+mx*(j-i) as i32-sum);
                }
            }
        }
        dp[k as usize&1][n-1]
    }
}
