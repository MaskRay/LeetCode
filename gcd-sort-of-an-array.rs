// GCD Sort of an Array
impl Solution {
    pub fn gcd_sort(nums: Vec<i32>) -> bool {
        fn find(uf: &mut Vec<i32>, mut x: i32) -> usize {
            while uf[x as usize] != x {
                uf[x as usize] = uf[uf[x as usize] as usize];
                x = uf[x as usize];
            }
            x as usize
        }
        let m = nums.iter().max().unwrap() + 1;
        let mut sieve = (0..m).collect::<Vec<_>>();
        for i in 2..=(m as f64).sqrt() as i32 {
            if sieve[i as usize] != i { continue; }
            let mut j = i*i;
            while j < m {
                sieve[j as usize] = i;
                j += i;
            }
        }
        let mut uf = (0..m).collect::<Vec<_>>();
        for &(mut x) in nums.iter() {
            let rx = find(&mut uf, x);
            while x > 1 {
                let p = sieve[x as usize];
                let rp = find(&mut uf, p);
                uf[rp] = rx as i32;
                x /= p;
            }
        }
        let mut sorted = nums.clone();
        sorted.sort_unstable();
        for i in 0..nums.len() {
            if find(&mut uf, sorted[i]) != find(&mut uf, nums[i]) {
                return false;
            }
        }
        true
    }
}
