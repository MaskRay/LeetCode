#include <cstdio>
#include <cctype>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define FOR(i, a, b) for (__typeof(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

#include <list>
#include <map>

struct Point
{
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

#define FOR(i, a, b) for (__typeof(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
      if (! head) return head;
      ListNode *p = head, *q, **r;
      while (q = p->next) {
        if (p->val <= q->val) {
          p = p->next;
          continue;
        }
        p->next = q->next;
        r = &head;
        while ((*r)->val < q->val)
          r = &(*r)->next;
        q->next = *r;
        *r = q;
      }
      return head;
    }
};

int main()
{
  ListNode *x = NULL;
  REP(i, 10) {
    ListNode *y = new ListNode(i);
    y->next = x;
    x = y;
  }
  x = Solution().insertionSortList(x);
  while (x) {
    printf("%d ", x->val);
    x = x->next;
  }
}
