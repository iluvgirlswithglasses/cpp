
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Nov  4 18:48:45 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <cstdio>
#include <vector>
using namespace std;

#define ll long long

const int K = 22, N = 52;
const ll  I = 5e10+7;
int k, n, a[N];

bool valid(ll m, int k) {
	vector<int> v(a, a+n);
	int i = 0;
	while (k--) {
		ll cr = 0;
		while (i < n) {
			if (v[i] > m - cr) {
				ll add = m - cr;
				v[i] -= add;
				cr = m;
			} else {
				cr += v[i];
				v[i] = 0;
				i++;
			}
			//
			if (cr == m) break;
		}
		//
		if (cr < m) return false;
	}
	return true;
}

int main() {		
	// ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//
	ll l = 0, r = I;
	while (l < r) {
		ll m = (l + r + 1) >> 1;
		if (valid(m, k)) {
			l = m;
		} else {
			r = m-1;
		}
	}
	printf("%Ld\n", l);
	return 0;
}

