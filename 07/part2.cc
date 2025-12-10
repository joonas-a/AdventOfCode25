#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ifstream file("input.txt");
  string raw_line;

  vector<string> lines;
  while (getline(file, raw_line)) {
    lines.push_back(raw_line);
  }

  const size_t n_lines = lines.size();
  const size_t line_length = lines.at(0).length();

  vector<ll> state(line_length, 0);

  for (size_t y = 0; y < n_lines; y++) {
    const auto &line = lines[y];
    for (size_t x = 0; x < line_length; x++) {
      if (y == 0) {
        if (line[x] == 'S') {
          state[x]++;
        }
      } else {
        if (line[x] == '^' && state[x] != 0) {
          state[x - 1] += state[x];
          state[x + 1] += state[x];
          state[x] = 0;
        }
      }
    }
  }

  ll amount = 0;
  for (const auto num : state) {
    amount += num;
  }

  cout << amount << endl;
  return 0;
}
