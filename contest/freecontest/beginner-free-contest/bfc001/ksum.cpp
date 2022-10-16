
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 19:27:54 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long

const int N = 1e5+7;
int n, k;
ll  s[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i-1];
	}
	ll best = 0;
	for (int l = 0, r = k; r <= n; l++, r++) {
		best = max(best, s[r] - s[l]);
	}
	cout << best << "\n";
	return 0;
}
