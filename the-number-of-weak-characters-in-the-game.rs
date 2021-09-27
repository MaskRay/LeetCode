// The Number of Weak Characters in the Game
impl Solution {
    pub fn number_of_weak_characters(mut properties: Vec<Vec<i32>>) -> i32 {
        properties.sort_unstable_by_key(|x| (x[0],-x[1]));
        let mut a = vec![];
        let mut ans = 0;
        for p in properties.into_iter() {
            while !a.is_empty() && a[a.len()-1] < p[1] {
                a.pop();
                ans += 1;
            }
            a.push(p[1]);
        }
        ans
    }
}
