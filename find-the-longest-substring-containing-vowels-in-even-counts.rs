// Find the Longest Substring Containing Vowels in Even Counts
impl Solution {
    pub fn find_the_longest_substring(s: String) -> i32 {
        let mut pos = vec![-1; 1<<5];
        pos[0] = 0;
        let mut sum = 0;
        let mut ans = 0;
        for (i, c) in s.as_bytes().iter().enumerate() {
            let i = i as i32;
            match c {
                b'a' => sum ^= 1,
                b'e' => sum ^= 2,
                b'i' => sum ^= 4,
                b'o' => sum ^= 8,
                b'u' => sum ^= 16,
                _ => (),
            }
            if pos[sum] < 0 {
                pos[sum] = i+1;
            } else {
                ans = ans.max(i+1-pos[sum]);
            }
        }
        ans
    }
}
