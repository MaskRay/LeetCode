// Binary Tree Postorder Traversal
class Solution {
public:
  vector<int> postorderTraversal(TreeNode *p) {
    vector<int> a;
    stack<TreeNode *> s;
    for(;;) {
      while (p) {
        s.push(p);
        p = p->left;
      }
      while (! s.empty() && s.top()->right == p) {
        p = s.top();
        s.pop();
        a.push_back(p->val);
      }
      if (s.empty()) break;
      p = s.top()->right;
    }
    return a;
  }
};
