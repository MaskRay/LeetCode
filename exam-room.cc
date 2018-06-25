// Exam Room

class ExamRoom {
  int n;
  vector<int> a;
public:
  ExamRoom(int N) {
    n = N;
  }
  int seat() {
    int p = 0, t, d;
    if (a.size()) {
      d = a[0];
      for (int i = 1; i < a.size(); i++)
        if ((t = (a[i]-a[i-1])/2) > d)
          d = t, p = a[i-1]+t;
      if (n-1-a.back() > d)
        p = n-1;
    }
    int i;
    a.emplace_back();
    for (i = a.size()-1; i && p < a[i-1]; i--)
      a[i] = a[i-1];
    return a[i] = p;
  }
  void leave(int p) {
    a.erase(find(a.begin(), a.end(), p));
  }
};
