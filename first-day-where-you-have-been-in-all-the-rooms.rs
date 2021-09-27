// First Day Where You Have Been in All the Rooms
impl Solution {
    pub fn first_day_been_in_all_rooms(next_visit: Vec<i32>) -> i32 {
        const MOD: i64 = 1000000007;
        let n = next_visit.len();
        let mut dp = vec![0; n+1];
        for i in 1..n {
            dp[i] = (dp[i-1]*2-dp[next_visit[i-1] as usize]+2) % MOD;
        }
        ((dp[n-1]+MOD)%MOD) as i32
    }
}
