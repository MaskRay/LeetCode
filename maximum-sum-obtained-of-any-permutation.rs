// Maximum Sum Obtained of Any Permutation
impl Solution {
    pub fn max_sum_range_query(nums: Vec<i32>, requests: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut sorted = Vec::with_capacity(n); unsafe { sorted.set_len(n); }
        let mut cnt = nums.iter().fold(vec![0; *nums.iter().max().unwrap() as usize+1], |mut c, &v| {c[v as usize] += 1; c});
        for i in 1..cnt.len() { cnt[i] += cnt[i-1]; }
        for v in nums.into_iter() {
            cnt[v as usize] -= 1;
            sorted[cnt[v as usize]] = v;
        }

        let mut cnt = vec![0; requests.len()+1];
        let mut freq = requests.into_iter().fold(vec![0i32; n+1], |mut f, r| {
            f[r[0] as usize] += 1;
            f[r[1] as usize + 1] -= 1;
            f
        });
        for i in 0..n {
            cnt[freq[i] as usize] += 1;
            freq[i+1] += freq[i];
        }
        for i in 1..cnt.len() { cnt[i] += cnt[i-1]; }
        (freq[0..n].iter().fold(0, |ans,&v| {
            cnt[v as usize] -= 1;
            ans + sorted[cnt[v as usize]] as i64 * v as i64
        }) % 1000000007) as i32
    }
}
