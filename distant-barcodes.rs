// Distant Barcodes
impl Solution {
    pub fn rearrange_barcodes(barcodes: Vec<i32>) -> Vec<i32> {
        let mut freq = vec![0; 10001];
        let n = barcodes.len();
        for &ch in barcodes.iter() { freq[ch as usize] += 1; }
        let mut a = freq.into_iter().enumerate().collect::<Vec<_>>();
        a.sort_unstable_by_key(|x| std::cmp::Reverse(x.1));
        let mut ans = vec![0; n];
        let mut j = 0;
        for (i, c) in a.into_iter() {
            for _ in 0..c {
                ans[j] = i as i32;
                j += 2;
                if j >= n { j = 1; }
            }
        }
        ans
    }
}
