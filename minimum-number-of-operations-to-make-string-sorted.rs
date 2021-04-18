// Minimum Number of Operations to Make String Sorted
const MOD: i64 = 1000000007;

impl Solution {
    fn inv(mut x: i32) -> i32 {
        let mut s = 1;
        while x > 1 {
            s = s * (MOD-MOD/x as i64) % MOD;
            x = MOD as i32 % x;
        }
        return s as i32;
    }
    pub fn make_string_sorted(s: String) -> i32 {
        let n = s.len();
        let mut fac = vec![1; n+1];
        let mut invfac = vec![1; n+1];
        for i in 1..=n {
            fac[i] = (fac[i-1] as i64 * i as i64 % MOD) as i32;
            invfac[i] = Self::inv(fac[i]);
        }
        let mut cnt: Vec<usize> = vec![0; 26];
        let mut ans = 0;
        for i in (0..n).rev() {
            let ch = (s.as_bytes()[i]-b'a') as usize;
            let mut c = cnt[0..ch].iter().sum::<usize>() as i64 * fac[n-1-i] as i64 % MOD;
            cnt[ch] += 1;
            for j in 0..26 {
                c = c * invfac[cnt[j]] as i64 % MOD;
            }
            ans = (ans+c)%MOD;
        }
        ans as i32
    }
}
