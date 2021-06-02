impl Solution {
    pub fn min_k_bit_flips(mut nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let k = k as usize;
        let mut ans = 0;
        for i in 0..n {
            if i > 0 { nums[i] ^= nums[i-1] & 2; }
            if nums[i] == 0 || nums[i] == 3 {
                if i+k > n { return -1; }
                nums[i] ^= 2;
                if i+k < n { nums[i+k] ^= 2; }
                ans += 1;
            }
        }
        ans
    }
}
