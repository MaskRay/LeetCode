// Minimum Moves to Make Array Complementary
impl Solution {
    pub fn min_moves(nums: Vec<i32>, limit: i32) -> i32 {
        let limit = limit as usize;
        let n = nums.len();
        let mut s = vec![0i32; 2*limit+2];
        for i in 0..n/2 {
            let mn = nums[i].min(nums[n-1-i]) as usize;
            let mx = nums[i].max(nums[n-1-i]) as usize;
            s[0] += 2;
            s[mn+mx] -= 1;
            s[mn+mx+1] += 1;
            s[mn+1] -= 1;
            s[mx+limit+1] += 1;
        }
        let mut ans = (2*n) as i32;
        for i in 0..=2*limit {
            ans = ans.min(s[i]);
            s[i+1] += s[i];
        }
        ans as i32
    }
}
