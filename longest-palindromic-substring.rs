impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let a = s.as_bytes(); let n = a.len();
        let mut r0 = vec![0; n];
        let mut r1 = vec![0; n];
        let mut f = 0; let mut g = 0;
        let mut bgn = 0; let mut len = 0;
        for i in 0..n {
            r1[i] = if i < g && r1[2*f-i] != g-i { r1[2*f-i].min(g-i) } else {
                f = i;
                g = g.max(i);
                while g < n && 2*f >= g && a[2*f-g] == a[g] { g += 1; }
                g-f
            };
            if 2*r1[i]-1 > len {
                bgn = i+1-r1[i];
                len = 2*r1[i]-1;
            }
        }
        g = 0;
        for i in 0..n {
            r0[i] = if i < g && r0[2*f-i] != g-i { r0[2*f-i].min(g-i) } else {
                f = i;
                g = g.max(i);
                while g < n && 2*f >= g+1 && a[2*f-1-g] == a[g] { g += 1; }
                g-f
            };
            if 2*r0[i] > len {
                bgn = i-r0[i];
                len = 2*r0[i];
            }
        }
        s[bgn..bgn+len].to_string()
    }
}
