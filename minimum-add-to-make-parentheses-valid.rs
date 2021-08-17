// Minimum Add to Make Parentheses Valid
impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut l = 0;
        let mut r = 0;
        for &c in s.as_bytes().iter() {
            if c == b'(' {
                l += 1;
            } else if l > 0 {
                l -= 1;
            } else {
                r += 1;
            }
        }
        l+r
    }
}
