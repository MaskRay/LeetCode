// Maximum XOR With an Element From Array
impl Solution {
    pub fn maximize_xor(mut nums: Vec<i32>, mut queries: Vec<Vec<i32>>) -> Vec<i32> {
        use std::usize::MAX;
        let n = nums.len();
        nums.sort_unstable();
        for (i, q) in queries.iter_mut().enumerate() { q.push(i as i32); }
        queries.sort_unstable_by_key(|q| q[1]);
        let mut ans = Vec::with_capacity(queries.len()); unsafe { ans.set_len(queries.len()); }
        let mut best = vec![MAX; queries.len()];
        let mut p0: Vec<usize> = (0..n).map(|i| i.wrapping_sub(1)).collect();
        let mut p1 = Vec::with_capacity(n); unsafe { p1.set_len(n); }
        for kk in (0..30).rev() {
            let k = 1 << kk;
            for i in 0..n {
                if p0[i] == MAX { p1[i] = MAX; }
                else if ((nums[i]^nums[p0[i]]) & k) == 0 { p1[i] = p1[p0[i]]; }
                else { p1[i] = p0[i]; p0[i] = p1[p0[i]]; }
            }
            let mut i = 0;
            for (q, b) in queries.iter().zip(&mut best) {
                while i < n && nums[i] <= q[1] { i += 1; }
                if *b == MAX { *b = i.wrapping_sub(1); }
                if *b != MAX && ((q[0]^nums[*b]) & k) == 0 && p1[*b] != MAX { *b = p1[*b]; }
            }
        }
        for (q, b) in queries.iter().zip(best) {
            ans[q[2] as usize] = if b == MAX { -1 } else { q[0]^nums[b] };
        }
        ans
    }
}
