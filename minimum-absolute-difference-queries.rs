// Minimum Absolute Difference Queries
impl Solution {
    pub fn min_difference(a: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        const V: usize = 100;
        let n = a.len();
        let mut s = vec![[0i32; V]; n+1];
        for i in 0..n {
            let (before, after) = s.split_at_mut(i+1);
            after[0].clone_from_slice(&before[i]);
            s[i+1][a[i] as usize-1] += 1;
        }
        let mut ans = vec![];
        for q in queries.into_iter() {
            let mut x = std::i32::MAX;
            let mut last = -1;
            let l = &s[q[0] as usize];
            let r = &s[q[1] as usize+1];
            for i in 0..100 {
                if (*r)[i as usize] != (*l)[i as usize] {
                    if last >= 0 { x = x.min(i-last); }
                    last = i;
                }
            }
            ans.push(if x==std::i32::MAX {-1} else {x});
        }
        ans
    }
}
