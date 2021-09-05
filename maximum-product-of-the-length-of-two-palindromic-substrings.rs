// Maximum Product of the Length of Two Palindromic Substrings
impl Solution {
    pub fn max_product(s: String) -> i64 {
        let a = s.as_bytes(); let n = a.len();
        let mut r = vec![0; n];
        let mut f = 0; let mut g = 0;
        for i in 0..n {
            r[i] = if i < g && r[2*f-i] != g-i { r[2*f-i].min(g-i) } else {
                f = i;
                g = g.max(i);
                while g < n && 2*f >= g && a[2*f-g] == a[g] { g += 1; }
                g-f
            };
        }
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        left[0] = 1;
        let mut p = 0;
        for i in 1..n {
            while p+r[p] <= i { p += 1; }
            left[i] = left[i-1].max(2*(i-p)+1);
        }
        p = n-1;
        right[n-1] = 1;
        for i in (0..n-1).rev() {
            while p+1-r[p] > i { p -= 1; }
            right[i] = right[i+1].max(2*(p-i)+1);
        }
        let mut ans = 0;
        for i in 0..n-1 {
            ans = ans.max(left[i] as i64*right[i+1] as i64);
        }
        ans
    }
}
