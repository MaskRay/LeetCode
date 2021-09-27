// Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
impl Solution {
    pub fn min_flips(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let row = (1<<n)-1;
        let mut bgn = 0;
        let mut full = 0;
        for i in 0..m {
            for j in 0..n {
                if mat[i][j] != 0 { bgn |= 1 << i*(n+1)+j; }
                full |= 1 << i*(n+1)+j; }}
        let mut ans = std::u32::MAX;
        for k0 in 0..1i32<<(m*n) {
            let mut k = 0;
            for i in 0..m { k |= (k0>>i*n & row) << i*(n+1); }
            if ((k ^ k>>1 ^ k<<1 ^ k>>n+1 ^ k<<n+1) & full) == bgn {
                ans = ans.min(k.count_ones());
            }
        }
        if ans == std::u32::MAX {-1} else {ans as i32}
    }
}

///

impl Solution {
    pub fn min_flips(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let row = (1<<n)-1;
        let mut bgn = 0;
        let mut full = 0;
        for i in 0..m {
            for j in 0..n {
                if mat[i][j] != 0 { bgn |= 1 << i*(n+1)+j; }
                full |= 1 << i*(n+1)+j; }}
        for ans in 0..=m*n {
            let mut k0 = (1i32<<ans)-1;
            loop {
                let mut k = 0;
                for i in 0..m { k |= (k0>>i*n & row) << i*(n+1); }
                if ((k ^ k>>1 ^ k<<1 ^ k>>n+1 ^ k<<n+1) & full) == bgn { return ans as i32; }
                let r = k0 & -k0;
                k0 += r;
                if k0 == 0 || k0 >= 1<<m*n { break; }
                let z = (k0 & -k0) - r;
                k0 = k0 | z >> z.trailing_zeros()+1;
            }
        }
        -1
    }
}
