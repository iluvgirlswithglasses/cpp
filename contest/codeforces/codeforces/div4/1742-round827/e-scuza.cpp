
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 14 13:18:10 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

const int N = 2e5+7, I = 1e9+7, R = 1e9+7;
int n, q, a[N];
ll  s[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			s[i] = a[i] + s[i-1];
			a[i] = max(a[i], a[i-1]);
		}
		while (q--) {
			int k; cin >> k;
			int p = upper_bound(a+1, a+1+n, k) - a;
			cout << s[p-1] - s[0] << " ";
		}
		cout << "\n";
	}
	return 0;
}
