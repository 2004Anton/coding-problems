// Given a string, find the minimum number of characters to be inserted to
// convert it to palindrome. For Example: ab: Number of insertions required
// is 1. bab or aba aa: Number of insertions required is 0. aa abcd: Number of
// insertions required is 3. dcbabcd
// https://practice.geeksforgeeks.org/problems/form-a-palindrome/0

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>


int main() {
  char s[] = "geeks";
  cout << s << " strlen " << strlen(s) << endl;
  cout << findMinInsertions(s, 0, strlen(s) - 1) << endl;

  return 0;
}
