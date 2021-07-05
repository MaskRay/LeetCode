// Minimum Cost to Change the Final Value of Expression
impl Solution {
    pub fn min_operations_to_flip(e: String) -> i32 {
        let mut isp = vec![0; 127];
        isp[b'&' as usize]=3; isp[b'|' as usize]=3; isp[b'(' as usize]=1;
        let mut icp = vec![0; 127];
        icp[b'&' as usize]=2; icp[b'|' as usize]=2; icp[b'(' as usize]=4; icp[b')' as usize]=1;
        let mut op = vec![b'\0'];
        let mut st = vec![];
        for &c in e.as_bytes().iter().chain(std::iter::once(&b'\0')) {
            if c == b'0' || c == b'1' {
                let v = (c-b'0') as i32;
                st.push((v, 1-v));
                continue;
            }
            while isp[op[op.len()-1] as usize] > icp[c as usize] {
                let y = st.pop().unwrap();
                let x = st.pop().unwrap();
                let c00 = x.0+y.0; let c01 = x.0+y.1;
                let c10 = x.1+y.0; let c11 = x.1+y.1;
                st.push(if op.pop().unwrap() == b'&' {
                    (c00.min(c01).min(c10), c11.min(c01+1).min(c10+1))
                } else {
                    (c00.min(c01+1).min(c10+1), c11.min(c01).min(c10))
                });
            }
            if isp[op[op.len()-1] as usize] == icp[c as usize] {
                op.pop();
            } else {
                op.push(c);
            }
        }
        let x = st.pop().unwrap();
        x.0.max(x.1)
    }
}

///

impl Solution {
    pub fn min_operations_to_flip(e: String) -> i32 {
        let mut isp = vec![0; 127];
        isp[b'&' as usize]=3; isp[b'|' as usize]=3; isp[b'(' as usize]=1;
        let mut icp = vec![0; 127];
        icp[b'&' as usize]=2; icp[b'|' as usize]=2; icp[b'(' as usize]=4; icp[b')' as usize]=1;
        let mut op = vec![b'\0'];
        let mut st = vec![];
        for &c in e.as_bytes().iter().chain(std::iter::once(&b'\0')) {
            if c == b'0' || c == b'1' {
                let v = (c-b'0') as i32;
                st.push((v, 1-v));
                continue;
            }
            while isp[op[op.len()-1] as usize] > icp[c as usize] {
                let y = st.pop().unwrap();
                let x = st.pop().unwrap();
                let c00 = x.0+y.0; let c01 = x.0+y.1;
                let c10 = x.1+y.0; let c11 = x.1+y.1;
                st.push(if op.pop().unwrap() == b'&' {
                    (c00.min(c01).min(c10), c11.min(c01+1).min(c10+1))
                } else {
                    (c00.min(c01+1).min(c10+1), c11.min(c01).min(c10))
                });
            }
            if isp[op[op.len()-1] as usize] == icp[c as usize] {
                op.pop();
            } else {
                op.push(c);
            }
        }
        let x = st.pop().unwrap();
        x.0.max(x.1)
    }
}
