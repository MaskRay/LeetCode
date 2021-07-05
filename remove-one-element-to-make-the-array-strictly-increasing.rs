// Remove One Element to Make the Array Strictly Increasing
impl Solution {
    pub fn can_be_increasing(nums: Vec<i32>) -> bool {
        let mut prev = nums[0];
        let mut flag = false;
        for i in 1..nums.len() {
            if prev < nums[i] {
                prev = nums[i];
            } else {
                if flag { return false; }
                flag = true;
                if i == 1 || nums[i-2] < nums[i] {
                    prev = nums[i];
                }
            }
        }
        true
    }
}
