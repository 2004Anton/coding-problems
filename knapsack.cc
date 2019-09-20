// 0-1 Knapsack Problem | DP-10
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// Given weights and values of n items, put these items in a knapsack of
// capacity W to get the maximum total value in the knapsack. In other words,
// given two integer arrays val[0..n-1] and wt[0..n-1] which represent values
// and weights associated with n items respectively. Also given an integer W
// which represents knapsack capacity, find out the maximum value subset of
// val[] such that sum of the weights of this subset is smaller than or equal to
// W. You cannot break an item, either pick the complete item, or don’t pick it
// (0-1 property).
//

#include <iostream>
#include <vector>
using namespace std;

#define MAX(a, b) (a > b ? a : b)

// Dynamic programming: be aware of K[i][*] is working on wt[i-1] and price[i-1]
int knapsack_dp(int W, int wt[], int price[], int n) {
// add your code here
}

int main() {
  int W = 50;
  int wt[] = {10, 20, 30};
  int price[] = {60, 100, 120};
  int n = 3;

  cout << "knapsack DP returns " << knapsack_dp(W, wt, price, n) << endl;
  return 0;
}
