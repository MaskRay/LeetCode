// Super Ugly Number
impl Solution {
    pub fn nth_super_ugly_number(n: i32, primes: Vec<i32>) -> i32 {
        let m = primes.len();
        let mut a = vec![1];
        let mut ix = vec![0; m];
        while a.len() < n as usize {
            let mn = (0..m).fold(std::i32::MAX, |mn,i| mn.min(a[ix[i]]*primes[i]));
            a.push(mn);
            for i in 0..m {
                if a[ix[i]]*primes[i] == mn {
                    ix[i] += 1;
                }
            }
        }
        *a.last().unwrap()
    }
}
