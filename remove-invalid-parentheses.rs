impl Solution {
    pub fn remove_invalid_parentheses(s: String) -> Vec<String> {
        fn dfs(s: Vec<u8>, ans: &mut Vec<String>, par: u8, ii: usize, jj: usize) {
            let mut c = 0i32;
            for i in ii..s.len() {
                if s[i] == par { c += 1; }
                else if s[i] == (par^1) { c -= 1; }
                if c < 0 {
                    for j in jj..=i {
                        if s[j] == (par^1) && (j == jj || s[j-1] != (par^1)) {
                            let mut s1 = s.clone();
                            s1.remove(j);
                            dfs(s1, ans, par, i, j);
                        }
                    }
                    return;
                }
            }
            let mut s1 = s.clone();
            s1.reverse();
            if par == b'(' {
                dfs(s1, ans, par^1, 0, 0);
            } else {
                ans.push(String::from_utf8_lossy(&s1).into_owned());
            }
        }
        let mut ans = vec![];
        dfs(Vec::from(s.as_bytes()), &mut ans, b'(', 0, 0);
        ans
    }
}
