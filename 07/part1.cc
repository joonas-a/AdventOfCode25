#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");
  string raw_line;

  vector<string> lines;
  while (getline(file, raw_line)) {
    lines.push_back(raw_line);
  }

  const size_t n_lines = lines.size();
  const size_t line_length = lines.at(0).length();

  int amount = 0;
  vector<bool> state(line_length, false);

  for (size_t y = 0; y < n_lines; y++) {
    const auto &line = lines[y];
    for (size_t x = 0; x < line_length; x++) {
      if (y == 0) {
        if (line[x] == 'S') {
          state[x] = true;
        }
      } else {
        if (line[x] == '^' && state[x] == true) {
          state[x] = false;
          state[x - 1] = true;
          state[x + 1] = true;
          amount++;
        }
      }
    }
  }

  cout << amount << endl;
  return 0;
}
