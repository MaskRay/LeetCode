// Sum of Subarray Minimums
impl Solution {
    pub fn sum_subarray_mins(a: Vec<i32>) -> i32 {
        let mut st: Vec<(i32, i32)> = vec![];
        let mut sum: i64 = 0;
        let mut ans = 0;
        for &cur in a.iter() {
            let mut cnt = 1;
            while let Some(&(x, c)) = st.last() {
                if x < cur { break; }
                st.pop();
                cnt += c;
                sum -= x as i64 * c as i64;
            }
            st.push((cur, cnt));
            sum += cur as i64 * cnt as i64;
            ans += sum;
        }
        (ans % 1000000007) as i32
    }
}
