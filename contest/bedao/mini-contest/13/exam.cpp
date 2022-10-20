
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 13 08:42:18 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int q; cin >> q;
		map<int, int> a;
		bool flag = true;
		//
		while (q--) {
			int t, x; cin >> t >> x;
			if (t == 1)
				a[x]++;
			else {
				if (a[x] > 0)
					a[x]--;
				else if (a[0] > 0)
					a[0]--;
				else
					flag = false;
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
