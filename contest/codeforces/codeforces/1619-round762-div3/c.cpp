
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 21 21:02:56 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

string merge(const vector<int>& b, int l) {
	string s;
	for (int i = l; i < b.size(); i++) 
		s += to_string(b[i]);
	return s;
}

string calc(const string& a, const string& s) {
	// có bao nhiêu chỗ để tạo tổng có giá trị >= 10
	vector<bool> loc(s.size());
	for (int i = 0; i < s.length()-1; i++) {
		if (s[i] == '1') loc[i] = true;
	}
	//
	for (int mk = 0; mk < (1<<loc.size()); mk++) {
		vector<int> b(s.size(), 0);
		//
		for (int in_a = a.size()-1, in_s = s.size() - 1; ; in_a--, in_b--) {

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string a, s;
		cin >> a >> s;
		//
		cout << calc(a, s) << "\n";
	}
	return 0;
}
