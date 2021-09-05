// Find Array Given Subset Sums
impl Solution {
    pub fn recover_array(_n: i32, mut sums: Vec<i32>) -> Vec<i32> {
        let mut m = sums.len();
        sums.sort_unstable();
        let mut ans = vec![];
        while m > 1 {
            let mut left = vec![];
            let mut right = vec![];
            let d = sums[1]-sums[0];
            let mut k = 0;
            let mut zero = false;
            for j in 0..m {
                if k < right.len() && sums[j] == right[k] {
                    k += 1;
                } else {
                    if sums[j] == 0 { zero = true; }
                    left.push(sums[j]);
                    right.push(sums[j]+d);
                }
            }
            if zero {
                ans.push(d);
                sums = left;
            } else {
                ans.push(-d);
                sums = right;
            }
            m /= 2;
        }
        ans
    }
}
