// Painting the Walls
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<int> f(n*2, INT_MAX/2);
    f[0] = 0;
    REP(i, n) {
      int x = min(time[i]+1, n);
      ROF(j, x, n*2)
        f[j] = min(f[j], f[j-x]+cost[i]);
    }
    return *min_element(f.begin()+n, f.end());
  }
};
