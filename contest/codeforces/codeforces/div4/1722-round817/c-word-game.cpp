
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Sep 14 11:42:40 2022
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

#define all(c) c.begin(), c.end()
int n;
set<string> s[3];
int pts[3];

void init() {
	s[0].clear(); s[1].clear(); s[2].clear();
	pts[0] = pts[1] = pts[2] = 0;
}

bool has(set<string> &s, set<string>::iterator i) {
	return s.find(*i) != s.end();
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		init();
		for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++) {
			string k; cin >> k;
			s[i].insert(k);
		}
		//
		for (set<string>::iterator i = s[0].begin(), nxt = i; i != s[0].end(); i = nxt) {
			nxt++;
			if (has(s[1], i) && has(s[2], i)) {
				s[1].erase(*i);
				s[2].erase(*i);
				s[0].erase(i);
			}
		}
		//
		for (set<string>::iterator i = s[0].begin(), nxt = i; i != s[0].end(); i = nxt) {
			nxt++;
			if (has(s[1], i)) {
				s[1].erase(*i);
				s[0].erase(i);
				pts[0]++;
				pts[1]++;
			} else if (has(s[2], i)) {
				s[2].erase(*i);
				s[0].erase(i);
				pts[0]++;
				pts[2]++;
			}
		}
		for (set<string>::iterator i = s[1].begin(), nxt = i; i != s[1].end(); i = nxt) {
			nxt++;
			if (has(s[2], i)) {
				s[2].erase(*i);
				s[1].erase(i);
				pts[1]++;
				pts[2]++;
			}
		}
		//
		for (int i = 0; i < 3; i++) {
			cout << pts[i] + 3*s[i].size() << " ";
		}
		cout << "\n";
	}
	return 0;
}
