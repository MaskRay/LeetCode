impl Solution {
    pub fn nth_ugly_number(n: i32) -> i32 {
        let mut a = vec![1];
        let mut i2 = 0;
        let mut i3 = 0;
        let mut i5 = 0;
        while a.len() < n as usize {
            let mn = (a[i2]*2).min(a[i3]*3).min(a[i5]*5);
            a.push(mn);
            if a[i2]*2 == mn { i2 += 1; }
            if a[i3]*3 == mn { i3 += 1; }
            if a[i5]*5 == mn { i5 += 1; }
        }
        *a.last().unwrap()
    }
}
