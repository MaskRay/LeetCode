// Maximum Alternating Subsequence Sum
impl Solution {
    pub fn max_alternating_sum(nums: Vec<i32>) -> i64 {
        let mut s = nums[0] as i64;
        for i in 1..nums.len() {
            if nums[i] > nums[i-1] {
                s += (nums[i]-nums[i-1]) as i64;
            }
        }
        s
    }
}
