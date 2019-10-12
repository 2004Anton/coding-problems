// A fairly routine problem in mathematics is that of finding the greatest
// common denominator of two integers, what we are essentially after is the
// greatest number which is a multiple of both, e.g. the greatest common
// denominator of 9, and 15 is 3. One of the most elegant solutions to this
// problem is based on Euclid’s algorithm that has a run time complexity of O(n
// 2
// ).

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


int main() {
  cout << " 150, 90 returns " << greatestCommonDeno(150, 90) << endl;
  cout << " 10000, 9000 returns " << greatestCommonDeno(10000, 9000) << endl;
  return 0;
}
