// Minimum Interval to Include Each Query
/// scan line algorithm + heap
impl Solution {
    pub fn min_interval(mut intervals: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;
        intervals.sort_unstable_by_key(|itv| itv[0]);
        let mut i = 0;
        let mut h: BinaryHeap<Reverse<(i32, i32)>> = BinaryHeap::new();
        let mut queries: Vec<(usize, i32)> = queries.into_iter().enumerate().collect();
        queries.sort_unstable_by_key(|x| x.1);
        let mut ans = vec![-1; queries.len()];
        for (qi, q) in queries {
            while i < intervals.len() && intervals[i][0] <= q {
                h.push(Reverse((intervals[i][1]-intervals[i][0]+1, intervals[i][1])));
                i += 1;
            }
            while let Some(Reverse(top)) = h.peek() {
                if top.1 >= q { break; }
                h.pop();
            }
            if let Some(Reverse(top)) = h.peek() {
                ans[qi] = top.0;
            }
        }
        ans
    }
}

/// segment tree with range modification but no query
impl Solution {
    pub fn min_interval(intervals: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        use std::{i32,usize};
        let mut sorted = vec![];
        for itv in intervals.iter() {
            sorted.push(itv[0]);
            sorted.push(itv[1]+1);
        }
        sorted.sort_unstable();
        sorted.dedup();
        let n = sorted.len();
        // partition_point is stable since 1.52.0
        let deflate = |key| -> usize { sorted.binary_search(&key).unwrap_or_else(|i| i) };

        let mut seg = vec![i32::MAX; 2*n];
        for itv in intervals.iter() {
            let mut l = deflate(itv[0]) + n-1;
            let mut r = deflate(itv[1]+1) + n;
            while (l ^ r) != 1 {
                if l%2 == 0 { seg[l^1] = seg[l^1].min(itv[1]-itv[0]+1); }
                if r%2 != 0 { seg[r^1] = seg[r^1].min(itv[1]-itv[0]+1); }
                l /= 2;
                r /= 2;
            }
        }
        for i in 2..2*n {
            seg[i] = seg[i].min(seg[i/2]);
        }

        queries.into_iter().map(|q| {
            let i = deflate(q+1)-1;
            if i == usize::MAX || seg[n+i] == i32::MAX { -1 } else { seg[n+i] }
        }).collect()
    }
}

/// union-find set
impl Solution {
    pub fn min_interval(mut intervals: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        use std::{i32,usize};
        let mut sorted = vec![];
        for itv in intervals.iter() {
            sorted.push(itv[0]);
            sorted.push(itv[1]+1);
        }
        sorted.sort_unstable();
        sorted.dedup();
        let n = sorted.len();
        // partition_point is stable since 1.52.0
        let deflate = |key| -> usize { sorted.binary_search(&key).unwrap_or_else(|i| i) };

        let mut uf: Vec<usize> = (0..n).collect();
        let mut len: Vec<i32> = vec![-1; n];
        fn find(uf: &mut Vec<usize>, mut x: usize) -> usize {
            while uf[x] != x {
                uf[x] = uf[uf[x]];
                x = uf[x];
            }
            x
        };
        intervals.sort_unstable_by_key(|itv| itv[1]-itv[0]);
        for itv in intervals.iter() {
            let mut l = deflate(itv[0]);
            let r = deflate(itv[1]+1);
            loop {
                l = find(&mut uf, l);
                if l >= r { break; }
                len[l] = itv[1]-itv[0]+1;
                uf[l] = l+1;
            }
        }

        queries.into_iter().map(|q| {
            let i = deflate(q+1)-1;
            if i == usize::MAX { -1 } else { len[i] }
        }).collect()
    }
}
