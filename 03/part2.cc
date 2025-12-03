#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main() {
  ifstream file("input.txt");
  string line;

  long long total = 0;

  size_t idx;
  string row_val;

  while (file >> line) {
    idx = 0;
    row_val.clear();

    for (int i = 11; i >= 0; i--) {
      auto it = max_element(line.begin() + idx, line.end() - i);
      idx = distance(line.begin(), it) + 1;

      row_val += *it;
    }

    total += stoll(row_val);
  }

  cout << total << endl;

  return 0;
}
