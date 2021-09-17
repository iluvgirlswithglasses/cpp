#include <string>
#include <iostream>
using namespace std;

#define lli long long int

//
string s;
unsigned lli res = 1;

//
int main() {
	cin >> s; s += "1";
	int len = s.length();
	//
	int dup = 0;
	for (int i = 1; i < len; i++) {
		//
		if (s.at(i) == s.at(i-1)) {
			dup += 1;
		} else {
			// if there is dup --> new choice
			if (dup > 0) {
				res = (res * (lli)(dup+1)) % 1000000007;
				dup = 0;
			}
		}
	}
	cout << res << endl;
	//
	system("pause");
	return 0;
}
