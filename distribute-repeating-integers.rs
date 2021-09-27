// Distribute Repeating Integers
impl Solution {
    pub fn can_distribute(mut nums: Vec<i32>, quantity: Vec<i32>) -> bool {
        nums.sort_unstable();
        let mut freq = vec![];
        let mut i = 0;
        while i < nums.len() {
            let j = i;
            let x = nums[i];
            loop {
                i += 1;
                if i == nums.len() || nums[i] != x { break; }
            }
            freq.push(i-j);
        }
        freq.sort_unstable();
        let n = quantity.len();
        let mut sum = vec![0; 1<<n];
        for x in 1..1<<n {
            let y = x & x-1;
            sum[x] = sum[y]+quantity[(x^y).trailing_zeros() as usize];
        }

        let mut dp = vec![false; 1<<n];
        dp[0] = true;
        for &f in freq.iter().rev().take(n) {
            for x in (1..1<<n).rev() {
                let mut y = x-1;
                while !dp[x] {
                    if dp[y] && sum[x^y] <= f as i32 { dp[x] = true; }
                    if y == 0 { break; }
                    y = y-1 & x;
                }
            }
        }
        *dp.last().unwrap()
    }
}
