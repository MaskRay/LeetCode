///
#[derive(Default)]
struct Trie { c: [Option<Box<Self>>; 26], is_word: bool }

impl Solution {
    pub fn find_all_concatenated_words_in_a_dict(mut words: Vec<String>) -> Vec<String> {
        words.sort_by_key(|w| w.len());
        let mut trie: Trie = Default::default();
        let mut vis: Vec<isize> = vec![0; words.last().unwrap().len()+1];
        let mut q: Vec<usize> = vec![];
        let mut tick = 0;
        let mut ans: Vec<String> = vec![];
        for ww in words.into_iter() {
            if ww.is_empty() { continue; }
            let w = ww.as_bytes();
            q.clear();
            q.push(0);
            tick += 1;
            while let Some(bgn) = q.pop() {
                let mut t: &Trie = &mut trie;
                for i in bgn..w.len() {
                    if let Some(t1) = &t.c[(w[i]-b'a') as usize] {
                        t = t1;
                        if t.is_word && vis[i+1] != tick {
                            vis[i+1] = tick;
                            q.push(i+1);
                        }
                    } else {
                        break;
                    }
                }
                if vis[w.len()] == tick {
                    ans.push(ww.clone());
                    break;
                }
            }

            let mut t = &mut trie;
            for c in w.iter().map(|ch| (ch-b'a') as usize) {
                t = t.c[c].get_or_insert_with(|| Default::default());
            }
            t.is_word = true;
        }
        ans
    }
}

/// memoization

#[derive(Default)]
struct Trie { c: [Option<Box<Self>>; 26], is_word: bool }

impl Solution {
    pub fn find_all_concatenated_words_in_a_dict(mut words: Vec<String>) -> Vec<String> {
        struct St<'a> { root: &'a Trie, memo: &'a mut [(isize,bool)], tick: isize, w: &'a [u8] };
        fn dfs(st: &mut St, mut t: &Trie, bgn: usize) -> bool {
            if st.memo[bgn].0 == st.tick { return st.memo[bgn].1 }
            let w = st.w;
            if w.len() == bgn { return true; }
            let mut ans = false;
            for i in bgn..w.len() {
                if let Some(t1) = &t.c[(w[i]-b'a') as usize] {
                    t = t1;
                    if t1.is_word && dfs(st, st.root, i+1) {
                        ans = true;
                        break;
                    }
                } else {
                    break;
                }
            }
            st.memo[bgn] = (st.tick, ans);
            ans
        }

        words.sort_by_key(|w| w.len());
        let mut trie: Trie = Default::default();
        let mut memo: Vec<(isize,bool)> = vec![(0, false); words.last().unwrap().len()+1];
        let mut tick = 0;
        let mut ans: Vec<String> = vec![];
        for w in words.into_iter() {
            tick += 1;
            let mut st = St { root: &trie, memo: &mut memo, tick, w: w.as_bytes() };
            if w.len() > 0 && dfs(&mut st, &trie, 0) {
                ans.push(w.to_owned());
            }
            let mut t = &mut trie;
            for c in w.as_bytes().iter().map(|ch| (ch-b'a') as usize) {
                t = t.c[c].get_or_insert_with(|| Default::default());
            }
            t.is_word = true;
        }
        ans
    }
}
