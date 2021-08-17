// Minimum Insertions to Balance a Parentheses String
impl Solution {
    pub fn min_insertions(s: String) -> i32 {
        let mut ans = 0;
        let mut x = 0;
        for &c in s.as_bytes().iter() {
            if c == b'(' {
                if x%2 == 1 {
                    x -= 1;
                    ans += 1;
                }
                x += 2;
            } else {
                if x == 0 {
                    x += 2;
                    ans += 1;
                }
                x -= 1;
            }
        }
        ans+x
    }
}
