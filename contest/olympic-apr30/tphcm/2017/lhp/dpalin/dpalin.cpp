// whoever idiot made this ?
// this jumped straight to be the dumpest question I have ever seen in an Olympic

#include <bits/stdc++.h>
using namespace std;
ifstream inp("dpalin.inp");
ofstream out("dpalin.out");

//
int recursion(string s) {
	if (s.length() < 2) return 0;
	// who care about the middle letter !
	for (int i = 0; i < s.length() / 2; i++) {
		if (s.at(i) != s.at(s.length() - 1 - i)) {
			// not palin
			return 0;
		}
	}
	return 1 + recursion(s.substr(0, (s.length() + 1) / 2));
}

int main() {
	string s;
	while (inp >> s) {
		cout << s.length() << " " << recursion(s) << " -1\n";
	}
	//
	getchar();
	return 0;
}
