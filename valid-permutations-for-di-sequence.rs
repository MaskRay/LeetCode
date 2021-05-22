// Valid Permutations for DI Sequence
impl Solution {
    pub fn num_perms_di_sequence(s: String) -> i32 {
        const MOD: i32 = 1000000007;
        let s = s.as_bytes();
        let mut dp: Vec<i32> = vec![0; s.len()+1];
        dp[0] = 1;
        for i in 0..s.len() {
            if s[i] == b'I' {
                let mut x = 0;
                let mut ul = dp[0];
                dp[0] = 0;
                for j in 1..=i+1 {
                    x += ul; if x >= MOD { x -= MOD; }
                    ul = dp[j];
                    dp[j] = x;
                }
            } else {
                let mut x = dp[i];
                for j in (0..i).rev() {
                    x += dp[j]; if x >= MOD { x -= MOD; }
                    dp[j] = x;
                }
            }
        }
        dp.iter().fold(0, |acc,x| (acc+x)%MOD)
    }
}
