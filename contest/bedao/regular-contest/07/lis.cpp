
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jun 12 10:56:36 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/**
 * after 6 months without cp
 * my statement reading skill is like trash
 * */

#include <iostream>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

int n;
map<int, int> m;
ll res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		m[a]++;
	}
	//
	ll len = 1;
	for (pi &p: m) {
		res += len * p.nd;
		len++;
	}
	cout << res << "\n";
	return 0;
}
