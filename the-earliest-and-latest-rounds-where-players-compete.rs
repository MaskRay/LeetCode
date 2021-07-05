// The Earliest and Latest Rounds Where Players Compete
impl Solution {
    pub fn earliest_and_latest(n: i32, first: i32, second: i32) -> Vec<i32> {
        if first+second == n + 1 { return vec![1, 1]; }
        let (first, second) = if first+second <= n+1 {(first, second)} else {(n+1-second, n+1-first)};
        let s = first+second;
        let mut early = 1;
        if s == n {
            if first%2 == 0 {
                early = if first+2 < second {2} else {1+first.trailing_zeros() as i32};
            }
        } else if first+1 == second {
            early = 32 - ((n-1) / (s-1)).leading_zeros() as i32;
            early += ((n-1) >> early).trailing_zeros() as i32;
        } else if s <= (n+1)/2 {
            early = 32 - ((n-1) / (s-1)).leading_zeros() as i32;
        }
        vec![early+1, (32-(n-1).leading_zeros() as i32).min(n+1-second)]
    }
}
