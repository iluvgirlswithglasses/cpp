
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep 29 22:50:37 2022
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

const int N = 1e5+7;
set<int> s;
int n, a[N], r[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 1; i--) {
		set<int>::iterator p = s.upper_bound(a[i]);
		r[i] = p == s.end() ? -1 : *p;
		s.insert(a[i]);
	}
	for (int i = 1; i <= n; i++)
		cout << r[i] << " ";
	cout << "\n";
	return 0;
}
