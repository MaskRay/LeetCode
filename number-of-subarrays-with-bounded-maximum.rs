// Number of Subarrays with Bounded Maximum
impl Solution {
    pub fn num_subarray_bounded_max(nums: Vec<i32>, left: i32, right: i32) -> i32 {
        let mut ans = 0;
        let mut cnt = 0;
        let mut bgn = 0;
        for (i, x) in nums.into_iter().enumerate() {
            if x > right {
                cnt = 0;
                bgn = i+1;
            } else {
                if x >= left {
                    cnt = i+1-bgn;
                }
                ans += cnt;
            }
        }
        ans as i32
    }
}
