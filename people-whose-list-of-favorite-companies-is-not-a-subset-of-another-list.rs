// People Whose List of Favorite Companies Is Not a Subset of Another List
impl Solution {
    pub fn people_indexes(favorite_companies: Vec<Vec<String>>) -> Vec<i32> {
        use std::collections::HashMap;
        let n = favorite_companies.len();
        let mut a = vec![vec![]; n];
        let mut c2i: HashMap<String, usize> = HashMap::new();
        for (i,cs) in favorite_companies.iter().enumerate() {
            for c in cs.iter() {
                let len = c2i.len();
                let j = *c2i.entry(c.clone()).or_insert(len);
                a[i].push(j);
            }
        }
        for i in 0..n { a[i].sort_unstable(); }
        let mut ans = vec![];
        for i in 0..n {
            let mut ok = true;
            for j in 0..n {
                if i == j { continue; }
                ok = false;
                let mut k = 0;
                for &c in a[i].iter() {
                    while k < a[j].len() && a[j][k] < c { k += 1; }
                    if k == a[j].len() || a[j][k] != c { ok = true; break; }
                }
                if !ok { break; }
            }
            if ok { ans.push(i as i32); }
        }
        ans
    }
}
