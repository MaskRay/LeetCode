// Maximum Element After Decreasing and Rearranging
impl Solution {
    pub fn maximum_element_after_decrementing_and_rearranging(mut a: Vec<i32>) -> i32 {
        a.sort_unstable();
        a.into_iter().fold(0, |acc,v| v.min(acc+1))
    }
}

///

impl Solution {
    pub fn maximum_element_after_decrementing_and_rearranging(mut a: Vec<i32>) -> i32 {
        a.sort_unstable();
        a.iter().enumerate().fold(a.len(), |acc,(i,&v)| acc.min(a.len()-1-i+v as usize)) as i32
    }
}
