impl Solution {
    pub fn max_sum_after_partitioning(arr: Vec<i32>, k: i32) -> i32 {
        let n = arr.len();
        let mut dp = vec![0; n+1];
        for i in 0..n {
            let mut mx = 0;
            for j in ((if i < k as usize {0} else {i+1-k as usize})..=i).rev() {
                mx = mx.max(arr[j]);
                dp[i+1] = dp[i+1].max(dp[j]+mx*(i-j+1) as i32);
            }
        }
        dp[n]
    }
}
