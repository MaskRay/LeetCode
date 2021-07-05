// Maximum Number of Removable Characters
impl Solution {
    pub fn maximum_removals(s: String, p: String, removable: Vec<i32>) -> i32 {
        let s = s.as_bytes();
        let p = p.as_bytes();
        let mut l = 0;
        let mut h = removable.len();
        let mut del = vec![false; s.len()];
        while l < h {
            let m = l+h+1 >> 1;
            for i in 0..m { del[removable[i] as usize] = true; }
            let mut j = 0;
            for i in 0..s.len() {
                if !del[i] && s[i] == p[j] {
                    j += 1;
                    if j == p.len() { break; }
                }
            }
            for i in 0..m { del[removable[i] as usize] = false; }
            if j == p.len() {
                l = m;
            } else {
                h = m-1;
            }
        }
        l as i32
    }
}
