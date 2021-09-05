// Filling Bookcase Shelves
impl Solution {
    pub fn min_height_shelves(books: Vec<Vec<i32>>, shelf_width: i32) -> i32 {
        let n = books.len();
        let mut dp = vec![0; n+1];
        for i in 0..n {
            dp[i+1] = dp[i]+books[i][1];
            let mut sum = books[i][0];
            let mut hi = books[i][1];
            for j in (0..i).rev() {
                sum += books[j][0];
                if sum > shelf_width { break; }
                hi = hi.max(books[j][1]);
                dp[i+1] = dp[i+1].min(dp[j]+hi);
            }
        }
        dp[n]
    }
}
