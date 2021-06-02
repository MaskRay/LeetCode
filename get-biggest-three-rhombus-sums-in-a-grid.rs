// Get Biggest Three Rhombus Sums in a Grid
impl Solution {
    pub fn get_biggest_three(a: Vec<Vec<i32>>) -> Vec<i32> {
        use std::i32;
        let m = a.len();
        let n = a[0].len();
        let mut l = a.clone();
        let mut r = a.clone();
        for i in 1..m {
            for j in 0..n {
                if j > 0 { l[i][j] += l[i-1][j-1]; }
                if j+1 < n { r[i][j] += r[i-1][j+1]; }}}
        let mut mx = vec![i32::MIN; 3];
        for d in 0..(m.min(n)+1)/2 {
            for i in d..m-d {
                for j in d..n-d {
                    let s = if d==0 {a[i][j]} else {r[i][j-d]-r[i-d][j] + l[i][j+d]-l[i-d][j] +
                        l[i+d][j]-l[i][j-d] + r[i+d][j]-r[i][j+d] - a[i+d][j] + a[i-d][j]};
                    if s <= mx[2] || s == mx[1] || s == mx[0] { continue; }
                    mx[2] = s;
                    if mx[2] > mx[1] { mx.swap(2, 1); }
                    if mx[1] > mx[0] { mx.swap(1, 0); }
                }
            }
        }
        while *mx.last().unwrap() == i32::MIN { mx.pop(); }
        mx
    }
}
