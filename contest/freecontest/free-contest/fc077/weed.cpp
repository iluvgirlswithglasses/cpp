
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 19 12:10:12 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// do this cuz the name is kinda fun

#include <iostream>
#include <set>
using namespace std;

set<int> s;
int n, w, res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> w;
	s.insert(w);
	while (--n) {
		cin >> w;
		res = max(res, max(
			abs(*s.begin() - w),
			abs(*--s.end() - w)
		));
		s.insert(w);
	}
	cout << res << "\n";
	return 0;
}

