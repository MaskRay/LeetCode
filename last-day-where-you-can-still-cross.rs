// Last Day Where You Can Still Cross
impl Solution {
    pub fn latest_day_to_cross(row: i32, col: i32, cells: Vec<Vec<i32>>) -> i32 {
        fn find(uf: &mut [usize], mut x: usize) -> usize {
          while uf[x] != x {
            uf[x] = uf[uf[x]];
            x = uf[x];
          }
          x
        }
        fn unite(uf: &mut [usize], mut x: usize, mut y: usize) {
          x = find(uf, x);
          y = find(uf, y);
          uf[x] = y;
        }

        let row = row as usize;
        let col = col as usize;
        let src = row*col;
        let mut uf = vec![0; src+2];
        let mut valid = vec![false; src+2];

        for i in 0..src+2 { uf[i] = i; }
        for (i, cell) in cells.into_iter().enumerate().rev() {
            let x = (cell[0]-1) as usize;
            let y = (cell[1]-1) as usize;
            let id = x*col as usize+y;
            valid[id] = true;
            if x > 0 && valid[id-col] { unite(&mut uf[..], id, id-col); }
            if x+1 < row && valid[id+col] { unite(&mut uf[..], id, id+col); }
            if y > 0 && valid[id-1] { unite(&mut uf[..], id, id-1); }
            if y+1 < col && valid[id+1] { unite(&mut uf[..], id, id+1); }
            if x == 0 { unite(&mut uf[..], id, src); }
            if x == row-1 { unite(&mut uf[..], id, src+1); }
            if find(&mut uf, src) == find(&mut uf, src+1) { return i as i32; }
        }
        0
    }
}
