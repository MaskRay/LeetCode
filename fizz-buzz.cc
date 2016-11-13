// Fizz Buzz
class Solution {
public:
  vector<string> fizzBuzz(int n) {
    int fizz = 3, buzz = 5, fizzbuzz = 15;
    vector<string> r;
    for (int i = 1; i <= n; i++)
      if (i == fizzbuzz)
        r.push_back("FizzBuzz"), fizz += 3, buzz += 5, fizzbuzz += 15;
      else if (i == fizz)
        r.push_back("Fizz"), fizz += 3;
      else if (i == buzz)
        r.push_back("Buzz"), buzz += 5;
      else
        r.push_back(to_string(i));
    return r;
  }
};
