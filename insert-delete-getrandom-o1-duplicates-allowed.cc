// Insert Delete GetRandom O(1) - Duplicates allowed
class RandomizedCollection {
public:
  unordered_multimap<int, int> m;
  vector<pair<int, decltype(m.begin())>> a;
public:
  /** Initialize your data structure here. */
  RandomizedCollection() {

  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val) {
    bool r = ! m.count(val);
    a.emplace_back(val, m.emplace(val, a.size()));
    return r;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val) {
    auto it = m.find(val);
    if (it == m.end()) return false;
    (a[it->second] = a.back()).second->second = it->second;
    m.erase(it);
    a.pop_back();
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    return a[rand()%a.size()].first;
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
