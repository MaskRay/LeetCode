impl Solution {
    fn next_permutation(a: &mut [u8]) {
        for i in (0..a.len()-1).rev() {
            if a[i] >= a[i+1] { continue; }
            let mut j = a.len()-1;
            while a[i] >= a[j] { j -= 1; }
            a.swap(i, j);
            a[i+1..].reverse();
            break;
        }
    }
    pub fn get_min_swaps(num: String, k: i32) -> i32 {
        let mut num: Vec<u8> = num.as_bytes().to_vec();
        let mut num1 = num.clone();
        for _ in 0..k {
            Self::next_permutation(&mut num1);
        }
        num1.into_iter().map(|x| {
            let j = num.iter().position(|&y| x == y).unwrap();
            num.remove(j);
            j as i32
        }).sum()
    }
}
