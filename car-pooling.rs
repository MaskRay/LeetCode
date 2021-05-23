// Car Pooling
impl Solution {
    pub fn car_pooling(trips: Vec<Vec<i32>>, capacity: i32) -> bool {
        let mut s = vec![0; 1001];
        for t in trips.iter() {
            s[t[1] as usize] += t[0];
            s[t[2] as usize] -= t[0];
        }
        let mut x = 0;
        for i in 0..1001 {
            x += s[i];
            if x > capacity { return false; }
        }
        true
    }
}
