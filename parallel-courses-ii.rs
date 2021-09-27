// Parallel Courses II
impl Solution {
    pub fn min_number_of_semesters(n: i32, relations: Vec<Vec<i32>>, k: i32) -> i32 {
        let n = n as usize;
        let mut req = vec![0; n];
        for rel in relations.into_iter() {
            req[rel[1] as usize-1] |= 1 << rel[0] as usize-1;
        }
        let m = 1 << n;
        let mut dp = vec![n as i32; m];
        dp[0] = 0;
        for i in 0..m {
            let mut can = 0usize;
            for j in 0..n {
                if (i >> j & 1) == 0 && (i & req[j]) == req[j] {
                    can |= 1 << j; }}
            let mut j = can;
            while j > 0 {
                if j.count_ones() <= k as u32 {
                    dp[i|j] = dp[i|j].min(dp[i]+1);
                }
                j = j-1 & can;
            }
        }
        dp[m-1]
    }
}
