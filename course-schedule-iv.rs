// Course Schedule IV
impl Solution {
    pub fn check_if_prerequisite(n: i32, prerequisites: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let n = n as usize;
        let mut g = vec![vec![false; n]; n];
        for p in prerequisites.iter() {
            g[p[0] as usize][p[1] as usize] = true;
        }
        for k in 0..n {
            for i in 0..n {
                for j in 0..n {
                    if g[i][k] && g[k][j] {
                        g[i][j] = true; }}}}
        queries.into_iter().map(|q| g[q[0] as usize][q[1] as usize]).collect()
    }
}
