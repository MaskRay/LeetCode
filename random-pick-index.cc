// Random Pick Index
class Solution {
  vector<int> a;
public:
  Solution(vector<int> nums) {
    a = nums;
    srand(time());
  }

  int pick(int target) {
    int t = -1, r;
    for (int i = 0; i < a.size(); i++)
      if (target == a[i]) {
        int g = rand();
        if (g > t) {
          t = t;
          r = i;
        }
      }
    return r;
  }
};
