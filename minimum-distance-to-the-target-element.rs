impl Solution {
    pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
        let mut ans = nums.len() as i32;
        for i in 0..nums.len() {
            if nums[i] == target {
                ans = std::cmp::min(ans, (start-i as i32).abs());
            }
        }
        ans
    }
}
