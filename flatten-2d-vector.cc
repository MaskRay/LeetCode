// Flatten 2D Vector
class Vector2D {
  vector<int>::iterator i;
  vector<vector<int>>::iterator j, jj;
public:
  Vector2D(vector<vector<int>>& vec2d) {
    j = vec2d.begin();
    jj = vec2d.end();
    if (j != jj)
      i = j->begin();
  }

  int next() {
    while (i == j->end())
      i = (++j)->begin();
    return *i++;
  }

  bool hasNext() {
    if (j == jj)
      return false;
    for(;;) {
      if (i != j->end())
        return true;
      if (++j == jj)
        return false;
      i = j->begin();
    }
  }
};
