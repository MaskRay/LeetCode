// Minimum Number of Flips to Make the Binary String Alternating
impl Solution {
    pub fn min_flips(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut b = (0..n).fold(0, |acc,i| acc + (s[i] as usize^i)%2);
        let mut ans = b.min(n-b);
        if n%2 != 0 {
            for i in 0..n-1 {
                if (s[i] as usize^i)%2 != 0 { b -= 1; }
                else { b += 1; }
                ans = ans.min(b.min(n-b));
            }
        }
        ans as i32
    }
}
