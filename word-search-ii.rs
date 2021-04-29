#[derive(Default)]
struct Trie { c: [Option<Box<Self>>; 26], num: usize, w: Option<String> }

impl Solution {
    pub fn find_words(mut board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        let mut trie: Trie = Default::default();
        for w in words.into_iter() {
            let mut x = &mut trie;
            for c in w.as_bytes().iter().map(|ch| (ch-b'a') as usize) {
                x = x.c[c].get_or_insert_with(|| Default::default());
                x.num += 1;
            }
            x.w = Some(w)
        }

        fn dfs(b: &mut Vec<Vec<char>>, ans: &mut Vec<String>, mut t: &mut Trie,
               x: usize, y: usize) -> usize {
            let ch = b[x][y];
            if ch == '.' { return 0; }
            if let Some(t1) = t.c[(ch as u8-b'a') as usize] {
                t = &mut *t1;
                if t.num == 0 { return 0; }
                let mut num = 0;
                if let Some(w) = t.w.take() {
                    ans.push(w);
                    num += 1;
                }
                b[x][y] = '.';
                if x > 0 { num += dfs(b, ans, t, x-1, y); }
                if x+1 < b.len() { num += dfs(b, ans, t, x+1, y); }
                if y > 0 { num += dfs(b, ans, t, x, y-1); }
                if y+1 < b[0].len() { num += dfs(b, ans, t, x, y+1); }
                b[x][y] = ch;
                t.num -= num;
                return num;
            }
            0
        }

        let m = board.len();
        let n = board[0].len();
        let mut ans = vec![];
        for x in 0..m {
            for y in 0..n {
                dfs(&mut board, &mut ans, &mut trie, x, y); } }
        ans
    }
}
