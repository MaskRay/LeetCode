// Binary Tree Preorder Traversal
class Solution {
public:
  vector<int> preorderTraversal(TreeNode *p) {
    vector<int> a;
    stack<TreeNode *> s;
    for(;;) {
      while (p) {
        a.push_back(p->val);
        if (p->right)
          s.push(p->right);
        p = p->left;
      }
      if (s.empty()) break;
      p = s.top();
      s.pop();
    }
    return a;
  }
};
