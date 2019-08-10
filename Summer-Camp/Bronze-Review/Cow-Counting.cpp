/*Cow Counting
============

Farmer John wants to label his N (1 <= N <= 1,000,000) cows, but
cows don't like having the digit L (0 <= L <= 9) written on them,
so he avoids that.

If the cows are labeled with the smallest set of N positive integers
that don't have the digit L, what is the largest number that Farmer
John has to write on any cow?

PROBLEM NAME: count

INPUT FORMAT:

* Line 1: Two space-separated integers: N and L.

SAMPLE INPUT:

10 1

INPUT DETAILS:

Farmer John has 10 cows he needs to label without using the digit 1.

OUTPUT FORMAT:

* Line 1: A single integer that is the largest number that Farmer John
        has to write on any cow.

SAMPLE OUTPUT:

22

OUTPUT DETAILS:

The smallest 10 numbers he can use are: 2, 3, 4, 5, 6, 7, 8, 9, 20, and 22.
*/
#include <iostream>
#include<cmath>
using namespace std;

int findLength(int num){
    int ans = 0;
    int p = num;
    while(p > 0){
        p= p/10;
        ans++;
    }
    return ans;
}


int main(){
    int cows;
    int num;
    cin >> cows;
    cin >> num;

    int min = 1;

    for(int i = 0; i < cows; i++){
        int len = findLength(min);
        int temp = min;
        for(int k = 0; k < len; k++){
            if(temp%10 == num){
                min = min+ (pow(10,k));
                temp = min/pow(10,k);
            }
            temp = temp/10;
        }
        if(i != cows-1){
            min++;
        }
    }
    cout << min;
}

