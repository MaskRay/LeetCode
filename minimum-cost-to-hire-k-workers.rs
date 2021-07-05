// Minimum Cost to Hire K Workers
use std::cmp::Ordering;

struct Ratio { num: i64, den: i64 }
impl Ord for Ratio {
    fn cmp(&self, o: &Self) -> Ordering {
        (self.num as i64 * o.den as i64).cmp(&(self.den as i64 * o.num as i64))
    }
}
impl PartialOrd for Ratio {
    fn partial_cmp(&self, o: &Self) -> Option<Ordering> {
        Some(self.cmp(o))
    }
}
impl PartialEq for Ratio {
    fn eq(&self, o: &Self) -> bool {
        self.cmp(o) == Ordering::Equal
    }
}
impl Eq for Ratio {}

impl Solution {
    pub fn mincost_to_hire_workers(quality: Vec<i32>, wage: Vec<i32>, k: i32) -> f64 {
        use std::collections::BinaryHeap;
        let k = k as usize;
        let n = quality.len();
        let mut a = (0..n).map(|i| Ratio{num: wage[i] as i64, den: quality[i] as i64}).collect::<Vec<Ratio>>();
        a.sort_unstable();
        let mut h = a[0..k].iter().map(|x| x.den).collect::<BinaryHeap<i64>>();
        let mut sum: i64 = h.iter().sum();
        let mut ans = Ratio{num: sum*a[k-1].num, den: a[k-1].den};
        for i in k..a.len() {
            sum += a[i].den;
            h.push(a[i].den);
            sum -= h.pop().unwrap();
            ans = ans.min(Ratio{num: sum*a[i].num, den: a[i].den});
        }
        ans.num as f64 / ans.den as f64
    }
}
