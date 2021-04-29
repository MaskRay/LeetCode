impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> Vec<String> {
        struct Sol<'a> { dict: &'a [String], ans: Vec<String>, parts: Vec<&'a str> }
        impl<'a> Sol<'a> {
            fn dfs(self: &mut Self, s: &str) {
                if s.is_empty() {
                    self.ans.push(self.parts.join(" "));
                    return;
                }
                for w in self.dict.iter() {
                    if s.starts_with(w) {
                        self.parts.push(w);
                        self.dfs(&s[w.len()..]);
                        self.parts.pop();
                    }
                }
            }
        }
        let mut sol = Sol { dict: &word_dict, ans: vec![], parts: vec![] };
        sol.dfs(&s);
        sol.ans
    }
}
