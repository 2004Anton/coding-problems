// Greedy Algorithm to find Minimum number of Coins
// https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
// Given a value V, if we want to make change for V Rs, and we have infinite
// supply of each of the denominations in Indian currency, i.e., we have
// infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes,
// what is the minimum number of coins and/or notes needed to make the change?
//
// Examples:
//
// Input: V = 70
// Output: 2
// We need a 50 Rs note and a 20 Rs note.
//
// Input: V = 121
// Output: 3
// We need a 100 Rs note, a 20 Rs note and a
// 1 Rs coin.
#include <iostream>

using namespace std;

int miniCoins(int S, int coins[], int n) {
	int numCoins = 0;
	for(int i = n-1; i >=0; i--){
		while(coins[i] <= S){ 
			numCoins++;
			S-=coins[i];
		}
	}
	return numCoins;

}

int main() {
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = sizeof(coins) / sizeof(int);

  cout << "70 returns " << miniCoins(70, coins, n) << endl;
  cout << "121 returns " << miniCoins(121, coins, n) << endl;
}
