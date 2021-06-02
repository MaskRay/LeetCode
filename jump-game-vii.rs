// Jump Game VII
impl Solution {
    pub fn can_reach(s: String, min_jump: i32, max_jump: i32) -> bool {
        let s = s.as_bytes();
        let n = s.len();
        if s[n-1] != b'0' { return false; }
        let mut a = vec![0; n+1];
        a[0] = 1;
        a[1] = -1;
        for i in 0..n {
            if a[i] > 0 && s[i] == b'0' {
                a[n.min(i+min_jump as usize)] += 1;
                a[n.min(i+max_jump as usize+1)] -= 1;
            }
            a[i+1] += a[i];
        }
        a[n-1] > 0
    }
}

