// Sum of Floored Pairs
impl Solution {
    pub fn sum_of_floored_pairs(nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut a = vec![0; 100001];
        let mut freq: HashMap<i32, i32> = HashMap::with_capacity(nums.len());
        for &x in nums.iter() { *freq.entry(x).or_insert(0) += 1; }
        for (&x, &f) in freq.iter() {
            for i in (x as usize..a.len()).step_by(x as usize) {
                a[i] += f as usize; }}
        for i in 1..a.len() { a[i] += a[i-1]; }
        (nums.iter().fold(0, |acc,&x| acc+a[x as usize]) % 1000000007) as i32
    }
}

///

impl Solution {
    pub fn sum_of_floored_pairs(nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut freq: HashMap<i32, i32> = HashMap::new();
        let mut freqs = vec![0; 100001];
        for &x in nums.iter() {
            *freq.entry(x).or_insert(0) += 1;
            freqs[x as usize] += 1;
        }
        for i in 1..freqs.len() { freqs[i] += freqs[i-1]; }
        (freq.iter().fold(0, |ans,(&x,&f)| ans + (x as usize..freqs.len()).step_by(x as usize)
           .fold(0, |acc,i| acc+nums.len()-freqs[i-1]) * f as usize) % 1000000007) as i32
    }
}
