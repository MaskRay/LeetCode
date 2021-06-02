// Stone Game VIII
impl Solution {
    pub fn stone_game_viii(mut a: Vec<i32>) -> i32 {
        let n = a.len();
        for i in 1..n { a[i] += a[i-1]; }
        a[1..n-1].iter().rev().fold(a[n-1], |s,x| s.max(x-s))
    }
}
