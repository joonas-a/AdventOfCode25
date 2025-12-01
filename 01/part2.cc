#include <fstream>
#include <iostream>

using namespace std;

struct Dial {
  int value = 50;
  int zeroes = 0;

  inline void rotateLeft(int amount) {
    for (int i = 0; i < amount; i++) {
      value--;

      if (value == 0) {
        zeroes++;
      } else if (value < 0) {
        value = 99;
      }
    }
  }

  inline void rotateRight(int amount) {
    for (int i = 0; i < amount; i++) {
      value++;

      if (value > 99) {
        value = 0;
        zeroes++;
      }
    }
  }
};

int main() {
  ifstream file("input.txt");
  string instruction;
  Dial dial;

  while (file >> instruction) {
    int amount = stoi(instruction.substr(1));

    if (instruction[0] == 'L')
      dial.rotateLeft(amount);
    else
      dial.rotateRight(amount);
  }

  cout << dial.zeroes << endl;
  return 0;
};
