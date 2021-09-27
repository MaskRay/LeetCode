// The Number of Good Subsets
impl Solution {
    pub fn number_of_good_subsets(nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1000000007;
        let ps = [2,3,5,7,11,13,17,19,23,29];
        let mut dp = vec![0; 1<<ps.len()];
        dp[0] = 1;
        let mut freq = vec![0; 31];
        for x in nums.into_iter() { freq[x as usize] += 1; }
        for i in 2..freq.len() {
            let mut ok = true;
            let mut m = 0;
            for (j, &p) in ps.iter().enumerate() {
                if i%p == 0 { m |= 1 << j; }
                if i%(p*p) == 0 { ok = false; }
            }
            if !ok { continue; }
            let invm = (1<<ps.len())-1-m;
            let mut j = invm;
            loop {
                dp[j|m] = (dp[j|m] + freq[i]*dp[j]) % MOD;
                if j == 0 { break; }
                j = j-1 & invm;
            }
        }
        let mut ans = (dp.iter().sum::<i64>()-1)%MOD;
        for _ in 0..freq[1] { ans = ans*2%MOD; }
        ans as i32
    }
}
