// Count Complete Tree Nodes
class Solution {
public:
  int countNodes(TreeNode* root) {
    if (! root) return 0;
    int dl = 0, dr = 0;
    TreeNode *l = root, *r = root;
    while (l) l = l->left, dl++;
    while (r) r = r->right, dr++;
    return dl == dr ? (1 << dl) - 1 : countNodes(root->left) + countNodes(root->right) + 1;
  }
};
