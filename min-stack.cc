// Min Stack
class MinStack {
public:
  MinStack() {}
  void push(int x) {
    a.push(x);
    if (b.empty() || x <= b.top())
      b.push(x);
  }
  void pop() {
    if (b.top() == a.top())
      b.pop();
    a.pop();
  }
  int top() {
    return a.top();
  }
  int getMin() {
    return b.top();
  }
private:
  stack<int> a, b;
};

// 棧中存儲與當前最小值的差值，可以判斷是否更新了最小值
// 最好使用unsigned，因爲signed類型溢出是未定義的
// 可惜Memory Limit Exceeded

class MinStack {
public:
  MinStack() : s(0), d(INT_MAX) {}
  void push(int x) {
    a.push(x-d);
    if (s++ % 32 == 0)
      b.push(0);
    if (int(x) < int(d)) {
      d = x;
      b.top() |= 1u << (s-1)%32;
    } else
      b.top() &= ~ (1u << (s-1)%32);
  }
  void pop() {
    if (b.top() & 1u << (s-1)%32)
      d -= a.top();
    a.pop();
    if (--s % 32 == 0)
      b.pop();
  }
  int top() {
    return b.top() & (1u << (s-1)%32) ? d : d+a.top();
  }
  int getMin() {
    return d;
  }
private:
  stack<unsigned> a, b;
  unsigned s, d;
};
