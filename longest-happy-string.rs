// Longest Happy String
impl Solution {
    pub fn longest_diverse_string(a: i32, b: i32, c: i32) -> String {
        use std::mem::swap;
        let mut ans = vec![];
        let mut s = vec![a, b, c];
        let mut l2 = 3;
        let mut l1 = 3;
        while s[0]+s[1]+s[2] > 0 {
            let mut x = 0; let mut y = 1; let mut z = 2;
            if s[x] < s[y] { swap(&mut x, &mut y); }
            if s[y] < s[z] { swap(&mut y, &mut z); }
            if s[x] < s[y] { swap(&mut x, &mut y); }
            if x != l2 || x != l1 {}
            else if s[y] > 0 { x = y; }
            else { break; }
            ans.push(b'a'+x as u8);
            s[x] -= 1;
            l2 = l1;
            l1 = x;
        }
        String::from_utf8_lossy(&ans).into_owned()
    }
}
