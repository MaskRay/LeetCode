class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (! head) return NULL;
    ListNode *x = head, *y, *z;
    int n = 0;
    for (; x; y = x, x = x->next)
      n++;
    if (! (k %= n)) return head;
    for (k = n-k, x = head; k; k--)
      z = x, x = x->next;
    y->next = head;
    z->next = NULL;
    return x;
  }
};

/// 拆成若干置換

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

int gcd(int a, int b)
{
  int t;
  while (b)
    t = a%b, a = b, b = t;
  return a;
}

class Solution {
public:
  void rotate(int a[], int n, int m) {
    m %= n;
    int d = gcd(n, m);
    REP(i, d) {
      int j = i, x = a[j];
      for(;;) {
        int k = j-m;
        if (k < 0) k += n;
        if (k == i) break;
        a[j] = a[k];
        j = k;
      }
      a[j] = x;
    }
  }
};
