// Remove Invalid Parentheses
class Solution {
  unordered_set<string> res;
  void f(const string &s, string ss, int k, int left, int right, int state) {
    if (k == s.size()) {
      if (! left && ! right && ! state)
        res.insert(ss);
      return;
    }
    if (s[k] == '(') {
      if (left > 0)
        f(s, ss, k+1, left-1, right, state);
      f(s, ss+'(', k+1, left, right, state+1);
    } else if (s[k] == ')') {
      if (right > 0)
        f(s, ss, k+1, left, right-1, state);
      if (state > 0)
        f(s, ss+')', k+1, left, right, state-1);
    } else
      f(s, ss+s[k], k+1, left, right, state);
  }
public:
  vector<string> removeInvalidParentheses(string s) {
    int l = 0, r = 0;
    for (auto c: s)
      if (c == '(')
        l++;
      else if (c == ')')
        l ? l-- : r++;
    f(s, "", 0, l, r, 0);
    return vector<string>(res.begin(), res.end());
  }
};

/// O(|ans|). no superfluous enumeration

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
  vector<string> halves, res;
  vector<int> milestones, milestones2;
  int split;
  // enumerate valid left part: s[0 , split)
  // invariant: for close parentheses in s[0 , milestones[i]], at least `i+1` of them must be removed
  void forward(const string &s, string ss, int k, int i, int removed, bool can) {
    if (k == split) {
      halves.push_back(ss);
      return;
    }
    if (s[k] == ')') {
      int ii = k == milestones[i] ? i+1 : i;
      if (can && removed < milestones.size()) // prefixes of continuous close parentheses can be removed, other parts are disallowed
        forward(s, ss, k+1, ii, removed+1, true);
      if (k < milestones[i] || removed > i) // if k == milestones[i], comply with the invariant
        forward(s, ss+s[k], k+1, ii, removed, false);
    } else
      forward(s, ss+s[k], k+1, i, removed, true);
  }
  // enumerate valid right part: s[split, n)
  // for open parentheses in s[milestones2[i] , n), at least `i+1` of them must be removed
  void backward(const string &s, string ss, int k, int i, int removed, bool can) {
    if (k == split) {
      reverse(ss.begin(), ss.end());
      for (auto &x: halves)
        res.push_back(x+ss);
      return;
    }
    k--;
    if (s[k] == '(') {
      int ii = i < milestones2.size() && k == milestones2[i] ? i+1 : i;
      if (can && removed < milestones2.size()) // suffixes of continuous open parentheses can be removed, other parts are disallowed
        backward(s, ss, k, ii, removed+1, true);
      if (i == milestones2.size() || k > milestones2[i] || removed > i) // if k == milestones2[i], comply with the invariant
        backward(s, ss+s[k], k, ii, removed, false);
    } else
      backward(s, ss+s[k], k, i, removed, true);
  }
public:
  vector<string> removeInvalidParentheses(string s) {
    int unmatched = 0;
    REP(i, s.size())
      if (s[i] == '(')
        unmatched++;
      else if (s[i] == ')') {
        if (unmatched > 0)
          unmatched--;
        else
          milestones.push_back(i);
      }
    split = milestones.empty() ? 0 : milestones.back()+1;
    unmatched = 0;
    ROF(i, split, s.size())
      if (s[i] == ')')
        unmatched++;
      else if (s[i] == '(') {
        if (unmatched > 0)
          unmatched--;
        else
          milestones2.push_back(i);
      }
    forward(s, "", 0, 0, 0, true);
    backward(s, "", s.size(), 0, 0, true);
    return res;
  }
};
