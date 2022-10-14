
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 14 13:02:54 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n;
		set<int> s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			s.insert(x);
		}
		if (s.size() == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
