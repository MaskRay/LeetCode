// Change Minimum Characters to Satisfy One of Three Conditions
impl Solution {
    pub fn min_characters(a: String, b: String) -> i32 {
        let na = a.as_bytes().len();
        let nb = b.as_bytes().len();
        let mut ca = vec![0; 26];
        let mut cb = vec![0; 26];
        for c in a.into_bytes().iter() { ca[(c-b'a') as usize] += 1; }
        for c in b.into_bytes().iter() { cb[(c-b'a') as usize] += 1; }
        let mut pa = 0;
        let mut pb = 0;
        let mut ans = na-ca[25]+nb-cb[25];
        for i in 0..25 {
            pa += ca[i];
            pb += cb[i];
            ans = ans.min(na-pa+pb).min(nb-pb+pa).min(na-ca[i]+nb-cb[i]);
        }
        ans as i32
    }
}
