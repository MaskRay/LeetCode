// Find Longest Awesome Substring
impl Solution {
    pub fn longest_awesome(s: String) -> i32 {
        let mut pos = vec![-1i32; 1<<10];
        let mut sum = 0;
        let mut ans = 0;
        pos[0] = 0;
        for (i, c) in s.as_bytes().iter().enumerate() {
            let i = i as i32;
            sum ^= 1 << c-b'0';
            if pos[sum] >= 0 {
                ans = ans.max(i+1-pos[sum]);
            } else {
                pos[sum] = i+1;
            }
            for j in 0..10 {
                let p = pos[sum ^ 1<<j];
                if p >= 0 {
                    ans = ans.max(i+1-p);
                }
            }
        }
        ans
    }
}
