impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let mut a = vec![1; ratings.len()];
        for i in 1..a.len() {
            if ratings[i] > ratings[i-1] { a[i] = a[i-1]+1; }
        }
        for i in (0..a.len()-1).rev() {
            if ratings[i] > ratings[i+1] { a[i] = a[i].max(a[i+1]+1); }
        }
        a.iter().sum()
    }
}
