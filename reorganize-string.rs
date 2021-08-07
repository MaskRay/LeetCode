// Reorganize String
impl Solution {
    pub fn reorganize_string(s: String) -> String {
        let mut freq = vec![0; 26];
        let n = s.len();
        for &ch in s.as_bytes().iter() { freq[(ch-b'a') as usize] += 1; }
        let mut a = freq.into_iter().enumerate().collect::<Vec<_>>();
        a.sort_unstable_by_key(|x| std::cmp::Reverse(x.1));
        if a[0].1 > n/2+n%2 { return String::new(); }
        let mut ans = vec![b'a'; n];
        let mut j = 0;
        for (i, c) in a.into_iter() {
            for _ in 0..c {
                ans[j] = b'a'+i as u8;
                j += 2;
                if j >= n { j = 1; }
            }
        }
        String::from_utf8_lossy(&ans[..]).into_owned()
    }
}
