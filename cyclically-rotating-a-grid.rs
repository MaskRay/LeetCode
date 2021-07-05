// Cyclically Rotating a Grid
impl Solution {
    pub fn rotate_grid(mut a: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let m = a.len()-1;
        let n = a[0].len()-1;
        let mut b = vec![];
        for q in 0..(m.min(n)+1)/2 {
            b.clear();
            for i in q..n-q { b.push(a[q][i]); }
            for i in q..m-q { b.push(a[i][n-q]); }
            for i in (q+1..=n-q).rev() { b.push(a[m-q][i]); }
            for i in (q+1..=m-q).rev() { b.push(a[i][q]); }
            b.rotate_left(k as usize%(2*(m+n)-q*8));
            let mut j = 0;
            for i in q..n-q { a[q][i] = b[j]; j += 1; }
            for i in q..m-q { a[i][n-q] = b[j]; j += 1; }
            for i in (q+1..=n-q).rev() { a[m-q][i] = b[j]; j += 1; }
            for i in (q+1..=m-q).rev() { a[i][q] = b[j]; j += 1; }
        }
        a
    }
}
