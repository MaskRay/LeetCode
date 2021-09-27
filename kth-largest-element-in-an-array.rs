impl Solution {
    pub fn find_kth_largest(mut nums: Vec<i32>, k: i32) -> i32 {
        fn nth(a: &mut [i32], lo: usize, hi: usize, k: usize) {
            if hi-lo < 2 { return; }
            let t = a[hi+lo>>1]; a[hi+lo>>1] = a[hi-1]; a[hi-1] = t;
            let pivot = a[hi-1];
            let mut p = lo;
            for i in lo..hi {
                if a[i] < pivot {
                    let t = a[p]; a[p] = a[i]; a[i] = t;
                    p += 1;
                }
            }
            let t = a[p]; a[p] = a[hi-1]; a[hi-1] = t;
            if k < p { nth(a, lo, p, k); }
            else if k > p { nth(a, p+1, hi, k); }
        }
        let n = nums.len();
        let k = n-k as usize;
        nth(&mut nums[..], 0, n, k);
        nums[k]
    }
}
