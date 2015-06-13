// Invert Binary Tree

// recursive
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root) {
      swap(root->left, root->right);
      invertTree(root->left);
      invertTree(root->right);
    }
    return root;
  }
};

// variant of Morris post-order traversal
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    TreeNode aux(0), *p = &aux;
    aux.left = root;
    while (p) {
      TreeNode *q = p->left;
      if (q) {
        while (q->right && q->right != p) q = q->right;
        if (q->right == p) {
          for (TreeNode *r = p->left; ; r = r->left) {
            swap(r->left, r->right);
            if (r == q) break;
          }
          q->left = NULL;
        } else {
          q->right = p;
          p = p->left;
          continue;
        }
      }
      p = p->right;
    }
    return aux.left;
  }
};
