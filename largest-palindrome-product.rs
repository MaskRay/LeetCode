// Largest Palindrome Product
impl Solution {
    pub fn largest_palindrome(n: i32) -> i32 {
        let l = 10i64.pow(n as u32-1);
        let h = 10i64.pow(n as u32)-1;
        for mut i in (l..=h).rev() {
            let mut s = i;
            while i > 0 {
                s = s*10+i%10;
                i /= 10;
            }
            let mut j = (s+h-1)/h;
            loop {
                if s/j < j { break; }
                if s%j == 0 { return (s%1337) as i32; }
                j += 1;
            }
        }
        9
    }
}
