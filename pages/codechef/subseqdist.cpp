
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 30 15:48:36 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

const int N = 1e5+7;
int n;
map<int, int> m;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		m.clear();
		s.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			m[x]++;
		}
		//
		for (pi &p: m) s.insert(p.nd);
		cout << ceil(log2(*s.rbegin())) << "\n";
	}
	return 0;
}
