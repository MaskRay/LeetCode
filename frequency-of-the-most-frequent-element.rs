impl Solution {
    pub fn max_frequency(mut nums: Vec<i32>, k: i32) -> i32 {
        let mut k = k as i64;
        let mut j = 0;
        let mut ans = 0;
        nums.sort();
        for (i, x) in nums.iter().enumerate() {
            while (i-j) as i64 * *x as i64 > k {
                k -= nums[j] as i64;
                j += 1;
            }
            ans = std::cmp::max(ans, i-j+1);
            k += *x as i64;
        }
        ans as i32
    }
}
