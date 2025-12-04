#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

struct pair_hash {
  size_t operator()(const pair<int, int> &p) const {
    return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
  }
};

int main() {
  ifstream file("input.txt");
  string line;

  int result = 0;
  int y = 0;
  int acc = 0;

  unordered_map<pair<int, int>, bool, pair_hash> layout;

  while (getline(file, line)) {
    for (size_t x = 0; x < line.size(); x++) {
      layout[{x, y}] = (line[x] != '.');
    }
    y++;
  }

  const pair<int, int> directions[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                        {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  for (const auto &[key, val] : layout) {
    if (!val)
      continue;

    acc = 0;
    for (const auto &dir : directions) {
      int nx = key.first + dir.first;
      int ny = key.second + dir.second;
      auto it = layout.find({nx, ny});
      if (it != layout.end() && it->second) {
        acc++;
      }
    }

    if (acc < 4)
      result++;
  }

  cout << result << endl;
  return 0;
}
