impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        use std::collections::HashMap;
        let mut freq: HashMap<i32, i32> = HashMap::new();
        for &x in nums.iter() { *freq.entry(x).or_insert(0) += 1; }
        let mut a = freq.into_iter().collect::<Vec<(i32, i32)>>();
        fn nth(a: &mut [(i32,i32)], lo: usize, hi: usize, k: usize) {
            if hi-lo < 2 { return; }
            let t = a[hi+lo>>1]; a[hi+lo>>1] = a[hi-1]; a[hi-1] = t;
            let pivot = a[hi-1].1;
            let mut p = lo;
            for i in lo..hi {
                if a[i].1 < pivot {
                    let t = a[p]; a[p] = a[i]; a[i] = t;
                    p += 1;
                }
            }
            let t = a[p]; a[p] = a[hi-1]; a[hi-1] = t;
            if k < p { nth(a, lo, p, k); }
            else if k > p { nth(a, p+1, hi, k); }
        }

        let n = a.len();
        let k = n-k as usize;
        nth(&mut a[..], 0, n, k);
        a.drain(k..).map(|x| x.0).collect()
    }
}
