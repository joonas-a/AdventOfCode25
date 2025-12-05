#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");
  string line;

  vector<pair<long, long>> ranges;

  while (file >> line) {
    auto loc = line.find('-');
    if (loc != string::npos) {
      ranges.push_back(
          pair(stol(line.substr(0, loc)), stol(line.substr(loc + 1))));
    } else {
      break;
    }
  }

  long fresh_ids = 0;
  long prev_end = 0;

  sort(ranges.begin(), ranges.end());

  for (auto range : ranges) {
    fresh_ids += range.first > prev_end
                     ? range.second - range.first + 1
                     : max(range.second - max(range.first, prev_end), 0l);
    prev_end = max(range.second, prev_end);
  }

  cout << fresh_ids << endl;
  return 0;
}
