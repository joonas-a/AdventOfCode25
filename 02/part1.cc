#include <fstream>
#include <iostream>
#include <string>

using namespace std;

inline bool isInvalid(const string &s) {
  auto n = s.size();
  return (n % 2 == 0) && s.substr(0, n / 2) == s.substr(n / 2);
}

int main() {
  constexpr char delim = ',';
  constexpr char dash = '-';

  ifstream file("input.txt");
  string input;
  getline(file, input);

  string range;
  size_t start = 0;
  size_t end = input.find(delim, start);

  long long result = 0;

  while (true) {
    if (end == string::npos)
      range = input.substr(start);
    else
      range = input.substr(start, end - start);

    auto dashLoc = range.find(dash);
    auto rangeStart = range.substr(0, dashLoc);
    auto rangeEnd = range.substr(dashLoc + 1);

    for (long long i = stoll(rangeStart); i <= stoll(rangeEnd); ++i) {
      if (isInvalid(to_string(i))) {
        result += i;
      }
    }

    if (end == string::npos)
      break;

    start = end + 1;
    end = input.find(delim, start);
  }

  cout << result << endl;
  return 0;
}
