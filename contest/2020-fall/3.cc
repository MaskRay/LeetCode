// 数字游戏
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)

class Solution {
public:
  vector<int> numsGame(vector<int>& nums) {
    int n = nums.size();
    long s0 = nums[0], s1 = 0;
    priority_queue q0{less{}, vector{nums[0]}};
    priority_queue q1{greater{}, vector<int>{}};
    vector ret{0};
    FOR(i, 1, n) {
      int x = nums[i]-i;
      if (x < q0.top()) {
        q0.push(x);
        s0 += x;
        if (q0.size() == q1.size()+2) {
          q1.push(q0.top());
          s1 += q0.top();
          s0 -= q0.top();
          q0.pop();
        }
      } else {
        q1.push(x);
        s1 += x;
        if (q1.size() == q0.size()+1) {
          q0.push(q1.top());
          s0 += q1.top();
          s1 -= q1.top();
          q1.pop();
        }
      }
      ret.push_back((i%2 ? s1-s0 : s1-s0+q0.top()) % 1000000007);
    }
    return ret;
  }
};
