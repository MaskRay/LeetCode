// Count Ways to Build Rooms in an Ant Colony
impl Solution {
    pub fn ways_to_build_rooms(prev: Vec<i32>) -> i32 {
        const MOD: usize = 1000000007;
        let n = prev.len();
        let mut inv = vec![1; n];
        let mut fac = vec![1; n];
        let mut invfac = vec![1; n];
        fac[0] = 1; invfac[0] = 1;
        fac[1] = 1; invfac[1] = 1; inv[1] = 1;
        for i in 2..n {
            inv[i] = ((MOD-MOD/i)*(inv[MOD%i] as usize)%MOD) as i32;
            fac[i] = (fac[i-1] as usize*i%MOD) as i32;
            invfac[i] = (invfac[i-1] as usize*inv[i] as usize%MOD) as i32;
        }

        let mut d = vec![0; n];
        let mut top = std::usize::MAX;
        for &p in prev.iter() { if p >= 0 { d[p as usize] += 1; }}
        for i in 0..n { if d[i] == 0 { d[i] = top; top = i; }}

        let mut num = vec![0; n];
        let mut cnt = vec![1; n];
        let mut ans = 1;
        while top != std::usize::MAX {
            let u = top;
            let p = prev[u] as usize;
            top = d[top];
            cnt[u] = cnt[u] *fac[num[u]] as usize%MOD;
            num[u] += 1;
            if p == std::usize::MAX {
                ans = cnt[u];
            } else {
                cnt[p] = cnt[p] *cnt[u]%MOD *invfac[num[u]] as usize%MOD;
                num[p] += num[u];
                d[p] -= 1;
                if d[p] == 0 {
                    d[p] = top;
                    top = p;
                }
            }
        }
        ans as i32
    }
}
