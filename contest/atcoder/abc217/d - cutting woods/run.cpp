
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 18 22:06:04 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <set>
using namespace std;

int l, q, c, x;
set<int> s;

/*
Here, for both kinds of queries c=1,2, 
it is guaranteed that there will have been no cut at Mark x 
when the query is to be processed.
*/

int get() {
	set<int>::iterator p = s.lower_bound(x);
	int r = *p, l = *--p;
	return r - l;
}

void cut() {
	s.insert(x);
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> l >> q;
	s.insert(0);
	s.insert(l);
	//
	while (q--) {
		cin >> c >> x;
		if (c == 1) {
			cut();
		} else if (c == 2) {
			cout << get() << "\n";
		}
	}
	return 0;
}

