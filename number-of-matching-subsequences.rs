// Number of Matching Subsequences
impl Solution {
    pub fn num_matching_subseq(s: String, words: Vec<String>) -> i32 {
        let s = s.as_bytes();
        let mut pi = [-1; 26];
        let mut dfa: Vec<[i32; 26]> = Vec::with_capacity(s.len()+1);
        unsafe { dfa.set_len(s.len()+1); }
        dfa[s.len()] = pi;
        for (i,&ch) in s.iter().enumerate().rev() {
            pi[(ch-b'a') as usize] = (i+1) as i32;
            dfa[i] = pi;
        }
        words.into_iter().fold(0, |acc,word| {
            let mut x = 0;
            for &ch in word.as_bytes().iter() {
                x = dfa[x as usize][(ch-b'a') as usize];
                if x < 0 { break; }
            }
            acc + if x >= 0 {1} else {0}
        })
    }
}
