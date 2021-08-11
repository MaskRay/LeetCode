// String Without AAA or BBB
impl Solution {
    pub fn str_without3a3b(mut a: i32, mut b: i32) -> String {
        use std::mem::swap;
        let mut ans = vec![];
        let mut A = b'a';
        let mut B = b'b';
        if a < b { swap(&mut a, &mut b); swap(&mut A, &mut B); }
        while a > 0 {
            ans.push(A);
            if a-1 <= b { a -= 1; }
            else { ans.push(A); a -= 2; }
            if b > 0 { ans.push(B); b -= 1; }
        }
        String::from_utf8_lossy(&ans).into_owned()
    }
}
