
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Feb 12 17:13:49 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// fword :)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

const int N = 504;
string s;
int n, m, k, x;
vector<char> alt[N];
char rep[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> x;
	x--;	// everything starts at 0 you dumbass
	cin >> s;
	for (int i = 0; i < m; i++) {
		string a; cin >> a;
		alt[i].reserve(a.length());
		for (char c: a) alt[i].push_back(c);
		//
		sort(all(alt[i]));
	}
	//
	for (int i = m-1; i >= 0; i--) {
		rep[i] = alt[i][x % k];
		x /= k;
	}
	//
	for (int i = 0, j = 0; i < s.length(); i++) {
		if (s[i] == '#') {
			cout << rep[j++];
		} else {
			cout << s[i];
		}
	}
	cout << "\n";
	return 0;
}
