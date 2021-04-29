impl Solution {
    pub fn max_building(n: i32, restrictions: Vec<Vec<i32>>) -> i32 {
        use std::cmp;
        let mut a: Vec<(i32, i32)> = restrictions.into_iter().map(|x| (x[0], x[1])).collect();
        a.push((1, 0));
        a.push((n, n-1));
        a.sort_unstable();
        let mut ans = 0;
        for i in 0..a.len()-1 {
            a[i+1].1 = a[i+1].1.min(a[i+1].0-a[i].0+a[i].1);
        }
        for i in (1..a.len()).rev() {
            let d = a[i].0-a[i-1].0;
            a[i-1].1 = a[i-1].1.min(d+a[i].1);
            ans = ans.max(a[i-1].1+a[i].1+d >> 1);
        }
        ans
    }
}
