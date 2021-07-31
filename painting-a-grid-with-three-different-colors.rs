// Painting a Grid With Three Different Colors
impl Solution {
    pub fn color_the_grid(m: i32, n: i32) -> i32 {
        const MOD: i32 = 1000000007;
        let ns = 3<<m-1;
        let mut tr = vec![vec![]; ns];
        for i in 0..ns {
            for j in 0..ns {
                let mut i0 = i>>m-1;
                let mut j0 = j>>m-1;
                let mut ok = i0 != j0;
                for k in 0..m-1 {
                    i0 = (i0+1+(i>>k&1))%3;
                    j0 = (j0+1+(j>>k&1))%3;
                    ok = ok && i0 != j0;
                }
                if ok { tr[i].push(j); }
            }
        }
        let mut f = vec![1; ns];
        let mut g = vec![0; ns];
        for i in 1..n {
            for j in 0..ns { g[j] = 0; }
            for j in 0..ns {
                for &k in tr[j].iter() {
                    g[k] = (f[j]+g[k])%MOD;
                }
            }
            for j in 0..ns { f[j] = g[j]; }
        }
        f.iter().fold(0, |acc,v| (acc+v)%MOD)
    }
}
