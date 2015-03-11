// Candy
class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> a(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++)
      if (ratings[i-1] < ratings[i])
        a[i] = a[i-1]+1;
    for (int i = ratings.size()-2; i >= 0; i--)
      if (ratings[i] > ratings[i+1])
        a[i] = max(a[i], a[i+1]+1);
    return accumulate(a.begin(), a.end(), 0);
  }
};
