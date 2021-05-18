impl Solution {
    pub fn rotate(a: &mut Vec<Vec<i32>>) {
        a.reverse();
        let n = a.len();
        for i in 1..a.len() {
            let (before, after) = a.split_at_mut(i);
            for j in 0..i {
                std::mem::swap(&mut after[0][j], &mut before[j][i]);
            }
        }
    }
}
