// Minimum Space Wasted From Packaging
impl Solution {
    pub fn min_wasted_space(mut ps: Vec<i32>, boxes: Vec<Vec<i32>>) -> i32 {
        use std::{i64,iter};
        use std::cmp::Ordering::{Less,Greater};
        ps.sort_unstable();
        let s: Box<[i64]> = iter::once(0).chain(ps.iter().scan(0, |s,&y| { *s += y as i64; Some(*s) })).collect();
        let mut ans = i64::MAX;
        for mut bs in boxes.into_iter() {
            bs.sort_unstable();
            let mut last = 0;
            let mut sum = 0;
            for &b in bs.iter() {
                // let i = ps.partition_point(|&x| x <= b);
                let i = ps[last..].binary_search_by(|&x| if x <= b { Less } else { Greater }).unwrap_or_else(|i| i) + last;
                sum += b as i64*(i-last) as i64 - s[i]+s[last];
                last = i;
                if i == ps.len() { ans = ans.min(sum); break; }
            }
        }
        if ans == i64::MAX { -1 } else { (ans % 1000000007) as i32 }
    }
}

///

impl Solution {
    pub fn min_wasted_space(mut ps: Vec<i32>, boxes: Vec<Vec<i32>>) -> i32 {
        use std::{i64,iter};
        use std::cmp::Ordering::{Less,Greater};
        ps.sort_unstable();
        let s: Box<[i64]> = iter::once(0).chain(ps.iter().scan(0, |s,&y| { *s += y as i64; Some(*s) })).collect();
        let mut ans = i64::MAX;
        for mut bs in boxes.into_iter() {
            bs.sort_unstable();
            let mut last = 0;
            let mut sum = 0;
            for &b in bs.iter() {
                let mut l = last; let mut h = ps.len(); let mut k = 1;
                while l+k < h {
                    if ps[l+k] <= b { l += k+1; }
                    else { h = l+k; }
                    k <<= 1;
                }
                // let i = ps[l..h].partition_point(|&x| x <= b) + l;
                let i = ps[l..h].binary_search_by(|&x| if x <= b { Less } else { Greater }).unwrap_or_else(|i| i) + l;
                sum += b as i64*(i-last) as i64 - s[i]+s[last];
                last = i;
                if i == ps.len() { ans = ans.min(sum); break; }
            }
        }
        if ans == i64::MAX { -1 } else { (ans % 1000000007) as i32 }
    }
}
