// Maximum Genetic Difference Query
impl Solution {
    pub fn max_genetic_difference(parents: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        const LN: usize = 18;
        fn dfs(u: usize, dep: i32, fenwick: &mut Vec<i32>, g: &Vec<Vec<usize>>, q: &Vec<Vec<(i32, usize)>>, ans: &mut Vec<i32>) {
            let mut x = u;
            while x < 1<<LN { fenwick[x] += 1; x |= x+1; }
            for qu in q[u].iter() {
                let mut c = dep;
                x = 0;
                for i in (0..LN).rev().map(|i| 1<<i) {
                    let c1 = fenwick[x+i-1];
                    if c1 < c && ((qu.0 & i as i32) == 0 || c1 == 0) {
                        c -= c1;
                        x += i;
                    } else {
                        c = c1
                    }
                }
                ans[qu.1] = qu.0 ^ x as i32;
            }
            for &v in g[u].iter() {
                dfs(v, dep+1, fenwick, g, q, ans);
            }
            x = u;
            while x < 1<<LN { fenwick[x] -= 1; x |= x+1; }
        }

        let n = parents.len();
        let mut root = 0;
        let mut g = vec![vec![]; n];
        let mut q = vec![vec![]; n];
        for (i, p) in parents.into_iter().enumerate() {
            if p == -1 { root = i; }
            else { g[p as usize].push(i as usize); }
        }
        for (i, que) in queries.iter().enumerate() {
            q[que[0] as usize].push((que[1], i));
        }
        let mut fenwick = vec![0; 1<<LN];
        let mut ans = vec![0; queries.len()];
        dfs(root, 1, &mut fenwick, &g, &q, &mut ans);
        ans
    }
}
