// Construct Binary Tree from Preorder and Postorder Traversal
class Solution {
  vector<int> pre, post;
  TreeNode *f(int i, int j, int n) {
    if (!n) return 0;
    auto* r = new TreeNode(pre[i]);
    if (n > 1) {
      int k = find(post.begin()+j, post.begin()+j+n, pre[i+1])-post.begin()-j+1;
      r->left = f(i+1, j, k);
      r->right = f(i+k+1, j+k, n-k-1);
    }
    return r;
  }
public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    this->pre = pre;
    this->post = post;
    return f(0, 0, pre.size());
  }
};
