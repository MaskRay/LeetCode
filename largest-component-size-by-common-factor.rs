// Largest Component Size by Common Factor
impl Solution {
    pub fn largest_component_size(nums: Vec<i32>) -> i32 {
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
        for &x in nums.iter() {
            let rx = find(&mut uf, x);
            let mut x = x;
            while x > 1 {
                let p = sieve[x as usize];
                let rp = find(&mut uf, p);
                uf[rp] = rx as i32;
                x /= p;
            }
        }
        let mut size = vec![0; m as usize];
        for &x in nums.iter() {
            let rx = find(&mut uf, x);
            size[rx] += 1;
        }
        *size.iter().max().unwrap() as i32
    }
}
