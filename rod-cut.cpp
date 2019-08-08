#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct rodPiece{
  int length;
  int sellPrice;
};
bool sortBySize(rodPiece a, rodPiece b){
  return a.length > b.length;
}
int help(int index, int curRodSize, int curWorth, vector<rodPiece> r){
  rodPiece cur = r.begin() + index;
  if(cur.length > curRodSize || index > r.size()){
    return curWorth;
  }
  return max(help(0,curRodSize-cur.length,curWorth+cur.sellPrice,r),
  help(index+1,curRodSize,curWorth,r));
}

void main(){
  int n;
  int numInputs;
  cin >> n >> numInputs;
  vector<rodPiece> r;
  for(int i = 0; i < numInputs; i++){
    rodPiece temp;
    cin >> temp.length >> temp.sellPrice;
    r.push_back(temp);
  }
  sort(r.begin(),r.end(),sortBySize);
  cout << help(0,n,0,r);
  // return 0;
}
