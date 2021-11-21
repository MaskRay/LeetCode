// Range Frequency Queries
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)
using pii = pair<int, int>;

class RangeFreqQuery {
  vector<pii> a;
public:
  RangeFreqQuery(vector<int>& arr) {
    REP(i, arr.size())
      a.emplace_back(arr[i], i);
    sort(ALL(a));
  }
  int query(int left, int right, int value) {
    return upper_bound(ALL(a), pii{value, right}) - lower_bound(ALL(a), pii{value, left});
  }
};
