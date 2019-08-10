/*
Milk Pails
==========

Farmer John has received an order for exactly M units of milk (1 <= 
M <= 1,000) that he needs to fill right away. Unfortunately, his 
fancy milking machine has just become broken, and all he has are 
three milk pails of integer sizes X, Y, and M (1 <= X < Y < M). All 
three pails are initially empty. Using these three pails, he can 
perform any number of the following two types of operations:

- He can fill the smallest pail (of size X) completely to the top 
with X units of milk and pour it into the size-M pail, as long as 
this will not cause the size-M pail to overflow.

- He can fill the medium-sized pail (of size Y) completely to the 
top with Y units of milk and pour it into the size-M pail, as long 
as this will not cause the size-M pail to overflow.

Although FJ realizes he may not be able to completely fill the 
size-M pail, please help him determine the maximum amount of milk he can 
possibly add to this pail.

PROBLEM NAME: pails

INPUT FORMAT:

The first, and only line of input, contains X, Y, and M, separated 
by spaces.

OUTPUT FORMAT:

Output the maximum amount of milk FJ can possibly add to the size-M 
pail.

SAMPLE INPUT:

17 25 77

SAMPLE OUTPUT:

76

In this example, FJ fills the pail of size 17 three times and the 
pail of size 25 once, accumulating a total of 76 units of milk. 
*/
#include <iostream>
#include <cmath>
using namespace std;


int milk(int s, int m, int l, int curr){
    if(curr + m  > l ){
        if(curr + s > l){
            return curr;
        }
        return max(curr, milk(s,m,l,curr+s));
    }
    return max(milk(s,m,l,curr+s),milk(s,m,l,curr+m));
}


int getAns(int s, int m, int l){
    int maximum = 0;
    int maxM = floor(l/m)*m;
    for(int i = 0; i < floor(l/m)+1;i++){
        int temp = l-maxM;
        int add = floor(temp/s)*s;
        int n = add+maxM;
        if(n > maximum){
            maximum = n;
        }
        maxM=maxM-m;
    }
    return maximum;
}
int main(){
    int s;
    int m;
    int l;
    cin >> s >>m >>l;
    int ans =getAns(s,m,l);
    cout<<ans;
}
