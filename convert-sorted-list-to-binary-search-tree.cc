// Convert Sorted List to Binary Search Tree
class Solution {
  ListNode *l;
  TreeNode *f(int n) {
    if (! n) return 0;
    auto x = new TreeNode(0);
    x->left = f(n/2);
    x->val = l->val;
    l = l->next;
    x->right = f(n-n/2-1);
    return x;
  }
public:
  TreeNode *sortedListToBST(ListNode *head) {
    l = head;
    int n = 0;
    while (head) {
      head = head->next;
      n++;
    }
    return f(n);
  }
};
