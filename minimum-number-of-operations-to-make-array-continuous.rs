// Minimum Number of Operations to Make Array Continuous
impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut j = 0;
        nums.sort_unstable();
        nums.dedup();
        for i in 0..nums.len() {
            while j < nums.len() && nums[j] < nums[i]+n as i32 { j += 1; }
            ans = ans.max(j-i);
        }
        (n-ans) as i32
    }
}
