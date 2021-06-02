// Minimum Speed to Arrive on Time
impl Solution {
    pub fn min_speed_on_time(dist: Vec<i32>, hour: f64) -> i32 {
        let n = dist.len();
        if (n-1) as f64 >= hour { return -1; }
        let mut l = 1;
        let mut h = dist.iter().max().unwrap()*100;
        while l < h {
            let m = l+h >> 1;
            let mut t = (0..n-1).fold(0, |acc,i| acc+(dist[i]+m-1)/m);
            if hour < t as f64 + dist[n-1] as f64 / m as f64 {
                l = m+1;
            } else {
                h = m;
            }
        }
        l
    }
}
