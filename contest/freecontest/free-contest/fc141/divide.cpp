
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 27 22:27:34 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define vi vector<int, int>
#define pi vector<vi, vi>

const int N = 1e5+7;
int n, p[N];

void divide(vi &f, vi &g, int l, int r) {
	int *x = lower_bound(p+l+1, p+r+1, p[l] + (p[r] - p[l])/2);
	// f = {index, sum left, sum right}
	f = {x - p, *x - p[l], p[r] - *x}, g = f;
	if (--x - p >= l)
		g = {x - p, *x - p[l], p[r] - *x};
}

vi join(vi &f, vi &g) {
	vi v;
	for (int i = 1; i < 3; i++)
		v.push_back(f[i]), v.push_back(g[i]);
	return v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] += p[i-1];
	}
	int res = 1e9+7;
	vi fhalf, ghalf;
	divide(fhalf, ghalf, 0, n);
	// devide sub arrays here
	cout << res << "\n";
	return 0;
}
