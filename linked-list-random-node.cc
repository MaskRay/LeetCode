// Linked List Random Node
class Solution {
  int size;
  ListNode* head;
public:
  /** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) {
    this->head = head;
    size = 0;
    for (; head; head = head->next)
      size++;
  }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode* x = head;
    int t = rand() % size;
    while (t--)
      x = x->next;
    return x->val;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
