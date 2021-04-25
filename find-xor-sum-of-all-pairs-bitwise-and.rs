impl Solution {
    pub fn get_xor_sum(arr1: Vec<i32>, arr2: Vec<i32>) -> i32 {
        use std::ops::BitXor;
        arr1.iter().fold(0, BitXor::bitxor) & arr2.iter().fold(0, BitXor::bitxor)
    }
}
