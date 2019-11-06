#include <iostream>
#include <cmath>
using namespace std;
int calc(int n, int numbers[]){
	
	if(numbers[n] == -1){
		numbers[n] = calc((n%2 ==0) ? (n/2) : (n*3+1),numbers)+1;
	}
	cout <<"n: "<<n<< ", number[n]:  " << numbers[n]<<endl;
	return numbers[n];
	// cout <<n <<" "<<numbers[n] <<endl;
}
int main(){
	int start[100000];
	int end[100000];
	int index = 0; 
	int tmp1;
	int tmp2;
	while (cin >> tmp1>>tmp2){
		start[index] = min(tmp1,tmp2);
		end[index] = max(tmp1,tmp2);
		index++;
	}
	int numbers[1000000];
	for(int i = 0; i < 1000000; i++){
		numbers[i] = -1;
	}
	numbers[1] = 1;
	int cur_max = -1;
	for(int i = 0; i < index; i++){
		for(int k = start[i]; k <= end[i]; k++){
			cur_max = max(cur_max,calc(k,numbers));
		}
		cout << start[i] << " " << end[i] << " "<< cur_max<< endl;
		cur_max = -1;
	}
}
