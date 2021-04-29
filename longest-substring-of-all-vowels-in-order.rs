impl Solution {
    pub fn longest_beautiful_substring(word: String) -> i32 {
        let mut ans = 0;
        let mut c0 = 0;
        let mut l = 0;
        let mut n = 0;
        for (i, c) in word.as_bytes().iter().enumerate() {
            if c0 > *c { l = i; n = 1; }
            else if c0 < *c { n += 1; }
            c0 = *c;
            if n == 5 { ans = std::cmp::max(ans, i-l+1); }
        }
        ans as i32
    }
}
