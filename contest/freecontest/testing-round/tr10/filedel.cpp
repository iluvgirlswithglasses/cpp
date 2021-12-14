
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 14 21:17:13 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;

const int N = 1e5+7;
int n, q;
string s;
bool del[N];
set<int> in[26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (char c: s) in[c-'a'].insert(i);
	}
	while (q--) {
		char c; cin >> c;
		for (int i: in[c-'a']) {
			if (!del[i]) n--;
			del[i] = true;
		}
		cout << n << "\n";
		in[c-'a'].clear();
	}
	return 0;
}
