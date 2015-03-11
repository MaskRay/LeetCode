// Binary Tree Inorder Traversal
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *p) {
    vector<int> a;
    stack<TreeNode *> s;
    for(;;) {
      while (p) {
        s.push(p);
        p = p->left;
      }
      if (s.empty()) break;
      p = s.top();
      s.pop();
      a.push_back(p->val);
      p = p->right;
    }
    return a;
  }
};
