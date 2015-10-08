// Verify Preorder Sequence in Binary Search Tree
class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int p = INT_MIN;
    stack<int> s;
    for (auto x: preorder) {
      if (x < p)
        return false;
      while (! s.empty() && s.top() < x) {
        p = s.top();
        s.pop();
      }
      s.push(x);
    }
    return true;
  }
};
