// Count Number of Special Subsequences
impl Solution {
    pub fn count_special_subsequences(nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1000000007;
        let mut a = 0;
        let mut b = 0;
        let mut c = 0;
        for x in nums.iter() {
            match x {
                0 => a = (a*2+1) % MOD,
                1 => b = (b*2+a) % MOD,
                _ => c = (c*2+b) % MOD
            }
        }
        c as i32
    }
}
