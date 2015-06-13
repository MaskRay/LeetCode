// Implement Stack using Queues
class Stack {
  queue<int> q;
public:
  // Push element x onto stack.
  void push(int x) {
    auto s = q.size();
    q.push(x);
    while (s--) {
      q.push(q.front());
      q.pop();
    }
  }

  // Removes the element on top of the stack.
  void pop() {
    q.pop();
  }

  // Get the top element.
  int top() {
    return q.front();
  }

  // Return whether the stack is empty.
  bool empty() {
    return q.empty();
  }
};
