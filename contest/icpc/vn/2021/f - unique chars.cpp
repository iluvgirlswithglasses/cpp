
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 14 19:00:27 2021
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

#define ll long long
int n;
string s;

ll calc() {
	vector<int> loc[26];
	for (int c = 0; c < 26; c++)
		loc[c].push_back(-1);
	for (int i = 0; i < n; i++)
		loc[s[i] - 'a'].push_back(i);
	//
	ll res = 0;
	for (int c = 0; c < 26; c++) if (loc[c].size() > 1) {
		loc[c].push_back(n);
		// ways to choose L * ways to choose R
		for (int i = 1; i < loc[c].size() - 1; i++)
			res += (ll) (loc[c][i] - loc[c][i-1]) * (loc[c][i+1] - loc[c][i]);
	}
	//
	return res;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s;
		n = s.length();
		cout << calc() << "\n";
	}
	return 0;
}
