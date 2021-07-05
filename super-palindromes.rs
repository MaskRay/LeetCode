// Super Palindromes
impl Solution {
    pub fn superpalindromes_in_range(left: String, right: String) -> i32 {
        fn f(mut i: i64, mut j: i64) -> i64 {
            while j > 0 {
                i = i*10+j%10;
                j /= 10;
            }
            i
        }
        fn is(i: i64) -> bool {
            let mut t = i;
            let mut j = 0;
            while t > 0 {
                j = j*10+t%10;
                t /= 10;
            }
            i == j
        }
        let left = left.parse::<i64>().unwrap();
        let right = right.parse::<i64>().unwrap();
        let mut sqrtl = (left as f64).sqrt() as i64;
        let mut sqrtr = (right as f64).sqrt() as i64;
        if sqrtl*sqrtl < left { sqrtl += 1; }
        if sqrtr*sqrtr > right { sqrtr -= 1; }
        let mut i = 1;
        let mut x = 0;
        let mut ans = 0;
        while x <= sqrtr {
            x = f(i, i);
            if x >= sqrtl && x <= sqrtr && is(x*x) { ans += 1; }
            x = f(i, i/10);
            if x >= sqrtl && x <= sqrtr && is(x*x) { ans += 1; }
            i += 1;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    pub fn test() {
        assert_eq!(Solution::superpalindromes_in_range("38455498359".to_string(), "1000000002000000000".to_string()), 45);
        assert_eq!(Solution::superpalindromes_in_range("38455498359".to_string(), "1000000002000000001".to_string()), 46);
    }
}
