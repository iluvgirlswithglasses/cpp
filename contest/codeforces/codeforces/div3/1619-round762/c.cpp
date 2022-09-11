
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
using namespace std;

string merge(const vector<int>& b, int r) {
	string s;
	for (int i = r; i >= 0; i--)
		s += to_string(b[i]);
	return s;
}

string calc(const string& a, const string& s) {
	vector<int> b(s.size(), 0);
	for (int in_a = a.size()-1, in_s = s.size()-1, in_b = 0; in_a >= 0 || in_s >= 0; in_a--, in_s--) {
		if (in_s == 0 && in_a > 0) return "-1";
		//
		int cra = in_a >= 0 ? (a[in_a] - '0') : 0;
		if (s[in_s] - '0' < cra) {
			if (in_s-- == 0 || s[in_s] != '1') return "-1";
			int target = stoi(s.substr(in_s, 2));
			//
			if (target < 19)
				b[in_b++] = target - cra;
			else
				return "-1";
		} else {
			b[in_b++] = (s[in_s] - '0') - cra;
		}
	}
	//
	for (int i = b.size()-1; i >= 0; i--)
		if (b[i] != 0) return merge(b, i);
	return "0";
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
