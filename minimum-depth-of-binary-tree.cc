// Minimum Depth of Binary Tree
class Solution {
public:
    int minDepth(TreeNode *root) {
        return root ? root->left || root->right ? min(root->left?minDepth(root->left):99999, root->right?minDepth(root->right):99999) + 1 : 1 : 0;
    }
};
