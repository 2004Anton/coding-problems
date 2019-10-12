//
// find first non-repeative char in a string
// for example: aabbccd  ===> d
//              abccccc ===> a
//              jjikjkl  ===>i
#include <map>
#include <iostream>
#include <string>

using namespace std;

char getChar(char *buf) {
	string str =string(buf);
	//cout <<"A";
	int len = str.length();
	while(str.length() != 0){
		int count = -1;
		char cur = str[0];
		//cout << cur<<": ";
		for(int k = 0; k < str.length(); k++){
			//cout << str[k]<<", ";
			if(str[k] == cur){
				count++;
				//cout << str<<endl;
				str.erase(str.begin()+k);
				k--;
				//cout <<str<<endl;
			}
		}
		//cout <<str<<" "<< count<<endl;
		if(count == 0){
			return cur;
		}
	}
	return '0';
  // add your code here
	//cout << &buf;
}

int main() {
  cout << "for aabbccd return " << getChar("aabbccd") << endl;
  cout << "for abccccc return " << getChar("abccccc") << endl;
  cout << "for jjikjkl return " << getChar("jjikjkl") << endl;
  cout << "for ffggmmmmm return " << getChar("ffggmmmmm") << endl;
  cout << "for a return " << getChar("a") << endl;
  return 0;
}