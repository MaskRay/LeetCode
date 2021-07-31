// Describe the Painting
impl Solution {
    pub fn split_painting(segments: Vec<Vec<i32>>) -> Vec<Vec<i64>> {
        use std::collections::BTreeMap;
        let mut c = BTreeMap::new();
        for seg in segments.into_iter() {
            c.insert(seg[0], c.get(&seg[0]).unwrap_or(&0)+seg[2] as i64);
            c.insert(seg[1], c.get(&seg[1]).unwrap_or(&0)-seg[2] as i64);
        }
        let mut ans = vec![];
        let mut i = 0;
        let mut sum = 0;
        for (k, v) in c.into_iter() {
            if sum > 0 {
                ans.push(vec![i as i64, k as i64, sum]);
            }
            sum += v;
            i = k;
        }
        ans
    }
}
