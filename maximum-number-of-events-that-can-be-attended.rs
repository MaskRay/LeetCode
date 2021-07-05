// Maximum Number of Events That Can Be Attended
impl Solution {
    pub fn max_events(mut events: Vec<Vec<i32>>) -> i32 {
        let n = events.iter().fold(0, |acc,e| acc.max(e[1])) + 2;
        events.sort_unstable_by_key(|x| x[1]);
        let mut uf: Vec<i32> = (0..n).collect();
        let mut ans = 0;
        for e in events.into_iter() {
            let mut x = e[0];
            while uf[x as usize] != x {
                uf[x as usize] = uf[uf[x as usize] as usize];
                x = uf[x as usize];
            }
            if x <= e[1] {
                uf[x as usize] = x+1;
                ans += 1;
            }
        }
        ans
    }
}
