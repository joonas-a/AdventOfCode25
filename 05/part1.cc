#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");
  string line;

  vector<pair<long, long>> ranges;
  int fresh_count = 0;

  while (file >> line) {
    auto loc = line.find('-');
    if (loc != string::npos) {
      ranges.push_back(
          pair(stol(line.substr(0, loc)), stol(line.substr(loc + 1))));
    } else {
      auto query = stol(line);
      for (auto range : ranges) {
        if (range.first <= query && range.second >= query) {
          fresh_count++;
          break;
        }
      }
    }
  }

  cout << fresh_count << endl;
  return 0;
}
