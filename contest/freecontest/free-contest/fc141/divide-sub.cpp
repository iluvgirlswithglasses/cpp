
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 27 22:05:58 2022
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

const int N = 1e5+7;
int n, p[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] += p[i-1];
	}
	int res = 1e9+7;
	for (int i = 0; i <= n; i++)
	for (int j = i; j <= n; j++) {
		int s = p[n] - p[j];	// sum of s2 and s3
		int *x = lower_bound(p+j+1, p+n+1, p[j] + s/2);
		// f[] = {s0 s1 s2 s3}, s2 >= s3
		vector<int> f = {
			p[i] - p[0], p[j] - p[i], *x - p[j], p[n] - *x
		};
		res = min(res, *max_element(all(f)) - *min_element(all(f)));
		// f[] = {s0 s1 s2 s3}, s2 < s3
		if (--x - p >= j) {
			f[2] = *x - p[j];
			f[3] = p[n] - *x;
			res = min(res, *max_element(all(f)) - *min_element(all(f)));
		}
	}
	cout << res << "\n";
	return 0;
}
