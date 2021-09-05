impl Solution {
    pub fn shortest_palindrome(s: String) -> String {
        let a = s.as_bytes();
        let n = a.len();
        let mut border = vec![0; n];
        let mut j = 0;
        for i in 1..n {
            while j >= 0 && a[i] != a[j as usize] {
                j = if j > 0 { border[j as usize-1] } else { -1 }; }
            j += 1;
            border[i] = j;
        }
        j = 0;
        for i in 0..n {
            while j >= 0 && a[n-1-i] != a[j as usize] {
                j = if j > 0 { border[j as usize-1] } else { -1 }; }
            j += 1;
        }
        let mut ss = String::from(&s[j as usize..n]).chars().rev().collect::<String>();
        ss.push_str(&s);
        ss
    }
}
