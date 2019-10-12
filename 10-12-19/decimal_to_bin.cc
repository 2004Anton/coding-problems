// algorithms that convert a base 10 number to its
// equivalent binary, octal or hexadecimal form. For example 7810 has a binary
// representation of 10011102.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  vector<int> v1 = decToBin(25);
  for (auto k : v1)
    cout << k << " ";
  cout << endl;

  v1 = decToBin(11);
  for (auto k : v1)
    cout << k << " ";
  cout << endl;

  return 0;
}
