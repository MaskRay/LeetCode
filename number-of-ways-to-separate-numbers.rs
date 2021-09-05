// Number of Ways to Separate Numbers
impl Solution {
    pub fn number_of_combinations(num: String) -> i32 {
        const MOD: i32 = 1000000007;
        let a = num.as_bytes();
        let n = a.len();
        let mut p = vec![0; n+1];
        let mut f = vec![0; n+1];
        let mut g = vec![0; n+1];
        for l in 1..=n {
            for i in (l..=n-1).rev() {
                p[i] = if a[i-l] == a[i] {p[i+1]+1} else {0};
            }
            f[0] = 1;
            for i in 1..=n {
                g[i] = f[i];
                if l <= i && a[i-l] != b'0' {
                    if i >= 2*l && (p[i-l] >= l || a[i-l+p[i-l]] > a[i-l-l+p[i-l]]) {
                        g[i] = (g[i]+g[i-l]) % MOD;
                    } else {
                        g[i] = (g[i]+f[i-l]) % MOD;
                    }
                }
            }
            std::mem::swap(&mut f, &mut g);
        }
        f[n]
    }
}
