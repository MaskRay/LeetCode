// Prime Palindrome
impl Solution {
    pub fn prime_palindrome(n: i32) -> i32 {
        fn is_prime(n: i32) -> bool {
            let mut i = 3;
            loop {
                if n/i < i { break; }
                if n%i == 0 { return false; }
                i += 2;
            }
            true
        }
        if n <= 2 { return 2; }
        if 7 < n && n <= 11 { return 11; }
        for mut i in 3.. {
            let mut s = i;
            loop {
                i /= 10;
                if i == 0 { break; }
                s = s*10+i%10;
            }
            if s >= n && s%2!=0 && is_prime(s) { return s; }
        }
        -1
    }
}
