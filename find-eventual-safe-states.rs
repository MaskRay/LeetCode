// Find Eventual Safe States
impl Solution {
    pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
        fn dfs(u: usize, graph: &Vec<Vec<i32>>, vis: &mut Vec<i8>) -> bool {
            if vis[u] != 0 { return vis[u] == 1; }
            vis[u] = 1;
            if graph[u].iter().any(|&v| dfs(v as usize, graph, vis)) { return true; }
            vis[u] = 2;
            false
        }
        let mut vis: Vec<i8> = vec![0; graph.len()];
        (0..graph.len()).filter(|&i| !dfs(i, &graph, &mut vis)).map(|i| i as i32).collect()
    }
}
