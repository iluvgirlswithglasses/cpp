
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 21 20:44:25 2021
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

int calc(int n) {
	set<int> s;
	for (int i = 2; i * i <= n; i++)
		s.insert(i*i);
	for (int i = 2; i * i * i <= n; i++)
		s.insert(i*i*i);
	return s.size() + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << calc(n) << "\n";
	}
	return 0;
}
