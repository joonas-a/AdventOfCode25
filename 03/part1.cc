#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream file("input.txt");
  string line;

  int total = 0;

  string row_val;
  size_t idx;

  while (file >> line) {
    row_val.clear();
    idx = 0;

    auto first = max_element(line.begin() + idx, line.end() - 1);
    idx = distance(line.begin(), first) + 1;

    auto second = max_element(line.begin() + idx, line.end());

    row_val += *first;
    row_val += *second;
    total += stoi(row_val);
  }

  cout << total << endl;
  return 0;
}
