//
// find first non-repeative char in a string
// for example: aabbccd  ===> d
//              abccccc ===> a
//              jjikjkl  ===>i

#include <iostream>
#include <string>

using namespace std;

char getChar(char *buf) {
  // add your code here
}

int main() {
  cout << "for aabbccd return " << getChar("aabbccd") << endl;
  cout << "for abccccc return " << getChar("abccccc") << endl;
  cout << "for jjikjkl return " << getChar("jjikjkl") << endl;
  cout << "for ffggmmmmm return " << getChar("ffggmmmmm") << endl;
  cout << "for a return " << getChar("a") << endl;
  return 0;
}
