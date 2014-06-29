class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    struct Cmp {
      bool operator()(const ListNode *x, const ListNode *y) const {
        return x->val > y->val;
      }
    };
    priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
    for (auto x: lists)
      if (x)
        pq.push(x);
    ListNode *head = NULL, *tail = NULL;
    while (! pq.empty()) {
      ListNode *p = pq.top();
      pq.pop();
      int x = p->val;
      if (! head)
        head = tail = new ListNode(x);
      else {
        tail->next = new ListNode(x);
        tail = tail->next;
      }
      p = p->next;
      if (p)
        pq.push(p);
    }
    return head;
  }
};
