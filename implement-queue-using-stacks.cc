// Implement Queue using Stacks
class Queue {
  stack<int> a, b;

  void f() {
    if (a.empty())
      while (! b.empty()) {
        a.push(b.top());
        b.pop();
      }
  }
public:
  // Push element x to the back of queue.
  void push(int x) {
    b.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    f();
    a.pop();
  }

  // Get the front element.
  int peek(void) {
    f();
    return a.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return a.empty() && b.empty();
  }
};
