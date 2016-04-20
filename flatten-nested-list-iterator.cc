// Flatten Nested List Iterator
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
  stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> s;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    s.push({nestedList.begin(), nestedList.end()});
  }

  int next() {
    hasNext();
    return (s.top().first++)->getInteger();
  }

  bool hasNext() {
    while (! s.empty())
      if (s.top().first == s.top().second) {
        s.pop();
        if (! s.empty())
          ++s.top().first;
      } else if (s.top().first->isInteger())
        return true;
    else {
      auto &x = s.top().first->getList();
      s.push({x.begin(), x.end()});
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
