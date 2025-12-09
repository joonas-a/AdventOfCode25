#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ifstream file("input.txt");
  string line;

  vector<string> nums;
  vector<string> lines;
  vector<char> ops;
  vector<size_t> delims;

  while (getline(file, line)) {
    lines.push_back(line);
  }

  // Find delims (== empty cols)
  for (size_t i = 0; i < lines.back().size(); i++) {
    string last = lines.back();
    if (last[i] == '+' || last[i] == '*') {
      ops.push_back(last[i]);
      if (i != 0)
        delims.push_back(i - 1);
    }
  }
  delims.push_back(lines.back().size());

  // Construct nums including whitespace
  for (auto it = lines.begin(); it < lines.end() - 1; it++) {
    int j = 0;
    for (auto delim : delims) {
      nums.push_back(it->substr(j, delim - j));
      j = delim + 1;
    }
  }

  const size_t num_of_rows = lines.size() - 1;
  const size_t row_length = ops.size();

  string tmp;
  ll total = 0, count = 0;

  for (size_t outer_x = 0; outer_x < row_length; outer_x++) {
    const bool mul = ops[outer_x] == '*';
    count = mul ? 1 : 0;

    const size_t col_width = nums[outer_x].size();
    for (size_t inner_x = 0; inner_x < col_width; inner_x++) {
      for (size_t y = 0; y < num_of_rows; y++) {
        const auto &c = nums[outer_x + y * row_length][inner_x];
        if (c != ' ') {
          tmp += c;
        }
      }
      mul ? count *= stoll(tmp) : count += stoll(tmp);
      tmp.clear();
    }
    total += count;
  }

  cout << total << endl;
  return 0;
}
