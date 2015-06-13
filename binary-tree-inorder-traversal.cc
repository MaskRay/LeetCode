// Binary Tree Inorder Traversal

// stack
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

// Morris in-order traversal
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* p) {
    vector<int> ret;
    while (p) {
      TreeNode *q = p->left;
      if (q) {
        while (q->right && q->right != p) q = q->right;
        if (q->right == p) {
          q->right = NULL;
        } else {
          q->right = p;
          p = p->left;
          continue;
        }
      }
      ret.push_back(p->val);
      p = p->right;
    }
    return ret;
  }
};
