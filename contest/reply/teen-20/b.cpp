
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Mar  8 16:33:51 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e5+7;
int n;
ll  k, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
			a[i] += a[i-1];

		int l = 0, r = n;
		ll  ans = a[n-1];
		map<ll, int> m;	// { val, ind }
		m[0] = -1;

		for (int i = 0; i < n; i++) {
			// a[i] - a[j] >= k
			// --> a[j] <= a[i] - k
			map<ll, int>::iterator it = m.upper_bound(a[i] - k);
			if (it != m.begin()) {
				pair<const ll, int> p = *--it;
				ll sum = a[i] - p.st;
				if (sum < ans) {
					l = p.nd+1, r = i;
					ans = sum;
				}
			}
			m[a[i]] = i;
		}

		cout << "Case #" << t << ": " << l << " " << r << "\n";
	}
	return 0;
}
