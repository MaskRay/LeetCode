impl Solution {
    pub fn get_permutation(n: i32, mut k: i32) -> String {
        let f = [1,1,2,6,24,120,720,5040,40320];
        let mut a = 0x987654321u64;
        k -= 1;
        let mut s = String::new();
        for i in (0..n as usize).rev() {
            let t = k/f[i];
            k %= f[i];
            s.push(std::char::from_digit((a >> 4*t & 15) as u32, 10).unwrap());
            a = a&(1u64<<4*t)-1 | a>>4*(t+1)<<4*t;
        }
        s
    }
}
