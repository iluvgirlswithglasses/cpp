#include <bits/stdc++.h>
using namespace std;

// 50/50

//
int calc(string s) {
	bool found = false;
	int counts = 0, start = 0, end = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '0') {
			counts += 1;
		} else {
			if (!found) start = i;
			end = i;
			//
			found = true;
		}
	}

	//
	if (found) {
		return counts - start - (s.length() - end - 1);
	}
	return -1;
}

//

int main() {
	int t; cin >> t;
	string s;
	for (int i = 0; i < t; i++) {
		cin >> s; 
		cout << calc(s) << endl;
	}
	//
	return 0;
}
