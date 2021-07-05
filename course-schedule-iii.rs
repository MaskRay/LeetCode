// Course Schedule III
impl Solution {
    pub fn schedule_course(mut courses: Vec<Vec<i32>>) -> i32 {
        use std::collections::BinaryHeap;
        courses.sort_unstable_by_key(|x| x[1]);
        let mut h = BinaryHeap::new();
        let mut s = 0;
        for c in courses.into_iter() {
            s += c[0];
            h.push(c[0]);
            if s > c[1] {
                s -= h.pop().unwrap();
            }
        }
        h.len() as i32
    }
}
