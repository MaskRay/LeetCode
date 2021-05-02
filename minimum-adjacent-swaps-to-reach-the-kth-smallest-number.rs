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
        let n = num.len();
        let mut a = vec![0; n];
        for i in 0..n {
            for j in 0..n {
                if num[j] == num1[i] {
                    num[j] = b' ';
                    a[i] = j;
                    break;
                }
            }
        }
        let mut ans = 0;
        for j in 0..n {
            for i in 0..j {
                if a[i] > a[j] {
                    ans += 1; } } }
        ans
    }
}
