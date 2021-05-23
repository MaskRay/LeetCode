// Corporate Flight Bookings
impl Solution {
    pub fn corp_flight_bookings(bookings: Vec<Vec<i32>>, n: i32) -> Vec<i32> {
        let n = n as usize;
        let mut s = vec![0; n+1];
        for b in bookings.iter() {
            s[b[0] as usize - 1] += b[2];
            s[b[1] as usize] -= b[2];
        }
        let mut ans = vec![0; n];
        let mut x = 0;
        for i in 0..n {
            x += s[i];
            ans[i] = x;
        }
        ans
    }
}
