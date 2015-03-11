// Linked List Cycle
class Solution {
public:
  bool hasCycle(ListNode *head) {
    set<ListNode *> s;
    while (head && ! s.count(head)) {
      s.insert(head);
      head = head->next;
    }
    return !!head;
  }
};
