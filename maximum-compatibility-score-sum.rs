// Maximum Compatibility Score Sum
impl Solution {
    pub fn max_compatibility_sum(students: Vec<Vec<i32>>, mentors: Vec<Vec<i32>>) -> i32 {
        use std::{i32,usize};
        fn augment(n:usize, u:usize, mate:&mut[usize], slack:&mut[i32], lx:&mut[i32], ly:&mut[i32],
            fx:&mut[bool], fy:&mut[bool], a:&[Vec<i32>]) -> bool {
            fx[u] = true;
            for i in 0..n {
                if fy[i] { continue; }
                let t = lx[u]+ly[i]-a[u][i];
                if t != 0 {
                    slack[i] = slack[i].min(t);
                } else {
                    fy[i] = true;
                    if mate[i] == usize::MAX || augment(n, mate[i], mate, slack, lx, ly, fx, fy, a) {
                        mate[i] = u;
                        return true;
                    }
                }
            }
            false
        }

        let n = students.len();
        let m = students[0].len();
        let mut a = vec![vec![0; n]; n];
        for i in 0..n {
            for j in 0..n {
                for k in 0..m {
                    if students[i][k] == mentors[j][k] {
                        a[i][j] += 1; }}}}

        let mut mate = vec![usize::MAX; n];
        let mut lx = (0..n).map(|i| *a[i].iter().max().unwrap()).collect::<Vec<i32>>();
        let mut ly = vec![0; n];
        let mut slack = vec![0; n];
        let mut fx = vec![false; n];
        let mut fy = vec![false; n];
        for i in 0..n {
            // fill requires 1.50
            //slack.fill(i32::MAX);
            for j in 0..n { slack[j] = i32::MAX; }
            loop {
                for j in 0..n { fx[j] = false; fy[j] = false; }
                if augment(n, i, &mut mate, &mut slack, &mut lx, &mut ly, &mut fx, &mut fy,&a) { break; }
                let mut d = i32::MAX;
                for j in 0..n {
                    if !fy[j] && slack[j] < d {
                        d = slack[j]; }}
                for j in 0..n {
                    if fx[j] { lx[j] -= d; }
                    if fy[j] { ly[j] += d; }
                    else { slack[j] -= d; }
                }
            }
        }
        lx.iter().sum::<i32>()+ly.iter().sum::<i32>()
    }
}
