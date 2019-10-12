// printout all combinations of an array with unique values
// for example: all subsets of {1,2,5,6}
// {1}, {2}, {5}, {6}, {1,2}, {1,2,3}, {1,2,5}, {1,2,5,6}, {2,5}, {2,6}, {2,5,6}, {5,6}

#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

//master test...
using namespace std;

struct charInt{
	int i;
	vector<int> vals;
};

void printoutSubSets(vector<int> v) {
	queue<charInt> s;
	for(vector<int>::iterator it = v.begin(); it < v.end(); ++it){
		charInt ci;
		ci.i = it-v.begin();
		vector<int> tmp;
		tmp.push_back(*it);
		ci.vals = tmp;
		s.push(ci);
	}
	while(!(s.empty())){
		charInt top = s.front();
		s.pop();
		vector<int> vi = top.vals;
		cout << "(";
		for(vector<int>::iterator it = vi.begin(); it < vi.end(); ++it){
			cout << *it;
			if(it != vi.end()-1){
				cout << ",";
			}
		}
		cout << ") ";
		for(vector<int>::iterator it = v.begin()+top.i+1; it < v.end();++it){
			charInt newCi;
			newCi.i = it-v.begin();
			newCi.vals = top.vals;
			newCi.vals.push_back(*it);
			s.push(newCi);
		}		
	}

}

int main() {
  vector<int> vv{1, 2, 5, 6};
  printoutSubSets(vv);

  return 0;
}
