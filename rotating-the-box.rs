// Rotating the Box
impl Solution {
    pub fn rotate_the_box(b: Vec<Vec<char>>) -> Vec<Vec<char>> {
        let m = b.len();
        let n = b[0].len();
        let mut a = vec![vec!['.'; m]; n];
        for i in 0..m {
            let mut k = n;
            for j in (0..n).rev() {
                if b[i][j] != '.' {
                    if b[i][j] == '*' { k = j; }
                    else { k -= 1; }
                    a[k][m-1-i] = b[i][j];
                }
            }
        }
        a
    }
}
