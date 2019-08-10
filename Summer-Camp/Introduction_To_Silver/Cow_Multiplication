/*
Cow Multiplication
==================

Bessie is tired of multiplying pairs of numbers the usual way, so
she invented her own style of multiplication. In her style, A*B is
equal to the sum of all possible pairwise products between the
digits of A and B. For example, the product 123*45 is equal to 1*4
+ 1*5 + 2*4 + 2*5 + 3*4 + 3*5 = 54.  Given two integers A and B (1
<= A, B <= 1,000,000,000), determine A*B in Bessie's style of
multiplication.

PROBLEM NAME: cowmult

INPUT FORMAT:

* Line 1: Two space-separated integers: A and B.

SAMPLE INPUT:

123 45

INPUT DETAILS:

The two numbers are 123 and 45.

OUTPUT FORMAT:

* Line 1: A single line that is the A*B in Bessie's style of
        multiplication.

SAMPLE OUTPUT:

54
*/
#include <iostream>
using namespace std;

int len(int num){
    int count = 0;
    while(num > 0){
        num/=10;
        count++;
    }
    return count;
}
int main(){
    int a;
    int b;
    cin >> a>>b;
    int ans = 0;
    int tempA = a;
    for(int i = 0; i < len(a); i++){
        int tempB = b;
        for(int k = 0; k < len(b); k++){
            ans+=((tempA%10)*(tempB%10));
            tempB/=10;
        }
        tempA/=10;
    }
    cout << ans;
}
