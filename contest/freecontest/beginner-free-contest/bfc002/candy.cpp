
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 19:31:20 2022
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

const int N = 2e5+7;
const ll  I = 1e18+7;
int n;
ll  a[N], pre[N], suf[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		pre[i] = a[i] + pre[i-1];
	for (int i = n; i >= 1; i--)
		suf[i] = a[i] + suf[i+1];
	//
	ll best = I;
	for (int i = 1; i < n; i++) {
		best = min(best, abs(pre[i] - suf[i+1]));
	}
	cout << best << "\n";
	return 0;
}
