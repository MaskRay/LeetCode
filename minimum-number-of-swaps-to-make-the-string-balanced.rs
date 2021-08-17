// Minimum Number of Swaps to Make the String Balanced
impl Solution {
    pub fn min_swaps(s: String) -> i32 {
        let mut x = 0;
        for &c in s.as_bytes().iter() {
            if c == b'[' {
                x += 1;
            } else if x > 0 {
                x -= 1;
            }
        }
        (x+1)/2
    }
}
