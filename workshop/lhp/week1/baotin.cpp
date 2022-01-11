
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Jan 11 13:12:14 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define ld long double
const int N = 1e5+7;
int n;
// mid = trung điểm của điểm xa nhất và điểm đầu tiên
ld pos[N], k, mid, t, xl, xr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// freopen("BAOTIN.INP", "r", stdin);
	// freopen("BAOTIN.OUT", "w", stdout);
	//
	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> pos[i];
	sort(pos, pos+n);
	mid = (pos[n-1] - pos[0]) / 2;
	//
	if (n&1) {
		xl = (mid - k*(n>>1));
		xr = (mid + k*(n>>1));
	} else {
		xl = (mid - k*(n>>1) + (k/2));
		xr = (mid + k*(n>>1) - (k/2));
	}
	//
	t = max(
		pos[0] >= xl ? 0 : (xl - pos[0]),
		pos[n-1] <= xr ? 0 : (pos[n-1] - xr)
	);
	cout << setprecision(3) << fixed << t << "\n";
	return 0;
}
