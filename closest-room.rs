// Closest Room
impl Solution {
    pub fn closest_room(mut rooms: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        use std::collections::BTreeSet;
        rooms.sort_unstable_by_key(|r| -r[1]);
        let mut queries: Vec<_> = queries.into_iter().enumerate().collect();
        queries.sort_unstable_by_key(|(_,q)| -q[1]);
        let mut tree = BTreeSet::new();
        let mut ret = vec![-1; queries.len()];
        let mut j = 0;
        for (i, q) in queries {
            while j < rooms.len() && rooms[j][1] >= q[1] {
                tree.insert(rooms[j][0]);
                j += 1;
            }
            if tree.is_empty() { continue; }
            if let Some(&x) = tree.range(..q[0]).next_back() {
                ret[i] = x;
            }
            if let Some(&x) = tree.range(q[0]..).next() {
                if ret[i] == -1 || q[0]-ret[i] > x-q[0] {
                    ret[i] = x;
                }
            }
        }
        ret
    }
}
