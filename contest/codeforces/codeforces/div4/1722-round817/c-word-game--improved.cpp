
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Sep 14 11:57:31 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const string, vector<int>>
#define st first
#define nd second

int n;

int toPts(int sz) {
	if (sz == 1) return 3;
	if (sz == 2) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		vector<int> pts(3);
		map<string, vector<int>> m;
		//
		cin >> n;
		for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++) {
			string k; cin >> k;
			m[k].push_back(i);
		}
		//
		for (pi &p: m) {
			for (int i: p.nd) pts[i] += toPts(p.nd.size());
		}
		for (int i: pts) cout << i << " ";
		cout << "\n";
	}
	return 0;
}
