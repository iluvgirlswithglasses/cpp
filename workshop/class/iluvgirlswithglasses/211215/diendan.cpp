
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 15 18:15:50 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n, m, x[N];

bool valid(int d) {
	int cnt = 1, last = x[0];
	for (int i = 1; i < n; i++) {
		if (x[i] - last >= d) {
			cnt++;
			last = x[i];
		}
	}
	return cnt >= m;
}

int main() {
    // freopen("DIENDAN.INP", "r", stdin);
    // freopen("DIENDAN.OUT", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
    	cin >> n >> m;
    	for (int i = 0; i < n; i++)
    		cin >> x[i];
    	sort(x, x+n);
    	//
    	int l = 1, r = 1e9+7;
    	while (l < r) {
    		int m = (l + r + 1) >> 1;
    		if (valid(m)) {
    			l = m;
    		} else {
    			r = m-1;
    		}
    	}
    	cout << l << "\n";
    }
	return 0;
}

