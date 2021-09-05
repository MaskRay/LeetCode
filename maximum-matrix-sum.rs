// Maximum Matrix Sum
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut sum = 0;
        let mut neg_num = 0;
        let mut abs_min = std::i32::MAX;
        for row in matrix.iter() {
            for &cell in row.iter() {
                if cell >= 0 {
                    sum += cell as i64;
                    abs_min = abs_min.min(cell);
                } else {
                    sum -= cell as i64;
                    neg_num ^= 1;
                    abs_min = abs_min.min(-cell);
                }
            }
        }
        if neg_num != 0 {
            sum -= abs_min as i64 * 2;
        }
        sum
    }
}
