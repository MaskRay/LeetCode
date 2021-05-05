impl Solution {
    pub fn split_string(s: String) -> bool {
        let s = s.as_bytes();
        let mut xx = 0;
        for mut i in 0..s.len()-1 {
            xx = xx*10 + (s[i]-b'0') as usize;
            let mut x = xx;
            let mut y = 0;
            loop {
                i += 1;
                if i == s.len() { break; }
                y = y*10 + (s[i]-b'0') as usize;
                if y >= x { break; }
                if y+1 == x && (y != 0 || i+1 == s.len()) {
                    if i+1 == s.len() { return true; }
                    x = y;
                    y = 0;
                }
            }
        }
        false
    }
}

///

impl Solution {
    pub fn split_string(s: String) -> bool {
        fn dfs(s: &[u8], x: usize) -> bool {
            if s.is_empty() { return true; }
            let mut y = 0;
            for i in 0..s.len() {
                y = y*10 + (s[i]-b'0') as usize;
                if y >= x { break; }
                if y+1 == x && dfs(&s[i+1..], y) { return true; }
            }
            false
        }
        let s = s.as_bytes();
        let mut x = 0;
        for i in 0..s.len()-1 {
            x = x*10 + (s[i]-b'0') as usize;
            if dfs(&s[i+1..], x) { return true; }
        }
        false
    }
}
