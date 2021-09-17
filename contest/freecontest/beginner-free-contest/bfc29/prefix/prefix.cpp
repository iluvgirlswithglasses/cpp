#include <string>
#include <iostream>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	if (s == t.substr(0, s.length())) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	//
	return 0;
}
