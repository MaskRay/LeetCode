// Valid Parenthesis String
impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut mn = 0i32;
        let mut mx = 0i32;
        for &c in s.as_bytes().iter() {
            if c == b'(' {
                mn += 1;
                mx += 1;
            } else if c == b')' {
                mn -= 1;
                mx -= 1;
            } else {
                mn -= 1;
                mx += 1;
            }
            if mx < 0 { return false; }
            mn = mn.max(0);
        }
        mn == 0
    }
}
