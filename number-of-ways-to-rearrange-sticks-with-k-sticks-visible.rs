// Number of Ways to Rearrange Sticks With K Sticks Visible
impl Solution {
    pub fn rearrange_sticks(n: i32, k: i32) -> i32 {
        let n = n as usize;
        let mut s: Vec<usize> = vec![0; n+1];
        s[1] = 1;
        for i in 1..n {
            for j in (1..=i+1).rev() {
                s[j] = (s[j]*i + s[j-1]) % 1_000_000_007; }}
        s[k as usize] as i32
    }
}
