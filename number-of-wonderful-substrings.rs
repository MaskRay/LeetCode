// Number of Wonderful Substrings
impl Solution {
    pub fn wonderful_substrings(word: String) -> i64 {
        let mut s = vec![0; 1<<10];
        s[0] = 1;
        let mut sum = 0;
        let mut ans = 0;
        for c in word.as_bytes().iter() {
            sum ^= 1 << c-b'a';
            ans += s[sum];
            for j in 0..10 { ans += s[sum^1<<j]; }
            s[sum] += 1;
        }
        ans
    }
}
