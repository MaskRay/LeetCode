// Convert the Temperature
class Solution {
public:
  vector<double> convertTemperature(double c) {
    return {c+273.15, c*1.8+32};
  }
};
