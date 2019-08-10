/*
Scavenger Hunt
==============

Farmer John has scattered treats for Bessie at special places in
the pasture.  Since everyone knows that smart cows make tasty milk,
FJ has placed the treats at locations that require Bessie to think.
He has given her two numbers, P and Q (1 <= P <= 6,000; 1 <= Q <=
6,000), and she has to check every point in the pasture whose
x-coordinate is a factor of P and whose y-coordinate is a factor
of Q to find her treat.

Suppose FJ gives Bessie P = 24 and Q = 2. Here are all of their
respective factors:

P = 24 => 1, 2, 3, 4, 6, 8, 12, 24
Q = 2 => 1, 2

Bessie would thus check grid locations: (1, 1), (1, 2), (2, 1), (2,
2), (3, 1)...

Help Bessie by printing all of the points she ought to check.

PROBLEM NAME: scavhunt

INPUT FORMAT:

* Line 1: Two space separated integers: P and Q

SAMPLE INPUT:

24 2

OUTPUT FORMAT:

* Lines 1..?: A complete list of unique pairs of space-separated
        integers sorted by the first number and, if tied, the second
        number: a factor of P followed by a factor of Q

SAMPLE OUTPUT:

1 1
1 2
2 1
2 2
3 1
3 2
4 1
4 2
6 1
6 2
8 1
8 2
12 1
12 2
24 1
24 2

*/

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(){
    int a;
    int b;
    cin >> a >> b;
    int factorsA [a];
    int factorsB [b];
    int place = 0;
    for(int i = 1; i <= a; i++){
        if(a%i == 0){
            factorsA[place] = i;
            //cout<<factorsA[place]<<", ";
            place++;
        }
    }
    int place2 = 0;
   for(int i = 1; i <= b; i++){
        if(b%i == 0){
            factorsB[place2]=i;
            place2++;
        }
    }
    for(int i = 0; i < place; i++){
        for(int k = 0; k < place2; k++){
            cout<<factorsA[i]<<" "<<factorsB[k];
            cout<<"\n";
        }
    }
}
