// Longest Word in Dictionary through Deleting
impl Solution {
    pub fn find_longest_word(s: String, dictionary: Vec<String>) -> String {
        let mut p = vec![0; dictionary.len()];
        let ws: Vec<&[u8]> = dictionary.iter().map(|s| s.as_bytes()).collect();
        for &c in s.as_bytes().iter() {
            ws.iter().enumerate().for_each(|(i,w)| if p[i] < w.len() && w[p[i]] == c {p[i]+=1;});
        }
        String::from_utf8_lossy(
            ws.into_iter().zip(p.iter()).fold(&[], |acc,(w,&i)|
                if w.len()==i && (w.len()>acc.len() || w.len()==acc.len() && w < acc) {w} else {acc})
        ).into_owned()
    }
}
