impl Solution {
    pub fn largest_path_value(colors: String, edges: Vec<Vec<i32>>) -> i32 {
        let n = colors.len();
        let mut deg = vec![0; n];
        let mut head = vec![0; n];
        let mut es: Vec<(usize, usize)> = vec![(0,0)];
        for e in edges.iter() {
            deg[e[1] as usize] += 1;
            es.push((e[1] as usize, head[e[0] as usize]));
            head[e[0] as usize] = es.len()-1;
        }
        let mut q = vec![];
        for i in 0..n {
            if deg[i] == 0 {
                q.push(i); }}
        let mut i = 0;
        while i < q.len() {
            let u = q[i];
            i += 1;
            let mut j = head[u];
            while j != 0 {
                let v = es[j].0;
                j = es[j].1;
                deg[v] -= 1;
                if deg[v] == 0 { q.push(v); }
            }
        }
        if q.len() != n { return -1; }

        let mut ans = 0;
        for c in b'a'..(b'z'+1) {
            let mut dp = vec![0; n];
            for &u in q.iter() {
                if colors.as_bytes()[u] == c { dp[u] += 1; }
                let mut j = head[u];
                while j != 0 {
                    let v = es[j].0;
                    j = es[j].1;
                    dp[v] = dp[v].max(dp[u]);
                }
            }
            ans = dp.iter().fold(ans, |acc,&v| acc.max(v));
        }
        ans
    }
}
