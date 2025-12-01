#include <fstream>
#include <iostream>

using namespace std;

struct Dial {
  int value = 50;
  int zeroes = 0;

  void fit() {
    value %= 100;
    if (value < 0) {
      value += 100;
    }

    if (value == 0)
      zeroes++;
  }
};

int main() {
  ifstream file("input.txt");
  string row;

  Dial dial;

  while (file >> row) {
    int amount = stoi(row.substr(1));
    if (row[0] == 'L')
      dial.value -= amount;
    else
      dial.value += amount;

    dial.fit();
  }

  cout << dial.zeroes << endl;
  return 0;
};
