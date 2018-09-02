// Orderly Queue
class Solution {
public:
  string orderlyQueue(string S, int K) {
    if (K > 1)
      sort(S.begin(), S.end());
    else {
      string r = S;
      for (auto _: S)
        S = min(S, r = r.substr(1) + r[0]);
    }
    return S;
  }
};
