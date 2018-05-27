// Find And Replace in String
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
    int m = indexes.size();
    vector<int> p(m);
    iota(ALL(p), 0);
    sort(ALL(p), [&](int a, int b) {return indexes[a] < indexes[b];});
    string r;
    int n = S.size();
    for (int j = 0, i = 0; i < n; ) {
      while (j < indexes.size() && indexes[p[j]] < i) j++;
      while (j < indexes.size() && indexes[p[j]] == i) {
        if (i + sources[p[j]].size() <= n &&
          S.compare(i, sources[p[j]].size(), sources[p[j]]) == 0) {
          i += sources[p[j]].size();
          r += targets[p[j]];
          goto next;
        }
        j++;
      }
      r += S[i++];
    next:;
    }
    return r;
  }
};
