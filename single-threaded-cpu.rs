impl Solution {
    pub fn get_order(tasks: Vec<Vec<i32>>) -> Vec<i32> {
        use std::collections::BinaryHeap;
        use std::cmp::Reverse;
        let n = tasks.len();
        let mut tasks: Vec<(i32, i32, usize)> = tasks
            .into_iter().enumerate().map(|(i,a)| (a[0], a[1], i)).collect();
        tasks.sort_by_key(|v| v.0);

        let mut q: BinaryHeap<Reverse<(i32, usize)>> = BinaryHeap::new();
        let mut ans = Vec::new();
        let mut tick = 0;
        let mut i = 0;
        while ans.len() != n {
            if i < n && tasks[i].0 <= tick {
                q.push(Reverse((tasks[i].1, tasks[i].2)));
                i += 1;
            } else if !q.is_empty() {
                let x = q.pop().unwrap().0;
                ans.push(x.1 as i32);
                tick += x.0;
            } else {
                tick = tasks[i].0;
            }
        }
        ans
    }
}
