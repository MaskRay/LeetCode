// Maximum Number of Weeks for Which You Can Work
impl Solution {
    pub fn number_of_weeks(a: Vec<i32>) -> i64 {
        let (s,m) = a.into_iter().map(|x| x as i64).fold((0,0), |(s,m),x| (s+x, m.max(x)));
        if s < m*2 { (s-m)*2+1 } else { s }
    }
}
