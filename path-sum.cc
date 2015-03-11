// Path Sum
class Solution {
public:
    bool hasPathSum(TreeNode *x, int s) {
        return x ? s -= x->val, x->left || x->right ? hasPathSum(x->left, s) + hasPathSum(x->right, s) : !s : false;
    }
};
