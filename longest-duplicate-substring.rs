impl Solution {
    pub fn longest_dup_substring(s: String) -> String {
        let a = s.as_bytes();
        let n = a.len();
        let mut sa: Vec<i32> = Vec::with_capacity(n);
        let mut r: Vec<i32> = a.iter().map(|c| *c as i32).collect();
        let mut m = 128;
        let mut h = vec![0; n.max(m)];
        let mut x: Vec<i32> = Vec::with_capacity(n);
        unsafe { sa.set_len(n); x.set_len(n); }
        for i in 0..n { h[r[i] as usize] += 1; }
        for i in 1..m { h[i] += h[i-1]; }
        for i in (0..n).rev() { let v = &mut h[r[i] as usize]; *v -= 1; sa[*v as usize] = i as i32; }
        let mut k: usize = 1;
        loop {
            for i in 0..k { x[i as usize] = (n-k+i) as i32; }
            let mut j = k;
            for i in 0..n { if sa[i] >= k as i32 { x[j] = sa[i]-k as i32; j += 1; } }
            for i in 0..m { h[i] = 0; } // h[0..m].fill(0);
            for &i in x.iter() { h[r[i as usize] as usize] += 1; }
            for i in 1..m { h[i] += h[i-1]; }
            for &i in x.iter().rev() { let v = &mut h[r[i as usize] as usize]; *v -= 1; sa[*v as usize] = i; }
            for i in 0..m { h[i] = 0; } // h[0..m].fill(0);
            m = 1;
            h[sa[0] as usize] = 0;
            for i in 1..n {
                if r[sa[i] as usize] != r[sa[i-1] as usize] || sa[i].max(sa[i-1]) >= (n-k) as i32 || r[sa[i] as usize+k] != r[sa[i-1] as usize+k] { m += 1; }
                h[sa[i] as usize] = m as i32-1;
            }
            for i in 0..n { r[i] = h[i]; }
            if m == n { break; }
            k *= 2;
        }
        k = 0;
        h[0] = 0;
        let mut res0 = 0;
        let mut res1 = 0;
        for i in 0..n {
            if r[i] > 0 {
                let j = sa[r[i] as usize-1] as usize;
                while i.max(j)+k < n && a[i+k] == a[j+k] { k += 1; }
                h[r[i] as usize] = k as i32;
                if k > res1 {
                    res0 = i;
                    res1 = k;
                }
                if k > 0 { k -= 1; }
            }
        }
        s[res0..res0+res1].to_string()
    }
}

/// suffix automaton
impl Solution {
    pub fn longest_dup_substring(s: String) -> String {
        const AB: usize = 26;
        #[derive(Clone, Default)]
        struct Node { f: i32, c: [i32; AB], num: u8, l: i32, lc: i32 }
        fn add(ch: usize, pool: &mut [Node], tail: &mut usize, allo: &mut usize) {
            let x = *allo; *allo += 1;
            pool[x].l = pool[*tail].l+1;
            let mut p = *tail; *tail = x;
            while pool[p].c[ch] == 0 {
                pool[p].c[ch] = x as i32;
                if p == 0 { pool[x].f = 0; return; }
                p = pool[p].f as usize;
            }
            let q = pool[p].c[ch] as usize;
            if pool[p].l+1 == pool[q].l {
                pool[x].f = q as i32;
            } else {
                let r = *allo; *allo += 1;
                pool[r] = Node { f: pool[q].f, c: pool[q].c, l: pool[p].l+1, ..Default::default() };
                pool[x].f = r as i32;
                pool[q].f = r as i32;
                while pool[p].c[ch] == q as i32 {
                    pool[p].c[ch] = r as i32;
                    if p == 0 { break; }
                    p = pool[p].f as usize;
                }
            }
        }

        let s1 = s.as_bytes();
        let n = s1.len();
        let mut pool: Vec<Node> = vec![Default::default(); 2*n];
        let mut tail = 0; let mut allo = 1;
        for &ch in s1.iter() {
            add((ch-b'a') as usize, &mut pool[..], &mut tail, &mut allo);
            pool[tail].num = 1;
        }

        let mut c = vec![0; n+1];
        let mut seq = vec![0; allo];
        for i in 0..allo { c[pool[i].l as usize] += 1; }
        for i in 1..=n { c[i] += c[i-1]; }
        for i in (0..allo).rev() { let r = &mut c[pool[i].l as usize]; *r -= 1; seq[*r] = i; }
        let mut res0 = 0;
        let mut res1 = 0;
        for i in (0..allo).rev() {
            let x = seq[i];
            let p = pool[x].f as usize;
            if p > 0 {
                pool[p].num = (pool[p].num+pool[x].num).min(2);
            }
            let mut lc = -1; // maxContext
            for ch in 0..AB {
                if pool[x].c[ch] > 0 {
                    lc = lc.max(pool[pool[x].c[ch] as usize].lc);
                }
            }
            pool[x].lc = lc+1;
            if pool[x].num > 1 && pool[x].l as usize > res1 {
                res0 = n-pool[x].lc as usize;
                res1 = pool[x].l as usize;
            }
        }
        s[res0-res1..res0].to_string()
    }
}
