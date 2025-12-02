#include <fstream>
#include <iostream>
#include <string>

using namespace std;

inline string repeat(const string &s, const int n) {
  string out;
  out.reserve(s.size() * n);
  for (auto i = 0; i < n; ++i) {
    out += s;
  }
  return out;
}

inline bool isInvalid(const string &s, const int chunkSize) {
  size_t n = s.size();
  size_t repeats = n / chunkSize;

  if (chunkSize * repeats == n) {
    return repeat(s.substr(0, chunkSize), repeats) == s;
  }
  return false;
}

int main() {
  constexpr char delim = ',';
  constexpr char dash = '-';

  ifstream file("input.txt");
  string input;
  getline(file, input);

  size_t start = 0;
  size_t end = input.find(delim, start);

  long long result = 0;
  string range;

  while (true) {
    if (end == string::npos)
      range = input.substr(start);
    else
      range = input.substr(start, end - start);

    auto dashLoc = range.find(dash);
    auto rs = range.substr(0, dashLoc);
    auto re = range.substr(dashLoc + 1);

    for (long long i = stoll(rs); i <= stoll(re); ++i) {
      auto half = to_string(i).size() / 2;

      for (size_t j = 1; j <= half; ++j) {
        if (isInvalid(to_string(i), j)) {
          result += i;
          break;
        }
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
