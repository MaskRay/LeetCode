// Number of Orders in the Backlog
impl Solution {
    pub fn get_number_of_backlog_orders(orders: Vec<Vec<i32>>) -> i32 {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;
        let mut buy = BinaryHeap::new();
        let mut sell = BinaryHeap::new();
        for order in orders.into_iter() {
            if order[2] == 0 { buy.push((order[0], order[1])); }
            else { sell.push(Reverse((order[0], order[1]))); }
            while let (Some(tb), Some(ts)) = (buy.peek(), sell.peek()) {
                if (ts.0).0 > tb.0 { break; }
                let x = (ts.0).1.min(tb.1);
                if tb.1 == x { buy.pop(); }
                else { buy.peek_mut().unwrap().1 -= x; }
                if (ts.0).1 == x { sell.pop(); }
                else { (sell.peek_mut().unwrap().0).1 -= x; }
            }
        }
        ((buy.into_vec().iter().fold(0i64, |acc,x| acc + x.1 as i64) +
         sell.into_vec().iter().fold(0i64, |acc,Reverse(x)| acc + x.1 as i64)) % 1000000007) as i32
    }
}
