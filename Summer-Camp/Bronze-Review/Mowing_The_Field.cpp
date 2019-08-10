/*
Mowing the Field
================

Farmer John is quite reliable in all aspects of managing his farm, 
except one: he is terrible at mowing the grass in a timely or 
logical fashion.

The farm is a large 2D grid of square unit cells. FJ starts in one 
of these cells at time t=0, mowing the grass in this cell so that 
it is initially the only cell in which the grass is cut. FJ's 
remaining mowing pattern is described by a sequence of N 
statements. For example, if the first statement is "W 10", then for 
times t=1 through t=10 (i.e., the next 10 units of time), FJ will 
step one cell to his west, mowing the grass along the way. After 
completing this sequence of steps, he will end up 10 cells to his 
west at time t=10, having mowed the grass in every cell along the 
way.

So slow is FJ's progress that some of the grass he mows might grow 
back before he is finished with all his mowing. Any section of 
grass that is cut at time t will reappear at time t+x.

FJ's mowing pattern might have him re-visit the same cell multiple 
times, but he remarks that he never encounters a cell in which the 
grass is already cut. That is, every time he visits a cell, his 
most recent visit to that same cell must have been at least x units 
of time earlier, in order for the grass to have grown back.

Please determine the maximum possible value of x so that FJ's 
observation remains valid.

PROBLEM NAME: mowing

INPUT FORMAT:

The first line of input contains N (1 <= N <= 100). Each of the 
remaining N lines contains a single statement and is of the form 'D 
S', where D is a character describing a direction (N=north, E=east, 
S=south, W=west) and S is the number of steps taken in that 
direction (1 <= S <= 10).

OUTPUT FORMAT:

Please determine the maximum value of x such that FJ never steps on 
a cell with cut grass. If FJ never visits any cell more than once, 
please output -1.

SAMPLE INPUT:

6
N 10
E 2
S 3
W 4
S 5
E 8

SAMPLE OUTPUT:

10

In this example, FJ steps on a cell at time 17 that he stepped on 
earlier at time 7; therefore, x must be at most 10 or else the 
grass from his first visit would not yet have grown back. He also 
steps on a cell at time 26 that he also visited at time 2; hence x 
must also be at most 24. Since the first of these two constraints 
is tighter, we see that x can be at most 10. 

*/

#include <iostream>
using namespace std;

int main(){
    int rows;
    cin >> rows;
    char directions [rows];
    int paces [rows];
    for(int i = 0; i < rows; i++){
        cin >> directions[i] >> paces[i];
        //cout << directions[i] << paces[i];
    }
    
    int maxTime = 1;
    int maxS = 0;
    int maxW = 0;
    int maxN = 0;
    int maxE = 0;
    
    for(int i = 0; i < rows; i++){
        if(directions[i] == 'N'){
            maxN += paces[i];
        }
        if(directions[i] == 'S'){
            maxS += paces[i];
        }
        if(directions[i] == 'W'){
            maxW += paces[i];
        }
        if(directions[i] == 'E'){
            maxE += paces[i];
        }
    }
    maxTime+=maxN+maxS+maxW+maxE;
    if(maxE+maxW == 0 || maxN+maxS == 0){
        cout<< -1;
    }
    else if(maxE != 0 && maxW != 0 && maxN == 0 && maxS == 0){
        cout<< 1;
    }
    else if(maxE == 0 && maxW == 0 && maxN != 0 && maxS != 0){
        cout<< 1;
    }
    else {//cout<<"maxN: "<<maxN<<", maxS: "<<maxS<< ", maxW: "<<maxW<<", maxE: "<<maxE;
        int x = maxW;
        int y = maxN;
        int m = 2147483647;
        int field[maxN + maxS+1][maxE + maxW+1];
        for(int i = 0; i < maxN+maxS+1; i++){
            for(int k = 0; k < maxE + maxW+1; k++){
                field[i][k] = 0;
            }
        }
        int currI = 0;
        int temp = 0;
        //cout << "x" <<x << "y" <<y;
        for(int i = 1; i < maxTime; i++){
            if(field[x][y] != 0){
                //cout<<x<<","<<y;
                cout<<", i: "<<i<<", (x,y): "<<field[x][y];
                m = min(m,i-field[x][y]);
            }
            //cout<<", X:"<<x<<", Y:"<<y;
            field[x][y] = i;
            if(temp>=paces[currI]){
                temp = 0;
                currI++;
            }
            if(directions[currI] == 'N'){
                y--;
                temp++;
            }
            if(directions[currI] == 'S'){
                y++;
                temp++;
            }
            if(directions[currI] == 'W'){
                x--;
                temp++;
            }
            if(directions[currI] == 'E'){
                x++;
                temp++;
            }    
        }
        if(m != 2147483647 && m > 0){
            cout << m;
        }
       
        else{
            cout<<"-1";
        }
    }
}
