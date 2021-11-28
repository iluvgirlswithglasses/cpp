
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 28 20:01:14 2021
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

int n;
string s, pre;
set<string> h;

int proc() {
	for (int i = 2; i <= n; i++) {
		cin >> s;
		if (h.find(s) != h.end()) {
			return i;
		}
		h.insert(s);
		if (s[0] != pre[pre.size()-1]) return i;
		pre = s;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> pre;
	h.insert(pre);
	int res = proc();
	if (res == -1) {
		cout << "YES\n";
	} else {
		cout << "NO\n" << res << "\n";
	}
	return 0;
}
