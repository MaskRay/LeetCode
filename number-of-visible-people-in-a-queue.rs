// Number of Visible People in a Queue
impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
        let mut st: Vec<usize> = vec![];
        let mut ans = vec![0; heights.len()];
        for (i, &h) in heights.iter().enumerate() {
            while st.len() > 0 && heights[*st.last().unwrap()] <= h {
                ans[st.pop().unwrap()] += 1;
            }
            if let Some(x) = st.last() {
                ans[*x] += 1;
            }
            st.push(i);
        }
        ans
    }
}

///

impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
        let mut st = vec![];
        let mut ans = vec![0; heights.len()];
        for (i, &h) in heights.iter().enumerate().rev() {
            let c = st.len();
            while st.len() > 0 && *st.last().unwrap() <= h {
                st.pop();
            }
            ans[i] = (c-st.len()) as i32 + if st.is_empty() {0} else {1};
            st.push(h);
        }
        ans
    }
}

///

impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
        let mut st = vec![];
        let mut ans = heights.into_iter().rev().map(|h| {
            let c = st.len();
            st.truncate(st.iter().rposition(|&x| x > h).and_then(|i| Some(i+1)).unwrap_or(0));
            st.push(h);
            (c+1-st.len()) as i32 + if st.len()==1 {0} else {1}
        }).collect::<Vec<_>>();
        ans.reverse();
        ans
    }
}
