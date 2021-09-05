// Minimum Non-Zero Product of the Array Elements
impl Solution {
    pub fn min_non_zero_product(p: i32) -> i32 {
        const MOD: i64 = 1000000007;
        let mut s = ((1i64<<p)-1) % MOD;
        let mut a = s+MOD-1;
        let mut n = ((1i64<<p-1)-1) % (MOD-1);
        while n > 0 {
            if n%2 != 0 {
                s = s*a % MOD;
            }
            a = a*a % MOD;
            n /= 2;
        }
        s as i32
    }
}
