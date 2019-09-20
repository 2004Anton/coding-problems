// Minimum number of jumps to reach end
// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
// Given an array of integers where each element represents the max number of
// steps that can be made forward from that element. Write a function to return
// the minimum number of jumps to reach the end of the array (starting from the
// first element). If an element is 0, then cannot move through that element.
//
// Example:
//
// Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
// Output: 3 (1-> 3 -> 8 ->9)
// First element is 1, so can only go to 3. Second element is 3, so can make at
// most 3 steps eg to 5 or 8 or 9.

#include <cstdlib>  // For atoi()
#include <iostream> // For cout and cerr
#include <math.h>
#include <string>

using namespace std;
#define MIN(a, b) (a > b ? b : a)

int getMinJump(int arr[], int n) {
// add your code here
}

int main() {
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int n = sizeof(arr) / sizeof(int);
  cout << "getMinJump returns " << getMinJump(arr, n) << endl;

  return 0;
}
