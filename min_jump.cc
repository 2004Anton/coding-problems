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
	int steps[n];
	for(int i =0 ; i <n;i++){
		steps[i] = 20000000;
	}
	for(int i = 0; i <n;i++){
		if(i == 0){
			steps[i] = 0;
		}
		for(int k = i; k <= n && k <= i+arr[i]; k++){
			steps[k] = MIN(steps[k],steps[i]+1);
		}
	}
	return steps[n-1];
}

int main() {
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9,1,1,1,1,1,1,2,3,4,1};
  int n = sizeof(arr) / sizeof(int);
  cout << "getMinJump returns " << getMinJump(arr, n) << endl;

  return 0;
}
