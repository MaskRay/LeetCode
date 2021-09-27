impl Solution {
    pub fn distinct_subseq_ii(s: String) -> i32 {
        const MOD: i64 = 1000000007;
        let mut dp = vec![0; 26];
        let mut sum = 0;
        for &c in s.as_bytes() {
            let x = dp[(c-b'a') as usize];
            dp[(c-b'a') as usize] = sum+1;
            sum += (sum+1-x) % MOD;
        }
        ((sum%MOD+MOD)%MOD) as i32
    }
}
