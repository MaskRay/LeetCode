// Checking Existence of Edge Length Limited Paths
impl Solution {
    pub fn distance_limited_paths_exist(n: i32, mut es: Vec<Vec<i32>>, qs: Vec<Vec<i32>>) -> Vec<bool> {
        fn find(uf: &mut Vec<usize>, mut x: usize) -> usize {
            while uf[x] != x {
                uf[x] = uf[uf[x]];
                x = uf[x];
            }
            x
        }
        es.sort_unstable_by_key(|e| e[2]);
        let mut pi: Vec<usize> = (0..qs.len()).collect();
        pi.sort_unstable_by_key(|&i| qs[i][2]);
        let mut uf: Vec<usize> = (0..n as usize).collect();
        let mut ans = vec![false; qs.len()];
        let mut j = 0;
        for i in pi {
            while j < es.len() && es[j][2] < qs[i][2] {
                let u = find(&mut uf, es[j][0] as usize);
                let v = find(&mut uf, es[j][1] as usize);
                uf[u] = v;
                j += 1;
            }
            ans[i] = find(&mut uf, qs[i][0] as usize) == find(&mut uf, qs[i][1] as usize);
        }
        ans
    }
}
