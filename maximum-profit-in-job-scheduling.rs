// Maximum Profit in Job Scheduling
impl Solution {
    pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
        let n = start_time.len();
        let mut a = vec![(0,0,0); n];
        for i in 0..n { a[i] = (start_time[i], end_time[i], profit[i]); }
        a.sort_unstable_by_key(|x| x.1);
        let mut dp = vec![0; n];
        dp[0] = a[0].2;
        for i in 1..n {
            let mut l = 0;
            let mut h = i;
            while l < h {
                let m = l+h >> 1;
                if a[m].1 <= a[i].0 { l = m+1; }
                else { h = m; }
            }
            dp[i] = dp[i-1].max(a[i].2 + (if l > 0 {dp[l-1]} else {0}));
        }
        dp[n-1]
    }
}
