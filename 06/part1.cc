#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

inline ll sum(size_t &line_size, int nth, vector<int> &nums, bool multiply) {
  ll count = multiply ? 1 : 0;
  for (size_t i = 0; i < nums.size() / line_size; i++) {
    multiply ? count *= nums[nth + line_size * i]
             : count += nums[nth + line_size * i];
  }
  return count;
}

int main() {
  ifstream file("input.txt");
  string word;

  vector<int> nums;
  vector<char> ops;

  while (file >> word) {
    word == "+" || word == "*" ? ops.push_back(*word.c_str())
                               : nums.push_back(stoi(word));
  }

  auto line_size = nums.size() / (nums.size() / ops.size());
  ll count = 0;
  for (int i = 0; i < ops.size(); i++) {
    count += ops[i] == '+' ? sum(line_size, i, nums, false)
                           : sum(line_size, i, nums, true);
  }

  cout << count << endl;
  return 0;
}
